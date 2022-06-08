#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	bubblesort(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}	
}

// int main()
// {
// 	int arr[] = {80, 50, 70, 10, 60, 20, 40, 30};

// 	bubblesort(arr, sizeof(arr) / sizeof(int));
// 	for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// }