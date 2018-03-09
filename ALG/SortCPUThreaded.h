#pragma once
#include <thread>
#include "SortCPU.h"

namespace sort
{
	class CPUThreaded
	{
	public:
		CPUThreaded() {};
		~CPUThreaded() {};

		template<typename iterator>
		static void BubbleSort(iterator begin, iterator end);

	private:
		static unsigned int m_uiThreadsAvailable;
		static unsigned int m_uiThreadsUsed;
	};
	template<typename iterator>
	inline void CPUThreaded::BubbleSort(iterator begin, iterator end)
	{
		//bubble sort x partitions
		//join threads
		//merge sort partitions
	}
}