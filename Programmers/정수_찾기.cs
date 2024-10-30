using System;

public class Solution
{
    public int Solution(int[] num_list, int n)
    {
        return num_list.Contains(n) ? 1 : 0;
    }
}