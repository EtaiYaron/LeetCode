using System;

public class Solution
{
    public static void Main(string[] args)
    {
        string s = "0P";
        Console.WriteLine(isPalindrome("A man, a plan, a canal: Panama"));
    }


    public static bool isPalindrome(string s)
    {
        s = s.ToLower();
        string s1 = "";
        for (int i = 0; i < s.Length; i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                s1 += s[i];
            continue;
        }
        while (s1.Length != 0)
        {
            if (s1.Length == 1)
                return true;
            if (s1[0] != s1[s1.Length - 1])
                return false;
            s1 = s1.Substring(1,s1.Length-2);
        }
        return true;
    }
}