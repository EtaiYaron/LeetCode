#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int countPrimes(int n) {
    if (n <= 2)
        return 0;
    int cnt = 0;
	int* arr = (int *)malloc(n* sizeof (int));
	if (arr == NULL) {
		return -1;
	}
	for (int i = 0; i < n; i++) {
		if (i < 2)
		{
			arr[i] = 0;
		}
		else
			arr[i] = i;
	}
    for (int i = 2; i < 3; i++) {
		for (int j = 0; j < n; j += i)
		{
			if (j != i)
			{
				arr[j] = 0;
			}
		}
    }
	for (int i = 3; i < n; i+= 2) {
		if (arr[i] != 0)
		{

			for (int j = 0; j < n; j += i)
			{
				if (j != i)
				{
					arr[j] = 0;
				}
			}
		}
	}
	for (int i = 2; i < n; i++) {
		if (arr[i] != 0)
		{
			cnt++;
		}
	}
	return cnt;
}