/*
 * edge.h
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

#ifndef _edge_h
#define _edge_h

#include "model/graphElement.h"

//forward definitions
template
<
	class TGraphElementId,
	class TValue,
	class TShortCut
>
class Vertex;


/**
 * The edge template
 */
template
<
	class TGraphElementId,
	class TValue,
	class TShortCut
>
class Edge :
		public GraphElement<TGraphElementId, TValue, TShortCut> {

typedef Vertex<TGraphElementId, TValue, TShortCut> MyVertex;

private:

	/**
	 * The source vertex
	 */
	const MyVertex* const Source;

	/**
	 * The destination vertex
	 */
	const MyVertex* const Destination;

public:

	/**
	 * Gets the source of the edge
	 * @return Source vertex
	 */
	const MyVertex* const GetSource();

	/**
	 * Gets the destination vertex of the edge
	 * @return Destination vertex
	 */
	const MyVertex* const GetDestination();
};

#endif
