using System;

Console.OutputEncoding = System.Text.Encoding.UTF8;

string input;
string menu = "(1)商品列表 (2)新增至購物車 (3)自購物車刪除 (4)查看購物車 (5)結帳 (6)轉換幣值 (7)退出網站\n輸入數字選擇功能 : ";
string list = "列表:\n商品名稱 商品單價\n(1)潛水相機防丟繩 (TWD)199\n(2)潛水配重帶 (TWD)460\n(3)潛水作業指北針 (TWD)1100\n";
string listt = "(1)潛水相機防丟繩 (2)潛水配重帶 (3)潛水作業指北針\n輸入數字選擇商品 : ";
string resubmit = "輸入錯誤!請重新輸入!\n";
int[] cart = new int[4];
double[] currency = new double[5]{0,1,0.031,0.23,4.59};
string[] coin = new string[5] { "", "TWD", "USD", "CNY", "JPY" };
int option = 0;
int nowcurr = 1;
while (true)
{
    Console.Write(menu);
    input = Console.ReadLine();
    option = int.Parse(input);
    if (option > 7 || option < 1)
    {
        Console.WriteLine(resubmit);
        continue;
    }
    else
    {
        if (option == 1)
        {
            Console.WriteLine(list);
        }
        if (option == 2)
        {
            Console.Write(listt);
            input = Console.ReadLine();
            int item = int.Parse(input);
            Console.Write("輸入數量 : ");
            input = Console.ReadLine();
            int quantity = int.Parse(input);
            cart[item] += quantity;
            Console.Write("\n");
            continue;
        }
        if (option == 3)
        {
            Console.Write(string.Format("購物車內容:\n商品 單價 數量 小計\n(1)潛水相機防丟繩 ({0}){1} {2} {3}\n(2)潛水配重帶 ({4}){5} {6} {7}\n(3)潛水作業指北針 ({8}){9} {10} {11}\n輸入數字選擇商品 : "
                , coin[nowcurr], 199 * currency[nowcurr], cart[1], cart[1] * 199 * currency[nowcurr], coin[nowcurr], 460 * currency[nowcurr], cart[2], cart[2] * 460 * currency[nowcurr], coin[nowcurr], 1100 * currency[nowcurr], cart[3], cart[3] * 1100 * currency[nowcurr]));
            input = Console.ReadLine();
            int item = int.Parse(input);
            if (item > 3 || item < 1)
            {
                Console.WriteLine(resubmit);
                continue;
            }
            Console.Write("輸入數量 : ");
            input = Console.ReadLine();
            int quantity = int.Parse(input);
            cart[item] -= quantity;
            Console.Write("成功刪除商品!\n\n");
            continue;
        }
        if (option == 4)
        {
            Console.Write(string.Format("購物車內容:\n商品 單價 數量 小計\n(1)潛水相機防丟繩 ({0}){1} {2} {3}\n(2)潛水配重帶 ({4}){5} {6} {7}\n(3)潛水作業指北針 ({8}){9} {10} {11}\n輸入數字選擇商品 : "
                , coin[nowcurr],199 * currency[nowcurr], cart[1], cart[1] * 199 * currency[nowcurr], coin[nowcurr], 460 * currency[nowcurr], cart[2], cart[2] * 460 * currency[nowcurr], coin[nowcurr], 1100 * currency[nowcurr], cart[3], cart[3] * 1100 * currency[nowcurr]));

            continue;
        }
        if (option == 5)
        {
            Console.Write("訂單商品:\n商品 單價 數量 小計\n");
            if (cart[1] > 0)
                Console.Write(string.Format("(1)潛水相機防丟繩 ({0}){1} {2} {3}\n", coin[nowcurr], 199 * currency[nowcurr], cart[1], cart[1] * 199 * currency[nowcurr]));
            if (cart[2] > 0)
                Console.Write(string.Format("(2)潛水配重帶 ({0}){1} {2} {3}\n", coin[nowcurr], 460 * currency[nowcurr], cart[2], cart[2] * 460 * currency[nowcurr]));
            if (cart[3] > 0)
                Console.Write(string.Format("(3)潛水作業指北針 ({0}){1} {2} {3}\n", coin[nowcurr], 1100 * currency[nowcurr], cart[3], cart[3] * 1100 * currency[nowcurr]));
            int total = cart[1] * 199 + cart[2] * 460 + cart[3] * 1100;
            Console.Write("總價 = {0}\n*是否要結帳(Y/N)*:", total* currency[nowcurr]); 
            
            input = Console.ReadLine();
            if(input == "N")
            {
                Console.Write("\n");
                continue;
            }
            if (input != "Y" && input != "N")
            {
                Console.WriteLine(resubmit);
                continue;
            }
            if (cart[1]>1|| cart[2] > 2|| cart[3] > 1)
            {
                if (cart[1] >1)
                    Console.WriteLine("潛水相機防丟繩庫存不足!剩餘數量1!");
                if (cart[2] > 2)
                    Console.WriteLine("潛水配重帶庫存不足!剩餘數量2!");
                if (cart[3] > 1)
                    Console.WriteLine("潛水作業指北針庫存不足!剩餘數量1!");
                Console.Write("\n");
                continue;
            }
            Console.Write("*選擇結帳方式(1.線上支付2.貨到付款):");
            input = Console.ReadLine();
            
            if(input != "1" && input != "2")
            {
                Console.WriteLine(resubmit);
                continue;
            }
            Console.Write("*折扣碼(若無折扣碼則輸入N):");
            string voucher= Console.ReadLine();
            
            if (voucher != "N" && voucher != "1111")
            {
                Console.WriteLine(resubmit);
                continue;
            }
            Console.Write("訂單狀態:\n商品 單價 數量 小計\n");
            if (cart[1] > 0)
                Console.Write(string.Format("(1)潛水相機防丟繩 ({0}){1} {2} {3}\n", coin[nowcurr], 199 * currency[nowcurr], cart[1], cart[1] * 199 * currency[nowcurr]));
            if (cart[2] > 0)
                Console.Write(string.Format("(1)潛水相機防丟繩 ({0}){1} {2} {3}\n", coin[nowcurr], 460 * currency[nowcurr], cart[2], cart[2] * 460 * currency[nowcurr]));
            if (cart[3] > 0)
                Console.Write(string.Format("(1)潛水相機防丟繩 ({0}){1} {2} {3}\n", coin[nowcurr], 1100 * currency[nowcurr], cart[3], cart[3] * 1100 * currency[nowcurr]));
            if (input == "1")
            {   
                Console.Write("總價 = {0}\n",total* currency[nowcurr]);
                if(voucher == "1111")
                    Console.Write("總價(折扣後) = {0}\n", total*0.95* currency[nowcurr]);
                Console.WriteLine("狀態:已付款\n");
            }

            if (input == "2")
            {
                Console.Write("總價 = {0}\n", total* currency[nowcurr]);
                if (voucher == "1111")
                    Console.Write("總價(折扣後) = {0}\n", total * 0.95*currency[nowcurr]);
                Console.WriteLine("狀態:尚未付款\n");
            }

        }
        if (option == 6)
        {
            Console.Write("選擇貨幣 1.TWD 2.USD 3.CNY 4.JPY :");
            nowcurr = int.Parse(Console.ReadLine());
            continue;
        }
        if (option == 7)
        {
            System.Environment.Exit(0);
        }
    }

}
