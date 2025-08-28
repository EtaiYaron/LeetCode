
#include <climits>

class Solution {
public:
    int reverse(int x) {
        if (x >= INT_MAX || x <= INT_MIN)
            return 0;
        int magicnum = 10;
        int base = 0;
        bool ispos = (x > 0);
        if (!ispos)
            x *= -1;
        int tmp = x;
        while (tmp != 0) {
            tmp /= magicnum;
            if (base == 0)
                base = 1;
            else
                base *= magicnum;
        }
        if (base == 0)
            base += 1;
        int ans = 0;
        bool equal = (INT_MAX / base < 10);
        while (x != 0)
        {
            if ((x % 10 > INT_MAX / base && equal) || ans > INT_MAX - ((x % 10) * base))
                return 0;
            if (INT_MAX / base > x % 10)
                equal = false;
            ans += ((x % 10) * base);
            base /= 10;
            x /= 10;
        }
        if (ispos)
            return ans;
        return ans * -1;
    }
};
