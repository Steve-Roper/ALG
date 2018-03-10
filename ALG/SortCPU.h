#pragma once
#include "stdafx.h"
#include <algorithm>

namespace sort
{
	template<typename iterator, typename Comparable>
	void swap(iterator first, iterator second)
	{
		Comparable temp = *first;
		*first = *second;
		*second = temp;
	}

	class CPU
	{
	public:
		template<typename iterator, typename CompareFunc = std::less<typename std::iterator_traits<iterator>::value_type>>
		static void BubbleSort(iterator begin, iterator end, CompareFunc cmpf = CompareFunc());
		template<typename iterator, typename CompareFunc = std::less<typename std::iterator_traits<iterator>::value_type>>
		static void MergeSort(iterator begin, iterator end, CompareFunc cmpf = CompareFunc());

	private:
		CPU() {};
		~CPU() {};
	};

	template<typename iterator, typename CompareFunc>
	inline void CPU::BubbleSort(iterator begin, iterator end, CompareFunc cmpf)
	{
		iterator sorting = begin;
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

	template<typename iterator, typename CompareFunc>
	inline void CPU::MergeSort(iterator begin, iterator end, CompareFunc cmpf)
	{
		if (std::distance(begin, end) < 2) return;
		iterator middle = begin + std::distance(begin, end) / 2;
		MergeSort(begin, middle, cmpf);
		MergeSort(middle, end, cmpf);
		std::inplace_merge(begin, middle, end, cmpf); //TODO: replace with my own impl.
	}

}