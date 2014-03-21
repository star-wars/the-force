/*
 * columnStorePropertyPolicy.h
 *
 *  Created on: 21.03.2014
 *      Author: cosh
 *     Purpose: This is a property policy implementation
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

#ifndef _columnStorePropertyPolicy_h
#define _columnStorePropertyPolicy_h

#include "propertyStore.h"

template<class TValue, class TGraphElementId>
class ColumnStorePropertyPolicy {

private:

	const TGraphElementId _id;
	const PropertyStore<TValue, long long, unsigned short>* const _ps;

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
	 * Initializes the property policy
	 * @param propertyStore the property store
	 */
	explicit ColumnStorePropertyPolicy(
			const PropertyStore<TValue, long long, unsigned short>* const propertyStore,
			const TGraphElementId id);

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
};

template<class TValue, class TGraphElementId>
inline void ColumnStorePropertyPolicy<TValue, TGraphElementId>::AddProperty(
		const unsigned short propertyId, TValue* const value,
		const unsigned int ttl) {
	_ps->InsertOrUpdate(_id, propertyId, value, ttl);
}

template<class TValue, class TGraphElementId>
inline const void ColumnStorePropertyPolicy<TValue, TGraphElementId>::RemoveProperty(
		const unsigned short propertyId) {
	_ps->Tombstone(_id, propertyId);
}

template<class TValue, class TGraphElementId>
inline ColumnStorePropertyPolicy<TValue, TGraphElementId>::ColumnStorePropertyPolicy(
		const PropertyStore<TValue, long long, unsigned short>* const propertyStore,
		const TGraphElementId id) :
		_id(id), _ps(propertyStore){
}

template<class TValue, class TGraphElementId>
inline const TValue* const ColumnStorePropertyPolicy<TValue, TGraphElementId>::GetProperty(
		const unsigned short propertyId) {

	TValue* value;
	_ps->TryGet(_id, propertyId, value);

	return value;
}

template<class TValue, class TGraphElementId>
inline const TGraphElementId ColumnStorePropertyPolicy<TValue, TGraphElementId>::GetId() {
	return _id;
}

#endif
