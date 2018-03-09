// ALG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CPUSortingAlgorithms.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main()
{
	srand(time(NULL));
	std::vector<int> data;

	for (int i = 0; i < 1000; ++i)
	{
		data.push_back(rand());
	}
	
	sort::CPU::BubbleSort(data.begin(), data.end());

	for (int i = 0; i < 1000; ++i)
	{
		std::cout << data[i] << '\t';
	}

	std::cin.get();

    return 0;
}

