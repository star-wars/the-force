/*
 * edgeContainer.h
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

#ifndef _edgeContainer_h
#define _edgeContainer_h

#include <edge.h>
#include <pointerContainer.h>

template
<
	class TGraphElementId,
	class DatePolicy,
	class TShortCut,
	template <class TShortCut> class ShortCutPolicy,
	class TValue,
	template <class TValue, class TGraphElementId> class PropertyPolicy
> class EdgeContainer: public PointerContainer<Edge<TGraphElementId, DatePolicy, TShortCut, ShortCutPolicy, TValue, PropertyPolicy>>  {

private:

	/**
	 * The edge property identifier
	 */
	const short _edgePropertyId;

public:

	/**
	 * Creates a new edge container
	 * @param edgePropertyId The edge property identifier
	 */
	explicit EdgeContainer(const short edgePropertyId);

	/**
	 * Returns the edge property identifier
	 */
	const short EdgePropertyId();
};

#endif
