/*
 * C4.tpp
 *
 *  Created on: 09.09.2013
 *      Author: cosh
 *     Purpose: Template code of the key value store
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

#include "C4.h"

template<class TValue, class TRowId, class TColumnId>
void C4<TValue, TRowId, TColumnId>::InsertOrUpdate(
		const TRowId rowId, const TColumnId columnId, const TValue* value,
		const int ttl) {
}

template<class TValue, class TRowId, class TColumnId>
bool C4<TValue, TRowId, TColumnId>::TryGet(
		const TRowId rowId, const TColumnId columnId, TValue* outResult) {
	return true;
}

template<class TValue, class TRowId, class TColumnId>
void C4<TValue, TRowId, TColumnId>::Tombstone(
		const TRowId rowId, const TColumnId columnId) {
}

template<class TValue, class TRowId, class TColumnId>
void C4<TValue, TRowId, TColumnId>::Tombstone(
		const TRowId rowId) {
}

template<class TValue, class TRowId, class TColumnId>
void C4<TValue, TRowId, TColumnId>::Compact() {
}

template<class TValue, class TRowId, class TColumnId>
void C4<TValue, TRowId, TColumnId>::TabulaRasa() {
}

template<class TValue, class TRowId, class TColumnId>
void C4<TValue, TRowId, TColumnId>::Save(
		const char* outputStream) {
}

template<class TValue, class TRowId, class TColumnId>
void C4<TValue, TRowId, TColumnId>::Load(
		const char* inputStream) {
}

template<class TValue, class TRowId, class TColumnId>
void C4<TValue, TRowId, TColumnId>::Shutdown() {
}