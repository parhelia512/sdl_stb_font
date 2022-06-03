// This file is autogenerated. See look at the .lzz files in the src/ directory for a more human-friendly version
// producerConsumerFrontend.hh
//

#ifndef LZZ_producerConsumerFrontend_hh
#define LZZ_producerConsumerFrontend_hh
/// Used for when you want to have, eg, an Update thread and a Render thread
/// 
#ifndef SSF_MUTEX
	#define SSF_MUTEX std::mutex
	#include <mutex>
#endif

typedef uint32_t pcfc_handle;
struct producer_consumer_font_cache;

#ifdef SSF_CONCURRENT_QUEUE
	#define SSF_STATE_TRANSFER SSF_CONCURRENT_QUEUE<state_t*>
#else
	#define SSF_STATE_TRANSFER SSF_MUTEX mMutex; state_t
#endif
#define LZZ_INLINE inline
struct pcfc_prerendered_text : public sttfont_prerendered_text
{
  pcfc_handle handle;
  producer_consumer_font_cache * owner;
  void freeTexture ();
};
class producer_consumer_font_cache : public sttfont_font_cache
{
protected:
  struct pcfc_consumer_prerendered_text : public sttfont_prerendered_text
  {
    pcfc_handle handle;
    sttfont_formatted_text text;
    pcfc_consumer_prerendered_text ();
  };
  struct pcfc_formatted_text
  {
    sttfont_formatted_text text;
    int x;
    int y;
  };
public:
  sttfont_font_cache * consumer_font_cache;
public:
  pcfc_handle nextPrerenderTokenId;
  SSF_MAP <pcfc_handle, sttfont_prerendered_text*> prerenderMap;
  SSF_MAP <uint64_t, sttfont_glyph> mGlyphs;
  struct state_t
  {
    SSF_VECTOR <producer_consumer_font_cache::pcfc_consumer_prerendered_text> prerender;
    SSF_VECTOR <pcfc_handle> destroyPrerender;
    SSF_VECTOR <producer_consumer_font_cache::pcfc_formatted_text> text;
    void * userdata;
    state_t ();
    void swap (state_t & s);
    void clear ();
  };
  state_t producerState;
  SSF_STATE_TRANSFER txQueue;
  state_t consumerState;
  pcfc_handle getNextPrerenderToken ();
public:
  producer_consumer_font_cache ();
  void freeStoredPrerenderedText (bool const freeTextures);
  sttfont_glyph * getGlyph (uint64_t const target);
  sttfont_glyph * genGlyph_createAndInsert (uint64_t const target, uint32_t const codepoint, uint8_t const format);
  void loadFontManagedBoth (sttfont_memory & memory, int index = 0);
  void addFontManagedBoth (sttfont_memory & memory, int index = 0);
  void addFormatFontManagedBoth (uint8_t formatMask, sttfont_memory & memory, int index = 0);
  pcfc_handle pushText (int const x, int const y, char const * c, uint32_t const maxLen = -1, int * xOut = NULL, int * widthOut = NULL, int * heightOut = NULL);
  pcfc_handle pushText (int const x, int const y, SSF_STRING const & str, int * xOut = NULL, int * widthOut = NULL, int * heightOut = NULL);
  pcfc_handle pushText (int const x, int const y, sttfont_formatted_text const & str, int * xOut = NULL, int * widthOut = NULL, int * heightOut = NULL);
  void drawCodepoint (sttfont_glyph const * const GS, int const x, int const y, uint32_t const codepoint, sttfont_format const * const format, uint8_t const formatCode, int const kerningAdv, int & overdraw);
  void renderTextToObject (sttfont_prerendered_text * textOut, char const * c, uint32_t const maxLen = -1);
  void renderTextToObject (sttfont_prerendered_text * textOut, SSF_STRING const & str);
  void renderTextToObject (sttfont_prerendered_text * textOut, sttfont_formatted_text const & str);
  void destroyPrerender (pcfc_handle const handle);
  void pushUserdata (void * data);
  void submitToConsumer ();
  bool receiveFromProducer ();
  template <typename T>
  int dispatchPrerenderJobs ();
  template <typename T>
  int dispatchDestroy ();
  void dispatchSinglePrerendered (pcfc_handle const prtId, int x, int y) const;
  void dispatchSinglePrerenderedWColorMod (pcfc_handle const prtId, int x, int y, int const r, int const g, int const b, int const a) const;
  void dispatchSingleText (pcfc_handle const texId);
  void * getUserdata ();
};
template <typename T>
int producer_consumer_font_cache::dispatchPrerenderJobs ()
                                    {
		// T is the sttfont_prerendered_text subclass that is used by consumer_font_cache
		int nDone = 0;
		for (pcfc_consumer_prerendered_text & p2 : consumerState.prerender) {
			auto itt = prerenderMap.find(p2.handle);
			if (itt != prerenderMap.end())
				abort(); // Idx reusued, this will leak memory
			T* t = SSF_NEW(T);
			consumer_font_cache->renderTextToObject(t, p2.text);
			prerenderMap[p2.handle] = t;
			nDone++;
			}
		consumerState.prerender.clear();
		return nDone;
		}
