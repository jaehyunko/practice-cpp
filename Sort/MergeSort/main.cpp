#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
#include "MergeSort.h"

void TestMergeSortEmpty(void (*mergeSort)(std::vector<int>&))
{
	std::vector<int> v;

	mergeSort(v);

	assert(v.size() == 0);
}

void TestMergeSortAnElement(void (*mergeSort)(std::vector<int>&))
{
	std::vector<int> v({ 1 });

	mergeSort(v);

	assert(v.size() == 1);
	assert(v[0] == 1);
}

void TestMergeSortTwoElements(void (*mergeSort)(std::vector<int>&))
{
	std::vector<int> v1({ 1, 2 });

	mergeSort(v1);

	assert(v1.size() == 2);
	assert(v1[0] == 1);
	assert(v1[1] == 2);

	std::vector<int> v2({ 1, 1 });

	mergeSort(v2);

	assert(v2.size() == 2);
	assert(v2[0] == 1);
	assert(v2[1] == 1);

	std::vector<int> v3({ 2, 1 });

	mergeSort(v3);

	assert(v3.size() == 2);
	assert(v3[0] == 1);
	assert(v3[1] == 2);
}

void TestMergeSortOddElements(void (*mergeSort)(std::vector<int>&))
{
	std::vector<int> expected({ 1, 2, 3, 4, 5 });

	std::vector<std::vector<int>> inputs({
		{ 1, 2, 3, 4, 5 },
		{ 5, 4, 3, 2, 1 },
		{ 5, 2, 3, 4, 1 },
		{ 1, 4, 3, 2, 5 },
		{ 2, 3, 4, 5, 1 },
		{ 5, 1, 2, 3, 4 },
		{ 3, 4, 5, 1, 2 },
		{ 4, 5, 1, 2, 3 },
		});

	for (auto input : inputs)
	{
		mergeSort(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestMergeSortOddDupElements(void (*mergeSort)(std::vector<int>&))
{
	std::vector<int> expected({ 1, 2, 2, 4, 5 });

	std::vector<std::vector<int>> inputs({
		{ 1, 2, 2, 4, 5 },
		{ 5, 4, 2, 2, 1 },
		{ 5, 2, 2, 4, 1 },
		{ 1, 4, 2, 2, 5 },
		{ 2, 2, 4, 5, 1 },
		{ 5, 1, 2, 2, 4 },
		{ 2, 4, 5, 1, 2 },
		{ 4, 5, 1, 2, 2 },
		});

	for (auto input : inputs)
	{
		mergeSort(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestMergeSortEvenElements(void (*mergeSort)(std::vector<int>&))
{
	std::vector<int> expected({ 1, 2, 3, 4, 5, 6 });

	std::vector<std::vector<int>> inputs({
		{ 1, 2, 3, 4, 5, 6 },
		{ 6, 5, 4, 3, 2, 1 },
		{ 6, 5, 2, 3, 4, 1 },
		{ 1, 4, 3, 2, 5, 6 },
		{ 2, 3, 4, 5, 6, 1 },
		{ 5, 6, 1, 2, 3, 4 },
		{ 3, 4, 5, 6, 1, 2 },
		{ 4, 5, 6, 1, 2, 3 },
		});

	for (auto input : inputs)
	{
		mergeSort(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestMergeSortEvenDupElements(void (*mergeSort)(std::vector<int>&))
{
	std::vector<int> expected({ 1, 2, 3, 3, 5, 6 });

	std::vector<std::vector<int>> inputs({
		{ 1, 2, 3, 3, 5, 6 },
		{ 6, 5, 3, 3, 2, 1 },
		{ 6, 5, 2, 3, 3, 1 },
		{ 1, 3, 3, 2, 5, 6 },
		{ 2, 3, 3, 5, 6, 1 },
		{ 5, 6, 1, 2, 3, 3 },
		{ 3, 3, 5, 6, 1, 2 },
		{ 3, 5, 6, 1, 2, 3 },
		});

	for (auto input : inputs)
	{
		mergeSort(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestMergeSortRandomElements(void (*mergeSort)(std::vector<int>&))
{
	const size_t TEST_COUNT = 10;

	std::vector<int> arr;

	for (size_t i = 0; i < 10000; ++i)
	{
		arr.push_back(rand() % std::numeric_limits<size_t>::max());
	}

	std::vector<int> expected(arr);
	std::sort(expected.begin(), expected.end());
	mergeSort(arr);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr[i]);
	}
}

int main()
{
	TestMergeSortEmpty(jh::MergeSortRecursive);
	TestMergeSortAnElement(jh::MergeSortRecursive);
	TestMergeSortTwoElements(jh::MergeSortRecursive);
	TestMergeSortOddElements(jh::MergeSortRecursive);
	TestMergeSortOddDupElements(jh::MergeSortRecursive);
	TestMergeSortEvenElements(jh::MergeSortRecursive);
	TestMergeSortEvenDupElements(jh::MergeSortRecursive);
	TestMergeSortRandomElements(jh::MergeSortRecursive);

	return 0;
}
