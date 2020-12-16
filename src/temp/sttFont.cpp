// sttFont.cpp
//

#include "sttFont.hh"
#include <stdio.h>

#ifndef STB_TRUETYPE_INCLUDE_HANDLED
	////////////////////////////////////////
	// STB TRUETYPE 
	#define STB_TRUETYPE_IMPLEMENTATION
	#include <math.h>
	#include <string.h>
	#include <assert.h>
	#include <stdlib.h>
	#include "stb_truetype.h"
	////////////////////////////////////////
#endif

#define LZZ_INLINE inline
sttfont_lookupHint::sttfont_lookupHint ()
  : index (0), workingLen (0), workingX (0), workingY (0), uCharLast (0), writeOut (false)
                                                                                                                {}
void sttfont_format_callback::callbackOnDraw (sttfont_formatted_text const & text, int index, int x, int y, int xOffsetInitial, int xOffsetAfter, int segmentWidth, int segmentHeight)
                                                                                                                                                                             {}
uint8_t const sttfont_format::FORMAT_NONE = 0 << 0;
uint8_t const sttfont_format::FORMAT_BOLD = 1 << 0;
uint8_t const sttfont_format::FORMAT_ITALIC = 1 << 1;
uint8_t const sttfont_format::FORMAT_UNDERLINE = 1 << 2;
uint8_t const sttfont_format::FORMAT_STRIKETHROUGH = 1 << 3;
uint8_t const sttfont_format::FORMAT_RENDER_EVEN_IF_CALLBACK_EXISTS = 1 << 7;
uint8_t const sttfont_format::FORMAT_FLAGS_COLOUR_SET = 1 << 0;
sttfont_format::sttfont_format ()
  : r (255), g (255), b (255), a (255), format (0), flags (0)
                                                                               {}
sttfont_format::sttfont_format (uint8_t const _format)
  : r (255), g (255), b (255), a (255), format (_format), flags (0)
                                                                                                    {}
sttfont_format::sttfont_format (uint8_t const _format, uint8_t const _r, uint8_t const _g, uint8_t const _b, uint8_t const _a)
  : r (_r), g (_g), b (_b), a (_a), format (_format), flags (FORMAT_FLAGS_COLOUR_SET)
                                                                                                                      {}
void sttfont_format::combine (sttfont_format const & other)
                                                   {
		format |= other.format;
		flags |= other.flags;
		r = 255*((r/255.0)*(other.r/255.0));
		g = 255*((g/255.0)*(other.g/255.0));
		b = 255*((b/255.0)*(other.b/255.0));
		a = 255*((a/255.0)*(other.a/255.0));
		}
sttfont_format sttfont_format::color (uint8_t const _r, uint8_t const _g, uint8_t const _b, uint8_t const _a)
                                                                                                                   { sttfont_format ret(FORMAT_NONE,_r,_g,_b,_a); ret.flags |= FORMAT_FLAGS_COLOUR_SET; return ret; }
sttfont_format sttfont_format::colour (uint8_t const _r, uint8_t const _g, uint8_t const _b, uint8_t const _a)
                                                                                                                   { sttfont_format ret(FORMAT_NONE,_r,_g,_b,_a); ret.flags |= FORMAT_FLAGS_COLOUR_SET; return ret; }
sttfont_format const sttfont_format::bold = sttfont_format(FORMAT_BOLD);
sttfont_format const sttfont_format::italic = sttfont_format(FORMAT_ITALIC);
sttfont_format const sttfont_format::underline = sttfont_format(FORMAT_UNDERLINE);
sttfont_format const sttfont_format::strikethrough = sttfont_format(FORMAT_STRIKETHROUGH);
sttfont_format const sttfont_format::red = sttfont_format(FORMAT_NONE,255,  0,  0,255);
sttfont_format const sttfont_format::green = sttfont_format(FORMAT_NONE,  0,255,  0,255);
sttfont_format const sttfont_format::blue = sttfont_format(FORMAT_NONE,  0,  0,255,255);
sttfont_format const sttfont_format::yellow = sttfont_format(FORMAT_NONE,255,255,  0,255);
sttfont_format const sttfont_format::black = sttfont_format(FORMAT_NONE,  0,  0,  0,255);
sttfont_format const sttfont_format::white = sttfont_format(FORMAT_NONE,255,255,255,255);
sttfont_format const sttfont_format::magenta = sttfont_format(FORMAT_NONE,255,  0,255,255);
sttfont_format const sttfont_format::cyan = sttfont_format(FORMAT_NONE,  0,255,255,255);
sttfont_format const sttfont_format::grey = sttfont_format(FORMAT_NONE,128,128,128,255);
sttfont_format_reset const sttfont_format::reset;
void sttfont_format::swap (sttfont_format & other)
                                          {
		sttfont_format tmp = *this;
		*this = other;
		other = tmp;
		}
void sttfont_format::sttr_register ()
                                    {
		#ifdef STTR_ENABLED
		// Reflection stuff - see snappertt/sttr on github for more info. You don't need STTR to use this library
		sttr::RegNamespace & R = *sttr::getGlobalNamespace();
		R.beginClass<sttfont_format>("sttfont_format")
			.STTR_REGF(sttfont_format,r,STTR_JSON_ENABLED)
			.STTR_REGF(sttfont_format,g,STTR_JSON_ENABLED)
			.STTR_REGF(sttfont_format,b,STTR_JSON_ENABLED)
			.STTR_REGF(sttfont_format,a,STTR_JSON_ENABLED)
			.STTR_REGF(sttfont_format,format,STTR_JSON_ENABLED)
			.STTR_REGF(sttfont_format,flags,STTR_JSON_ENABLED)
			
			.STTR_REG(sttfont_format,combine)
			
			.STTR_REG(sttfont_format,color)
			.STTR_REG(sttfont_format,colour)
			.STTR_REG(sttfont_format,bold)
			.STTR_REG(sttfont_format,italic)
			.STTR_REG(sttfont_format,underline)
			.STTR_REG(sttfont_format,strikethrough)
			
			.STTR_REG(sttfont_format,red)
			.STTR_REG(sttfont_format,green)
			.STTR_REG(sttfont_format,blue)
			.STTR_REG(sttfont_format,yellow)
			.STTR_REG(sttfont_format,black)
			.STTR_REG(sttfont_format,white)
			.STTR_REG(sttfont_format,magenta)
			.STTR_REG(sttfont_format,cyan)
			.STTR_REG(sttfont_format,grey)
			
			.STTR_REG(sttfont_format,reset)
		.endClass();
		#endif
		}
void * sttfont_format::sttr_getClassSig () const
        { return ( void * ) sttr :: getTypeSignature < sttfont_format > ( ) ; }
