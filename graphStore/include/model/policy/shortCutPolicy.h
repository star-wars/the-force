/*
 * shortCutPolicy.h
 *
 *  Created on: 21.03.2014
 *      Author: cosh
 *     Purpose: This is a shortcut policy implementation
 *
 * Copyright (c) 2014 Henning Rauch
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in the
 * Software without restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */

#ifndef _shortCutPolicy_h
#define _shortCutPolicy_h

template<class TShortCut>
class ShortCutPolicy {

private:
	/**
	 * The shortcut is a fast lookup property
	 */
	TShortCut _shortCut;

protected:

	/**
	 * Sets the shortcut
	 * @param shortCut The shortcut
	 */
	void SetShortCut(const TShortCut shortCut);

	/**
	 * Initializes a shortcut
	 * @param shortCut The shortcut
	 */
	explicit ShortCutPolicy(const TShortCut shortCut);

public:

	/**
	 * Get the shortcut
	 * @return The shortcut
	 */
	const TShortCut GetShortcut();
};

template<class TShortCut>
inline void ShortCutPolicy<TShortCut>::SetShortCut(const TShortCut shortCut) {
	_shortCut = shortCut;
}

template<class TShortCut>
inline ShortCutPolicy<TShortCut>::ShortCutPolicy(const TShortCut shortCut) :
	_shortCut(shortCut){
}

template<class TShortCut>
inline const TShortCut ShortCutPolicy<TShortCut>::GetShortcut() {
	return _shortCut;
}

#endif
