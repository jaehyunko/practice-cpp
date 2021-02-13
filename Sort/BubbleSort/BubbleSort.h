#pragma once

#include <vector>

namespace jh
{
	template <typename T>
	void BubbleSort(std::vector<T>& arr, bool (*compare)(const T&, const T&))
	{
		if (arr.size() == 0)
		{
			return;
		}

		for (size_t i = arr.size() - 1; i > 0; --i)
		{
			for (size_t j = 0; j < i; ++j)
			{
				if (compare(arr[j + 1], arr[j]))
				{
					T temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	template <typename T>
	void BubbleSort(std::vector<T>& arr)
	{
		if (arr.size() == 0)
		{
			return;
		}

		for (size_t i = arr.size() - 1; i > 0; --i)
		{
			for (size_t j = 0; j < i; ++j)
			{
				if (arr[j] > arr[j + 1])
				{
					T temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}