char const * const sttfont_format::sttr_getClassName () const
        { return sttr :: getTypeName < sttfont_format > ( ) ; }
sttfont_formatted_text_item::sttfont_formatted_text_item ()
  : callback (0)
                                                     {}
sttfont_formatted_text_item::sttfont_formatted_text_item (SSF_STRING const & _text, sttfont_format const & _format)
  : text (_text), format (_format), callback (0)
                                                                                                                                            {}
sttfont_formatted_text_item::sttfont_formatted_text_item (SSF_STRING_MS _text, sttfont_format const & _format)
  : text (_text), format (_format), callback (0)
                                                                                                                                                    {}
sttfont_formatted_text_item & sttfont_formatted_text_item::setCallback (sttfont_format_callback * _cb)
                                                                               { callback = _cb; return *this; }
void sttfont_formatted_text_item::sttr_register ()
                                    {
		#ifdef STTR_ENABLED
		sttr::RegNamespace & R = *sttr::getGlobalNamespace();
		R.beginClass<sttfont_formatted_text_item>("sttfont_formatted_text_item")
			.STTR_REGF(sttfont_formatted_text_item,text,STTR_JSON_ENABLED)
			.STTR_REGF(sttfont_formatted_text_item,format,STTR_JSON_ENABLED)
		.endClass();
		#endif
		}
void * sttfont_formatted_text_item::sttr_getClassSig () const
        { return ( void * ) sttr :: getTypeSignature < sttfont_formatted_text_item > ( ) ; }
char const * const sttfont_formatted_text_item::sttr_getClassName () const
        { return sttr :: getTypeName < sttfont_formatted_text_item > ( ) ; }
sttfont_formatted_text::sttfont_formatted_text ()
                                {}
sttfont_formatted_text::sttfont_formatted_text (sttfont_formatted_text const & obj)
                                                                   { mItems = std::move(obj.mItems); activeFormat = std::move(obj.activeFormat); }
sttfont_formatted_text::sttfont_formatted_text (SSF_STRING const & text)
                                                        { *this << text; }
sttfont_formatted_text::sttfont_formatted_text (SSF_STRING_MS text)
                                                                { *this << text; }
sttfont_formatted_text::sttfont_formatted_text (char const * text)
                                                                { *this << text; }
sttfont_formatted_text::sttfont_formatted_text (sttfont_formatted_text_item_MS text)
                                                                                        { *this << text; }
sttfont_formatted_text::sttfont_formatted_text (sttfont_formatted_text_item const & text)
                                                                                { *this << text; }
sttfont_formatted_text::sttfont_formatted_text (sttfont_formatted_text_MS obj)
                                                             { mItems = std::move(obj.mItems); activeFormat = std::move(obj.activeFormat); }
sttfont_formatted_text & sttfont_formatted_text::operator = (sttfont_formatted_text_MS obj)
                                                                          { mItems = std::move(obj.mItems); activeFormat = std::move(obj.activeFormat); return *this; }
sttfont_formatted_text & sttfont_formatted_text::operator = (sttfont_formatted_text const & obj)
                                                                               { mItems = obj.mItems; activeFormat = obj.activeFormat; return *this; }
void sttfont_formatted_text::resetFormat ()
                           { activeFormat = sttfont_format(); }
sttfont_formatted_text & sttfont_formatted_text::operator << (SSF_STRING const & text)
                                                                        { mItems.push_back(sttfont_formatted_text_item(text, activeFormat)); resetFormat(); return *this; }
sttfont_formatted_text & sttfont_formatted_text::operator << (SSF_STRING_MS text)
                                                                                { mItems.push_back(sttfont_formatted_text_item(text, activeFormat)); resetFormat(); return *this;  }
sttfont_formatted_text & sttfont_formatted_text::operator << (char const * text)
                                                                                { mItems.push_back(sttfont_formatted_text_item(SSF_STRING(text), activeFormat)); resetFormat(); return *this;  }
sttfont_formatted_text & sttfont_formatted_text::operator += (SSF_STRING const & text)
                                                                        { mItems.push_back(sttfont_formatted_text_item(text, activeFormat)); resetFormat(); return *this; }
sttfont_formatted_text & sttfont_formatted_text::operator += (SSF_STRING_MS text)
                                                                                { mItems.push_back(sttfont_formatted_text_item(text, activeFormat)); resetFormat(); return *this;  }
sttfont_formatted_text & sttfont_formatted_text::operator += (char const * text)
                                                                                        { mItems.push_back(sttfont_formatted_text_item(SSF_STRING(text), activeFormat)); resetFormat(); return *this;  }
sttfont_formatted_text & sttfont_formatted_text::operator << (sttfont_format const & format)
                                                                                        { activeFormat.combine(format); return *this; }
sttfont_formatted_text & sttfont_formatted_text::operator << (sttfont_format_reset const & reset)
                                                                                        { resetFormat(); return *this; }
sttfont_formatted_text & sttfont_formatted_text::operator << (sttfont_formatted_text_item const & obj)
                                                                                      { mItems.push_back(obj); return *this; }
sttfont_formatted_text & sttfont_formatted_text::operator << (sttfont_formatted_text_item_MS obj)
                                                                                        { mItems.push_back(obj); return *this; }
void sttfont_formatted_text::sttr_register ()
                                    {
		#ifdef STTR_ENABLED
		sttr::RegNamespace & R = *sttr::getGlobalNamespace();
		R.beginClass<sttfont_formatted_text>("sttfont_formatted_text")
			.STTR_REGF(sttfont_formatted_text,mItems,STTR_JSON_ENABLED)
			.STTR_REGF(sttfont_formatted_text,activeFormat,STTR_JSON_ENABLED)
		.endClass();
		#endif
		}
void * sttfont_formatted_text::sttr_getClassSig () const
        { return ( void * ) sttr :: getTypeSignature < sttfont_formatted_text > ( ) ; }
char const * const sttfont_formatted_text::sttr_getClassName () const
        { return sttr :: getTypeName < sttfont_formatted_text > ( ) ; }
sttfont_formatted_text sttfont_formatted_text::copy () const
                                            {
		// Explicit copy - named function
		sttfont_formatted_text r = *this;
		return r;
		}
void sttfont_formatted_text::swap (sttfont_formatted_text & other)
                                                  {
		other.mItems.swap(mItems);
		other.activeFormat.swap(activeFormat);
		}
size_t sttfont_formatted_text::size () const
                            {
		/// Combined length of all the segments
		size_t workingLen = 0;
		for (unsigned int  i = 0; i < mItems.size(); ++i ) {
			workingLen += mItems[i].text.size();
			}
		return workingLen;
		}
size_t sttfont_formatted_text::length () const
                              { return size(); }
