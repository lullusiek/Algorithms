#include <iostream>


static int BinarySearch(int arr[], int length, int wanted)
{
	int leftSide = 0;
	int rightSide = (length - 1);
	while (leftSide <= rightSide)
	{
		int middle = leftSide + (rightSide - leftSide) / 2;
		if (arr[middle] == wanted)
		{
			return middle;
		}
		if (arr[middle] < wanted)
		{
			leftSide = middle + 1;
		}
		else
		{
			rightSide = middle - 1;
		}
	}
	return -1;
}


int NumberOfOccurrences(int arr[], int length, int wanted)
{
	int numberOfOccurrences = 0;
	int index = BinarySearch(arr, length, wanted);
	if (index == -1)
	{
		return 0;
	}
	for (int i = index; i < length; i++)
	{
		if (arr[i] == wanted)
		{
			numberOfOccurrences++;
		}
		else
		{
			break;
		}
	}
	for (int i = (index - 1); i >= 0; i--)
	{
		if (arr[i] == wanted)
		{
			numberOfOccurrences++;
		}
		else
		{
			break;
		}
	}
	return numberOfOccurrences;
}


void NOOccurrences()
{
	const int ArrSize = 10;
	int arr[ArrSize];
	for (int i = 0; i < ArrSize; i++)
	{
		std::cin >> arr[i];
	}
	int wanted = 11;
	int number = NumberOfOccurrences(arr, ArrSize, wanted);
	std::cout << number;
}