#include "CPUMultiThreadSortingAlgorithms.h"
#include <thread>
#include <iostream>

unsigned int CPUMultiThreadSortingAlgorithms::m_iThreads = 1;

template<typename Comparable>
inline void CPUMultiThreadSortingAlgorithms::BubbleSort(std::vector<Comparable> dataset)
{

}

void CPUMultiThreadSortingAlgorithms::Initialize()
{
	m_iThreads = std::thread::hardware_concurrency();
#ifdef DEBUG
	std::cout << m_iThreads << std::endl;
#endif
}
