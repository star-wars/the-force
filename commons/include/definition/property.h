/*
 * property.h
 *
 *  Created on: 11.03.2014
 *      Author: cosh
 *     Purpose: key value
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

#ifndef _property_h
#define _property_h

template<class TKey, class TValue>
class Property {

private:

	/**
	 * The key of the property
	 */
	TKey const _key;

	/**
	 * The value of the property
	 */
	TValue const _value;

public:

	/**
	 * Creates a new property
	 * @param key The key of the property
	 * @param value The value of the property
	 */
	explicit Property(TKey const key, TValue const value) :
			_key(key), _value(value) {
	}

	/**
	 * Gets the key of the property
	 * @return The key
	 */
	TKey const GetKey()
	{
		return _key;
	}

	/**
	 * Gets the value of the property
	 * @return The value
	 */
	TValue const GetValue()
	{
		return _value;
	}
};

#endif
