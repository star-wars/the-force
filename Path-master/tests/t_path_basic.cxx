#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "path_tests.h"
#include "pathDb.h"
#include <boost/any.hpp>

TEST(test_path_basic_1) {
	assert(1 > 0);

	return 0;
}

TEST(test_path_basic_2) {
        assert(1 > 0);

        return 0;
}

int main() {
	int err = 0;
	PathDb<boost::any, long, short, boost::any> *pathDb = new PathDb<boost::any, long, short, boost::any>(1000);

	test_path_basic_1(pathDb);
	test_path_basic_2(pathDb);

	return err ? -1 : 0;
}