template <typename T>
int producer_consumer_font_cache::dispatchDestroy ()
                              {
		// T is the sttfont_prerendered_text subclass that is used by consumer_font_cache
		int nDone = 0;
		for (const pcfc_handle idx : consumerState.destroyPrerender) {
			auto itt = prerenderMap.find(idx);
			if (itt != prerenderMap.end()) {
				itt->second->freeTexture();
				SSF_DEL(itt->second);
				prerenderMap.erase(itt);
				nDone++;
				}
			}
		consumerState.destroyPrerender.clear();
		return nDone;
		}
#undef LZZ_INLINE
#endif

////////////////////////////////////////////////////////////////////////

#ifdef SDL_STB_FONT_IMPL
#ifndef SDL_STB_FONT_IMPL_DOUBLE_GUARD_producerConsumerFrontend
#define SDL_STB_FONT_IMPL_DOUBLE_GUARD_producerConsumerFrontend
// producerConsumerFrontend.cpp
//

#define LZZ_INLINE inline
void pcfc_prerendered_text::freeTexture ()
                           {
		if (owner)
			owner->destroyPrerender(handle);
		}
producer_consumer_font_cache::pcfc_consumer_prerendered_text::pcfc_consumer_prerendered_text ()
                                                 {}
producer_consumer_font_cache::state_t::state_t ()
  : userdata (NULL)
                                           {}
void producer_consumer_font_cache::state_t::swap (state_t & s)
                                       {
			prerender.swap(s.prerender);
			destroyPrerender.swap(s.destroyPrerender);
			text.swap(s.text);
			void * tmp = s.userdata;
			s.userdata = userdata;
			userdata = tmp;
			}
void producer_consumer_font_cache::state_t::clear ()
                             {
			prerender.clear();
			destroyPrerender.clear();
			text.clear();
			userdata = NULL;
			}
pcfc_handle producer_consumer_font_cache::getNextPrerenderToken ()
                                            {
		return nextPrerenderTokenId++;
		}
producer_consumer_font_cache::producer_consumer_font_cache ()
  : consumer_font_cache (NULL), nextPrerenderTokenId (0)
                                                                                            {}
void producer_consumer_font_cache::freeStoredPrerenderedText (bool const freeTextures)
                                                                {
		for (auto ppair : prerenderMap) {
			sttfont_prerendered_text* prt = ppair.second;
			if (!prt) continue;
			if (freeTextures) {
				prt->freeTexture();
				}
			SSF_DEL(prt);
			}
		prerenderMap.clear();
		}
sttfont_glyph * producer_consumer_font_cache::getGlyph (uint64_t const target)
                                                        {
		auto it = mGlyphs.find(target);
		if (it == mGlyphs.end())
			return NULL;
		return &((*it).second);
		}
sttfont_glyph * producer_consumer_font_cache::genGlyph_createAndInsert (uint64_t const target, uint32_t const codepoint, uint8_t const format)
                                                                                                                        {
		sttfont_glyph g;
		genGlyph(codepoint, format, &g);
		mGlyphs[target] = g;
		return getGlyph(target);
		}
void producer_consumer_font_cache::loadFontManagedBoth (sttfont_memory & memory, int index)
                                                                          {
		sttfont_memory memory2;
		memory.cloneTo(memory2);
		
		consumer_font_cache->syncFrom(*this);
		consumer_font_cache->loadFontManaged(memory2, index);
		this->syncFrom(*consumer_font_cache);
		this->loadFontManaged(memory, index);
		}
void producer_consumer_font_cache::addFontManagedBoth (sttfont_memory & memory, int index)
                                                                         {
		sttfont_memory memory2;
		memory.cloneTo(memory2);
		
		consumer_font_cache->syncFrom(*this);
		consumer_font_cache->addFontManaged(memory2, index);
		this->syncFrom(*consumer_font_cache);
		this->addFontManaged(memory, index);
		}
void producer_consumer_font_cache::addFormatFontManagedBoth (uint8_t formatMask, sttfont_memory & memory, int index)
                                                                                                   {
		sttfont_memory memory2;
		memory.cloneTo(memory2);
		
		consumer_font_cache->syncFrom(*this);
		consumer_font_cache->addFormatFontManaged(formatMask, memory2, index);
		this->syncFrom(*consumer_font_cache);
		this->addFormatFontManaged(formatMask, memory, index);
		}
pcfc_handle producer_consumer_font_cache::pushText (int const x, int const y, char const * c, uint32_t const maxLen, int * xOut, int * widthOut, int * heightOut)
                                                                                                                                                                 {
		sttfont_formatted_text tmp(c, maxLen);
		return pushText(x, y, tmp, xOut, widthOut, heightOut);
		}
