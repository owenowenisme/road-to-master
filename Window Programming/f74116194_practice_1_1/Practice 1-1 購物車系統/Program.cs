Console.OutputEncoding = System.Text.Encoding.UTF8;

string input;
string menu = "(1)商品列表 (2)新增至購物車 (3)自購物車刪除 (4)查看購物車 (5)計算總金額 (6)退出網站\n輸入數字選擇功能 : ";
string list = "列表:\n商品名稱 商品單價\n(1)潛水相機防丟繩 (TWD)199\n(2)潛水配重帶 (TWD)460\n(3)潛水作業指北針 (TWD)1100\n";
string listt = "(1)潛水相機防丟繩 (2)潛水配重帶 (3)潛水作業指北針\n輸入數字選擇商品 : ";
string resubmit = "輸入錯誤!請重新輸入!\n";
int[] cart= new int[4];
int option = 0;
while (true && option != 6 )
{
    Console.Write(menu);
    input = Console.ReadLine();
    option = int.Parse(input);
    if(option> 6 || option < 1)
    {
        Console.WriteLine(resubmit);
        continue;
    }
    else
    {
        if (option == 1)
        {
            Console.WriteLine(list);
        }if(option == 2)
        {
            Console.Write(listt);
            input = Console.ReadLine();
            int item  = int.Parse(input);
            Console.Write("輸入數量 : ");
            input = Console.ReadLine();
            int quantity = int.Parse(input);
            cart[item] += quantity;
            Console.Write("\n");
            continue;
        }if(option == 3)
        {
            Console.Write(string.Format("購物車內容:\n商品 單價 數量 小計\n(1)潛水相機防丟繩 (TWD)199 {0} {1}\n(2)潛水配重帶 (TWD)460 {2} {3}\n(3)潛水作業指北針 (TWD)1100 {4} {5}\n輸入數字選擇商品 : "
                , cart[1], cart[1] * 199, cart[2], cart[2] * 460, cart[3], cart[3] * 1100));
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
            Console.Write(string.Format("購物車內容:\n商品 單價 數量 小計\n(1)潛水相機防丟繩 (TWD)199 {0} {1}\n(2)潛水配重帶 (TWD)460 {2} {3}\n(3)潛水作業指北針 (TWD)1100 {4} {5}\n\n"
                , cart[1], cart[1] * 199, cart[2], cart[2] * 460, cart[3], cart[3] * 1100));

            continue;
        }
        if (option == 5)
        {
            Console.Write("購物車內容:\n商品 單價 數量 小計\n");
            if (cart[1]>0)
                Console.Write("(1)潛水相機防丟繩 (TWD)199 {0} {1}\n", cart[1], cart[1] * 199);
            if (cart[2] > 0)
                Console.Write("(2)潛水配重帶 (TWD)460 {0} {1}\n", cart[2], cart[2] * 460);
            if (cart[3] > 0)
                Console.Write("(3)潛水作業指北針 (TWD)1100 {0} {1}\n", cart[3], cart[3] * 1100);

            Console.Write("總價 = {0}\n\n", cart[1] * 199+ cart[2] * 460 + cart[3] * 1100);

        }
        if(option == 6)
        {
            System.Environment.Exit(0);
        }
    }
    
}
