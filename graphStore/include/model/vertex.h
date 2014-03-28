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

/**
 * The vertex template
 */
template<class TGraphElementId, class DatePolicy, class TShortCut, template<
		class TShortCut> class ShortCutPolicy, class TValue, template<
		class TValue, class TGraphElementId> class PropertyPolicy>
class Vertex: public GraphElement<TGraphElementId, DatePolicy, TShortCut,
		ShortCutPolicy, TValue, PropertyPolicy> {

	typedef Edge<TGraphElementId, DatePolicy, TShortCut, ShortCutPolicy, TValue,
			PropertyPolicy> MyEdge;
	typedef Vertex<TGraphElementId, DatePolicy, TShortCut, ShortCutPolicy,
			TValue, PropertyPolicy> MyVertex;
	typedef PointerContainer<
			EdgeContainer<TGraphElementId, DatePolicy, TShortCut,
					ShortCutPolicy, TValue, PropertyPolicy>> MyEdgeContainerArray;

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

public:
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
	 *
	 * @return
	 */
	const PointerContainer<MyEdge>* const GetAllInEdges();
	const PointerContainer<MyEdge>* const GetOutEdges(
			const short edgePropertyId);
	const PointerContainer<MyEdge>* const GetInEdges(
			const short edgePropertyId);

	const PointerContainer<MyVertex>* const GetAllNeighbors();
	const PointerContainer<MyVertex>* const GetAllOutNeighbors();
	const PointerContainer<MyVertex>* const GetAllInNeighbors();
	const PointerContainer<MyVertex>* const GetOutNeighbors(
			const short edgePropertyId);
	const PointerContainer<MyVertex>* const GetInNeighbors(
			const short edgePropertyId);

	const short* GetInEdgeIds();
	const short* GetOutEdgeIds();

	unsigned int GetOutDegree();
	unsigned int GetInDegree();

};

#endif
