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

/**
 *
 */
template<
	class TValue,
	class TGraphElementId,
	class TPropertyId,
	class TShortCut>
class GraphStore {

private:

	/**
	 *
	 */
	PropertyStore<TValue, TGraphElementId, TPropertyId>* _ps;

	/**
	 *
	 */
	TransactionManager* _transactionManager;

public:

	/**
	 *
	 * @param compactionInterval
	 */
	explicit GraphStore(int compactionInterval)
	{
		_ps = new PropertyStore<TValue, TGraphElementId, TPropertyId>(compactionInterval);
		_transactionManager = new TransactionManager();
	}


	/**
	 *
	 * @param properties
	 * @param shortCut
	 * @param creationDate
	 * @return
	 */
	const TGraphElementId AddVertex(
		Property<TPropertyId, TValue> const properties[],
		const TShortCut* const shortCut,
		const long const creationDate);

	/**
	 *
	 * @param id
	 * @return
	 */
	const Vertex<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetVertex(
			const TGraphElementId id);

	/**
	 *
	 * @param source
	 * @param destination
	 * @param edgePropertyId
	 * @param properties
	 * @param shortCut
	 * @param creationDate
	 * @return
	 */
	const TGraphElementId AddEdge(
		const TGraphElementId source,
		const TGraphElementId destination,
		const TPropertyId edgePropertyId,
                const Property<TPropertyId, TValue> properties[],
                const TShortCut* const shortCut,
        		const long const creationDate);

	/**
	 *
	 * @param id
	 * @return
	 */
	const Edge<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetEdge(
			const TGraphElementId id);

	/**
	 *
	 * @param id
	 * @return
	 */
	const GraphElement<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetGraphElement(
				const TGraphElementId id);

	/**
	 *
	 * @param id
	 * @return
	 */
	const bool RemoveGraphElement(const TGraphElementId id);

	/**
	 *
	 * @param id
	 * @return
	 */
	const bool RemoveEdge(const TGraphElementId id);

	/**
	 *
	 * @param id
	 * @return
	 */
	const bool RemoveVertex(const TGraphElementId id);

	/**
	 *
	 * @param id
	 * @param columnId
	 * @return
	 */
	const bool TombstoneProperty(const TGraphElementId id, const TPropertyId columnId);

	/**
	 *
	 * @param id
	 * @param columnId
	 * @return
	 */
	const bool TombstoneEdgeProperty(const TGraphElementId id, const TPropertyId columnId);

	/**
	 *
	 */
	void TabulaRasa();

	/**
	 * Saves the graph database
	 * @param outputStream The output stream
	 */
	void Save(const char* outputlStream);

	/**
	 * Loads the graph database
	 * @param inputStream The input stream
	 */
	void Load(const char* inputStream);

	/**
	 * Shutdown
	 */
	void Shutdown();
};

#endif
