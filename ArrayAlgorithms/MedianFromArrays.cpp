#include <iostream>
#include <array>
#include<algorithm>


float Median(std::array<int, 10> arr, int length)
{
	if ((length % 2) != 0)
	{
		return arr[(length / 2)];
	}
	return ((arr[(length / 2)] + arr[(length / 2) - 1]) / 2);
}

void Med()
{
	const int ArrSize = 5;
	int A[ArrSize];
	int B[ArrSize];
	for (int i = 0; i < ArrSize; i++)
	{
		std::cin >> A[i];
	}
	for (int i = 0; i < ArrSize; i++)
	{
		std::cin >> B[i];
	}
	std::array <int, (ArrSize * 2)> C;
	for (int i = 0; i < ArrSize; i++)
	{
		C[i] = A[i];
		C[i + ArrSize] = B[i];
	}
	std::sort(C.begin(), C.end());
	float median = Median(C, (ArrSize * 2));
	std::cout << median;

}