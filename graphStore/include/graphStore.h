/*
 * graphStore.h
 *
 *  Created on: 29.04.2013
 *      Author: cosh
 *     Purpose: The graphStore header file
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

#ifndef _graphStore_h
#define _graphStore_h

#include "manager/transactionManager.h"
#include "propertyStore.h"
#include "definition/property.h"

template<class TValue, class TGraphElementId, class TPropertyId, class TShortCut> class Edge;
template<class TValue, class TGraphElementId, class TPropertyId, class TShortCut> class Vertex;

template<class TValue, class TGraphElementId, class TPropertyId, class TShortCut>
class GraphStore {
private:
	PropertyStore<TValue, TGraphElementId, TPropertyId>* _ps;
	TransactionManager* _transactionManager;

public:
	explicit GraphStore(int compactionInterval)
	{
		_ps = new PropertyStore<TValue, TGraphElementId, TPropertyId>(compactionInterval);
		_transactionManager = new TransactionManager();
	}

	const TGraphElementId* const AddVertex(
		Property<TPropertyId, TValue> const properties[],
		const TShortCut* const shortCut);

	const Vertex<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetVertex(const TGraphElementId* const id);

	const TGraphElementId* const AddEdge(
		const TGraphElementId source,
		const TGraphElementId destination,
		const TPropertyId edgePropertyId,
                const Property<TPropertyId, TValue> properties[],
                const TShortCut* const shortCut);

	const Edge<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetEdge(const TGraphElementId* const id);
};

#endif
