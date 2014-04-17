#include <assert.h>
#include "commons_tests.h"
#include "memory/growthByNextPowerOfTwo.h"
#include "memory/arrayAllocator.h"



TEST(test_commons_arrayAllocator_basic) {

	const std::size_t size = 10;
	ArrayAllocator<int, GrowthByNextPowerOfTwo, size>* allocator =
			new ArrayAllocator<int, GrowthByNextPowerOfTwo, size>();

	ArrayObject<int>* const firstElementOfArray_0 = allocator->GetArray(0);
	firstElementOfArray_0->GetFirstElement();
	firstElementOfArray_0->GetFirstElement();

	ArrayObject<int>* const firstElementOfArray_1 = allocator->GetArray(1);
	firstElementOfArray_1->GetFirstElement();
	firstElementOfArray_1->GetFirstElement();

	ArrayObject<int>* const firstElementOfArray_4 = allocator->GetArray(126);
	firstElementOfArray_4->GetFirstElement();
	firstElementOfArray_4->GetFirstElement();

	delete (allocator);

	return 0;
}

TEST(test_commons_arrayAllocator_mass) {

	const std::size_t size = 10;
	ArrayAllocator<int, GrowthByNextPowerOfTwo, size>* allocator =
			new ArrayAllocator<int, GrowthByNextPowerOfTwo, size>();

	const int numberOfIterations = 10000;

	ArrayObject<int>* array[numberOfIterations];

	for (int i = 0; i < numberOfIterations; ++i) {
		ArrayObject<int>* const firstElementOfArray_4 = allocator->GetArray(126);
		firstElementOfArray_4->GetFirstElement();
		firstElementOfArray_4->GetFirstElement();

		array[i] = firstElementOfArray_4;
	}

	for(int i = 0; i < numberOfIterations; ++i)
	{
		allocator->Free(array[i]);
	}

	return 0;
}

TEST(test_commons_growth_GetNextSize) {

	GrowthByNextPowerOfTwo* growth = new GrowthByNextPowerOfTwo();

	assert(growth->GetNextSize(0) == 1);

	assert(growth->GetNextSize(1) == 2);

	assert(growth->GetNextSize(2) == 4);

	assert(growth->GetNextSize(3) == 4);

	assert(growth->GetNextSize(4) == 8);

	assert(growth->GetNextSize(126) == 128);

	assert(growth->GetNextSize(8388607) == 8388608);

	delete(growth);

	return 0;
}

TEST(test_commons_growth_GetSlotForSize) {

	GrowthByNextPowerOfTwo* growth = new GrowthByNextPowerOfTwo();

	assert(growth->GetSlotForSize(0) == 0);

	assert(growth->GetSlotForSize(1) == 0);

	assert(growth->GetSlotForSize(2) == 1);

	assert(growth->GetSlotForSize(3) == 1);

	assert(growth->GetSlotForSize(4) == 2);

	assert(growth->GetSlotForSize(4294967296) == 32);

	delete(growth);

	return 0;
}

int main() {
	int err = 0;

	test_commons_growth_GetNextSize();
	test_commons_growth_GetSlotForSize();
	test_commons_arrayAllocator_basic();
	test_commons_arrayAllocator_mass();


	return err ? -1 : 0;
}
