using System;

public class Example
{
    public static void Main()
    {
        String[] s;

        Console.Clear();
        s = Console.ReadLine().Split(' ');

        int a = Int32.Parse(s[0]);
        
        Console.Write(a);
        if (a % 2 == 0)
        {
            Console.WriteLine(" is even");
        }
        else
        {
            Console.WriteLine(" is odd");
        }
    }
}