bool sttfont_formatted_text::isEmpty () const
                             {
		/// Returns true if there are no segments, or there are only empty segments
		/// Ie, returns true if this contains no characters
		if (!mItems.size()) return true;
		//if (mItems.size() == 1) return !mItems[0].text.size();
		for (sttfont_formatted_text_item item : mItems)
			if (item.text.size()) return false;
		return false;
		}
SSF_STRING sttfont_formatted_text::getString () const
                                     {
		/// Returns a plain unformatted string of all the segments stitched together
		SSF_STRING r;
		r.reserve(size());
		for (unsigned int  i = 0; i < mItems.size(); ++i ) {
			r += mItems[i].text;
			}
		return r;
		}
SSF_STRING sttfont_formatted_text::getStringTruncated (unsigned int const maxLen) const
                                                                       {
		/// Returns a plain unformatted string of all the segments stitched together, cut to max len
		SSF_STRING r;
		r.reserve(size());
		for (unsigned int  i = 0; i < mItems.size(); ++i ) {
			r += mItems[i].text;
			if (r.size() > maxLen) {
				if (maxLen > 3)
					return r.substr(0, maxLen-3)+"...";
				return r.substr(0, maxLen);
				}
			}
		return r;
		}
void sttfont_formatted_text::append (sttfont_formatted_text const & obj)
                                                        {
		if (obj.mItems.size() == 1 && mItems.size()) {
			if (mItems[mItems.size()-1].format == obj.mItems[0].format) {
				mItems[mItems.size()-1].text += obj.mItems[0].text;
				return;
				}
			}
		mItems.insert(mItems.end(), obj.mItems.begin(), obj.mItems.end());
		activeFormat = obj.activeFormat;
		}
void sttfont_formatted_text::append (sttfont_formatted_text_MS obj)
                                                   {
		if (obj.mItems.size() == 1 && mItems.size()) {
			if (mItems[mItems.size()-1].format == obj.mItems[0].format) {
				mItems[mItems.size()-1].text += std::move(obj.mItems[0].text);
				return;
				}
			}
		mItems.insert(mItems.end(), std::make_move_iterator(obj.mItems.begin()), std::make_move_iterator(obj.mItems.end()));
		activeFormat = obj.activeFormat;
		}
void sttfont_formatted_text::clear ()
                     {
		*this = sttfont_formatted_text();
		}
void sttfont_formatted_text::setColour (sttfont_format const & fmt)
                                                   {
		/// If any pieces do not have their colour set, set the colour to fmt's colour
		for (sttfont_formatted_text_item & sfti : mItems) {
			if (!(sfti.format.flags & sttfont_format::FORMAT_FLAGS_COLOUR_SET)) {
				uint8_t nfmt  = fmt.format | sfti.format.format;
				uint8_t nflg  = fmt.flags;
				sfti.format = fmt;
				sfti.format.format = nfmt;
				sfti.format.flags  = nflg;
				}
			}
		}
void sttfont_formatted_text::consolidateSegments ()
                                   {
		/// "Cleans" up this object by merging adjacent items if they have
		/// the same format, and removes empty segments
		
		// Strip empty segments
		for (unsigned int  i = mItems.size() - 1; i < mItems.size(); --i ) {
			if (!mItems[i].text.size())
				mItems.erase(mItems.begin() + i + 1);
			}
		size_t szStart;
		size_t szEnd;
		do {
			szStart = mItems.size();
			consolidateSegments_worker();
			szEnd = mItems.size();
			}
		while (szEnd < szStart);
		}
void sttfont_formatted_text::consolidateSegments_worker ()
                                          {
		/// "Cleans" up this object by merging adjacent items if they have the same format
		/// Removes empty segments
		for (unsigned int  i = mItems.size() - 2; i < mItems.size(); --i ) {
			if (mItems[i].format == mItems[i+1].format) {
				mItems[i].text += mItems[i+1].text;
				mItems.erase(mItems.begin() + i + 1);
				}
			}
		
		}
bool sttfont_formatted_text::back (unsigned int const num)
                                          {
		/// Removes @num bytes from the end of this
		/// Returns true if changed
		unsigned int nToRemove = num;
		for (unsigned int  i = mItems.size() - 1; i < mItems.size(); --i ) {
			if ( mItems[i].text.size() <= nToRemove) {
				nToRemove -= mItems[i].text.size();
				mItems.erase(mItems.begin() + i);
				if (nToRemove == 0 || i == 0) {
					return true;
					}
				}
			else {
				SSF_STRING& s = mItems[i].text;
				s = s.erase(s.length()-nToRemove);
				return true;
				}
			}
		return false;
		}
void sttfont_formatted_text::getIndexAt (unsigned int const position, unsigned int & indexOut, unsigned int & localPosOut, sttfont_lookupHint * mHint) const
                                                                                                                                                 {
		/// Returns the segment index and position within the segment of a character position
		/// A hint can be used to prevent itterating over the whole thing
		indexOut = -1;
		localPosOut = -1;
		
		unsigned int start = 0;		
		unsigned int workingLen = 0;
		
		if (mHint) {
			if (position >= mHint->workingLen) {
				start = mHint->index;
				workingLen = mHint->workingLen;
				}
			else {
				// Uncomment below to test for useless hints
				//std::cout << "Hint is useless!: " << position << " " << mHint->workingLen << std::endl;
				}
			}
		
		for (unsigned int  i = start; i < mItems.size(); ++i ) {
			if (mItems[i].text.size() + workingLen > position && workingLen <= position) {
				indexOut = i;
				localPosOut = position - workingLen;
				
				if (mHint) {
					if (mHint->writeOut) {
						mHint->index = i;
						mHint->workingLen = workingLen;
						}
					}
				
				return;
				}
			workingLen += mItems[i].text.size();
			}
		}
void sttfont_formatted_text::utf8_charsizeAt (unsigned int const position, unsigned int & posOut, unsigned int & sizeOut, sttfont_lookupHint * mHint)
                                                                                                                                            {
		/// At @position, what is the caracter size? Returns this in @sizeOut
		/// If this is in the middle of a character, return the position of the start of the character in @posOut
		posOut = position;
		sizeOut = 0;
		
		unsigned int index, offset;
		getIndexAt(position, index, offset, mHint);
		if (index >= mItems.size()) return; // not found
		
		// Lookup to 3 characters back and get the charSize
		for (unsigned int lookup = 0; lookup <= offset;) {
			int thisSz = sttfont_font_cache::utf8_charsize(&mItems[index].text[lookup]);
			
			//std::cout << "Lookup utf8_charsizeAt " << lookup << " " << thisSz
			//		<< " char[" << mItems[index].text.substr(lookup, thisSz) << "] " << offset << std::endl;
			
			if (thisSz + lookup > offset) {				
				//std::cout << "Out! size: " << thisSz << std::endl;
				posOut = lookup + position - offset;
				sizeOut = thisSz;
				return;
				}
			if (thisSz)
				lookup += thisSz;
			else
				lookup++;
			}
		}
