#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionforshell(int arr[], int first, int last, int gap)
{
	for (int i = first + gap; i <= last; i += gap)
	{
		int temp = arr[i];
		int j = i - gap;
		while (j >= first && arr[j] > temp)
		{
			arr[j + gap] = arr[j];
			j -= gap;
		}
		arr[j + gap] = temp;
	}
}

void shellsort(int arr[], int size)
{
	int gap;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for(int i = 0; i < gap; i++)
			insertionforshell(arr, i, size - 1, gap);
	}
}

int main()
{
	int arr[] = {80, 50, 70, 10, 60, 20, 40, 30};
	shellsort(arr, sizeof(arr) / sizeof(int));

	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}