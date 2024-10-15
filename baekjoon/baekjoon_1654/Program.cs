namespace baekjoon_1654
{
    public class Solution
    {
        private int lanLine;
        private int needLine;
        private int[] lanLines;

        public Solution(int lanLine, int needLine)
        {
            this.lanLine = lanLine;
            this.needLine = needLine;
        }

        public void ReadLenLines()
        {
            lanLines = new int[lanLine];
            for (int i = 0; i < lanLine; i++)
            {
                lanLines[i] = int.Parse(Console.ReadLine()!);
            }
        }

        public int GetLenLine()
        {
            long left = 1;
            long right = lanLines.Max();
            long mid = 0;
            long result = 0;

            while (left <= right)
            {
                mid = (left + right) / 2;
                long count = 0;
                foreach (var lan in lanLines)
                {
                    count += lan / mid;
                }

                if (count >= needLine)
                {
                    left = mid + 1;
                    result = Math.Max(result, mid);
                }
                else
                {
                    right = mid - 1;
                }
            }

            return (int)result;
        }

    }

    public class Program
    {
        public static void Main(string[] args)
        {
            var input = Console.ReadLine()!.Split(' ');

            Solution solution = new Solution(int.Parse(input[0]), int.Parse(input[1]));

            solution.ReadLenLines();
            System.Console.WriteLine(solution.GetLenLine());
        }
    }
}