void sttfont_formatted_text::insert (unsigned int const position, SSF_STRING const & str, sttfont_lookupHint * mHint)
                                                                                                            {
		/// Inserts @str at character position @pos
		unsigned int index, offset;
		getIndexAt(position, index, offset, mHint);
		if (index >= mItems.size()) { *this << str; return; } // not found, append to end
		mItems[index].text.insert(offset, str);
		}
void sttfont_formatted_text::insert (unsigned int const position, SSF_STRING_MS str, sttfont_lookupHint * mHint)
                                                                                                       {
		/// Inserts @str at character position @pos. Moving version
		unsigned int index, offset;
		getIndexAt(position, index, offset, mHint);
		if (index >= mItems.size()) { *this << std::move(str); return; } // not found, append to end
		mItems[index].text.insert(offset, std::move(str));
		}
void sttfont_formatted_text::insert (unsigned int const position, sttfont_formatted_text const & str, sttfont_lookupHint * mHint)
                                                                                                                        {
		/// Inserts @str at character position @pos. Copying formatted text version
		if (str.mItems.size() == 0) return;
		unsigned int index, offset;
		getIndexAt(position, index, offset, mHint);
		if (index >= mItems.size()) { append(str); return; } // not found, append to end

		if (str.mItems.size() == 1) { // Quickie - only 1 format being inserted. Do not split
			if (mItems[index].format == str.mItems[0].format) {
				mItems[index].text.insert(offset, str.mItems[0].text); return;
				}
			}
			
		sttfont_formatted_text_item after = mItems[index];	
		mItems[index].text.erase(offset);
		after.text.erase(0, offset);	
		
		unsigned int strSz = str.mItems.size();
		mItems.insert(mItems.begin()+index+1, str.mItems.begin(), str.mItems.end());
		
		if (after.text.length())
			mItems.insert(mItems.begin()+index+1+strSz, std::move(after));
		}
void sttfont_formatted_text::insert (unsigned int const position, sttfont_formatted_text_MS str, sttfont_lookupHint * mHint)
                                                                                                                   {
		/// Inserts @str at character position @pos. Moving version
		if (str.mItems.size() == 0) return;
		unsigned int index, offset;
		getIndexAt(position, index, offset, mHint);
		if (index >= mItems.size()) { append(std::move(str)); return; } // not found, append to end
		
		if (str.mItems.size() == 1) { // Quickie - only 1 format being inserted. Do not split
			if (mItems[index].format == str.mItems[0].format) {
				mItems[index].text.insert(offset, std::move(str.mItems[0].text)); return;
				}
			}
			
		sttfont_formatted_text_item after = mItems[index];	
		mItems[index].text.erase(offset);
		after.text.erase(0, offset);	
		
		unsigned int strSz = str.mItems.size();
		mItems.insert(mItems.begin()+index+1, std::make_move_iterator(str.mItems.begin()), std::make_move_iterator(str.mItems.end()));
		
		if (after.text.length())
			mItems.insert(mItems.begin()+index+1+strSz, std::move(after));
		}
void sttfont_formatted_text::remove (unsigned int const position, unsigned int const num, sttfont_lookupHint * mHint)
                                                                                                            {
		/// Removes @num characters after position num
		/// Note that if you're using hints that they might be invalid after removing text
		unsigned int index, offset;
		getIndexAt(position, index, offset, mHint);
		if (index >= mItems.size()) return; // not found
		
		unsigned int numToRemove = num;
		
		for (unsigned int i = index; i < mItems.size(); ++i) {
			unsigned int nToRemove = mItems[i].text.size() - offset;
			if (nToRemove > numToRemove) nToRemove = numToRemove;
			
			if (nToRemove == mItems[i].text.size() && offset == 0) {
				mItems.erase(mItems.begin() + i);
				--i;
				return;
				}
			mItems[i].text.erase(offset, nToRemove);
			
			numToRemove -= nToRemove;
			offset = 0;
			}
			
		}
SSF_STRING sttfont_formatted_text::substr (unsigned int const position, unsigned int const num, sttfont_lookupHint * mHint) const
                                                                                                                        {
		/// Reads @num characters after @position. If num goes past the end of a string
		/// then returns the end of the string. Returns as a plain string
		/// To get a "formatted" substr use this->extract(position, num);
		SSF_STRING r;
		unsigned int index, offset;
		getIndexAt(position, index, offset, mHint);
		if (index >= mItems.size()) return r; // not found
		
		unsigned int numToRemove = num;
		
		for (unsigned int i = index; i < mItems.size(); ++i) {
			unsigned int nToRemove = mItems[i].text.size() - offset;
			if (nToRemove > numToRemove) nToRemove = numToRemove;
			
			r += mItems[i].text.substr(offset, nToRemove);
			
			numToRemove -= nToRemove;
			offset = 0;
			}
		return r;
		}
sttfont_formatted_text sttfont_formatted_text::extract (unsigned int const position, unsigned int const num, sttfont_lookupHint * mHint) const
                                                                                                                                     {
		/// Creates a new @sttfont_formatted_text containing the segments starting at character @position and of length @num in bytes
		/// To get a std::string substring use this->substr(position, num)
		sttfont_formatted_text r;
		
		unsigned int index, offset;
		getIndexAt(position, index, offset, mHint);
		if (index >= mItems.size()) {
			return r;
			}
			
		unsigned int numToRemove = num;
		
		for (unsigned int i = index; i < mItems.size() && numToRemove; ++i) {
			unsigned int nToRemove = mItems[i].text.size() - offset;
			if (nToRemove > numToRemove) nToRemove = numToRemove;
			
			//std::cout << "extracting: " << i << " " << " offset: " << offset << ", nToRemove: " << nToRemove << "/" << numToRemove << " " << mItems[i].text.size() << std::endl;
			
			if (nToRemove == mItems[i].text.size() && offset == 0) {
				r.mItems.push_back(mItems[i]);
				}
			else {
				sttfont_formatted_text_item sfti;
				sfti.format = mItems[i].format;
				sfti.text = mItems[i].text.substr(offset, nToRemove);
				r.mItems.push_back(std::move(sfti));
				}
			//r += mItems[i].text.substr(offset, nToRemove);
			
			numToRemove -= nToRemove;
			offset = 0;
			}
		return r;
		}
