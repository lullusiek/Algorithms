#include <iostream>

void Sort(int arr[], int length)
{
	for (int j = 0; j < length; j++)
	{
		for (int i = 0; i < (length - 1); i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temporary = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temporary;
			}
		}
	}
}

int NSmallestElementOfArray(int arr[], int length, int nElement)
{
	Sort(arr, length);
	return arr[(nElement - 1)];
}

void NSEOArray()
{
	const int ArrSize = 10;
	int arr[ArrSize];
	for (int i = 0; i < ArrSize; i++)
	{
		std::cin >> arr[i];
	}
	int n = 4;
	int nSmallestElementOfArray = NSmallestElementOfArray(arr, ArrSize, n);
	std::cout << nSmallestElementOfArray;
}