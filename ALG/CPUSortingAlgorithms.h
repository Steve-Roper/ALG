#pragma once
#include "SortingAlgorithms.h"
using namespace Sort;
class CPUSortingAlgorithms : public SortingAlgorithms
{
public:
	CPUSortingAlgorithms() {};
	~CPUSortingAlgorithms() {};

	template<typename Comparable>
	static void BubbleSort(std::vector<Comparable> dataset);
	template<typename Comparable>
	static void OddEvenSort(std::vector<Comparable> dataset);
private:
};
