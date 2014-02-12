#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "graphStore_tests.h"
#include "graphStore.h"
#include <boost/any.hpp>

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
	GraphStore<boost::any, long, short, boost::any> *gs = new GraphStore<boost::any, long, short, boost::any>(1000);

	test_graphStore_basic_1(gs);
	test_graphStore_basic_2(gs);

	return err ? -1 : 0;
}

