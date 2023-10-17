using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace practice4_1
{
    public partial class Form1 : Form
    {
        int a = 0, b = 0, c = 0, d = 0;
        int answer_a = 0, answer_b = 0, answer_c = 0, answer_d = 0;
        Random random = new Random();

        private int validation()
        {
            int q = 0;
            if (a == answer_a && b == answer_b && c == answer_c && d == answer_d)
                return 0;
            else
            {
                if (a != answer_a)
                {
                    q++;
                }
                if (b != answer_b)
                {
                    q++;
                }
                if (c != answer_c)
                {
                    q++;
                }
                if (d != answer_d)
                {
                    q++;
                }
            }
            return q;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            int wrong = validation();
            if(wrong > 0)
            {
                DialogResult result = MessageBox.Show($"猜對{4-wrong}個位置", "失敗", MessageBoxButtons.RetryCancel, MessageBoxIcon.Error);
                if(result == DialogResult.Cancel)
                {
                    MessageBox.Show($"答案是{answer_a}{answer_b}{answer_c}{answer_d}");
                }
            }
            else
            {
                MessageBox.Show("解鎖成功","成功",MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
                
        }

     

        public Form1()
        {
            InitializeComponent();
            randomize();
        }
        private void randomize()
        {
            answer_a = random.Next(10);
            answer_b = random.Next(10);
            answer_c = random.Next(10);
            answer_d = random.Next(10);
        }
        private void pictureBox1_Click(object sender, EventArgs e)
        {
            a++; a %= 10;
            pictureBox1.Image = Image.FromFile($"..\\..\\Practice 4_img\\img4_1\\{a}.jpg");
        }
        
        private void pictureBox2_Click(object sender, EventArgs e)
        {
            b++; b %= 10;
            pictureBox2.Image = Image.FromFile($"..\\..\\Practice 4_img\\img4_1\\{b}.jpg");
        }
        private void pictureBox3_Click(object sender, EventArgs e)
        {
            c++; c %= 10;
            pictureBox3.Image = Image.FromFile($"..\\..\\Practice 4_img\\img4_1\\{c}.jpg");
        }
        private void pictureBox4_Click(object sender, EventArgs e)
        {
            d++; d %= 10;
            pictureBox4.Image = Image.FromFile($"..\\..\\Practice 4_img\\img4_1\\{d}.jpg");
        }

    }
}
