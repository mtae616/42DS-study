#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heap(int *arr, int size){
	for(int i = 1; i < size; i++){
		int child = i;
        while(child > 0)
		{
            int root = (child - 1) / 2;
            if(arr[root] < arr[child])
			{
                int temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
            }
            child = root;
        }
    }
}


int main()
{
	int arr[] = {80, 50, 70, 10, 60, 20, 40, 30};
	int size = sizeof(arr) / sizeof(int);
	heap(arr, size);

	for(int i = size - 1; i >= 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heap(arr, i);
	}
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}