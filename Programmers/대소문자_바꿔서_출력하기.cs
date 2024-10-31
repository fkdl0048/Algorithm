using System;

public class Example
{
    public static void Main()
    {
        String s;

        Console.Clear();
        s = Console.ReadLine();
        
        string result = "";
        foreach (char c in s) {
            if (char.IsUpper(c))
                result += char.ToLower(c);
            else
                result += char.ToUpper(c);
        }
        
        Console.WriteLine(result);
    }
}