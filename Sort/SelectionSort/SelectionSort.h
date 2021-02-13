#pragma once

#include <vector>

namespace jh
{
	template <typename T>
	void SelectionSort(std::vector<T>& arr)
	{
		if (arr.size() == 0)
		{
			return;
		}

		size_t minIndex;

		for (size_t i = 0; i < arr.size() - 1; ++i)
		{
			minIndex = i;

			for (size_t j = i + 1; j < arr.size(); ++j)
			{
				if (arr[j] < arr[minIndex])
				{
					minIndex = j;
				}
			}

			if (i != minIndex)
			{
				T temp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex] = temp;
			}
		}
	}
}