#include <cassert>
#include <vector>
#include "SelectionSort.h"

void TestSelectionSortIntArray()
{
	const std::vector<int> expected({ 1, 2, 3, 4, 5 });

	std::vector<int> arr1({ 1, 2, 3, 4, 5 });

	jh::SelectionSort(arr1);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr1[i]);
	}

	std::vector<int> arr2({ 5, 4, 3, 2, 1 });

	jh::SelectionSort(arr2);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr2[i]);
	}

	std::vector<int> arr3({ 1, 4, 3, 2, 5 });

	jh::SelectionSort(arr3);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr3[i]);
	}
}

void TestSelectionSortEmptyArray()
{
	const std::vector<int> expected;

	std::vector<int> arr1;

	jh::SelectionSort(arr1);

	assert(arr1.size() == 0);
}

void TestSelectionSortCharArray()
{
	const std::vector<char> expected({ 'a', 'b', 'c', 'd', 'e' });

	std::vector<char> arr1({ 'a', 'b', 'c', 'd', 'e' });

	jh::SelectionSort(arr1);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr1[i]);
	}

	std::vector<char> arr2({ 'e', 'd', 'c', 'b', 'a' });

	jh::SelectionSort(arr2);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr2[i]);
	}

	std::vector<char> arr3({ 'a', 'd', 'c', 'b', 'e' });

	jh::SelectionSort(arr3);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr3[i]);
	}
}

int main()
{
	TestSelectionSortIntArray();
	TestSelectionSortEmptyArray();
	TestSelectionSortCharArray();

	return 0;
}