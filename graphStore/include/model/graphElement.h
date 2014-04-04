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

#include "propertyStore.h"

/**
 * The class that hosts the attributes and functions that are used by any graph element
 */
template<class TGraphElementId, class TValue, class TShortCut>
class GraphElement {

private:

	/**
	 * The graph element identifier
	 */
	const TGraphElementId _id;

	/**
	 * The property store
	 */
	const PropertyStore<TValue, long long, unsigned short>* const _ps;

	/**
	 * The shortcut is a fast lookup property
	 */
	TShortCut _shortCut;

	/**
	 * The creation date
	 */
	const long long _creationDate;

	/**
	 * The modification date difference
	 */
	unsigned int _modificationDateDifference;

protected:

	/**
	 * Add a property to the graph element
	 * @param propertyId The unique identifier of the property
	 * @param value The value of the property
	 * @param ttl The time to live for the property
	 */
	void AddProperty(const unsigned short propertyId, TValue* const value,
			const unsigned int ttl = 0);

	/**
	 * Removes a property
	 * @param propertyId The unique identifier of the property
	 */
	const void RemoveProperty(const unsigned short propertyId);

	/**
	 * Sets the modification date
	 * @param currentDate The current date as utc timestamp
	 */
	void SetModificationDate(const long long currentDate);

	/**
	 * Sets the shortcut
	 * @param shortCut The shortcut
	 */
	void SetShortCut(const TShortCut shortCut);

	/**
	 * Creates a new graph element
	 * @param id The graph element identifier
	 * @param propertyStore The property store
	 * @param shortCut the short cut
	 * @param creationDate The creation date
	 */
	explicit GraphElement(const TGraphElementId id,
			const PropertyStore<TValue, long long, unsigned short>* const propertyStore,
			TShortCut shortCut,
			const long long creationDate);

public:

	/**
	 * Gets a property
	 * @param propertyId The unique identifier of the property
	 * @return The value of the property
	 */
	const TValue * const GetProperty(const unsigned short propertyId);

	/**
	 * Gets the graph element Id
	 * @return The graph element identifier
	 */
	const TGraphElementId GetId();

	/**
	 * Get the shortcut
	 * @return The shortcut
	 */
	const TShortCut GetShortcut();

	/**
	 * Gets the creation date
	 */
	const long long GetCreationDate();

	/**
	 * Gets the modification date
	 */
	const long long GetModificationDate();

};

template<class TGraphElementId, class TValue, class TShortCut>
inline void GraphElement<TGraphElementId, TValue, TShortCut>::AddProperty(
		const unsigned short propertyId, TValue* const value,
		const unsigned int ttl) {
	_ps->InsertOrUpdate(_id, propertyId, value, ttl);
}

template<class TGraphElementId, class TValue, class TShortCut>
inline const void GraphElement<TGraphElementId, TValue, TShortCut>::RemoveProperty(
		const unsigned short propertyId) {
	_ps->Tombstone(_id, propertyId);
}

template<class TGraphElementId, class TValue, class TShortCut>
inline GraphElement<TGraphElementId, TValue, TShortCut>::GraphElement(
		const TGraphElementId id,
		const PropertyStore<TValue, long long, unsigned short>* const propertyStore,
		TShortCut shortCut,
		const long long creationDate) :
		_id(id), _ps(propertyStore), _shortCut(shortCut), _creationDate(creationDate), _modificationDateDifference(0) {
}

template<class TGraphElementId, class TValue, class TShortCut>
inline const TValue* const GraphElement<TGraphElementId, TValue, TShortCut>::GetProperty(
		const unsigned short propertyId) {

	TValue* value;
	_ps->TryGet(_id, propertyId, value);

	return value;
}

template<class TGraphElementId, class TValue, class TShortCut>
inline const TGraphElementId GraphElement<TGraphElementId, TValue, TShortCut>::GetId() {
	return _id;
}

template<class TGraphElementId, class TValue, class TShortCut>
inline void GraphElement<TGraphElementId, TValue, TShortCut>::SetShortCut(
		const TShortCut shortCut) {
	_shortCut = shortCut;
}

template<class TGraphElementId, class TValue, class TShortCut>
inline const TShortCut GraphElement<TGraphElementId, TValue, TShortCut>::GetShortcut() {
	return _shortCut;
}

#endif
