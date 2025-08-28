public class Solution
{
    public int MyAtoi(string s)
    {
        while (s.Length > 0 && (s[0] == ' '))
        {
            s = s.Substring(1);
        }
        if (s.Length == 0)
            return 0;
        int sign;
        if (s[0] == '+' || s[0] == '-')
        {
            sign = s[0] == '-' ? -1 : 1;
            s = s.Substring(1);
            if (s.Length == 0) return 0;
        }
        else if (s.Length == 0 || s[0]  < '0' || s[0] > '9')
        {
            return 0;
        }
        else
        {
            sign = 1;
        }
        int result = 0;
        int b = 10;
        int i = 0;
        while (i < s.Length && s[i] >= '0' && s[i] <= '9')
        {            
            if (result > (int.MaxValue - (s[i] - '0')) / 10)
                return sign == 1 ? int.MaxValue : int.MinValue;
            result = result * b + (s[i] - '0');
            i++;
        }
        result *= sign;
        return result;
    }
}


class Program
{
    static void Main(string[] args)
    {
        Solution solution = new Solution();
        string input = "4193 with words";
        int result = solution.MyAtoi(input);
        Console.WriteLine(result); 
    }
}