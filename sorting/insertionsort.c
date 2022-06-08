#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionsort(int arr[], int size)
{	
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int prev = i - 1;
		while (arr[prev] > temp)
		{
			arr[prev + 1] = arr[prev];
			prev--;
		}
		arr[prev + 1] = temp;
	}
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// int main()
// {
// 	int arr[] = {80, 50, 70, 10, 60, 20, 40, 30};

// 	insertionsort(arr, sizeof(arr) / sizeof(int));

// 	return 0;
// }