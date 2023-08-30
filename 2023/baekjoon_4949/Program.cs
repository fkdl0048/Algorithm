namespace baekjoon_4949
{
    public class ValidStringReader
    {
        private char[] brackets;

        public bool Read(string input)
        {
            brackets = new char[100];

            int index = 0;
            foreach (var c in input)
            {
                if (c == '(' || c == '[')
                {
                    brackets[index++] = c;
                }
                else if (c == ')')
                {
                    if (index == 0 || brackets[--index] != '(')
                    {
                        return false;
                    }
                }
                else if (c == ']')
                {
                    if (index == 0 || brackets[--index] != '[')
                    {
                        return false;
                    }
                }
            }

            return index == 0;
        }
    }   

    public class Program
    {
        public static void Main(string[] args)
        {
            var reader = new ValidStringReader();
            while (true)
            {
                var input = System.Console.ReadLine();
                if (input == ".")
                {
                    break;
                }

                System.Console.WriteLine(reader.Read(input) ? "yes" : "no");
            }
        }
    }
}