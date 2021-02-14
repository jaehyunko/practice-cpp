#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>
#include "QuickSort.h"

void TestQuickSortRecursiveEmpty()
{
	std::vector<int> v;

	jh::QuickSortRecursive(v);

	assert(v.size() == 0);
}

void TestQuickSortRecursiveAnElement()
{
	std::vector<int> v({ 1 });

	jh::QuickSortRecursive(v);

	assert(v.size() == 1);
	assert(v[0] == 1);
}

void TestQuickSortRecursiveTwoElements()
{
	std::vector<int> v1({ 1, 2 });

	jh::QuickSortRecursive(v1);

	assert(v1.size() == 2);
	assert(v1[0] == 1);
	assert(v1[1] == 2);

	std::vector<int> v2({ 1, 1 });

	jh::QuickSortRecursive(v2);

	assert(v2.size() == 2);
	assert(v2[0] == 1);
	assert(v2[1] == 1);

	std::vector<int> v3({ 2, 1 });

	jh::QuickSortRecursive(v3);

	assert(v3.size() == 2);
	assert(v3[0] == 1);
	assert(v3[1] == 2);
}

void TestQuickSortRecursiveOddElements()
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
		jh::QuickSortRecursive(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestQuickSortRecursiveOddDupElements()
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
		jh::QuickSortRecursive(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestQuickSortRecursiveEvenElements()
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
		jh::QuickSortRecursive(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestQuickSortRecursiveEvenDupElements()
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
		jh::QuickSortRecursive(input);
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == input[i]);
		}
	}
}

void TestQuickSortRecursiveRandomElements()
{
	const size_t MAX_ELEMENT_COUNT = 10000;
	const size_t TEST_COUNT = 100;

	for (size_t t = 0; t < TEST_COUNT; ++t)
	{
		size_t elementCount = rand() % MAX_ELEMENT_COUNT;

		std::vector<int> arr;

		for (size_t i = 0; i < elementCount; ++i)
		{
			arr.push_back(rand() % MAX_ELEMENT_COUNT);
		}

		std::vector<int> expected(arr);
		std::sort(expected.begin(), expected.end());

		jh::QuickSortRecursive(arr);

		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == arr[i]);
		}
	}
}

int main()
{
	TestQuickSortRecursiveEmpty();
	TestQuickSortRecursiveAnElement();
	TestQuickSortRecursiveTwoElements();
	TestQuickSortRecursiveOddElements();
	TestQuickSortRecursiveOddDupElements();
	TestQuickSortRecursiveEvenElements();
	TestQuickSortRecursiveEvenDupElements();
	TestQuickSortRecursiveRandomElements();

	return 0;
}