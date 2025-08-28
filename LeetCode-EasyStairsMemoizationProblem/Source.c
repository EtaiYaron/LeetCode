#include <stdio.h>

int climbStairs(int n) {
	int arr[46] = { 0 };
	arr[1] = 1;
	arr[2] = 2;
	return c(n, arr);
}

int c(int n, int arr[]) {

	if (arr[n] != 0) {
		return arr[n];
	}
	else {
		arr[n] = c(n - 1, arr) + c(n - 2, arr);
		return arr[n];
	}
}