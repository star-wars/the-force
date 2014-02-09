/*
 * pathDb.h
 *
 *  Created on: 29.04.2013
 *      Author: cosh
 *     Purpose: The pathDb header file
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

#ifndef _pathDb_h
#define _pathDb_h

#include "manager/transactionManager.h"
#include "C4.h"

template<class TValue, class TRowId, class TColumnId> class C4;

template<class TValue, class TGraphElementId, class TPropertyId, class TShortCut>
class PathDb {
private:
	C4<TValue, TGraphElementId, TPropertyId>* _c4;
	TransactionManager* _transactionManager;

public:
	void Print();

	explicit PathDb(int compactionInterval)
	{
		_c4 = new C4<TValue, TGraphElementId, TPropertyId>(compactionInterval);
		_transactionManager = new TransactionManager();
	}
};

#endif
