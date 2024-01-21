#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <dynarr/dynarr.hpp>


TEST_CASE("dynarr size") {
	DynArr arr_def;
	CHECK_EQ(arr_def.Size(), 0);

	const int size = 5;
	DynArr arr_s(size);
	CHECK_EQ(arr_s.Size(), size);
	CHECK_THROWS(void(DynArr(0)));
	CHECK_THROWS(void(DynArr(-size)));
}


TEST_CASE("dynarr functions") {
	DynArr arr(7);
	for (int i = 0; i < 7; i++) {
		arr[i] = i;
	}
	CHECK_EQ(arr[4], 4);
	CHECK_THROWS(arr[-1]);
	CHECK_THROWS(arr[arr.Size()]);
	CHECK_EQ(arr.Empty(), 0);

	arr.Push_back(7);
	CHECK_EQ(arr[7], 7);

	arr.Pop_back();
	CHECK_THROWS(arr[7]);

	arr.Erase(2);
	CHECK_EQ(arr[2], 3);

	arr.Insert(2, 2);
	CHECK_EQ(arr[2], 2);

	arr.Resize(10);
	CHECK_EQ(arr[8], 0);
	arr.Resize(5);
	CHECK_THROWS(arr[7]);

	arr.Clear();
	CHECK_THROWS(arr[0]);
	CHECK_EQ(arr.Empty(), 1);

	DynArr arr2(5);
	arr2[2] = 10;
	arr = arr2;
	CHECK_EQ(arr[0], 0);
	CHECK_EQ(arr[2], 10);
}