void sttfont_formatted_text::tokenise (SSF_VECTOR <sttfont_formatted_text> & arrOut, uint32_t const delimiter, bool const checkQuoteMarks, uint32_t const escapeChar, bool const includeDelimiterInToken) const
                                                                                                                                                                                                                     {
		/// Breaks this into an array of sttfont_formatted_text objects
		/// tokenised by "delimter" (unless inbetween two `"` marks).
		/// An escape character negates the delimiter
		/// Handles UTF-8
		///
		/// Example usage - tokenise on newlines:
		///     vector<sttfont_formatted_text> output;
		///     input.tokenise(output, '\n', true, '\\');
		///
		const sttfont_formatted_text & stringIn = *this;
		
		bool open = false;
		bool escape = false;
		
		uint32_t segmentStart = 0;	// The start of the working token
		uint32_t workingPos = 0;	// The cumulative positon along the string
		uint32_t offset = 0;		// A small offset to prevent including the token character in the extracted strings
		
		uint32_t workingPosLastStart = 0;
		uint32_t siLastStart = 0;
		
		uint32_t delimiterSize = 1;
		if (delimiter > 0x007F) delimiterSize = 2;
		if (delimiter > 0x07FF) delimiterSize = 3;
		if (delimiter > 0xFFFF) delimiterSize = 4;
		
		for (size_t si = 0; si < stringIn.mItems.size(); ++si) {
			const SSF_STRING & s = stringIn.mItems[si].text;
			uint32_t seek = 0;
			const uint32_t len = s.length();
			
			while (seek < len) {
				const uint32_t seekBefore = seek;
				uint32_t uChar = sttfont_font_cache::utf8_read(&s[seek], seek, len);
				
				if (escape) {
					escape = false;
					continue;
					}
			
				if (uChar == escapeChar) {
					// Add the next charcter in regardless
					escape = true;
					continue;
					}
				if (uChar != delimiter || open) {
					if (uChar != '"' || !checkQuoteMarks) {
						// No-op
						}
					else {
						open = !open;
						}
					}
				else {
					sttfont_lookupHint mHint;
						mHint.index = siLastStart;
						mHint.workingLen = workingPosLastStart;
						
					if (includeDelimiterInToken)
						workingPos+=delimiterSize;
						
					workingPosLastStart = workingPos;
					siLastStart = si;
					
					sttfont_formatted_text d = stringIn.extract(segmentStart + offset, (workingPos + seekBefore) - segmentStart - offset, &mHint);
					segmentStart = workingPos + seekBefore;
					offset = sttfont_font_cache::utf8_charsize(uChar); // Used to skip including the newline
					arrOut.push_back(std::move(d));
					}
				}
			workingPos += len;
			}
		
		sttfont_lookupHint mHint;
			mHint.index = siLastStart;
			mHint.workingLen = workingPosLastStart;
		sttfont_formatted_text d = stringIn.extract(segmentStart + offset, -1, &mHint);
		arrOut.push_back(std::move(d));
		}
sttfont_prerendered_text::sttfont_prerendered_text ()
  : width (0), height (0)
                                                          {}
void sttfont_prerendered_text::freeTexture ()
                                   {
		// Make your own implmentation for your own frontend here
		// Used to clear any resources held here
		}
int sttfont_prerendered_text::draw (int const x, int const y)
                                                    { return x + width; }
int sttfont_prerendered_text::drawWithColorMod (int const x, int const y, uint8_t const r, uint8_t const g, uint8_t const b, uint8_t const a)
                                                                                                                                         {
		return x + width;
		}
sttfont_glyph::sttfont_glyph ()
  : advance (0), leftSideBearing (0), width (0), height (0), xOffset (0), yOffset (0)
                                                                                                       {}
void sttfont_memory::alloc (size_t const size)
                                      {
		data = SSF_NEW_ARR(char, size);
		ownsData = true;
		}
void sttfont_memory::transferTo (sttfont_memory & destination)
                                                      {
		destination.data = data;
		destination.ownsData = destination.data;
		ownsData = false;
		}
sttfont_memory::sttfont_memory ()
  : data (NULL), ownsData (false)
                                                        {}
sttfont_memory::~ sttfont_memory ()
                           {
		if (ownsData) {
			SSF_DEL_ARR(data);
			data = NULL;
			}
		}
sttfont_font_list::sttfont_font_list ()
  : format (0), next (NULL)
                                                    {}
sttfont_font_list::~ sttfont_font_list ()
                             {
		for (sttfont_font_list * fl : mFormatedVariants)
			delete fl;
		if (next) delete next;
		}
void sttfont_font_list::fetchFontForCodepoint (uint32_t const codepoint, uint8_t const format, stbtt_fontinfo * * mFontOut, int * indexOut)
                                                                                                                               {
		sttfont_font_list * working = this;
		
		*mFontOut = NULL;
		*indexOut = 0;
		
		while (working) {
			int index = stbtt_FindGlyphIndex(&(working->mFont), codepoint);
			if (index) {
				// Check for format in the variants
				if (format) {
					int bestBitsCount = 0;
					sttfont_font_list * bestMatch = NULL;
					sttfont_font_list * bestMatch2 = NULL;
					for (sttfont_font_list * f : mFormatedVariants) {
						uint8_t mask = (format & f->format);
						if (mask) {
							int nBits = 0;
							for (int i = 0; i < 7; ++i)
								if (mask & (1 << i)) nBits++;
							if (nBits > bestBitsCount) {
								bestBitsCount = nBits;
								bestMatch2 = bestMatch;
								bestMatch = f;
								}
							}
						}
					
					if (bestMatch) {
						int index2 = stbtt_FindGlyphIndex(&(bestMatch->mFont), codepoint);
						*mFontOut = &(bestMatch->mFont);
						*indexOut = index2;
						return;
						}
					if (bestMatch2) {
						int index2 = stbtt_FindGlyphIndex(&(bestMatch2->mFont), codepoint);
						*mFontOut = &(bestMatch2->mFont);
						*indexOut = index2;
						return;
						}
					}
				
				// Format not found/no format
				*mFontOut = &(working->mFont);
				*indexOut = index;
				return;
				}
			working = working->next;
			}
		}
sttfont_font_cache::sttfont_font_cache ()
  : ascent (0), descent (0), lineGap (0), baseline (0), rowSize (0), tabWidth (1), scale (1.f), underlineThickness (1.0), strikethroughThickness (1.0), underlinePosition (0.0), strikethroughPosition (0.0), faceSize (20), tabWidthInSpaces (8)
                                                  {}
sttfont_font_cache::~ sttfont_font_cache ()
                                       {}
void sttfont_font_cache::setFaceSize (int const _faceSize)
                                              { faceSize = _faceSize; }
int sttfont_font_cache::getScaledRowSize () const
                                      { return scale * rowSize; }
