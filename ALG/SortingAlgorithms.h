#pragma once
#include <vector>
namespace Sort
{
	class SortingAlgorithms
	{
	public:
		SortingAlgorithms() {};
		~SortingAlgorithms() {};

		template<typename Comparable>
		virtual void BubbleSort(std::vector<Comparable> data) = 0;
		template<typename Comparable>
		virtual void OddEvenSort(std::vector<Comparable> data) = 0;
	};
}