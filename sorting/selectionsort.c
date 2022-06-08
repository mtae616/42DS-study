#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void selectionsort(int arr[], int size)
{
	int temp = 0;

	for (int i = 0; i < size; i++)
	{
		int min = 999999999;
		int min_idx = 0;
		for(int j = i; j < size; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				min_idx = j;
			}
		}
		temp = arr[i];
		arr[min_idx] = temp;
		arr[i] = min;
	}
}

// int main()
// {
// 	int arr[] = {80, 50, 70, 10, 60, 20, 40, 30};

// 	selectionsort(arr, sizeof(arr) / sizeof(int));
// 	for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// 	return 0;
// }