void sttfont_font_cache::loadFont (char const * ttf_buffer, int index)
                                                               {
		stbtt_InitFont(&mFont.mFont, (const unsigned char *) ttf_buffer, stbtt_GetFontOffsetForIndex((const unsigned char *) ttf_buffer,index));
		stbtt_GetFontVMetrics(&mFont.mFont, &ascent, &descent, &lineGap);
		
		scale = stbtt_ScaleForPixelHeight(&mFont.mFont, faceSize);
		baseline = ascent*scale;
		rowSize = ascent - descent + lineGap;
		
		strikethroughThickness = faceSize/20.0;
		if (strikethroughThickness < 1) strikethroughThickness = 1;
		strikethroughPosition = baseline * 0.75 - strikethroughThickness/2;
		underlineThickness = strikethroughThickness;
		underlinePosition = baseline + underlineThickness;
		
		int w,h;
		getTextSize(w,h,"                                                                                                                                ", tabWidthInSpaces <= 128 ? tabWidthInSpaces : 128);
		tabWidth = w;
		if (tabWidth < 1) tabWidth = 1;
		}
void sttfont_font_cache::loadFontManaged (sttfont_memory & memory, int index)
                                                                      {
		memory.transferTo(mFont.mMemory);
		loadFont(mFont.mMemory.data, index);
		}
void sttfont_font_cache::addFont (char const * ttf_buffer, int index)
                                                              {
		addFontWrap afw(ttf_buffer);
		afw.index = index;
		addFont_worker(afw, false);
		}
void sttfont_font_cache::addFontManaged (sttfont_memory & memory, int index)
                                                                     {
		addFontWrap afw(NULL);
		afw.memory = &memory;
		afw.index = index;
		addFont_worker(afw, false);
		}
void sttfont_font_cache::addFormatFont (uint8_t formatMask, char const * ttf_buffer, int index)
                                                                                        {
		addFontWrap afw(ttf_buffer);
		afw.index = index;
		addFont_worker(afw, true, formatMask);
		}
void sttfont_font_cache::addFormatFontManaged (uint8_t formatMask, sttfont_memory & memory, int index)
                                                                                               {
		addFontWrap afw(NULL);
		afw.memory = &memory;
		afw.index = index;
		addFont_worker(afw, true, formatMask);
		}
sttfont_font_cache::addFontWrap::addFontWrap (char const * c)
  : ttf_buffer (c), memory (NULL), index (0)
                                                                                     {}
void sttfont_font_cache::addFont_worker (addFontWrap & fwm, bool isFormatVariant, uint8_t formatMask)
                                                                                             { 
		sttfont_font_list * n = SSF_NEW(sttfont_font_list);
		sttfont_font_list * w = &mFont;
		while (w->next)
			w = w->next;
		n->format = formatMask;
		
		if (fwm.memory) {
			sttfont_memory & memory = *(fwm.memory);
			memory.transferTo(n->mMemory);
			stbtt_InitFont(&n->mFont, (const unsigned char *) n->mMemory.data, stbtt_GetFontOffsetForIndex((const unsigned char *) n->mMemory.data,fwm.index));
			}
		else {
			stbtt_InitFont(&n->mFont, (const unsigned char *) fwm.ttf_buffer, stbtt_GetFontOffsetForIndex((const unsigned char *) fwm.ttf_buffer,fwm.index));
			}
		if (isFormatVariant)
			w->mFormatedVariants.push_back(n);
		else
			w->next = n;
		}
void sttfont_font_cache::genGlyph (uint32_t const codepoint, uint8_t const format, sttfont_glyph * gOut)
                                                                                             {
		// Fetch font and index - existance check for glyph in font
		stbtt_fontinfo * mFontContaining;
		int mIndex;
		mFont.fetchFontForCodepoint(codepoint, format, &mFontContaining, &mIndex);
		
		if (!mIndex)
			return;
		
		// found the font! generate the glyph
	   	unsigned char *bitmap;
	   	int w,h,woff,hoff;
		bitmap = stbtt_GetCodepointBitmap(mFontContaining, 0, scale, codepoint, &w, &h, &woff, &hoff);
		
        // Convert bitmap to RGBA
        unsigned int sz = w*h;
        unsigned char bitmap2[sz*4];
        for (unsigned int i = 0; i < sz; ++i) {
        	bitmap2[i*4+0] = 255;
        	bitmap2[i*4+1] = 255;
        	bitmap2[i*4+2] = 255;
        	bitmap2[i*4+3] = bitmap[i];
        	}
        
        stbtt_FreeBitmap (bitmap, 0);
        
        if (w && h) {
			genGlyph_writeData(gOut, bitmap2, w, h);
			}
		
		gOut->width = w;
		gOut->height = h;
		stbtt_GetCodepointHMetrics(mFontContaining, codepoint, &gOut->advance, &gOut->leftSideBearing);
		
		gOut->xOffset = woff;
		gOut->yOffset = hoff;
		}
void sttfont_font_cache::genGlyph_writeData (sttfont_glyph * gOut, unsigned char * bitmap2, int w, int h)
                                                                                                      {
		// Make your own implmentation for your own frontend here
		}
sttfont_glyph * sttfont_font_cache::getGlyph (uint64_t const target)
                                                                {
		// Make your own implmentation for your own frontend here
		return NULL;
		}
sttfont_glyph * sttfont_font_cache::getGenGlyph (uint32_t const codepoint, uint8_t const format)
                                                                                    {
		uint64_t target = codepoint | (uint64_t(format) << 32);
		sttfont_glyph * r = getGlyph(target);
		if (r) return r;
		return genGlyph_createAndInsert(target, codepoint, format);
		}
sttfont_glyph * sttfont_font_cache::genGlyph_createAndInsert (uint64_t const target, uint32_t const codepoint, uint8_t const format)
                                                                                                                                {
		// Make your own implmentation for your own frontend here
		return getGlyph(target);
		}
int sttfont_font_cache::getKerningAdvance (uint32_t const cp1, uint32_t const cp2)
                                                                      {
		return stbtt_GetCodepointKernAdvance(&mFont.mFont, cp1, cp2);
		}
int sttfont_font_cache::utf8_charsize (char const * c)
                                                {
		if (!c) return 0;
		if ((uint8_t)*c <= 0x7F) return 1;
		else if ((uint8_t)*c <= 0xE0) return 2;
		else if ((uint8_t)*c <= 0xF0) return 3;
		else
			return 4;
		}
int sttfont_font_cache::utf8_charsize (uint32_t const codepoint)
                                                           {
		if ((codepoint & 0x000000ff) == codepoint) return 1;
		if ((codepoint & 0x0000ffff) == codepoint) return 2;
		if ((codepoint & 0x00ffffff) == codepoint) return 3;
		return 4;
		}
