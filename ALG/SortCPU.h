#pragma once
#include "stdafx.h"

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
		template <typename iterator>
		static void BubbleSort(iterator begin, iterator end);
	private:
		CPU() {};
		~CPU() {};
	};

	template<typename iterator>
	inline void CPU::BubbleSort(iterator begin, iterator end)
	{
		iterator sorting = begin;

		while (sorting != end)
		{
			iterator compareTo = sorting + 1;
			iterator least = sorting;

			while (compareTo != end)
			{
				if (*least > *compareTo)
				{
					least = compareTo;
				}
				++compareTo;
			}
			sort::swap<iterator, iterator::value_type>(sorting, least);
			++sorting;
		}
	}
}