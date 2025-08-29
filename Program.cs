public class Solution
{
    public bool CanJump(int[] nums)
    {
        int[] memo = new int[nums.Length];
        for (int i = 0; i < memo.Length; i++)
            memo[i] = -1;
        return CanJump(nums, 0, memo);
    }

    public bool CanJump(int[] nums, int i, int[] memo)
    {
        if (i >= nums.Length - 1)
            return true;
        if (i < 0 || i >= nums.Length)
            return false;
        if (memo[i] != -1)
            return (memo[i] > 0);
        int jump = nums[i];
        if (jump == 0)
            return false;
        bool ans = false;
        for (int j = 1; j <= jump && !ans; j++)
        {
            ans = CanJump(nums, i + j, memo);
        }
        if (ans)
            memo[i] = 1;
        else
            memo[i] = 0;
        return ans;
    }
}