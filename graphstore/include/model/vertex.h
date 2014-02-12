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

//forward definitions
template<class TValue, class TGraphElementId, class TPropertyId, class TShortCut> class Edge;
template<class TValue, class TGraphElementId, class TPropertyId, class TShortCut> class EdgeContainer;

template<class TValue, class TGraphElementId, class TPropertyId, class TShortCut>
class Vertex : public GraphElement<TValue, TGraphElementId, TPropertyId, TShortCut> {

private:
	const EdgeContainer<TValue, TGraphElementId, TPropertyId, TShortCut>* const _inEdgeContainer;
	const EdgeContainer<TValue, TGraphElementId, TPropertyId, TShortCut>* const _outEdgeContainer;

	void AddEdge();
	void AddOutEdge(const TPropertyId edgePropertyId, Edge<TValue, TGraphElementId, TPropertyId, TShortCut> * const outEdge);
	void AddInEdge(const TPropertyId edgePropertyId, Edge<TValue, TGraphElementId, TPropertyId, TShortCut> * const inEdge);

public:
	const Edge<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetAllEdges();
	const Edge<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetAllOutEdges();
	const Edge<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetAllInEdges();
	const Edge<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetOutEdges(const TPropertyId edgePropertyId);
	const Edge<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetInEdges(const TPropertyId edgePropertyId);

	const Vertex<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetAllNeighbors();
	const Vertex<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetAllOutNeighbors();
	const Vertex<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetAllInNeighbors();
	const Vertex<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetOutNeighbors(const TPropertyId edgePropertyId);
	const Vertex<TValue, TGraphElementId, TPropertyId, TShortCut>* const GetInNeighbors(const TPropertyId edgePropertyId);

	const TPropertyId* GetInEdgeIds();
	const TPropertyId* GetOutEdgeIds();

	unsigned int GetOutDegree();
	unsigned int GetInDegree();
};

#endif
