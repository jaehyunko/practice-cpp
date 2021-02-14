#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
#include "QuickSort.h"

void TestQuickSortEmpty(void (*quickSort)(std::vector<int>&))
{
	std::vector<int> v;

	quickSort(v);

	assert(v.size() == 0);
}

void TestQuickSortAnElement(void (*quickSort)(std::vector<int>&))
{
	std::vector<int> v({ 1 });

	quickSort(v);

	assert(v.size() == 1);
	assert(v[0] == 1);
}

void TestQuickSortTwoElements(void (*quickSort)(std::vector<int>&))
{
	std::vector<int> v1({ 1, 2 });

	quickSort(v1);

	assert(v1.size() == 2);
	assert(v1[0] == 1);
	assert(v1[1] == 2);

	std::vector<int> v2({ 1, 1 });

	quickSort(v2);

	assert(v2.size() == 2);
	assert(v2[0] == 1);
	assert(v2[1] == 1);

	std::vector<int> v3({ 2, 1 });

	quickSort(v3);

	assert(v3.size() == 2);
	assert(v3[0] == 1);
	assert(v3[1] == 2);
}

void TestQuickSortOddElements(void (*quickSort)(std::vector<int>&))
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
		quickSort(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestQuickSortOddDupElements(void (*quickSort)(std::vector<int>&))
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
		quickSort(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestQuickSortEvenElements(void (*quickSort)(std::vector<int>&))
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
		quickSort(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestQuickSortEvenDupElements(void (*quickSort)(std::vector<int>&))
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
		quickSort(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestQuickSortRandomElements(void (*quickSort)(std::vector<int>&))
{
	const size_t TEST_COUNT = 10;

	for (size_t t = 0; t < TEST_COUNT; ++t)
	{
		std::vector<int> arr;

		for (size_t i = 0; i < (t + 1) * 1000000; ++i)
		{
			arr.push_back(rand() % std::numeric_limits<size_t>::max());
		}

		std::chrono::steady_clock::time_point begin;
		std::chrono::steady_clock::time_point end;

		std::vector<int> expected(arr);

		begin = std::chrono::steady_clock::now();
		std::sort(expected.begin(), expected.end());
		end = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << ", ";

		begin = std::chrono::steady_clock::now();
		quickSort(arr);
		end = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == arr[i]);
		}
	}
}

int main()
{
	std::cout << "recursive" << std::endl;

	TestQuickSortEmpty(jh::QuickSortRecursive);
	TestQuickSortAnElement(jh::QuickSortRecursive);
	TestQuickSortTwoElements(jh::QuickSortRecursive);
	TestQuickSortOddElements(jh::QuickSortRecursive);
	TestQuickSortOddDupElements(jh::QuickSortRecursive);
	TestQuickSortEvenElements(jh::QuickSortRecursive);
	TestQuickSortEvenDupElements(jh::QuickSortRecursive);
	TestQuickSortRandomElements(jh::QuickSortRecursive);

	std::cout << "iterative" << std::endl;

	TestQuickSortEmpty(jh::QuickSortIterative);
	TestQuickSortAnElement(jh::QuickSortIterative);
	TestQuickSortTwoElements(jh::QuickSortIterative);
	TestQuickSortOddElements(jh::QuickSortIterative);
	TestQuickSortOddDupElements(jh::QuickSortIterative);
	TestQuickSortEvenElements(jh::QuickSortIterative);
	TestQuickSortEvenDupElements(jh::QuickSortIterative);
	TestQuickSortRandomElements(jh::QuickSortIterative);

	return 0;
}