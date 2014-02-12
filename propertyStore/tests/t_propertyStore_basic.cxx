#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "propertyStore_tests.h"
#include "propertyStore.h"
#include "propertyStore.tpp"
#include <boost/any.hpp>

TEST(test_propertyStore_basic_1) {
	assert(1 > 0);

	return 0;
}

TEST(test_propertyStore_basic_2) {
        assert(1 > 0);

        return 0;
}

int main() {
        int err = 0;
        PropertyStore<boost::any, long, short>* ps = new PropertyStore<boost::any, long, short>(23);

        test_propertyStore_basic_1(ps);
        test_propertyStore_basic_2(ps);

        return err ? -1 : 0;
}

