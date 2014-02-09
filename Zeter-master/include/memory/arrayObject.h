/*
 * arrayObject.h
 *
 *  Created on: 05.07.2013
 *      Author: cosh
 *     Purpose: The container for the arrays containing payload and meta data
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

#ifndef _arrayObject_h
#define _arrayObject_h

#include "arrayMetaData.h"

/**
 * TObject is the type of the object that is inside the arrays
 */
template<class TObject>
class ArrayObject {

private:

	/**
	 * Pointer to the first object in the array
	 */
	TObject * const _first;

	/**
	 * The array meta data
	 */
	ArrayMetaData * const _metaData;

public:

	/**
	 * Creates a new array object
	 * @param first The pointer to the first element in the array
	 * @param metaData The pointer to the corresponding meta data
	 */
	explicit ArrayObject(TObject * const first, ArrayMetaData * const metaData) :
			_first(first), _metaData(metaData) {
	}

	/**
	 * Gets the first element of the array
	 * @return First element of the array
	 */
	TObject * const GetFirstElement()
	{
		return _first;
	}

	/**
	 * Gets the array meta data
	 * @return The meta data
	 */
	ArrayMetaData * const GetArrayMetaData()
	{
		return _metaData;
	}

	/**
	 * Gets the size of the array
	 * @return Size
	 */
	size_t GetSize()
	{
		return _metaData->GetSizeOfArray();
	}
};

#endif
