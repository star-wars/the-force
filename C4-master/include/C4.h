/*
 * C4.h
 *
 *  Created on: 25.03.2013
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

#ifndef C4_H_
#define C4_H_

/**
 * C4 is an in memory column store
 *
 * TValue: The type of the values in the columns
 * TRowId: The type of the row identifier
 * TColumnId: The type of the column identifier
 */
template<class TValue, class TRowId, class TColumnId>
class C4 {

private:

	int _compactionInterval;

public:

	/**
	 * Creates a new column store
	 * @param compactionInterval The interval that the columnstore should be compacted
	 */
	explicit C4(int compactionInterval) :
			_compactionInterval(compactionInterval) {

	}

	/**
	 * Inserts or updates a new row including the corresponding column with a new value
	 *
	 * @param rowId The row identifier
	 * @param columnId The column identifier
	 * @param value The to be inserted/updated value
	 * @param ttl The time to live of the value
	 */
	void InsertOrUpdate(const TRowId rowId, const TColumnId columnId, const TValue* value,
			const int ttl = 0);


	/**
	 * Tries to get a column in a row
	 * @param rowId The row identifier
	 * @param columnId The column identifier
	 * @param outResult The resulting value if it exists
	 * @return True if the value has been found, otherwise false
	 */
	bool TryGet(const TRowId rowId, const TColumnId columnId, TValue* outResult);

	/**
	 * Tombstones a column in a row. Tomestones are finally deleted in the next compaction.
	 * @param rowId The row identifier
	 * @param columnId The column identifier
	 */
	void Tombstone(const TRowId rowId, const TColumnId columnId);

	/**
	 * Tombstones a row. Tomestones are finally deleted in the next compaction.
	 * @param rowId The row identifier
	 */
	void Tombstone(const TRowId rowId);

	/**
	 * Executes a compaction
	 */
	void Compact();

	/**
	 * Cleares the column store
	 */
	void TabulaRasa();

	/**
	 * Saves the column store
	 * @param outputStream The output stream
	 */
	void Save(const char* outputStream);

	/**
	 * Loads the columnstore
	 * @param inputStream The input stream
	 */
	void Load(const char* inputStream);

	/**
	 * Shutdown
	 */
	void Shutdown();
};

#endif /* C4_H_ */
