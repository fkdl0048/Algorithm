namespace baekjoon_1259
{
    public class Palindrome
    {
        public bool IsPalindrome(string str)
        {
            int len = str.Length;
            for (int i = 0; i < len / 2; i++)
            {
                if (str[i] != str[len - i - 1])
                    return false;
            }
            return true;
        }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            Palindrome palindrome = new Palindrome();
            while (true)
            {
                string str = System.Console.ReadLine();
                if (str == "0")
                    break;
                if (palindrome.IsPalindrome(str))
                    System.Console.WriteLine("yes");
                else
                    System.Console.WriteLine("no");
            }
        }
    }
}