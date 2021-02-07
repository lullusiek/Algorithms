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


void BSearch()
{
	const int ArrSize = 10;
	int arr[ArrSize];
	int wanted = 100;
	for (int i = 0; i < ArrSize; i++)
	{
		std::cin >> arr[i];
	}
	std::cout << BinarySearch(arr, ArrSize, wanted);

}