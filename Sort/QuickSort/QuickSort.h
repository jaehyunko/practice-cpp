#pragma once

#include <stack>
#include <vector>

namespace jh
{
	template <typename T>
	void QuickSortIterative(std::vector<T>& arr)
	{
		std::stack<size_t> stack;

		stack.push(0);
		stack.push(arr.size());

		while (!stack.empty())
		{
			size_t endIndex = stack.top();
			stack.pop();

			size_t beginIndex = stack.top();
			stack.pop();

			if (beginIndex >= endIndex)
			{
				continue;
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

			stack.push(beginIndex);
			stack.push(leftEndIndex);

			stack.push(leftEndIndex + 1);
			stack.push(endIndex);
		}
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