uint32_t sttfont_font_cache::utf8_read (char const * c, uint32_t & seek, uint32_t const maxLen)
                                                                                         {
		if (!c) return 0;
		int chsz = utf8_charsize(c);
		seek += chsz;
	
		if (seek > maxLen) {
			return *c; //Buffer overflow - stop to be safe!
			}
			
		if (chsz == 1) return *c;		
		if (chsz == 2)
			return (((uint32_t((uint8_t) c[0] & 0b00111111) << 6)) | uint32_t((uint8_t) c[1] & 0b00111111));
		if (chsz == 3)
			return (uint32_t((uint8_t) c[0] & 0b00011111) << 12) | (uint32_t((uint8_t) c[1] & 0b00111111) << 6) | uint32_t((uint8_t) c[2] & 0b00111111);
		return (uint32_t((uint8_t) c[0] & 0b00001111) << 18) | (uint32_t((uint8_t) c[1] & 0b00111111) << 12) | (uint32_t((uint8_t) c[2] & 0b00111111) << 6) | uint32_t((uint8_t) c[3] & 0b00111111);
		}
int sttfont_font_cache::drawText (int const x, int const y, char const * c, uint32_t const maxLen)
                                                                                           {
		return processString(x, y, c, maxLen, NULL, true);
		}
int sttfont_font_cache::drawText (int const x, int const y, SSF_STRING const & str)
                                                                        {
		return drawText(x,y,str.data(),str.size());
		}
int sttfont_font_cache::drawText (int const x, int const y, int & widthOut, int & heightOut, char const * c, uint32_t const maxLen)
                                                                                                                            {
		return processString(x, y, c, maxLen, NULL, true, &widthOut, &heightOut);
		}
int sttfont_font_cache::drawText (int const x, int const y, SSF_STRING const & str, int & widthOut, int & heightOut)
                                                                                                         {
		return drawText(x,y,widthOut, heightOut, str.data(),str.size());
		}
int sttfont_font_cache::drawText (int const x, int const y, sttfont_formatted_text const & text)
                                                                                    {
		int dummyWidth, dummyHeight;
		return drawText(x, y, text, dummyWidth, dummyHeight);
		}
int sttfont_font_cache::drawText (int const x, int const y, sttfont_formatted_text const & text, int & widthOut, int & heightOut)
                                                                                                                     {
		return processFormatted(text, x, y, true, &widthOut, &heightOut);
		}
int sttfont_font_cache::getTextSize (int & w, int & h, char const * c, uint32_t const maxLen, sttfont_lookupHint * mHint, int const * const maxWidth)
                                                                                                                                                             {
		return processString(0, 0, c, maxLen, NULL, false, &w, &h, maxWidth);
		}
int sttfont_font_cache::getTextSize (int & w, int & h, SSF_STRING const & str, sttfont_lookupHint * mHint, int const * const maxWidth)
                                                                                                                                         {
		return processString(0, 0, str.data(), str.size(), NULL, false, &w, &h, maxWidth, mHint);
		}
int sttfont_font_cache::getTextSize (int & w, int & h, sttfont_formatted_text const & str, sttfont_lookupHint * mHint, int const * const maxWidth)
                                                                                                                                                     {
		return processFormatted(str, 0, 0, false, &w, &h, maxWidth, mHint);
		}
int sttfont_font_cache::getNumberOfRows (SSF_STRING const & str)
                                                     {
		int n = 1;
		for (const char c : str)
			if (c == '\n') n++;
		return n;
		}
int sttfont_font_cache::getNumberOfRows (sttfont_formatted_text const & str)
                                                                 {
		int n = 1;
		for (const sttfont_formatted_text_item & item : str.mItems) {
			for (const char c : item.text)
				if (c == '\n') n++;
			}
		return n;
		}
int sttfont_font_cache::getTextHeight (SSF_STRING const & str)
                                                   {
		return scale*rowSize*getNumberOfRows(str);
		}
int sttfont_font_cache::getTextHeight (sttfont_formatted_text const & str)
                                                               {
		return scale*rowSize*getNumberOfRows(str);
		}
int sttfont_font_cache::processString (int const x, int const y, char const * c, uint32_t const maxLen, sttfont_format const * const format, bool const isDrawing, int * const widthOut, int * const heightOut, int const * const maxWidth, sttfont_lookupHint * mHint, int const * const threshX, int const * const threshY, int * const caretPosition, int initialXOffset)
                                                                                                                                                                                                                                                                                                                                                                                                                     {
		// Scan through function and extract the glyphs
		// returns the x position at the end
		uint32_t seek = 0;
		uint32_t seekLast = 0;
		uint32_t uCharLast = 0;
		
		int xx = x + initialXOffset;
		int overdraw = SSF_INT_MIN;
		int yy = y;
		
		if (mHint) {
			seek = mHint->workingLen;
			seekLast = seek;
			xx = mHint->workingX;
			yy = mHint->workingY;
			uCharLast = mHint->uCharLast;
			}
			
		uint32_t uChar = utf8_read(c+seek, seek, maxLen);
		if (widthOut) { *widthOut = 0; if (mHint) *widthOut = mHint->workingX-x; }
		if (heightOut) { *heightOut = 0; if (mHint) *heightOut = mHint->workingY-y; }
		
		const bool lookupCaret = caretPosition && threshX && threshY;
		if (lookupCaret) {
			*caretPosition = -1;
			}
		
		int xxl = xx;
		while (uChar && seek <= maxLen) {
			//if (mHint)
			//	std::cout << "Processing: (" << seekLast << "," << (seek-seekLast) << ") " << std::string(&c[seekLast], seek-seekLast) << ", codePoint " << uChar << ", suibstring: [" << std::string(&c[seekLast]) << "], fullstring:["<<maxLen<<"] " << c << std::endl;
			xxl = xx;
			if (uChar == '\t') {
				// Next tab position:
				int nTabsSoFar = (xx - x)/tabWidth;
				xx = x + (nTabsSoFar+1)*tabWidth;
				}
			else if (uChar == '\n') {
				if (widthOut)
					if (*widthOut < xx) *widthOut = xx;
				xx = x;
				yy += scale*rowSize;
				overdraw = SSF_INT_MIN;
				}
			else {
				int dx = scale*getKerningAdvance(uCharLast, uChar);
				xx += dx;
				processCodepoint(xx, yy, uChar, format, isDrawing, dx, overdraw);
				}
			
			if (lookupCaret) {
				//const int dx = xx - x;
				if (xx > *threshX && xxl <= *threshX ) {
					if (*threshX > xxl + (xx - xxl)/2)
						*caretPosition = seek; // right half of char
					else
						*caretPosition = seekLast; // left half of char
						
					if (mHint) {
						if (mHint->writeOut) {
							mHint->workingLen = seek;
							mHint->workingX = xx;
							mHint->workingY = yy;
							mHint->uCharLast = uCharLast;
							}
						}
					return xx;
					}
				}
				
			if (mHint) {
				if (mHint->writeOut) {
					mHint->uCharLast = uCharLast;
					mHint->workingLen = seek;
					mHint->workingX = xx;
					mHint->workingY = yy;
					}
				}
			uCharLast = uChar;
			seekLast = seek;
			uChar = utf8_read(c + seek, seek, maxLen);
			if (maxWidth) {
				if (xx > *maxWidth) break;
				}
			}
		if (widthOut) {
			if (*widthOut < xx) *widthOut = xx;
			*widthOut -= x;
			}
		if (heightOut) {
			if (*heightOut < yy) *heightOut = yy;
			*heightOut += scale*rowSize;
			*heightOut -= y;
			}
		return xx;
		}
