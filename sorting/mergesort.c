#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *arr, int left, int right, int pivot)
{
	int temp[BUFSIZ];
	int L = left;
	int R = pivot + 1;
	int n = left;

	while (L <= pivot && R <= right)
	{
		if (arr[L] <= arr[R])
		{
			temp[n] = arr[L];
			n++;
			L++;
		}
		else
		{
			temp[n] = arr[R];
			n++;
			R++;
		}
	}
	if (L > pivot)
	{
		for (int i = R; i <= right; i++)
		{
			temp[n] = arr[i];
			n++;
		}
	}
	else
	{
		for (int i = L; i <= pivot; i++)
		{
			temp[n] = arr[i];
			n++;
		}
	}
	for(int i = left; i <= right; i++)
		arr[i] = temp[i];
}

void merge_sort(int *arr, int left, int right)
{
	int pivot = (left + right) / 2;
	if (left < right)
	{
		merge_sort(arr, left, pivot);
		merge_sort(arr, pivot + 1, right);
		printf("%d %d %d\n", left, right, pivot);
		merge(arr, left, right, pivot);
	}
}

int main()
{
	int arr[] = {80, 50, 70, 10, 60, 20, 40, 30};

	merge_sort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}