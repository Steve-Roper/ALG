#pragma once
#include <thread>
#include "SortCPU.h"
#include "stdafx.h"
#include "mutex"

#define AVAILABLETHREADS std::thread::hardware_concurrency();

namespace sort
{
	class CPUThreaded
	{
	public:
		CPUThreaded() {};
		~CPUThreaded() {};

		static void Initialize(int threadsInConstantUse = 0) {
			s_uiThreadsUsed = threadsInConstantUse;
			s_uiThreadsAvailable = std::thread::hardware_concurrency() - s_uiThreadsUsed;
			s_vThreads.reserve(s_uiThreadsAvailable);
			s_ppMutexes = new std::mutex*;
			for (unsigned int i = 0; i < s_uiThreadsAvailable; ++i)
			{
				s_ppMutexes[i] = new std::mutex();
			}
		};

		static void Destroy() {
			delete[] s_ppMutexes;
		}

		template<typename Comparable, typename CompareFunc = std::less<Comparable>>
		static void BubbleSort(std::vector<Comparable> &dataset, CompareFunc cmpf = CompareFunc());

	private:
		static unsigned int s_uiThreadsAvailable;
		static unsigned int s_uiThreadsUsed;
		static std::vector<std::thread> s_vThreads;
		static std::mutex** s_ppMutexes;

		template<typename iterator, typename CompareFunc>
		static void ThreadBubbleSort(iterator begin, iterator end, int mutexIndex, CompareFunc cmpf);
	};

	unsigned int CPUThreaded::s_uiThreadsAvailable;
	unsigned int CPUThreaded::s_uiThreadsUsed;
	std::vector<std::thread> CPUThreaded::s_vThreads;
	std::mutex** CPUThreaded::s_ppMutexes;

	template<typename Comparable, typename CompareFunc>
	inline void CPUThreaded::BubbleSort(std::vector<Comparable> &dataset, CompareFunc cmpf)
	{
		int step = dataset.size() / s_uiThreadsAvailable + 1; //the +1 ensures that all items are sortet and the last thread to be executed is the shortest, if there is any discrepancies in partition sizes
		std::vector<Comparable>::iterator startSort = dataset.begin();
		//bubble sort x partitions
		for (unsigned int i = 0; i < s_uiThreadsAvailable - 1; ++i)
		{
			std::vector<Comparable>::iterator endSort = startSort + step + 1;
			s_vThreads.push_back(std::thread([&]() { CPUThreaded::ThreadBubbleSort<std::vector<Comparable>::iterator>(startSort, endSort, i, cmpf); }));
			std::advance(startSort, step);
		}
		s_vThreads.push_back(std::thread([&]() { CPUThreaded::ThreadBubbleSort<std::vector<Comparable>::iterator>(startSort, dataset.end(), s_uiThreadsAvailable - 1, cmpf); }));

		//join threads
		for (unsigned int i = 0; i < s_uiThreadsAvailable; ++i)
		{
			s_vThreads[i].join();
		}
		s_vThreads.clear();

		//merge sort partitions
		CPU::MergeSort(dataset.begin(), dataset.end(), cmpf);
	}

	template<typename iterator, typename CompareFunc>
	inline void CPUThreaded::ThreadBubbleSort(iterator begin, iterator end, int mutexIndex, CompareFunc cmpf)
	{
		s_ppMutexes[mutexIndex]->lock();
		iterator sorting = begin;
		s_ppMutexes[mutexIndex]->unlock();
		for (sorting; sorting != end; ++sorting)
		{
			iterator compareTo;
			iterator least = sorting;
			for (compareTo = sorting + 1; compareTo != end; ++compareTo)
				if (cmpf(*compareTo, *least))
					least = compareTo;
			sort::swap<iterator, iterator::value_type>(sorting, least);
		}
	}
}