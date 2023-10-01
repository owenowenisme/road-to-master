using System;
using System.Runtime.InteropServices;

class Program
{
    static int rows = 3; 
    static int cols = 9; 
    static int desiredTrueCount = 5; 
    static int restrictedRow = 1;
    static int restrictedCol = 2;
    static bool[,] board = new bool[30, 30];
    static int[,] map = new int[30, 30];
    static bool[,] opened = new bool[30, 30];
    static int round = 0;

    static void Main()
    { 
        Console.OutputEncoding = System.Text.Encoding.UTF8;

        Console.WriteLine("設定遊戲參數");
        Console.Write("輸入空間的大小:");
        string[] input = Console.ReadLine().Split(',');
        rows = int.Parse(input[0]);
        cols = int.Parse(input[1]);

        Console.Write("輸入鬼的數量:");
        desiredTrueCount = int.Parse(Console.ReadLine());
        if (desiredTrueCount >= rows * cols)
        {
            Console.WriteLine("遊戲參數錯誤!");
            Environment.Exit(0);
        }

        Console.Clear();

        Console.Write("   ");
        for (char c = 'A'; c < cols + 'A'; c++)
        {
            Console.Write(c + " ");
        }
        Console.WriteLine();
        for (int i = 1; i <= rows; i++)
        {
            Console.Write($"{i-1,-3}");
            for (int j = 1; j <= cols; j++)
            {
                Console.Write("_" + " ");
            }
            Console.WriteLine();
        }

        Console.Write("輸入要查看的位置:");
        input = Console.ReadLine().Split(',');
        int row = int.Parse(input[0])+1;
        int col = input[1][0] - 'A' + 1;
        Console.Clear();
        
        restrictedCol = col;
        restrictedRow = row;

        init(row,col);
        while(true)
        {
            Console.Write("輸入要查看的位置:");
            try
            {
                input = Console.ReadLine().Split(',');
                row = int.Parse(input[0]) + 1;
                col = input[1][0] - 'A' + 1;
                showmap(row, col);
            }
            catch (Exception e)
            {
                Console.WriteLine("無效的輸入，請再試一次");
                continue;
            }
        }
    }
    static void init(int row, int col)
    {
        board[restrictedRow, restrictedCol] = false;

        Random random = new Random();

        int currentTrueCount = 0;

        while (currentTrueCount < desiredTrueCount)
        {
            int rowIndex = random.Next(rows);

            int colIndex = random.Next(cols);

            rowIndex++;
            colIndex++;
            if (!board[rowIndex, colIndex] && (rowIndex != restrictedRow || colIndex != restrictedCol))
            {
                board[rowIndex, colIndex] = true;
                currentTrueCount++;
            }
        }

        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                for (int q = i - 1; q <= i + 1; q++)
                {
                    for (int w = j - 1; w <= j + 1; w++)
                    {
                        map[i, j] += (board[q, w]) ? 1 : 0;
                    }
                }
                if (board[i, j])
                    map[i, j] = -1;
            }
        }
        showmap(row, col);
    }
    static int showmap(int row , int col)
    {

        if (row < 1 || col < 1 || row >rows || col > cols || opened[row,col])
        {

            Console.WriteLine("無效的輸入，請再試一次");
            return 0;
        }
        opened[row,col] = true;
        Console.Clear();
        round++;
        Console.Write("   ");
        for (char c = 'A'; c < cols+'A'; c++)
        {
            Console.Write(c+" ");
        }
        Console.WriteLine();
        if (map[row, col] == -1|| round == rows * cols - desiredTrueCount)
        {
            for (int i = 1; i <= rows; i++)
            {
                Console.Write($"{i - 1,-3}");
                for (int j = 1; j <= cols; j++)
                {
                        Console.Write(((map[i, j]==-1) ? "X" : map[i,j]) + " ");            
                }
                Console.WriteLine();
            }
            if(map[row, col] == -1)
                Console.WriteLine("遊戲結束! 你被鬼抓到了");
            else
                Console.WriteLine("遊戲結束! 你成功躲避所有的鬼了");
            Environment.Exit(0);
        }
        for(int i = 1; i <= rows;i++)
        {
            Console.Write($"{i - 1,-3}");
            for (int j = 1; j <= cols ; j++)
            {
                    Console.Write(((opened[i, j]) ? map[i, j] : "_" )+ " ");   
            }
            Console.WriteLine();
        }
        return 0;
    }
}
