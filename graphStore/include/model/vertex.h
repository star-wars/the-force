/*
 * vertex.h
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

#ifndef _vertex_h
#define _vertex_h

#include "graphElement.h"
#include "model/pointerContainer.h"
#include "model/edgeContainer.h"
#include "model/edge.h"
#include <vector>

/**
 * The vertex template
 */
template<class TGraphElementId, class TValue, class TShortCut>
class Vertex: public GraphElement<TGraphElementId, TValue, TShortCut> {

	typedef Edge<TGraphElementId, TValue, TShortCut> MyEdge;
	typedef Vertex<TGraphElementId, TValue, TShortCut> MyVertex;
	typedef PointerContainer<EdgeContainer<TGraphElementId, TValue, TShortCut>> MyEdgeContainerArray;

friend class GraphStore;

private:
	/**
	 * The container for incoming edges
	 */
	MyEdgeContainerArray* const _inEdgeContainer;

	/**
	 * The container for outgoing edges
	 */
	MyEdgeContainerArray* const _outEdgeContainer;

	/**
	 *
	 * @param id
	 * @param propertyStore
	 * @param shortCut
	 * @param creationDate
	 * @param outEdges
	 * @param inEdges
	 */
	explicit Vertex(const TGraphElementId id,
				const PropertyStore<TValue, long long, unsigned short>* const propertyStore,
				TShortCut shortCut, const long long creationDate, MyEdgeContainerArray* const outEdges, MyEdgeContainerArray* const inEdges);

public:

	/**
	 * Adds an outgoing edge
	 * @param edgePropertyId The edge property identifier
	 * @param outEdge The outgoing edge
	 */
	void AddOutEdge(const short edgePropertyId, MyEdge * const outEdge);

	/**
	 * Adds an incoming edge
	 * @param edgePropertyId The edge property identifier
	 * @param inEdge The incoming edge
	 */
	void AddInEdge(const short edgePropertyId, MyEdge * const inEdge);

	/**
	 * Adds an outgoing edge
	 * @param edgePropertyId The edge property identifier
	 * @param outEdge The outgoing edge
	 */
	void AddOutEdge(const short edgePropertyId, MyVertex * const outEdge);

	/**
	 * Adds an incoming edge
	 * @param edgePropertyId The edge property identifier
	 * @param inEdge The incoming edge
	 */
	void AddInEdge(const short edgePropertyId, MyVertex * const inEdge);

	/**
	 * Get all edges
	 * @return The edges
	 */
	const PointerContainer<MyEdge>* const GetAllEdges();

	/**
	 *Get all outgoing edges
	 * @return The edges
	 */
	const PointerContainer<MyEdge>* const GetAllOutEdges();

	/**
	 * Get all incoming edges
	 * @return all incoming edges
	 */
	const PointerContainer<MyEdge>* const GetAllInEdges();

	/**
	 * Get outgoing edges
	 * @param edgePropertyId The edge property identifier
	 * @return Outgoing edges of a given edge property identifier
	 */
	const PointerContainer<MyEdge>* const GetOutEdges(
			const short edgePropertyId);

	/**
	 * Get incoming edges
	 * @param edgePropertyId The edge property identifier
	 * @return Incoming edges of a given edge property identifier
	 */
	const PointerContainer<MyEdge>* const GetInEdges(
			const short edgePropertyId);

	/**
	 * Get all neighbors
	 * @return All neighbors
	 */
	const PointerContainer<MyVertex>* const GetAllNeighbors();

	/**
	 * Get all neighbors of outgoing edges
	 * @return Neighbors
	 */
	const PointerContainer<MyVertex>* const GetAllOutNeighbors();

	/**
	 * Get all neighbors of incoming edges
	 * @return Neighbors
	 */
	const PointerContainer<MyVertex>* const GetAllInNeighbors();

	/**
	 * Get neighbors from outgoing edges
	 * @param edgePropertyId The edge property identifier
	 * @return Neighbors from outgoing edges of a given edge property identifier
	 */
	const PointerContainer<MyVertex>* const GetOutNeighbors(
			const short edgePropertyId);

	/**
	 * Get neighbors from incoming edges
	 * @param edgePropertyId The edge property identifier
	 * @return Neighbors from incoming edges of a given edge property identifier
	 */
	const PointerContainer<MyVertex>* const GetInNeighbors(
			const short edgePropertyId);

	/**
	 * Get incoming edge identifier
	 * @return Incoming edge identifier
	 */
	const std::vector<short> GetInEdgeIds();

	/**
	 * Get outgoing edge identifier
	 * @return outgoing edge identifier
	 */
	const std::vector<short> GetOutEdgeIds();

	/**
	 * Get the out-degree
	 * @return Out-degree
	 */
	unsigned int GetOutDegree();

	/**
	 * Get the in-degree
	 * @return The in-degree
	 */
	unsigned int GetInDegree();

};

#endif
