using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;

namespace RemoteHostScanner
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

       

        private void scan_Click(object sender, EventArgs e)
        {
            short[] PortList = { 20, 21, 22, 23, 25, 53, 70, 88, 109, 110, 119, 143, 161, 162, 443, 3389 };
            string host = tbHostAddress.Text;
            lbMessage.Items.Add("Skanowanie portów dla " + host);
            lbMessage.Items.Add("To może chwilę potrwać...");
            foreach (short port in PortList)
            {
                this.Refresh();
                try
                {
                    TcpClient client = new TcpClient(host, port);
                    lbMessage.Items.Add("Port " + port.ToString() + " jest otwarty");

                }
                catch
                {
                    lbMessage.Items.Add("Port "+port.ToString()+" jest zamknięty");
                }
            }
        }
    }
}
