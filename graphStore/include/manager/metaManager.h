/*
 * metaManager.h
 *
 *  Created on: 17.04.2014
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

#ifndef _metaManager_h
#define _metaManager_h

#include "propertyStore.h"
#include "transactionManager.h"

/**
 * The meta manager
 */
template<class TGraphElementId, class TValue, class TShortCut>
class MetaManager {

	/**
	 * The graph store should be able to access private methods
	 */
	friend class GraphStore;

private:
	/**
	 * The transaction manager
	 */
	const TransactionManager* const _transactionManager;

	/**
	 * The property store
	 */
	const PropertyStore<TValue, long long, unsigned short>* const _propertyStore;

	/**
	 * Creates a new meta manager
	 * @param propertyStore The property store
	 * @param transactionManager The transaction manager
	 */
	explicit MetaManager(
			const PropertyStore<TValue, long long, unsigned short>* const propertyStore,
			const TransactionManager* const transactionManager) :
			_transactionManager(transactionManager), _propertyStore(
					propertyStore) {

	}

public:

	/**
	 * Get the transaction manager
	 * @return The transaction manager
	 */
	const TransactionManager* const GetTransactionManager() {
		return _transactionManager;
	}

	/**
	 * Get the property store
	 * @return The property store
	 */
	const PropertyStore<TValue, long long, unsigned short>* const GetPropertyStore() {
		return _propertyStore;
	}

};

#endif
