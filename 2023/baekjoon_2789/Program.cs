namespace baekjoon_2789
{
    public class Dealer
    {
        private int drawCardInt;
        private List<int> drawCardList = new List<int>();

        public Dealer(int _drawCardInt)
        {
            this.drawCardInt = _drawCardInt;
        }

        public void DrawCard()
        {
            var input = Console.ReadLine()!.Split(' ');

            if (drawCardInt != input.Length)
                throw new Exception("drawCardInt != input.Length");

            for (int i = 0; i < this.drawCardInt; i++)
            {
                this.drawCardList.Add(int.Parse(input[i]));
            }
        }

        public List<int> GetCardLit()
        {
            return this.drawCardList;
        }
    }

    public class Player
    {
        private int GoalCardSum;

        public Player(int _GoalCardSum)
        {
            this.GoalCardSum = _GoalCardSum;
        }

        public int Solution(List<int> cardList)
        {
            int result = 0;

            for (int i = 0; i < cardList.Count; i++)
            {
                for (int j = i + 1; j < cardList.Count; j++)
                {
                    for (int k = j + 1; k < cardList.Count; k++)
                    {
                        int sum = cardList[i] + cardList[j] + cardList[k];

                        if (sum <= this.GoalCardSum)
                        {
                            result = Math.Max(result, sum);
                        }
                    }
                }
            }

            return result;
        }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            var input = Console.ReadLine()!.Split(' ');

            Dealer dealer = new Dealer(int.Parse(input[0]));
            Player player = new Player(int.Parse(input[1]));

            dealer.DrawCard();

            Console.WriteLine(player.Solution(dealer.GetCardLit()));
        }
    }
}