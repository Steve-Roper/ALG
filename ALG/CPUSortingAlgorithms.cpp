#include "CPUSortingAlgorithms.h"

template<class Comparable>
void swap(std::vector<Comparable> dataset, int i, int j)
{
	Comparable temp = dataset[i];
	dataset[i] = dataset[j];
	dataset[j] = temp;
}

template<class Comparable>
void CPUSortingAlgorithms<Comparable>::BubbleSort(std::vector<Comparable> dataset)
{
	for (int i = 0; i < dataset.size(); ++i)
	{
		for (int j = 0; j < dataset.size() - i; ++j)
		{
			if (dataset[i] > dataset[j] && i < j)
			{
				swap(dataset, i, j);
			}
		}
	}
}

template<class Comparable>
void CPUSortingAlgorithms<Comparable>::OddEvenSort(std::vector<Comparable> dataset)
{
	int i = 0;
	bool swap = false;
	while(true)
	{
		for (; i < dataset.size() - 1; ++i)
		{
			if (dataset[i] > dataset[i + 1])
			{
				swap(dataset, i, i + 1);
				swap = true;
			}
		}
		if (!swap)
		{
			break;
		}
		i = !i;
	}
}