pcfc_handle producer_consumer_font_cache::pushText (int const x, int const y, SSF_STRING const & str, int * xOut, int * widthOut, int * heightOut)
                                                                                                                                              {
		sttfont_formatted_text tmp(str);
		return pushText(x, y, tmp, xOut, widthOut, heightOut);
		}
pcfc_handle producer_consumer_font_cache::pushText (int const x, int const y, sttfont_formatted_text const & str, int * xOut, int * widthOut, int * heightOut)
                                                                                                                                                          {
		if (xOut || widthOut || heightOut) {
			int xx = processFormatted(str, x, y, false, widthOut, heightOut);
			if (xOut) *xOut = xx;
			}
		pcfc_formatted_text p;
		p.text = str;
		p.x = x;
		p.y = y;
		producerState.text.push_back(std::move(p));
		return producerState.text.size() - 1; 
		}
void producer_consumer_font_cache::drawCodepoint (sttfont_glyph const * const GS, int const x, int const y, uint32_t const codepoint, sttfont_format const * const format, uint8_t const formatCode, int const kerningAdv, int & overdraw)
                                                                                                                                                                                                                     {
		// This function should never be called for this frontend. Use pushText instead of drawText
		abort();
		}
void producer_consumer_font_cache::renderTextToObject (sttfont_prerendered_text * textOut, char const * c, uint32_t const maxLen)
                                                                                                                 {
		sttfont_formatted_text tmp(c, maxLen);
		renderTextToObject (textOut, tmp);
		}
void producer_consumer_font_cache::renderTextToObject (sttfont_prerendered_text * textOut, SSF_STRING const & str)
                                                                                             {
		sttfont_formatted_text tmp(str);
		renderTextToObject (textOut, tmp);
		}
void producer_consumer_font_cache::renderTextToObject (sttfont_prerendered_text * textOut, sttfont_formatted_text const & str)
                                                                                                         {
		pcfc_prerendered_text* p = (pcfc_prerendered_text*) textOut;
		getTextSize(textOut->width, textOut->height, str);
		p->handle = getNextPrerenderToken();
		p->owner = this;
		
		pcfc_consumer_prerendered_text p2;
		p2.width = p->width;
		p2.height = p->height;
		p2.handle = p->handle;
		p2.text = str;
		
		producerState.prerender.push_back(p2);
		}
void producer_consumer_font_cache::destroyPrerender (pcfc_handle const handle)
                                                        {
		producerState.destroyPrerender.push_back(handle);
		}
void producer_consumer_font_cache::pushUserdata (void * data)
                                      {
		producerState.userdata = data;
		}
void producer_consumer_font_cache::submitToConsumer ()
                                {
		#ifdef SSF_CONCURRENT_QUEUE
			state_t * s = new state_t;
			s->swap(producerState);
			txQueue.enqueue(s);
		#else
			mMutex.lock();
			txQueue.clear();
			txQueue.swap(producerState);
			mMutex.unlock();
		#endif
		}
bool producer_consumer_font_cache::receiveFromProducer ()
                                   {
		#ifdef SSF_CONCURRENT_QUEUE
			state_t * s = NULL;
			if (txQueue.try_dequeue(s)) {
				s->swap(consumerState);
				delete s;
				return true;
				}
			return false;
		#else
			consumerState.clear();
			mMutex.lock();
			consumerState.swap(txQueue);
			mMutex.unlock();
			return true;
		#endif
		}
void producer_consumer_font_cache::dispatchSinglePrerendered (pcfc_handle const prtId, int x, int y) const
                                                                                    {
		auto itt = prerenderMap.find(prtId);
		if (itt != prerenderMap.end()) {
			itt->second->draw(consumer_font_cache, x, y);
			}
		else {
			//std::cout << "Could not find prerendered text #" << prtId << std::endl;
			}
		}
void producer_consumer_font_cache::dispatchSinglePrerenderedWColorMod (pcfc_handle const prtId, int x, int y, int const r, int const g, int const b, int const a) const
                                                                                                                                                 {
		auto itt = prerenderMap.find(prtId);
		if (itt != prerenderMap.end()) {
			itt->second->drawWithColorMod(consumer_font_cache, x, y, r, g, b, a);
			}
		}
void producer_consumer_font_cache::dispatchSingleText (pcfc_handle const texId)
                                                         {
		if (texId < consumerState.text.size() && texId >= 0) {
			pcfc_formatted_text & pcf = consumerState.text[texId];
			consumer_font_cache->drawText(pcf.x, pcf.y, pcf.text);
			}
		}
void * producer_consumer_font_cache::getUserdata ()
                            {
		return consumerState.userdata;
		}
#undef LZZ_INLINE
#endif //SDL_STB_FONT_IMPL_DOUBLE_GUARD_producerConsumerFrontend
#endif //SDL_STB_FONT_IMPL_IMPL
