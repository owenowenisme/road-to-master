using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Practice3_1
{
    public partial class Form1 : Form
    {
        String[] analysis = { "桃花運大漲", "家庭遭逢變故", "事業平步青雲，有升官可能", "事業起伏大", "親人病情好轉", "被財神眷顧", "近期一帆風順" };

        String[] suggest = { "少做壞事，夜路走多了總匯三明治",
                     "保持謙虛，一山還有一山高，雞蛋還有雞蛋糕",
                     "善待他人，不要任意嘲笑別人，除非你忍不住",
                     "早點睡覺，不要仗著自己長得醜，就任意熬夜",
                     "小心小人，可謂浮雲能蔽日，輕舟已過萬重山",
                     "不要偷懶，你在睡覺的時候，美國人還在上班阿",
                     "健康第一，定期身體檢查並謹記醫生怎麼說，doctor!",
                     "穩定情緒，今天不開心沒關係，反正明天也不會開心"};
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {   

            if (valiate() && namebox.Visible)
            {
                show_result();
            }

            else if (!namebox.Visible)
            {
                back_to_default();
            }
            
            
                
        }
        private bool valiate()
        {
            bool checker = true;
            name_check.Text = "";
            gender_check.Text = "";
            birth_check.Text = "";
            date_check.Text = "";
            choice_check.Text = "";
            if (namebox.Text == "")
            {

                checker = false;
                name_check.Text = "此欄未填寫";
            }
            if (genderbox.Text == "")
            {
                checker = false;
                gender_check.Text = "此欄未填寫";
            }
            else if (genderbox.Text != "男" && genderbox.Text != "女")
            {
                checker = false;
                gender_check.Text = "輸入應為男or女";
            }
            if (datebox.Text == "")
            {
                checker = false;
                date_check.Text = "此欄未填寫";
            }
            if (birthbox.Text == "")
            {
                checker = false;
                birth_check.Text = "此欄未填寫";
            }
            if (choicebox.Text == "")
            {
                checker = false;
                choice_check.Text = "此欄未填寫";
            }
            else if(choicebox.Text != "貓" && choicebox.Text != "貓派" && choicebox.Text != "狗" && choicebox.Text != "狗派")
            {
                checker = false;
                choice_check.Text = "輸入應為貓or狗";
            }
            
            
            return checker;
        }
        private void show_result()
        {
            label1.Text = "神諭時刻";
            button1.Text = "來，下面一位~~";
            name.Location = new Point(220, 60);
            gender.Location = new Point(510, 60);
            birth.Location = new Point(70, 120);
            date.Location = new Point(370, 120);
            choice.Location = new Point(640, 120);
            name_check.Location = new Point(220, 60 + 30);
            gender_check.Location = new Point(510, 60 + 30);
            birth_check.Location = new Point(70, 120 + 30);
            date_check.Location = new Point(370, 120 + 30);
            choice_check.Location = new Point(640, 120 + 30);
            name_check.Text = namebox.Text;
            gender_check.Text = genderbox.Text;
            birth_check.Text = birthbox.Text;
            date_check.Text = datebox.Text;
            choice_check.Text = choicebox.Text;
            namebox.Text = "";
            genderbox.Text = "";
            birthbox.Text = "";
            datebox.Text = "";
            choicebox.Text = "";
            namebox.Visible = false;
            genderbox.Visible = false;
            birthbox.Visible = false;
            datebox.Visible = false;
            choicebox.Visible = false;
            luckpicker();

        }
        private void back_to_default()
        {
            label1.Text = "資料輸入";
            name.Location = new Point(120, 80);
            gender.Location = new Point(120, 140);
            birth.Location = new Point(120, 200);
            date.Location = new Point(120, 260);
            choice.Location = new Point(120, 320);
            name_check.Location = new Point(580, 80);
            gender_check.Location = new Point(580, 140);
            birth_check.Location = new Point(580, 200);
            date_check.Location = new Point(580, 260);
            choice_check.Location = new Point(580, 320);
            namebox.Visible = true;
            genderbox.Visible = true;
            birthbox.Visible = true;
            datebox.Visible = true;
            choicebox.Visible = true;
            name_check.Text = "";
            gender_check.Text = "";
            birth_check.Text = "";
            date_check.Text = "";
            choice_check.Text = "";
            luck.Text = "";
            segg.Text = "";
        }
        private void luckpicker()
        {
            Random rand = new Random();
            luck.Text = "運勢:"+analysis[rand.Next(7)];
            segg.Text = "建議:" + suggest[rand.Next(7)];
        }
    }
}
