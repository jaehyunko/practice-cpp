#pragma once

#include <stack>
#include <vector>

namespace jh
{
	void MergeSortRecursive(std::vector<int>& arr, size_t begin, size_t end)
	{
		if (end - begin <= 1) return;

		size_t mid = (begin + end) / 2;

		MergeSortRecursive(arr, begin, mid);
		MergeSortRecursive(arr, mid, end);

		std::vector<int> sorted;
		sorted.reserve(arr.size());

		size_t i = begin;
		size_t j = mid;

		while (i < mid && j < end)
		{
			if (arr[i] < arr[j])
			{
				sorted.push_back(arr[i++]);
			}
			else
			{
				sorted.push_back(arr[j++]);
			}
		}

		while (i < mid)
		{
			sorted.push_back(arr[i++]);
		}

		while (j < end)
		{
			sorted.push_back(arr[j++]);
		}

		std::copy(sorted.begin(), sorted.end(), arr.begin() + begin);
	}

	void MergeSortRecursive(std::vector<int>& arr)
	{
		MergeSortRecursive(arr, 0, arr.size());
	}
}