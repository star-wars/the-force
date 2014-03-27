/*
 * powerEdgePolicy.h
 *
 *  Created on: 21.03.2014
 *      Author: cosh
 *     Purpose: This is a edge policy implementation
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

#ifndef _powerEdgePolicy_h
#define _powerEdgePolicy_h

#include <model/edge.h>
#include <model/pointerContainer.h>
#include <model/vertex.h>


template
<
	class TGraphElementId,
	class DatePolicy,
	class TShortCut,
	template <class TShortCut> class ShortCutPolicy,
	class TValue,
	template <class TValue, class TGraphElementId> class PropertyPolicy,
	template<class TGraphElementId, class DatePolicy, class TShortCut, class ShortCutPolicy, class TValue, class PropertyPolicy> class EdgePolicy
>
class PowerEdgePolicy {

	typedef Edge<TGraphElementId, DatePolicy, TShortCut, ShortCutPolicy, TValue, PropertyPolicy, EdgePolicy> MyEdge;
	typedef Vertex<TGraphElementId, DatePolicy, TShortCut, ShortCutPolicy, TValue, PropertyPolicy, EdgePolicy> MyVertex;
	typedef PointerContainer<MyVertex> MyVertexContainer;

	private:
	//PointerContainer<EdgeContainer>* _firstInEdgeContainer;
		//EdgeContainer* const _outEdgeContainer;



		void AddEdge();
		void AddOutEdge(const short edgePropertyId, MyEdge * const outEdge);
		void AddInEdge(const short edgePropertyId, MyEdge * const inEdge);

	protected:

		/**
		 * Initializes an edge policy
		 */
		explicit PowerEdgePolicy();

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
