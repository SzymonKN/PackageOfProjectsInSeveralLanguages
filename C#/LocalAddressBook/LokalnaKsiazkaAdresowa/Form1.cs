using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LokalnaKsiazkaAdresowa
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection(global::LokalnaKsiazkaAdresowa.Properties.Settings.Default.AddresBookConnectionString);
            try
            {
                conn.Open();
                string sql = "INSERT INTO Person (Id,Name) Values('" + textBox1.Text + "','" + textBox2.Text + "')";
                SqlCommand query = new SqlCommand(sql, conn);
                query.ExecuteNonQuery();
                MessageBox.Show("done succesfull", "Message", MessageBoxButtons.OK, MessageBoxIcon.Information);

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            finally
            {
                conn.Close();
            }


        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'addresBookDataSet.Person' table. You can move, or remove it, as needed.
            this.personTableAdapter.Fill(this.addresBookDataSet.Person);
          

        }

        private void refresh_Click(object sender, EventArgs e)
        {
            this.personTableAdapter.Fill(this.addresBookDataSet.Person);
          
        }
    }
}
