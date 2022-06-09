#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void radix_sort(int arr[], int size)
{
	int temp[BUFSIZ];
	int j = 0;

	for(int i = 0; i < BUFSIZ; i++)
		temp[i] = -1;
	for(int i = 0; i < size; i++)
		temp[arr[i]] = arr[i];
	for(int i = 0; i < BUFSIZ; i++)
	{
		if(temp[i] != -1)
		{
			arr[j] = temp[i];
			j++;
		}
	}
}

int main()
{
	int arr[] = {80, 50, 70, 10, 60, 20, 40, 30};

	radix_sort(arr, sizeof(arr) / sizeof(int));

	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}