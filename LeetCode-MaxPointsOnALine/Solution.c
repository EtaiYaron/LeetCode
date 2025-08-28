#include <stdio.h>

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
	if (pointsSize <= 2) return pointsSize;
	int max = 0;
	int i, j, k;
	for (k = 0; k < pointsSize; k++)
	{
		for (i = 0; i < pointsSize; i++)
		{
			int isverticalline = 0;
			int x = 0;
			float m = 0;
			if (points[i][0] == points[k][0])
			{
				isverticalline = 1;
				x = points[i][0];
			}
			else
			{
				m = (float)(points[i][1] - points[k][1]) / (points[i][0] - points[k][0]);
			}
			int cnt = 0;
			for (j = 0; j < pointsSize; j++)
			{
				if (isverticalline == 1)
				{
					if (x == points[j][0])
					{
						cnt++;
					}
				}
				else if ((points[i][0] == points[j][0] && points[i][1] == points[j][1]) || (points[i][0] != points[j][0] && m == (float)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0])))
				{
					cnt++;
				}
			}
			if (cnt > max)
			{
				max = cnt;
			}
		}
	}
	return max;
}

int main() {
	printf("Test case 1:\n");
	int pointsSize = 6;
	int pointsColSize = 2;
	int* points[] = { (int[]) { 1, 1 },
		(int[]) {3, 2},
		(int[]) {5, 3},
		(int[]) {4, 1},
		(int[]) {2, 3},
		(int[]) {1, 4} 
	};
	int result = maxPoints(points, pointsSize, &pointsColSize);
	if (result == 4)
	{
		printf("Maximum points on a line is: %d test passed\n", result);
	}
	else
	{
		printf("Maximum points on a line: %d the test failed expected was 4\n", result);
	}
	
	

	printf("Test case 2:\n");
	pointsSize = 6;
	pointsColSize = 2;
	int* points1[] = { (int[]) { 1, 0},
		(int[]) {1, 2},
		(int[]) {1, 7},
		(int[]) {1, 1},
		(int[]) {1, 3},
		(int[]) {1, 4} 
	};
	result = maxPoints(points1, pointsSize, &pointsColSize);
	if (result == 6)
	{
		printf("Maximum points on a line is: %d test passed\n", result);
	}
	else
	{
		printf("Maximum points on a line: %d the test failed expected was 6 \n", result);
	}
	return 0;
}