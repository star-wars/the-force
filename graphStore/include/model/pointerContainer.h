/*
 * pointerContainer.h
 *
 *  Created on: 29.04.2013
 *      Author: cosh
 *     Purpose:
 *
 * Copyright (c) 2013 Henning Rauch
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

#ifndef _pointerContainer_h
#define _pointerContainer_h

template
<
	class TPointer
>
struct PointerContainer {

private:
	/**
	 * Max number of pointer
	 */
	int _maxPointerCount;

	/**
	 * Current count of edges
	 */
	int _currentCount;

	/**
	 * first pointer
	 */
	TPointer* _firstPointer;


public:

	/**
	 * Get first pointer
	 * @return The first pointer
	 */
	TPointer* GetFirstPointer();

	/**
	 * Total number of pointer
	 * @return The total number of pointer
	 */
	int Count();

};

template<class TPointer>
inline TPointer* PointerContainer<TPointer>::GetFirstPointer() {
	return _firstPointer;

}

template<class TPointer>
inline int PointerContainer<TPointer>::Count() {
	return _currentCount;
}

#endif
