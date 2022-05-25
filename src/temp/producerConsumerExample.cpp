// producerConsumerExample.cpp
//

#include "producerConsumerExample.hh"
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <atomic>
#include <sstream>

#define SDL_STB_FONT_IMPL
#include "sdlStbFont.h"
#include "producerConsumerFrontend.h"

/// Opens a file and returns a string of the raw data
void readFileRaw (const std::string & fullPath, std::string & output) {
	std::ifstream fs(fullPath.c_str(), std::ios::in | std::ios::binary);
	
	if (!fs.is_open()) {
		std::cout << "readFileRaw: " << fullPath << " -- " << "WARNING: Could not open file." << std::endl;
		exit(1);
		return;
		}
	else {
		std::cout << "Opened! " << fullPath << std::endl;
		}
				
	fs.seekg (0, std::ios::end);
	const size_t LEN = fs.tellg();
	fs.seekg (0, std::ios::beg);
	
	output.resize(LEN);
	fs.read(&output[0], LEN);
	fs.close();
	}

////////////////////////////////////////////////////////////////////////
// Example command buffer

#define COMMAND_TYPE_SUB_ID 0
#define COMMAND_TYPE_RECT 1
#define COMMAND_TYPE_PRETEXT 2
#define COMMAND_TYPE_TEXT 3

struct command {
	int type;
	pcfc_handle handle;
	int x, y, w, h;
	
	inline command (int _type, pcfc_handle _handle = -1, int _x = 0, int _y = 0, int _w = 0, int _h = 0) :
		type(_type), handle(_handle), x(_x), y(_y), w(_w), h(_h) {}
	};
	
	
class CommandBuffer {
public:
	// Quick and dirty command buffer implementation
	// Consumer will resuse its buffer if producer has not made any
	// A better way to do this is to have a semaphore on the producer thread
	// and have the consumer signal said semaphore when it consumes
	std::vector<command> mCommandsProducer;
	std::vector<command> mCommandsTx;
	std::vector<command> mCommandsConsumer;
	std::mutex mMutex;
	std::atomic<int> workFlag;
	
	void push_back(command c) {
		mCommandsProducer.push_back(std::move(c));
		}
	
	void submitToConsumer() {
		while (workFlag > 0)
			SDL_Delay(1); //spinlock until consumer thread is finished
		workFlag = 1; // indicate that we have fresh data
		std::lock_guard LG(mMutex);
		mCommandsTx.swap(mCommandsProducer);
		}
		
	void receiveFromProducer() {
		workFlag = 0; // indicate that we are ready for stuff
		std::lock_guard LG(mMutex);
		if (mCommandsTx.size()) {
			mCommandsConsumer.clear();
			mCommandsTx.swap(mCommandsConsumer);
			}
		}
	};
	
class pcfc_example {
public:
	producer_consumer_font_cache mPcCache;
	sdl_stb_font_cache mSdlFontCache;
	CommandBuffer mCommandBuffer; // an example of this is at https://github.com/SnapperTT/nanovg_command_buffer
	std::atomic<int> killFlag;
	
	void initExample(std::string & fontData) {
		mPcCache.consumer_font_cache = &mSdlFontCache;
		killFlag = 0;
		
		sttfont_memory m;
		m.data = &fontData[0];
		m.size = fontData.size();
		m.ownsData = false;
		
		mPcCache.faceSize = 24;		
		mPcCache.loadFontManagedBoth(m); // loads a copy of the font into both mPcCache and mRenderCache
										 // note: faceSize, etc are sync'ed between both copies in here
		}
		
	void producerExample() {
		// example producer thread
		// init
		pcfc_prerendered_text prt;
		mPcCache.renderTextToObject(&prt, "Prerendered text from Producer Thread!"); // prt now holds a handle
		mPcCache.submitToConsumer();
		
		int submissionCounter = 0;
		
		// main loop - buffer draw commands somehow
		while (!killFlag) {
			mCommandBuffer.push_back(command(COMMAND_TYPE_SUB_ID, submissionCounter));
			mCommandBuffer.push_back(command(COMMAND_TYPE_RECT, -1, 0, 0, 450, 100));
			mCommandBuffer.push_back(command(COMMAND_TYPE_PRETEXT, prt.handle, 5, 35));
			std::stringstream ss;
			ss << "Direct Text from Producer Thread, Submission id: " << submissionCounter;
			pcfc_handle textHandle = mPcCache.pushText(5,5, ss.str());
			mCommandBuffer.push_back(command(COMMAND_TYPE_TEXT, textHandle));
			 
			//if (someUpdate) {
			//	mPcCache.destoryPrerender(id);
			//	mPcCache.submitToConsumer();
			//	}
			
			mPcCache.submitToConsumer();
			mCommandBuffer.submitToConsumer();
			submissionCounter++;
			}
		std::cout << "Producer thread exited" << std::endl;
		}
	
