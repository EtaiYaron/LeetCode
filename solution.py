class Solution(object):

    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        array = [[-1 for _ in range(n+1)] for _ in range(m+1)]
        array[1][1] = 1
        array[0][0] = 1
        array[1][0] = 1
        array[0][1] = 1
        self.uniquePaths(m, n, array)


    def uniquePaths(self, m, n, arr):
        """
        :type m: int
        :type n: int
        :rtype: int
        """

        if arr[m][n] != -1:
            return arr[m][n]
        elif m == 1:
            arr[m][n] = self.uniquePaths(m, n - 1)
            return arr[m][n]
        elif n == 1:
            arr[m][n] = self.uniquePaths(m - 1, n)
            return arr[m][n]
        else:
            arr[m][n] = self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)
            return arr[m][n]
