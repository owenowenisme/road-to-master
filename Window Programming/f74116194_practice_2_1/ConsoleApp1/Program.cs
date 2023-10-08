using System;
using System.Collections.Generic;
using System.Net.Sockets;

class Program
{
    
    class Subject
    {
        public double Score { get; set; }
        public int Credits { get; set; }
    }
    static Dictionary<string, Subject> subjects = new Dictionary<string, Subject>();
    static void Main(string[] args)
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        while (true)
        {
            Console.WriteLine("## 成績計算器 ## ");
            Console.WriteLine("1. 新增科目(create)");
            Console.WriteLine("2. 刪除科目(delete)");
            Console.WriteLine("3. 更新科目(update)");
            Console.WriteLine("4. 列印成績單(print)");
            Console.WriteLine("5. 退出(exit)");
            Console.Write("輸入要執行的指令操作：");


                string input = Console.ReadLine();
                string[] option = input.Split(' '); 
                switch (option[0])
                {
                    case "create":
                        AddSubject(option);
                        break;
                    case "delete":
                        RemoveSubject(option);
                        break;
                    case "update":
                        UpdateSubject(option);
                        break;
                    case "print":
                        PrintGradeSheet(option);
                        break;
                    case "exit":
                        Environment.Exit(0);
                        break;
                    default:
                        Console.WriteLine("指令格式不符! 請重新輸入!");
                        break;
                
            }
            Console.WriteLine("");
        }
    }

    static void AddSubject(string[] option )
    {

        if (option.Length != 4 )
        {
            Console.WriteLine("指令格式不符! 請重新輸入!");
            return;
        }
        double score = double.Parse(option[2]);
        int credit = int.Parse(option[3]);
        if (score < 0 || score > 100 || credit < 0 || credit > 10)
            if (score < 0 || score > 100)
            {
                Console.WriteLine("成績分數異常! 請重新輸入!");
                return;
            }
        if (score < 0 || score > 100)
        {
            Console.WriteLine("學分數異常! 請重新輸入!");
            return;
        }

        if (credit < 0 || credit > 10)
        {
            Console.WriteLine("學分數異常! 請重新輸入!");
            return;
        }
        else if (subjects.ContainsKey(option[1]))
        {
            Console.WriteLine("科目已存在");
        }
        else
        {
            subjects.Add(option[1],new Subject{Score = score,Credits = credit});
            Console.WriteLine("科目已新增");
        }
    }

    static void RemoveSubject(string[] option)
    {

        if (option.Length != 2)
        {
            Console.WriteLine("指令格式不符! 請重新輸入!");
            return;
        }
        if (subjects.ContainsKey(option[1]))
        {
            subjects.Remove(option[1]);
            Console.WriteLine("科目已刪除");
        }
        else
        {
            Console.WriteLine("科目不存在");
        }
    }

    static void UpdateSubject(string[] option )
    {
        if (option.Length != 4)
        {
            Console.WriteLine("指令格式不符! 請重新輸入!");
            return;
        }

        double score = double.Parse(option[2]);
        int credit = int.Parse(option[3]);

        if (score < 0 || score > 100)
        {
            Console.WriteLine("成績分數異常! 請重新輸入!");
            return;
        }

        if (credit < 0 || credit > 10)
        {
            Console.WriteLine("學分數異常! 請重新輸入!");
            return;
        }

        if (subjects.ContainsKey(option[1]))
        {
            subjects[option[1]].Score = score;
            subjects[option[1]].Credits = credit;
            Console.WriteLine("科目已更新");
        }
        else
        {
            Console.WriteLine("科目不存在");
        }

    }
    static void PrintGradeSheet(string[] option)
    {
        if(option.Length!=1)
        {
            Console.WriteLine("指令格式不符! 請重新輸入!");
            return;
        }
        var sortedSubjects = subjects.OrderByDescending(x => x.Value.Score).ToList();
        int totalCredits = 0;
        double totalScore = 0;
        int passedCredits = 0;
        double oldGpa = 0;
        double newGpa = 0;
        double tmpOldGpa = 0;
        double tmpNewGpa = 0;
        Console.WriteLine("我的成績單：");
        Console.WriteLine("編號  科目代碼    分數   等第   學分數");
        int index = 1;

        foreach (var sub in sortedSubjects)
        {

            double score = sub.Value.Score;
            int credits = sub.Value.Credits;
           
            if (score >= 60)
            {
                passedCredits += credits;
            }

            totalCredits += credits;
            totalScore += score*credits;
            
            string lvl = string.Format("{0,-2}",CalculateGrade(score, ref oldGpa, ref newGpa, credits));
            Console.WriteLine($"{index++}      {sub.Key}      {score}     {lvl}      {credits}");
        }

        double totalAverage = Math.Round(totalScore / totalCredits, 2);
        oldGpa = Math.Round(oldGpa / totalCredits ,1);
        newGpa = Math.Round(newGpa / totalCredits ,1);
        if (totalCredits <= 0)
        {
            totalAverage = 0;
            oldGpa = 0;
            newGpa = 0;
        }
        string formattedValue = totalAverage.ToString("0.00");
        Console.WriteLine($"總平均: {formattedValue}");
        string formattedOldGpa = oldGpa.ToString("0.0");
        string formattedNewGpa = newGpa.ToString("0.0");
        Console.WriteLine($"GPA: {formattedOldGpa}/4.0 (舊制), {formattedNewGpa}/4.3 (新制)");
        Console.WriteLine($"實拿學分數/總學分數: {passedCredits}/{totalCredits}");
    }
    
    static string CalculateGrade(double score , ref double oldGpa, ref double newGpa, int credit)
    {
        if (score >= 80) {
            oldGpa += 4 * credit;
        }
        else if (score >= 70)
        {
            oldGpa += 3 * credit;
        }
        else if (score >= 60)
        {
            oldGpa += 2 * credit;
        }
        else if (score >= 50)
        {
            oldGpa += 1 * credit;

        }
        if (score >= 90)
        {
            newGpa += 4.3 * credit;
            return "A+";
            
        }
        else if (score >= 85)
        {
            newGpa += 4.0 * credit;
            return "A";
        }
        else if (score >= 80)
        {
            newGpa += 3.7 * credit;
            return "A-";
        }
        else if (score >= 77)
        {
            newGpa += 3.3 * credit;
            return "B+";
        }
        else if (score >= 73)
        {
            newGpa += 3.0 * credit;
            return "B";
        }
        else if (score >= 70)
        {
            newGpa += 2.7 * credit;
            return "B-";
        }
        else if (score >= 67)
        {
            newGpa += 2.3 * credit;
            return "C+";
        }
        else if (score >= 63)
        {
            newGpa += 2.0 * credit;
            return "C";
        }
        else if (score >= 60)
        {
            newGpa += 1.7 * credit;
            return "C-";
        }
        else
        {
            return "F";
        }
    }


}