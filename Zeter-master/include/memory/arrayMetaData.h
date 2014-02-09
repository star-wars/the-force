/*
 * arrayMetaData.h
 *
 *  Created on: 30.06.2013
 *      Author: cosh
 *     Purpose: Helper class to know the size of an object and the corresponding pool
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

#ifndef _arrayMetaData_h
#define _arrayMetaData_h

#include "boost/pool/pool.hpp"

class ArrayMetaData {

private:
	/**
	 * The responsible pool
	 */
	boost::pool<>* const _responsiblePool;

	/**
	 * The size of the array
	 */
	const size_t _size;

public:
	/**
	 * Constructor
	 * @param pool The responsible pool
	 * @param arraySize The size of the array
	 */
	explicit ArrayMetaData(boost::pool<>* const pool, const size_t arraySize);

	/**
	 * Gets the pool that is responsible for the array
	 * @return The pool
	 */
	boost::pool<>* const GetCorrespondingPool();

	/**
	 * Gets the size of the array
	 * @return The size
	 */
	const size_t GetSizeOfArray();
};

#endif
