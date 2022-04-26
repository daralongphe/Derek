#include <iostream>
using namespace std;

template <class elemType>
void swap(elemType list[], int first, int second)
{
	elemType temp;

	temp = list[first];
	list[first] = list[second];
	list[second] = temp;
} //end swap

template <class elemType>
void quickSort_mid(elemType list[], int first, int last)
{
	//declaring and initialize variables
	int left = first;
	int right = last;
	if (left >= right)
		return;
	elemType pivot = list[(first + last) / 2];
	//Partitioning
	while (left <= right)
	{
		while (list[left] < pivot)
			left++;
		while (list[right] > pivot)
			right--;
		if (left <= right)
		{
			swap(list, left, right);
			left++;
			right--;
		}
	}
	//Recurring the process
	quickSort_mid(list, first, right);
	quickSort_mid(list, left, last);
}

template <class elemType>
void quickSort_b(elemType list[], int first, int last)
{
	//declaring and initialize variables
	int left = first;
	int right = last;
	if (left >= right)
		return;
	elemType pivot = list[(left + ((left + right) / 2) + right) / 3];
	//Partitioning
	while (left <= right)
	{
		while (list[left] < pivot)
			left++;
		while (list[right] > pivot)
			right--;
		if (left <= right)
		{
			swap(list, left, right);
			left++;
			right--;
		}
	}
	//Recurring the process
	quickSort_b(list, first, right);
	quickSort_b(list, left, last);
}

template <class elemType>
void insertionSort(elemType list[], int length)
{
	for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
	{
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
		{
			elemType temp = list[firstOutOfOrder];
			int location = firstOutOfOrder;

			do
			{
				list[location] = list[location - 1];
				location--;
			} while (location > 0 && list[location - 1] > temp);

			list[location] = temp;
		}
	}
} //end insertionSort

template <class elemType>
void quickSort_c(elemType list[], int first, int last)
{
	//declaring and initialize variables
	int left = first;
	int right = last;
	if (left >= right)
		return;
	if ((right - left) < 20)
	{
		insertionSort(list, (right - left));
	}
	elemType pivot = list[(first + last) / 2];
	//Partitioning
	while (left <= right)
	{
		while (list[left] < pivot)
			left++;
		while (list[right] > pivot)
			right--;
		if (left <= right)
		{
			swap(list, left, right);
			left++;
			right--;
		}
	}
	//Recurring the process
	quickSort_mid(list, first, right);
	quickSort_mid(list, left, last);
}

template <class elemType>
void quickSort_d(elemType list[], int first, int last)
{
	//declaring and initialize variables
	int left = first;
	int right = last;
	if (left >= right)
		return;
	if ((right - left) < 20)
	{
		insertionSort(list, (right - left));
	}
	elemType pivot = list[(left + ((left + right) / 2) + right) / 3];
	//Partitioning
	while (left <= right)
	{
		while (list[left] < pivot)
			left++;
		while (list[right] > pivot)
			right--;
		if (left <= right)
		{
			swap(list, left, right);
			left++;
			right--;
		}
	}
	//Recurring the process
	quickSort_mid(list, first, right);
	quickSort_mid(list, left, last);
}