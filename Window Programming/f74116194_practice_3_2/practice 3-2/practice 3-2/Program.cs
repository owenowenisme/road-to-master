using System.Text;
class Program
{
    Dictionary<string, string> stringMap = new Dictionary<string, string>
    {
        { "name",""},
        { "department","系的"},
        { "ID","學號的"},
        { "level","等級的"},
        { "title","職務的"}
    };
    List<stu> db = new List<stu>();
    class stu
    {
        public string name;
        public string ID;
        public string department;
        public string level = "萌新社員";
        public string title = "無";
    }
    static void Main()
    {
        Console.InputEncoding = Encoding.Unicode;
        Console.OutputEncoding = Encoding.Unicode;
        Console.WriteLine("-------------------------###    社員資料登記    ###------------------------");
        Console.WriteLine("新增社員資訊:\tregister\tname\tdepartment\tID");
        Console.WriteLine("以特定屬性查詢:\tsearch\t\tname\tag\tWant_search_string");
        Console.WriteLine("授予社員職位:\tentitle\t\tname\tdepartment\tID\tThat_title");
        Console.WriteLine("所有社員列表:\tcheck");
        Console.WriteLine("指令格式列表:\thelp");
        Console.WriteLine("離開此程式:\texit");
        Program program = new Program(); 
        
        string input="";
        while (true)
        {
            
            input = Console.ReadLine();
            string[] parsed = input.Split(' ');

            try
            {
                if (parsed[0] == "help")
                {
                    Console.WriteLine("---------------------------------------------------------------------------");
                    Console.WriteLine("新增社員資訊:\tregister\tname\tdepartment\tID");
                    Console.WriteLine("以特定屬性查詢:\tsearch\t\tname\tag\tWant_search_string");
                    Console.WriteLine("授予社員職位:\tentitle\t\tname\tdepartment\tID\tThat_title");
                    Console.WriteLine("所有社員列表:\tcheck");
                    Console.WriteLine("指令格式列表:\thelp");
                    Console.WriteLine("離開此程式:\texit");
                    Console.WriteLine("---------------------------------------------------------------------------");
                }
                else if (parsed[0] == "register")
                {
                    program.Register(parsed[1], parsed[2], parsed[3]);
                }
                else if (parsed[0] == "search")
                {
                    program.Search(parsed[1], parsed[2]);
                }
                else if (parsed[0] == "entitle")
                {
                    program.Entitle(parsed[1], parsed[2], parsed[3], parsed[4]);
                }
                else if (parsed[0] == "check")
                {
                    Console.WriteLine("----------------------------------------------------------");
                    for (int i = 0; i < program.db.Count(); i++)
                    {
                        Console.WriteLine($"{program.db[i].name}\t{program.db[i].department}\t{program.db[i].ID}\t{program.db[i].level}\t{program.db[i].title}");
                    }
                    Console.WriteLine("----------------------------------------------------------");
                }
                else if (parsed[0] == "exit")
                {
                    Environment.Exit(0);
                }
                else
                {
                    Console.WriteLine("\t不存在這個功能，有疑慮請打help");
                }
            }catch (Exception e)
            {
                Console.Write("輸入格式有誤，請重新輸入!");
            }
            
        }
    }
    public void Register(string name,string department,string id)
    {
        
        for(int i = 0; i < db.Count(); i++)
        {
            if (db[i].name == name && db[i].department == department && db[i].ID == id)
            {
                if (db[i].level == "永久社員")
                {
                    Console.WriteLine("已經是永久社員了喔");

                }
                else if (db[i].level == "萌新社員")
                {
                    db[i].level = "資深社員";
                    Console.WriteLine("已經晉升為資深社員");
                }
                else if (db[i].level == "資深社員")
                {
                    db[i].level = "永久社員";
                    Console.WriteLine("已經晉升為永久社員");
                }

                return;
            }
        }
        
        stu new_stu = new stu();
        new_stu.name = name;
        new_stu.department = department;
        new_stu.ID = id;
        db.Add(new_stu);
        Console.WriteLine("歡迎新社員!!");
        return;

    }
    public void Search(string tag, string query)
    {
        int checker = 0;
        for(int i = 0; i < db.Count(); i++)
        {

            if (db[i].GetType().GetField(tag).GetValue(db[i]).ToString() == query)
            { 
                Console.WriteLine($"{db[i].name}\t{db[i].department}\t{db[i].ID}\t{db[i].level}\t{db[i].title}");
                checker=1;
            }
        }
        if(checker == 0)
        {
            Console.WriteLine("\t找不到這個" + stringMap[tag] +"人ㄟ");
        }
    }
    public void Entitle(string name, string department,string ID,string title)
    {
        
        for (int i = 0; i < db.Count(); i++)
        {

            if (db[i].name == name && db[i].department == department && db[i].ID == ID)
            {
                bool containsSubstring = title.Contains("社長");
                if (containsSubstring) {
                    Console.WriteLine("\t我們的社長只有阿明一個人，你不要想篡位!");
                    return;
                }
                db[i].title = title;
                Console.WriteLine($"\t{db[i].name}已晉升為{db[i].title}!");
                return;
            }
        }
        Console.WriteLine("\t找不到這個人ㄟ");
    }
}