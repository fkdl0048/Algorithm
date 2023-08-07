using static System.Console;

namespace Beakjoon1018
{
    public class Pair<T1, T2>
    {
        public T1 First { get; private set; }
        public T2 Second { get; private set; }
        public Pair(T1 first, T2 second)
        {
            First = first;
            Second = second;
        }
    }

    public class ChessBoard
    {
        public int File {get; private set;}
        public int Rank {get; private set;}

        private char[,] ChessBoardArray;

        public ChessBoard(int file, int rank)
        {
            File = file;
            Rank = rank;

            ChessBoardArray = new char[file, rank];
        }

        public void AddRank(int file, string rank)
        {
            if (rank.Length != Rank)
            {
                throw new System.Exception("Rank length is not match");
            }

            for (int i = 0; i < rank.Length; i++)
            {
                ChessBoardArray[file, i] = rank[i];
            }
        }

        public int CheckMinFixedRealBoard()
        {
            int result = int.MaxValue;

            for (int i = 0; i <= File - 8; i++)
            {
                for (int j = 0; j <= Rank - 8; j++)
                {
                    int num = 0;
                    for (int x = i; x < i + 8; x++)
                    {
                        for (int y = j; y < j + 8; y++)
                        {
                            var c = (x + y) % 2 == 0 ? 'W' : 'B';
                            if (c != ChessBoardArray[x, y])
                            {
                                num++;
                            }
                        }
                    }
                    num = System.Math.Min(num, 64 - num);
                    result = System.Math.Min(result, num);
                }
            }

            return result;
        }

        public void Print()
        {
            for (int i = 0; i < File; i++)
            {
                for (int j = 0; j < Rank; j++)
                {
                    Write(ChessBoardArray[i, j]);
                }
                WriteLine();
            }
        }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            var input = Console.ReadLine()!.Split(' ');

            Pair<int, int> pair = new (int.Parse(input[0]), int.Parse(input[1]));

            ChessBoard chessBoard = new(pair.First, pair.Second);

            for (int i = 0; i < pair.First; i++)
            {
                chessBoard.AddRank(i, Console.ReadLine()!);
            }

            WriteLine(chessBoard.CheckMinFixedRealBoard());
        }
    }
}
