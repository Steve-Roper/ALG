#pragma once
#include "SortingAlgorithms.h"
using namespace Sort;

class CPUMultiThreadSortingAlgorithms : public SortingAlgorithms
{
public:
	CPUMultiThreadSortingAlgorithms() : SortingAlgorithms() {};
	~CPUMultiThreadSortingAlgorithms() {};
	static void Initialize();

	template<typename Comparable>
	static void BubbleSort(std::vector<Comparable> dataset);
	template<typename Comparable>
	static void OddEvenSort(std::vector<Comparable> dataset);
private:
	static unsigned int m_iThreads;
};