using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace practice4_2
{
    public partial class Form1 : Form
    {
        bool[] watered = new bool[13];
        bool[] ferted = new bool[13];
        Button[] buttons = new Button[13];
        int seed = 5, fertilizer = 5, money = 100,fruit = 0;
        public Form1()
        {
            InitializeComponent();
            buttons[1] = button1;
            buttons[2] = button2;
            buttons[3] = button3;
            buttons[4] = button4;
            buttons[5] = button5;
            buttons[6] = button6;
            buttons[7] = button7;
            buttons[8] = button8;
            buttons[9] = button9;
            buttons[10] = button10;
            buttons[11] = button11;
            buttons[12] = button12;
            update_item();
            for (int i = 1; i < 13; i++)
            {
                buttons[i].Click += Button_Click;
            }

        }
        private void Button_Click(object sender, EventArgs e)
        {
            Button clickedButton = sender as Button;
            int clickedButtonidx = 0;
            
            if (clickedButton != null)
            {
                for (int i = 1; i < 13; i++)
                {
                    if (clickedButton == buttons[i])
                    { clickedButtonidx = i;
                        break;
                    }
                    
                }

                
                if (radioButton2.Checked&&clickedButton.ImageIndex == 0 )
                {
                    if (plant())
                    {
                        clickedButton.ImageIndex = 1;
                        seed--;
                    }
                    else
                    {
                        MessageBox.Show("種子用完了", "警告",MessageBoxButtons.OK,MessageBoxIcon.Error);
                    }
                    
                }else if (clickedButton.ImageIndex == 1|| clickedButton.ImageIndex == 2)
                {
                    if (next_lvl(clickedButtonidx))
                    {
                        clickedButton.ImageIndex++;
                    }
                    
                }else if(clickedButton.ImageIndex == 3)
                {
                    if(radioButton4.Checked) { clickedButton.ImageIndex=0; fruit++; }
                }
                update_item();
            }
        }

        private void seed_amount_TextChanged(object sender, EventArgs e)
        {

        }

        private void buy_sell_Click(object sender, EventArgs e)
        {
            if(checkBox3.Checked&&fruit > 0)
            {
                money += 40;
                fruit --;
            }
            if (checkBox1.Checked)
            {
                if (money >= 10)
                {
                    seed++;
                    money -=10;
                }
            }
            if (checkBox2.Checked)
            {
                if (money >= 10)
                {
                    fertilizer++;
                    money -= 10;
                }
            }
            update_item() ;
        }

        private bool plant()
        {   
            return (seed > 0);
        }
        private bool next_lvl(int idx)
        {
            if (radioButton1.Checked)
            {
                watered[idx] = true;
            }
            else if (!ferted[idx]&& radioButton3.Checked)
            {
                if (fertilizer <= 0)
                {
                    MessageBox.Show("肥料用完了", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    ferted[idx] = true;
                    fertilizer--;
                }

            }
            if (watered[idx] && ferted[idx])
            {
                watered[idx] = false;
                ferted[idx] = false;
                return true;
            }
            return false;
        }
        private void update_item()
        {
            seed_amount.Text = $"擁有:{seed}";
            fert_amount.Text = $"擁有:{fertilizer}";
            textBox4.Text = $"擁有:{fruit}";
            textBox1.Text = $"金錢:{money}";
        }
        
    }
}