	static void producer_thread_main(void* data) {
		pcfc_example * I = (pcfc_example*) data;
		I->producerExample();
		}
	
	void consumerExample() {
		// example render thread
		int frameCounter = 0;
		int lastSubCounter = 0;
		
		uint64_t NOW = SDL_GetPerformanceCounter();
		uint64_t LAST = 0;
		
		while (true) {
			// Receive from producer thread
			mPcCache.receiveFromProducer();
			mPcCache.dispatchPrerenderJobs<sdl_stb_prerendered_text>(); // must be called to actually prerender the text
			mCommandBuffer.receiveFromProducer();
			
			// Handle SDL events
			SDL_Event ev;
			while (SDL_PollEvent(&ev)) {
				switch (ev.type) {
					case SDL_QUIT:
						{
						killFlag = 1;
						mCommandBuffer.workFlag = 0;
						SDL_Delay(10);
						return;
						break;
						}
					}
				}
			
			// Setup SDL Rendering
			SDL_Renderer* mSdlRenderer = mSdlFontCache.mRenderer;
			SDL_SetRenderDrawColor(mSdlRenderer, 125, 125, 125, 255); // Grey background to test glyph artefacts
			SDL_RenderClear(mSdlRenderer);
						
			// Process command buffer
			for (const command & mCommand : mCommandBuffer.mCommandsConsumer) {
				switch (mCommand.type) {
					case COMMAND_TYPE_SUB_ID:
						lastSubCounter = mCommand.handle;
						continue;
					case COMMAND_TYPE_PRETEXT: 
						mPcCache.dispatchSinglePrerendered(mCommand.handle, mCommand.x, mCommand.y);
						continue;
					case COMMAND_TYPE_TEXT:
						mPcCache.dispatchSingleText(mCommand.handle);
						continue;
					case COMMAND_TYPE_RECT:
						{
						SDL_SetRenderDrawColor(mSdlRenderer, 55, 55, 55, 255); // dark grey rectangle
						SDL_Rect r;
						r.x = mCommand.x; r.y = mCommand.y; r.w = mCommand.w; r.h = mCommand.h;
						SDL_RenderDrawRect(mSdlRenderer, &r);
						continue;
						}
					default:
						continue;
					}
				}
			
			std::stringstream ss;
			ss << "Text from consumer thread! Submission id: " << lastSubCounter;
			mSdlFontCache.drawText(5, 65, ss.str());
			
			SDL_RenderPresent(mSdlRenderer);
			frameCounter++;
			//SDL_Delay(13);
			
			if (frameCounter % 100 == 0) {
				LAST = NOW;
				NOW = SDL_GetPerformanceCounter();
				const double deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() ) / 100.0;
				std::cout << "Producer Consumer - Consumer Thread - 100 Frames Average - Frametime: " << deltaTime << "ms \t FPS: " << (1000.0/deltaTime) << std::endl;
				}
			}
		}
	};

int main(int argc, char**argv) {		
	// Setup the SDL window & renderer
	int windowWidth = 800;
	int windowHeight = 1000;

	SDL_Init(0);
	SDL_Window * mWindow = SDL_CreateWindow("Producer Consumer Example Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	
	SDL_Renderer * mSdlRenderer = SDL_CreateRenderer(mWindow, SDL_RENDERER_SOFTWARE, 0);
	
	pcfc_example ex;
	ex.mSdlFontCache.bindRenderer(mSdlRenderer);  // Must bind a renderer before generating any glyphs
	
	{
	std::string fontData;
	readFileRaw("fonts/NotoSans-Regular.ttf", fontData);
	ex.initExample(fontData);
	}
	
	// spawn a producer thread
	std::thread producerThread(pcfc_example::producer_thread_main, &ex);
	ex.consumerExample();
	producerThread.join();
	
	// Cleanup - just let ex.mPcCache fall out of scope
	ex.mPcCache.freeStoredPrerenderedText(true); // deletes all prerendered text objects stored. true == also calls prt->freeTexture() for all prerendered text

	std::cout << "Consumer thread exited" << std::endl;
	return 1;
	}

#define LZZ_INLINE inline
#undef LZZ_INLINE
