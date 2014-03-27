#include <assert.h>
#include <boost/any.hpp>
#include <model/policy/columnStorePropertyPolicy.h>
#include <model/policy/compressedDatePolicy.h>
#include <model/policy/powerEdgePolicy.h>
#include <errno.h>
#include <graphStore.h>
#include <model/policy/shortCutPolicy.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "graphStore_tests.h"

TEST(test_graphStore_basic_1) {
	assert(1 > 0);

	return 0;
}

TEST(test_graphStore_basic_2) {
        assert(1 > 0);

        return 0;
}

int main() {
	int err = 0;
	GraphStore<long long, CompressedDatePolicy, long, ShortCutPolicy, std::string, ColumnStorePropertyPolicy, PowerEdgePolicy> *gs = new GraphStore<long long, CompressedDatePolicy, long, ShortCutPolicy, std::string, ColumnStorePropertyPolicy, PowerEdgePolicy>(1000);

	test_graphStore_basic_1(gs);
	test_graphStore_basic_2(gs);

	return err ? -1 : 0;
}

