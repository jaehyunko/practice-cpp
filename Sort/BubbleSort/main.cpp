#include <cassert>
#include <vector>
#include "BubbleSort.h"
#include "Dummy.h"

void TestBubbleSortIntArray()
{
	const std::vector<int> expected({ 1, 2, 3, 4, 5 });

	std::vector<int> arr1({ 1, 2, 3, 4, 5 });

	jh::BubbleSort(arr1);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr1[i]);
	}

	std::vector<int> arr2({ 5, 4, 3, 2, 1 });

	jh::BubbleSort(arr2);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr2[i]);
	}

	std::vector<int> arr3({ 1, 4, 3, 2, 5 });

	jh::BubbleSort(arr3);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr3[i]);
	}
}

void TestBubbleSortEmptyArray()
{
	const std::vector<int> expected;

	std::vector<int> arr1;

	jh::BubbleSort(arr1);

	assert(arr1.size() == 0);
}

void TestBubbleSortCharArray()
{
	const std::vector<char> expected({ 'a', 'b', 'c', 'd', 'e' });

	std::vector<char> arr1({ 'a', 'b', 'c', 'd', 'e' });

	jh::BubbleSort(arr1);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr1[i]);
	}

	std::vector<char> arr2({ 'e', 'd', 'c', 'b', 'a' });

	jh::BubbleSort(arr2);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr2[i]);
	}

	std::vector<char> arr3({ 'a', 'd', 'c', 'b', 'e' });

	jh::BubbleSort(arr3);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr3[i]);
	}
}

void TestBubbleSortStable()
{
	std::vector<jh::Dummy> expected({ {1, 'a'}, {2, 'b'}, {2, 'c'}, {2, 'd'}, {3, 'd'} });

	std::vector<jh::Dummy> arr1({ {1, 'a'}, {2, 'b'}, {2, 'c'}, {2, 'd'}, {3, 'd'} });

	jh::BubbleSort(arr1);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr1[i]);
	}

	std::vector<jh::Dummy> arr2({ {2, 'b'}, {1, 'a'}, {2, 'c'}, {3, 'd'}, {2, 'd'} });

	jh::BubbleSort(arr2);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr2[i]);
	}

	std::vector<jh::Dummy> arr3({ {1, 'a'}, {3, 'd'}, {2, 'b'}, {2, 'c'}, {2, 'd'} });

	jh::BubbleSort(arr3);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr3[i]);
	}

	std::vector<jh::Dummy> arr4({ {2, 'b'}, {2, 'c'}, {2, 'd'}, {1, 'a'}, {3, 'd'} });

	jh::BubbleSort(arr4);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr4[i]);
	}

	std::vector<jh::Dummy> arr5({ {3, 'd'}, {1, 'a'}, {2, 'b'}, {2, 'c'}, {2, 'd'} });

	jh::BubbleSort(arr5);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr5[i]);
	}

	std::vector<jh::Dummy> arr6({ {2, 'b'}, {2, 'c'}, {2, 'd'}, {3, 'd'}, {1, 'a'} });

	jh::BubbleSort(arr6);

	for (size_t i = 0; i < expected.size(); ++i)
	{
		assert(expected[i] == arr6[i]);
	}
}

int main()
{
	TestBubbleSortIntArray();
	TestBubbleSortEmptyArray();
	TestBubbleSortCharArray();
	TestBubbleSortStable();

	return 0;
}