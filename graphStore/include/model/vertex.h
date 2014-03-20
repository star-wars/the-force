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
template
<
	class TGraphElementId,
	class TDate,
	template <class TDate> class DatePolicy,
	class TShortCut,
	template <class TShortCut> class ShortCutPolicy,
	class TValue,
	template <class TValue> class PropertyPolicy
> class Edge;

template
<
	class TGraphElementId,
	class TDate,
	template <class TDate> class DatePolicy,
	class TShortCut,
	template <class TShortCut> class ShortCutPolicy,
	class TValue,
	template <class TValue> class PropertyPolicy
> class EdgeContainer;

/**
 * The vertex template
 */
template
<
	class TGraphElementId,
	class TDate,
	template <class TDate> class DatePolicy,
	class TShortCut,
	template <class TShortCut> class ShortCutPolicy,
	class TValue,
	template <class TValue> class PropertyPolicy
>
class Vertex :
		public GraphElement<TGraphElementId, TDate, DatePolicy, TShortCut, ShortCutPolicy, TValue, PropertyPolicy> {

typedef Edge<TGraphElementId, TDate, DatePolicy, TShortCut, ShortCutPolicy, TValue, PropertyPolicy> MyEdge;
typedef EdgeContainer<TGraphElementId, TDate, DatePolicy, TShortCut, ShortCutPolicy, TValue, PropertyPolicy> MyEdgeContainer;
typedef Vertex<TGraphElementId, TDate, DatePolicy, TShortCut, ShortCutPolicy, TValue, PropertyPolicy> MyVertex;

private:
	const MyEdgeContainer* const _inEdgeContainer;
	const MyEdgeContainer* const _outEdgeContainer;

	void AddEdge();
	void AddOutEdge(const short edgePropertyId, MyEdge * const outEdge);
	void AddInEdge(const short edgePropertyId, MyEdge * const inEdge);

public:
	const MyEdge* const GetAllEdges();
	const MyEdge* const GetAllOutEdges();
	const MyEdge* const GetAllInEdges();
	const MyEdge* const GetOutEdges(const short edgePropertyId);
	const MyEdge* const GetInEdges(const short edgePropertyId);

	const MyVertex* const GetAllNeighbors();
	const MyVertex* const GetAllOutNeighbors();
	const MyVertex* const GetAllInNeighbors();
	const MyVertex* const GetOutNeighbors(const short edgePropertyId);
	const MyVertex* const GetInNeighbors(const short edgePropertyId);

	const short* GetInEdgeIds();
	const short* GetOutEdgeIds();

	unsigned int GetOutDegree();
	unsigned int GetInDegree();
};

#endif
