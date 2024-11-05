using System;

public class Example
{
    public static void Main()
    {
        String s;

        Console.Clear();
        s = Console.ReadLine();
        
        foreach(char c in s)
        {
            Console.WriteLine(c);
        }
    }
}