int sttfont_font_cache::processFormatted (sttfont_formatted_text const & text, int x, int y, bool const isDrawing, int * const widthOut, int * const heightOut, int const * const maxHeight, sttfont_lookupHint * mHint, int const * const threshX, int const * const threshY, int * const caretPosition, int initialXOffset)
                                                                                                                                                                                                                                                                                                                                                                      {
		int xOffset = initialXOffset;
		int yOffset = 0;
		
		if (widthOut) *widthOut = 0;
		if (heightOut) *heightOut = 0;
		
		size_t runningLength = 0;
		
		unsigned int start = 0;
		if (mHint) start = mHint->index;
		
		for (unsigned int i = start; i < text.mItems.size(); ++i) {
			const sttfont_formatted_text_item & ssfti = text.mItems[i];
			
			bool isDrawingWorking = isDrawing;
			if (ssfti.callback && isDrawingWorking)
				isDrawingWorking = (ssfti.format.format & sttfont_format::FORMAT_RENDER_EVEN_IF_CALLBACK_EXISTS);
			
			int widthWorking, heightWorking;
			
			int xOffsetBefore = xOffset;
			int carretPosition2 = -1;
			
			if (mHint) {
				if (mHint->writeOut) {
					mHint->index = i;
					}
				if (i != start) {
					mHint->workingLen = 0;
					mHint->workingX = 0;
					mHint->workingY = 0;
					}
				}
			xOffset = processString(x,y + yOffset, ssfti.text.data(), ssfti.text.size(), &ssfti.format, isDrawingWorking, &widthWorking, &heightWorking, maxHeight, mHint, threshX, threshY, caretPosition ? &carretPosition2 : NULL, xOffset); // color!!!
			
			if (caretPosition) {
				if (carretPosition2 >= 0)
					*caretPosition = runningLength + carretPosition2;
				runningLength += ssfti.text.size(); // running length is only calculated here as its only used here
				}
			
			xOffset -= x;
			yOffset += heightWorking - scale*rowSize;
			if (widthOut) *widthOut = *widthOut > widthWorking ? *widthOut : widthWorking;
			
			heightWorking = yOffset + scale*rowSize;
			if (heightOut) *heightOut = *heightOut > heightWorking ? *heightOut : heightWorking;
			
			if (ssfti.callback)
				ssfti.callback->callbackOnDraw(text, i, x, y, xOffsetBefore, xOffset, widthWorking, heightWorking);
			}
		return xOffset + x;
		}
int sttfont_font_cache::getCaretPos (SSF_STRING const & str, int const relMouseX, int const relMouseY, sttfont_lookupHint * mHint)
                                                                                                                             {
		int caretPosition = -1;
		processString(0,0, str.data(), str.length(), NULL, false, NULL, NULL, NULL, mHint, &relMouseX, &relMouseY, &caretPosition);
		return caretPosition;
		}
int sttfont_font_cache::getCaretPos (sttfont_formatted_text const & str, int const relMouseX, int const relMouseY, sttfont_lookupHint * mHint)
                                                                                                                                         {
		int caretPosition = -1;
		processFormatted(str, 0,0, false, NULL, NULL, NULL, mHint, &relMouseX, &relMouseY, &caretPosition);
		return caretPosition;
		}
bool sttfont_font_cache::isTofu (sttfont_glyph * G)
                                        {
		if (!G) return true;
		if (!G->advance) return true; //unprintable characters have no width
		return false;
		}
sttfont_glyph * sttfont_font_cache::getGlyphOrTofu (uint32_t const codepoint, uint8_t const format)
                                                                                        {
		sttfont_glyph * G = getGenGlyph(codepoint, format);
		if (!isTofu(G)) return G;
		
		G = getGenGlyph((uint32_t) 0xFFFD, format); // https://en.wikipedia.org/wiki/Specials_(Unicode_block)#Replacement_character
		if (!isTofu(G)) return G;
			
		G = getGenGlyph((uint32_t) '?', format);
		if (!isTofu(G)) return G;
		
		if (format)
			return getGlyphOrTofu(codepoint, 0);
		
		return NULL;
		}
void sttfont_font_cache::processCodepoint (int & x, int & y, uint32_t const codepoint, sttfont_format const * const format, bool isDrawing, int kerningAdv, int & overdraw)
                                                                                                                                                                        {
		// Draws the character, advances x & y to the next position
		// NOTE: KErning
		uint8_t formatCode = 0;
		if (format)
			formatCode = format->format;
			
		sttfont_glyph * G = getGlyphOrTofu(codepoint, formatCode);
		if (!G) {
			x += faceSize/2;
			return;
			}
		if (isDrawing) {
			// Make your own implmentation for your own frontend here
			}
		x += scale*G->advance;
		}
void sttfont_font_cache::renderTextToObject (sttfont_prerendered_text * textOut, char const * c, uint32_t const maxLen)
                                                                                                                         {
		// Make your own implmentation for your own frontend here
		//textOut->mSdlTexture = renderTextToTexture(c, maxLen, &(textOut->width), &(textOut->height));
		}
void sttfont_font_cache::renderTextToObject (sttfont_prerendered_text * textOut, SSF_STRING const & str)
                                                                                                     {
		// Make your own implmentation for your own frontend here
		//textOut->mSdlTexture = renderTextToTexture(str, &(textOut->width), &(textOut->height));
		}
void sttfont_font_cache::renderTextToObject (sttfont_prerendered_text * textOut, sttfont_formatted_text const & str)
                                                                                                                 {
		// Make your own implmentation for your own frontend here
		//textOut->mSdlTexture = renderTextToTexture(str, &(textOut->width), &(textOut->height));
		}
#undef LZZ_INLINE
