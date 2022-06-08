#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quicksort(int arr[], int left, int right)
{
	int L = left, R = right;
	int pivot = arr[(left + right) / 2];
	while (L <= R)
	{
		while(arr[L] < pivot)
			L += 1;
		while(arr[R] > pivot)
			R -= 1;
		if (L <= R)
		{
			int temp = 0;
			temp = arr[L];
			arr[L] = arr[R];
			arr[R] = temp;
			L += 1;
			R -= 1;
		}
	}
	if (left < R)
		quicksort(arr, left, R);
	if (L < right)
		quicksort(arr, L, right);
}

// int main()
// {
// 	int arr[] = {80, 50, 70, 10, 60, 20, 40, 30};

// 	quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);

// 	for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// 	return 0;
// }