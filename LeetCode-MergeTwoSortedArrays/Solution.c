#include <stdio.h>  
#include <stdlib.h>  

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int* mergedarr = (int*)malloc((m+n) * sizeof(int));
	if (!mergedarr) return;
	for (int i = 0; i < m+n; i++)
	{
		mergedarr[i] = 0;
	}
	int i = 0;
	int j = 0;
	for (int k = 0; k < m+n; k++)
	{
		if (i < m && j < n)
		{
			if (nums1[i] < nums2[j])
			{
				mergedarr[k] = nums1[i];
				i++;
			}
			else
			{
				mergedarr[k] = nums2[j];
				j++;
			}
		}
		else if (i < m)
		{
			mergedarr[k] = nums1[i];
			i++;
		}
		else
		{
			mergedarr[k] = nums2[j];
			j++;
		}
	}
	for (int k = 0; k < m + n; k++)
	{
		nums1[k] = mergedarr[k];
	}
}

int main() {
	int arr[6] = {1, 2, 3, 0, 0, 0};
	int size_of_arr = 6;
	int m = 3;
	int arr2[] = { 2, 5, 6 };
	int size_of_arr2 = 3;
	int n = 3;
	merge(arr, size_of_arr, m, arr2, size_of_arr2, n);
	int expected[] = { 1, 2, 2, 3, 5, 6 };
	for (int i = 0; i < size_of_arr; i++)
	{
		if (arr[i] != expected[i])
		{
			printf("Test failed int place %d expected was: %d, but the actual was %d\n", i, expected[i], arr[i]);
			return 0;
		}
	}
	printf("Test passed\n");
	return 0;
}


