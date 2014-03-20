/*
 * graphElement.cpp
 *
 *  Created on: 29.04.2013
 *      Author: cosh
 *     Purpose: This is the header file for the graph element.
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

#ifndef _graphElement_h
#define _graphElement_h

/**
 * The class that hosts the attributes and functions that are used by any graph element
 */
template<class TValue, class TGraphElementId>
class GraphElement {

private:
	/**
	 * The unique identifier of the graph element
	 */
	const TGraphElementId _id;

	/**
	 * The creation date of the graph element
	 */
	const long long _creationDate;

	/**
	 * The difference to the creation date
	 */
	unsigned int _modificationDateDifference;

	/**
	 * The shortcut is a fast lookup property
	 */
	std::string _shortCut;

	/**
	 * Add a property to the graph element
	 * @param propertyId The unique identifier of the property
	 * @param value The value of the property
	 * @param ttl The time to live for the property
	 */
	void AddProperty(const unsigned short propertyId, TValue* const value, const unsigned int ttl = 0);

	/**
	 * Removes a property
	 * @param propertyId The unique identifier of the property
	 */
	const bool RemoveProperty(const unsigned short propertyId);

public:

	/**
	  * Gets the creation date
	  * @return The utc time stamp
	  */
	const long long GetCreationDate();

	/**
	 * Gets the modification date
     * @return The utc time stamp
	 */
	const long long GetModificationDate();

	/**
	 * Get the shortcut
	 * @return The shortcut
	 */
	const std::string GetShortcut();

	/**
	 * Gets a property
	 * @param propertyId The unique identifier of the property
	 * @return The value of the property
	 */
	const TValue * const GetProperty(const unsigned short propertyId);
};

#endif
