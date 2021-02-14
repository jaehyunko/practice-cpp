#pragma once

#include <vector>

namespace jh
{
	void Foo()
	{

	}

	template <typename T>
	void QuickSortRecursive(std::vector<T>& arr, size_t beginIndex, size_t endIndex)
	{
		if (beginIndex >= endIndex)
		{
			return;
		}

		const T& pivot = arr[endIndex - 1];
		size_t leftEndIndex = beginIndex;

		for (size_t i = beginIndex; i < endIndex; ++i)
		{
			if (arr[i] < pivot)
			{
				std::swap(arr[leftEndIndex], arr[i]);
				++leftEndIndex;
			}
		}

		std::swap(arr[leftEndIndex], arr[endIndex - 1]);

		QuickSortRecursive(arr, beginIndex, leftEndIndex);
		QuickSortRecursive(arr, leftEndIndex + 1, endIndex);
	}

	template <typename T>
	void QuickSortRecursive(std::vector<T>& arr)
	{
		QuickSortRecursive(arr, 0, arr.size());
	}
}