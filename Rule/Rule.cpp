#include "stdafx.h"
#include <iostream>
#include<windows.h>
#include<string>
#include <string.h>
#include<fstream>

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

class Rule {
ofstream ofile;
ifstream ifile;
private:
int cris;
int rebel;               
int bigrebel;
int cervan;
int accident;
int turn=0;
string player;
int choice;
char answer;
int n1, n2;
int n = 0;
int sol;
int money;
int food;
int sol1;
int sol2;
int money1;
int money2;
int food1;
int food2;
int cap1;
int cap2;
int q = 1;
int ll;
int at;
int def;
string na,na1;
string m,m1;
string f,f1;
string so,so1;
string far1, far2;
string carav1, carav2;
int lands1,lands2,landsm1,landsm2,landsf1,landsf2;
int car1, car2, farm1, farm2;
int e = 0;
int zc=0;
int xyz[];


public:

void takeinf() 
{
	ifile.open("Player1.txt");
	while (ifile.good() && ifile >> na && ifile >> m && ifile >> f && ifile >> so && ifile >> far1 && ifile >> carav1)
	{
		n1 = stoi(na.substr(0, 1));
		money1 = stoi(m.substr(0, 5));
		food1 = stoi(f.substr(0,5));
		 sol1= stoi(so.substr(0,5));
		 farm1 = stoi(far1.substr(0, 5));
		 car1 = stoi(carav1.substr(0, 5));
	}
	ifile.close();
	ifile.open("Player2.txt");
	while (ifile.good() && ifile >> na1 && ifile >> m1 && ifile >> f1 && ifile >> so1 && ifile >> far2 && ifile >> carav2)
	{
		n2 = stoi(na.substr(0, 1));
		money2 = stoi(m1.substr(0,5));
		food2 = stoi(f1.substr(0,5));
		sol2 = stoi(so1.substr(0,5));
		farm2 = stoi(far2.substr(0, 5));
		car2 = stoi(carav2.substr(0, 5));
	}
	ifile.close();
	
}

void takeland()
{
	landsf1 = 0;
	landsm1 = 0;
	landsf2 = 0;
	landsm2 =0;

	ifile.open("Player1Lands.txt");
	while (ifile.good() && ifile >> lands1)
	{
		xyz[lands1] = 1;
		landsf1++;
		landsm1++;
		if (lands1 == 41 || lands1 == 49 || lands1 == 50 || lands1 == 57 || lands1 == 58 || lands1 == 59)
		{
			landsm1 += 2;
			landsf1--;
		}
	}
	ifile.close();
	ifile.open("Player2Lands.txt");
	while (ifile.good() && ifile >> lands2)
	{
		xyz[lands2] = 2;
		landsf2++;
		landsm2++;
		if (lands2 == 41 || lands2 == 49 || lands2 == 50 || lands2 == 57 || lands2 == 58 || lands2 == 59)
		{
			landsm2 += 2;
			landsf2--;
		}

	}
	ifile.close();
}

void giveland() 
{

	ofile.open("Player1Lands1.txt", ios::out);
	for (int i = 1; i <= 64; i++)
	{
		if (xyz[i] == 1)
		{
			ofile << i << " ";
		}
	}
	ofile.close();
	ofile.open("Player2Lands1.txt", ios::out);
	for (int i = 1; i <= 64; i++)
	{
		if (xyz[i] == 2)
		{
			ofile << i << " ";
		}
	}
	ofile.close();
	remove("Player2Lands.txt");
	remove("Player1Lands.txt");
	rename("Player2Lands1.txt", "Player2Lands.txt");
	rename("Player1Lands1.txt", "Player1Lands.txt");
}

void giveinf() 
{
	
	ofile.open("Player1.txt", ios::out);
	ofile <<n1<< "\n" << money1 << "\n" << food1 << "\n" << sol1 << "\n" << farm1 << "\n" << car1;
	ofile.close();
	ofile.open("Player2.txt", ios::out);
	ofile << n2 << "\n" << money2 << "\n" << food2 << "\n" << sol2 << "\n" << farm2 << "\n" << car2;
	ofile.close();

	
}

void check() 
{
	if (turn % 2 == 0)
	{
	    money = money1;
		food = food1;
		sol = sol1;
	}
	if (turn % 2 == 1)
	{
		 money = money2;
		 food = food2;
		 sol = sol2;
	}
}

void recheck()
{
	if (turn % 2 == 0)
	{
		money1 = money;
		food1 = food;
		sol1 = sol;
	}
	if (turn % 2 == 1)
	{
		money2 = money;
		food2 = food;
		sol2 = sol;
	}
}

void coardination()
{
	for (int i = 1; i <= 64; i++) 
	{
		xyz[i] = 0;
	}
};

void w()
{
	e++;
	if (xyz[e] == 1)
	{
		cout << "*";
	}
	if (xyz[e] == 2)
	{
		cout << "#";
	}
	SetConsoleTextAttribute(color, 15);	
	cout << "W";
	
};

void s()
{
	e++;
	cout << "@";
	SetConsoleTextAttribute(color, 01);		
	cout << "S";
		
};

void d()
{
	e++;
	if (xyz[e] == 1)
	{
		cout << "*";
	}
	if (xyz[e] == 2)
	{
		cout << "#";
	}
	SetConsoleTextAttribute(color, 12);
		
	cout << "D";
		
};

void l()
{
	e++;
	if (xyz[e] == 1)
	{
		cout << "*";
	}
	if (xyz[e] == 2)
	{
		cout << "#";
	}
	SetConsoleTextAttribute(color, 10);
		
	cout << "L";
		
};

void events()
	{
	    system("cls");
	    check();
		cris = rand() % 30;
		rebel = rand() % 30;
		bigrebel = rand() % 60;
		cervan = rand() % 15;
		if (cris == 1)
		{
			cout << "A big cris showed up! You lost your golds %20" << endl;
			money = money - (money /5);
			recheck();
			giveinf();

		}
		if (rebel == 1)
		{
			cout << "A small rebellion showed up! You can quell with money(you will lose your golds %30) " << endl;
			money = money - ((money * 3) / 10);
			recheck();
			giveinf();
		}
		if (bigrebel == 1)
		{
			cout << "A big rebellion showed up! You can only quell with soldiers (you will half of them) " << endl;
			sol = sol - (sol/2);
			recheck();
			giveinf();
		}
		if (cervan == 1)
		{
			int cer = 1;
			while (cer = 1) 
			{
				cout << "You see a cervan near your country! You will win your golds %10 but lose your soldiers %10 too. Dou you want to do it(y/n)?" << endl;
				cin >> answer;
				if (answer == 'y')
				{
					sol = sol - (sol / 10);
					money = money + (money / 10);
					recheck();
					giveinf();
				}
				if (answer == 'n')
				{
					q++;
					game();
				}
				else
					cout << "Eror!" << endl;
				system("cls");
			}
		}
		q++;
		game();
	}

void map()
	{
	e = 0;
		cout << "  ___A_______B_______C_______D_______E_______F_______G_______H___" << endl;
		cout << "1|__";
		w();
		cout << "0" << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		w();
		cout << "0" << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << "0" << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << "0" << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << "0" << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << "0" << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << "0" << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << "0" << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|" << endl;

		cout << "2|__";
		w();
		cout << "0" << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		w();
		cout <<e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|" << endl;

		cout << "3|__";
		w();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l(); 
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|" << endl;

		cout << "4|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|" << endl;

		cout << "5|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|" << endl;

		cout << "6|__";
		d();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|" << endl;

		cout << "7|__";
		d();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		d();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		w();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		w();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		s();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|" << endl;

		cout << "8|__";
		SetConsoleTextAttribute(color, 07);
		d();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		d();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		d();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		l();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		w();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		w();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|__";
		w();
		cout << e;
		SetConsoleTextAttribute(color, 07);
		cout << "_|" << endl;
		cout << "W=Winter" << "  " << "S=Sea" << "  " << "L=Land" << "  " << "D=Desert" << endl;
		cout << "Winter=(Attack:-*/Defense:*)" << "   Desert=(Food:-*/Gold:**)" << endl;
		borders();
		cout << "*=Player1, #=Player2, @=No Mans Land"<<endl;
		if (zc == 0) 
		{
			system("pause");
			game();
		}
		
	}

void nations()
{
	if (n == 0) 
	{
		xyz[1] = 1;
		xyz[2] = 1;
		xyz[9] = 1;
		xyz[10] = 1;
		xyz[17] = 1;
		xyz[18] = 1;
		xyz[25] = 1;
		xyz[26] = 1;
		xyz[33] = 1;
		xyz[34] = 1;
		xyz[42] = 1;
		xyz[27] = 1;
		xyz[35] = 1;
		xyz[28] = 1;
		xyz[36] = 1;
		xyz[44] = 1;
		xyz[43] = 1;
		xyz[12] = 1;
		xyz[13] = 1;
		xyz[20] = 1;
		xyz[41] = 1;
		xyz[49] = 1;
		xyz[50] = 1;
	}
	if (n == 1)
	{
		xyz[57] = 2;
		xyz[58] = 2;
		xyz[59] = 2;
		xyz[60] = 2;
		xyz[61] = 2;
		xyz[62] = 2;
		xyz[63] = 2;
		xyz[64] = 2;
		xyz[51] = 2;
		xyz[52] = 2;
		xyz[53] = 2;
		xyz[54] = 2;
		xyz[55] = 2;
		xyz[15] = 2;
		xyz[14] = 2;
		xyz[21] = 2;
		xyz[22] = 2;
		xyz[23] = 2;
		xyz[29] = 2;
		xyz[30] = 2;
		xyz[37] = 2;
		xyz[45] = 2;
		xyz[46] = 2;

	}
	gamer();
	giveland();
    cout << player <<"'s Turn"<< endl;
	cout << "Choose a Nation" << endl;
	cout << "1-Balrok" << endl;
	cout << "2-Cast" << endl;
	cout << "3-Buldan" << endl;
	cout << "Choice:";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		system("cls");
		balrok();
		break;
	}
	case 2:
	{
		system("cls");
		cast();
		break;
	}
	case 3:
	{
		system("cls");
		buldan();
		break;
	}
	default:
	{
		cout << "EROR" << endl;
		break;
	}
	}

}

void buldan()
{
	cout << "Attack:*" << endl;
	cout << "Defense:**" << endl;
	cout << "Food:*" << endl;
	cout << "Gold:*" << endl;
	cout << "Build:***" << endl;
	cout << "Do you want to contunie?(y/n)";
	cin >> answer;
	if (answer == 'y')
	{
		if (n == 0)
		{
			ofile.open("Player1.txt", ios::app);
			ofile << "2\n" << "1000\n" << "100\n" << "50\n"<<"0\n"<<"0\n";
			ofile.close();
			n1 = 2;
			money1 = 1000;
			food1 = 100;
			sol1 = 50;
			farm1 = 0;
			car1 = 0;
			n++;
			turn++;
			system("cls");
			nations();

		}


		if (n == 1)
		{
			ofile.open("Player2.txt", ios::app);
			ofile << "2\n" << "1000\n" << "100\n" << "50\n" << "0\n" << "0\n";
			ofile.close();
			n2 = 2;
			money2 = 1000;
			food2 = 100;
			sol2 = 50;
			farm2 = 0;
			car2 = 0;
			turn++;
			n++;
			system("cls");
			game();

		}


	}
	else if (answer == 'n')
	{
		system("cls");
		nations();
	}
	else
		cout << "Eror";
}

void balrok()
	{
		cout << "Attack:***" << endl;
		cout << "Defense:*" << endl;
		cout << "Food:***" << endl;
		cout << "Gold:*" << endl;
		cout << "Build:0" << endl;
		cout << "Do you want to contunie?(y/n)";
		cin >> answer;
		if (answer == 'y')
		{
			if (n == 0)
			{
				ofile.open("Player1.txt", ios::app);
				ofile << "0\n" << "1000\n" << "200\n" << "150\n" << "0\n" << "0\n";
				ofile.close();
				n1 = 0;
				money1 = 1000;
				food1 = 150;
				sol1 = 150;
				farm1 = 0;
				car1 = 0;
				n++;
				turn++;
				system("cls");
				nations();
				
			}
			
			
			if (n == 1)
			{
				ofile.open("Player2.txt", ios::app);
				ofile << "0\n" << "1000\n" << "150\n" << "150\n" << "0\n" << "0\n";
				ofile.close();
				n2 = 0;
				money2 = 1000;
				food2 = 150;
				sol2 = 150;
				farm2 = 0;
				car2 = 0;
				turn++;
				n++;
				system("cls");
				game();
			}
			
			
		}
		else if (answer == 'n')
		{
			system("cls");
			nations();
		}
		else
			cout << "Eror";


	}

void cast()
	{
		cout << "Attack:*" << endl;
		cout << "Defense:***" << endl;
		cout << "Food:*" << endl;
		cout << "Gold:**" << endl;
		cout << "Build:*" << endl;
		cout << "Do you want to contunie?(y/n)";
		cin >> answer;
		if (answer == 'y')
		{
			if (n == 0) 
			{
				ofile.open("Player1.txt", ios::app);
				ofile << "1\n" << "1500\n" << "100\n" << "50\n" << "0\n" << "0\n";
				ofile.close();
				n1 = 1;
				money1 = 1500;
				food1 = 100;
				sol1 = 50;
				farm1 = 0;
				car1 = 0;
				n++;
				turn++;
				system("cls");
				nations();
				
			}
			
			
			if (n == 1)
			{
				ofile.open("Player2.txt", ios::app);
				ofile << "1\n" << "1500\n" << "100\n" << "50\n";
				ofile.close();
				n2 = 1;
				money2 = 1500;
				food2 = 100;
				sol2 = 50;
				farm1 = 0;
				car1 = 0;
				turn++;
				n++;
				system("cls");
				game();

			}
			
			
		}
		else if (answer == 'n')
		{
			system("cls");
			nations();
		}
		else
			cout << "Eror";


	}

void borders()
{
	
		
	cout << "Player1's Lands" << endl;
	for (int i = 1; i <= 64; i++)
	{
		if (xyz[i] == 1)
		{
			cout << i << ", ";
		}
	}
	cout << endl;
	cout << "Player2's Lands" << endl;
	for (int i = 1; i <= 64; i++)
	{
		if (xyz[i] == 2)
		{
			cout << i << ", ";
		}
	}
	cout << endl;

}

void gamer() 
{
	if (turn % 2 == 0)
		player = "Player1";
	else if (turn % 2 == 1)
		player = "Player2";
}

void shop()
{
	system("cls");
	gamer();
	check();
	cout << player << "'s Turn" << endl;
	cout << "Money:" << money << " Food:" << food << " Soldiers:" << sol << endl;
	cout << "1-Buy Soldier(10 Money=1 Soldier)" << endl;
	cout << "2-Buy Food(2 Money =1 Food)" << endl;
	cout << "3-Back" << endl;
	cout << "Choice:";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		system("cls");
		cout << "How many soldiers you want to buy?" << endl;
		cin >> choice;
		money=money - (choice * 10);
		if (money >= 0) 
		{
			sol = sol + choice;
			recheck();
			giveinf();
			game();
		}
		else 
		{
			cout << "No money!" << endl;
			money = money + (choice * 10);
			shop();

		}
		break;
	}
	case 2:
	{
		system("cls");
		cout << "How many food you want to buy?" << endl;
		cin >> choice;
		money = money - (choice * 2);
		if (money >= 0) 
		{
			food = food + choice;
			recheck();
			giveinf();
			game();

		}
		else
		{
			cout << "No money!" << endl;
			money = money + (choice * 2);
			shop();

		}
		break;
	}
	case 3:
	{
		system("cls");
		game();
		break;
	}
	default:
	{
		cout << "EROR" << endl;
		break;
	}
	}
}

void endturn()
{
	if (turn % 2 == 0)
	{
		ofile.open("t.txt");
		ofile.close();
		if (n1 == 2)
		{
			money1 += landsm1 * 80;
			food1 += landsf1 * 40;
			money1 += car1 * 80;
			food1 += farm1 * 40;
		}
		if (n1 == 1) 
		{
			money1 += landsm1 * 120;
			food1 += landsf1 * 40;
			money1 += car1 * 120;
			food1 += farm1 * 40;
		}
		if (n1 == 0)
		{
			money1 += landsm1 * 80;
			food1 += landsf1 * 80;
			money1 += car1 * 80;
			food1 += farm1 * 80;
		}
	}
	else if (turn % 2 == 1)
	{
		remove("t.txt");
		if (n2 == 2)
		{
			money2 += landsm2 * 80;
			food2 += landsf2 * 40;
			money2 += car2 * 80;
			food2 += farm2 * 40;

		}
		if (n2 == 1)
		{
			money2 += landsm2 * 120;
			food2 += landsf2 * 40;
			money2 += car2 * 120;
			food2 += farm2 * 40;
		}
		if (n2 == 0)
		{
			money2 += landsm2 * 80;
			food2 += landsf2 * 80;
			money2 += car2 * 80;
			food2 += farm2 * 80;
		}
	}
}

void win() 
{
	int f = 0;
	int d = 0;
	for (int i = 1; i <= 64; i++)
	{
		if (xyz[i] == 1)
		{
			f++;
		}
		if (xyz[i] == 2)
		{
			d++;
		}
    }
	if (f == 0)
	{
		system("cls");
		cout << "Player 2 Win!" << endl;
		remove("Player1.txt");
		remove("Player2.txt");
		remove("Player1Lands.txt");
		remove("Player2Lands.txt");
		system("pause");
		start();
	}
	if (d == 0)
	{
		system("cls");
		cout << "Player 1 Win!" << endl;
		remove("Player1.txt");
		remove("Player2.txt");
		remove("Player1Lands.txt");
		remove("Player2Lands.txt");
		system("pause");
		start();
	}
}

void build() 
{
	system("cls");
	if (turn % 2 == 0)
	{
		cout << "farms:"<<farm1 << endl;
		cout << "caravanseraies:" << car1 << endl;
	}
	if (turn % 2 == 1)
	{
		cout << "farms:" << farm2 << endl;
		cout << "caravanseraies:" << car2 << endl;
	}
	cout << "(Balrok: 1 built =800 money Cast: 1 built =700 money Buldan: 1 built =500 money) " << endl;
	cout << "1-Build a farm" << endl;
	cout << "2-Build a caravanserai" << endl;
	cout << "3-Back" << endl;
	cout << "Choice:";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (turn % 2 == 0) 
		{
			if (n1 == 0)
			{
				if (money1 >= 800) 
				{
					money1 -= 800;
					farm1++;
					giveinf();
					game();
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
			if (n1 == 1)
			{
				if (money1 >= 700)
				{
					money1 -= 700;
					farm1++;
					giveinf();
					game();
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
			if (n1 == 2)
			{
				if (money1 >= 500)
				{
					money1 -= 500;
					farm1++;
					giveinf();
					game();
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
		}
		if (turn % 2 == 1)
		{
			if (n2 == 0)
			{
				if (money2 >= 800)
				{
					money2 -= 800;
					farm2++;
					giveinf();
					game();
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}

			}
			if (n2 == 1)
			{
				if (money2 >= 700)
				{
					money2 -= 700;
					farm2++;
					giveinf();
					game();
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
			if (n2 == 2)
			{
				if (money2 >= 500)
				{
					money2 -= 500;
					farm2++;
					giveinf();
					game();
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
		}
	}

	case 2:
	{
		if (turn % 2 == 0)
		{
			if (n1 == 0)
			{
				if (money1 >= 800)
				{
					money1 -= 800;
					car1++;
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
			if (n1 == 1)
			{
				if (money1 >= 700)
				{
					money1 -= 700;
					car1++;
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
			if (n1 == 2)
			{
				if (money1 >= 500)
				{
					money1 -= 500;
					car1++;
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
		}
		if (turn % 2 == 1)
		{
			if (n2 == 0)
			{
				if (money2 >= 800)
				{
					money2 -= 800;
					car2++;
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}

			}
			if (n2 == 1)
			{
				if (money2 >= 700)
				{
					money2 -= 700;
					car2++;
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
			if (n2 == 2)
			{
				if (money2 >= 500)
				{
					money2 -= 500;
					car2++;
				}
				else
				{
					cout << "No Money" << endl;
					system("pause");
					game();
				}
			}
		}
	}
	case 3:
	{
		system("cls");
		game();
		break;
	}
	default:
	{
		cout << "EROR" << endl;
		break;
	}

	}

}

void attack()
{
	zc = 1;
	map();
	cout << "!When you attacking 1 soldier eats 4 food, when you defending 1 soldier eats 2 food. Be carefull!!!" << endl;
	cout << "Choose for attack (You can only attack if you near the land)" << endl;
	cin >> ll;
	if (turn % 2 == 0)
	{

		if (xyz[ll] == 2)
		{
			if (xyz[ll + 1] == 1 || xyz[ll - 1] == 1 || xyz[ll - 8] == 1 || xyz[ll + 8] == 1)
			{
				cout << "How many soldiers dou you want to attack with?  Soldiers:"<<sol1<<"Food:"<<food1 << endl;
				cin >> at;
				if (at <= sol1 && food1>=at * 4)
				{
					if (food2<2) 
					{
						xyz[ll] = 1;
						cout << "You Succeed!" << endl;
						giveinf();
						giveland();
						system("pause");
						game();
					}
					cout << "(Player 2)How many soldiers do you want to defend with ?  Soldiers:" << sol2 << "Food:" << food2 << endl;
					cin >> def;
					if ( def <= sol2 && food2>=def * 2)
					{
						sol1 -= at;
						sol2 -= def;
						food1 -= at * 4;
						food2 -= def * 2;
						if (ll==1||ll==2||ll==9||ll==10||ll==17||ll==54||ll==55||ll==62||ll==63||ll==64) 
						{
							while (at > 0 && def > 0)
							{
								if (n1 == 0)
								{
									def -= at / 15;
									if (n2 == 0)
									{
										at -= def / 10;
									}
									if (n2 == 1)
									{
										at -= def / 2;
									}
									if (n2 == 2)
									{
										at -= def / 10;
									}
								}
								if (n1 == 1)
								{
									def -= at / 25;
									if (n2 == 0)
									{
										at -= def / 10;
									}
									if (n2 == 1)
									{
										at -= def / 2;
									}
									if (n2 == 2)
									{
										at -= def / 10;
									}
								}
								if (n1 == 2)
								{
									def -= at / 25;
									if (n2 == 0)
									{
										at -= def / 10;
									}
									if (n2 == 1)
									{
										at -= def / 2;
									}
									if (n2 == 2)
									{
										at -= def / 10;
									}
								}
							}
						}
						else
						{
							while (at > 0 && def > 0)
							{
								if (n1 == 0)
								{
									def -= at / 10;
									if (n2 == 0)
									{
										at -= def / 15;
									}
									if (n2 == 1)
									{
										at -= def / 5;
									}
									if (n2 == 2)
									{
										at -= def / 15;
									}
								}
								if (n1 == 1)
								{
									def -= at / 20;
									if (n2 == 0)
									{
										at -= def / 15;
									}
									if (n2 == 1)
									{
										at -= def / 5;
									}
									if (n2 == 2)
									{
										at -= def / 15;
									}
								}
								if (n1 == 2)
								{
									def -= at / 20;
									if (n2 == 0)
									{
										at -= def / 15;
									}
									if (n2 == 1)
									{
										at -= def / 5;
									}
									if (n2 == 2)
									{
										at -= def / 15;
									}
								}
							}
						}
						if (def <= 0)
						{
							sol1 += at;
							xyz[ll] = 1;
							giveinf();
							giveland();
							cout << "You Succeed!" << endl;
							system("pause");
						}
						if (at <= 0)
						{
							sol2 += def;		
							giveinf();
							cout << "You Failed!" << endl;
							system("pause");
						}
						game();
					}
					cout << "You dont have soldier or food!" << endl;
					game();
				}
				cout << "You dont have soldier or food!" << endl;
				game();
			}
			cout << "You cant attack" << endl;
			game();
		}
		cout << "You cant attack" << endl;
		game();
	}
    if (turn % 2 == 1)
	{
		if (xyz[ll] == 1)
		{
			if (xyz[ll + 1] == 2 || xyz[ll - 1] == 2 || xyz[ll - 8] == 2 || xyz[ll + 8] == 2)
			{
				cout << "How many soldiers dou you want to attack with?  Soldiers:" << sol2 << "Food:" << food2 << endl;
				cin >> at;
				if (at <= sol2 && food2>=at * 4)
				{
					if (food1<2)
					{
						xyz[ll] = 2;
						cout << "You Succeed!" << endl;
						giveinf();
						giveland();
						system("pause");
						game();
					}
					cout << "(Player 1)How many soldiers do you want to defend with ?  Soldiers:" << sol1 << "Food:" << food1 << endl;
					cin >> def;
					if (def <= sol1 && food1>=def * 2)
					{
						sol2 -= at;
						sol1 -= def;
						food2 -= at * 4;
						food1 -= def * 2;
						if (ll == 1 || ll == 2 || ll == 9 || ll == 10 || ll == 17 || ll == 54 || ll == 55 || ll == 62 || ll == 63 || ll == 64)
						{
							while (at > 0 && def > 0)
							{
								if (n2 == 0)
								{
									def -= at / 15;
									if (n1 == 0)
									{
										at -= def / 10;
									}
									if (n1 == 1)
									{
										at -= def / 2;
									}
									if (n1 == 2)
									{
										at -= def / 10;
									}
								}
								if (n2 == 1)
								{
									def -= at / 25;
									if (n1 == 0)
									{
										at -= def / 10;
									}
									if (n1 == 1)
									{
										at -= def / 2;
									}
									if (n1 == 2)
									{
										at -= def / 10;
									}
								}
								if (n2 == 2)
								{
									def -= at / 25;
									if (n1 == 0)
									{
										at -= def / 10;
									}
									if (n1 == 1)
									{
										at -= def / 2;
									}
									if (n1 == 2)
									{
										at -= def / 10;
									}
								}
							}
						}
						else
						{
							while (at > 0 && def > 0)
							{
								if (n2 == 0)
								{
									def -= at / 10;
									if (n1 == 0)
									{
										at -= def / 15;
									}
									if (n1 == 1)
									{
										at -= def / 5;
									}
									if (n1 == 2)
									{
										at -= def / 15;
									}
								}
								if (n2 == 1)
								{
									def -= at / 20;
									if (n1 == 0)
									{
										at -= def / 15;
									}
									if (n1 == 1)
									{
										at -= def / 5;
									}
									if (n1 == 2)
									{
										at -= def / 15;
									}
								}
								if (n2 == 2)
								{
									def -= at / 20;
									if (n1 == 0)
									{
										at -= def / 15;
									}
									if (n1 == 1)
									{
										at -= def / 5;
									}
									if (n1 == 2)
									{
										at -= def / 15;
									}
								}
							}
						}
						if (def <= 0)
						{
							sol2 += at;
							xyz[ll] = 2;
							cout << "You Succeed!" << endl;
							giveinf();
							giveland();
							system("pause");
						}
						if (at <= 0)
						{
							sol1 += def;
							cout << "You Failed!" << endl;
							giveinf();
							system("pause");
						}
						game();
					}
					cout << "You dont have soldier or food!" << endl;
					game();
				}
				cout << "You dont have soldier or food!" << endl;
				game();
			}
			cout << "You cant attack" << endl;
			game();
		}
		cout << "You cant attack" << endl;
		game();
	}
}

void game()
{
    system("cls");
    check();
    gamer();
    cout << player << "'s Turn" << endl;
	if (q == 1)
	{
		events();
	}
	cout << "1-Shop" << endl;
	cout << "2-Attack" << endl;
	cout << "3-Map" << endl;
	cout << "4-Build" << endl;
	cout << "5-End Turn" << endl;
	cout << "6-Surrender" << endl;
	cout << "Choice:";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		shop();
		break;
	}
	case 2:
	{

		attack();
		break;
	}
	case 3:
	{
		zc = 0;
		system("cls");
		map();
		break;
	}
	case 4:
	{

		build();
		break;
	}
	case 5:
	{
		system("cls");
		takeland();
		endturn();
		turn++;
		q--;  
		giveinf();
		win();
		game();
		break;
	}
	case 6:
	{
		system("cls");
		turn++;
		gamer();
		cout << player << " WIN!" << endl;
		remove("Player1.txt");
		remove("Player2.txt");
		remove("Player1Lands.txt");
		remove("Player2Lands.txt");
		system("pause");
	    system("cls");
		break;
	}
	default:
	{
		cout << "EROR" << endl;
		break;
	}
	}
}

void start() 
{
	cout << "Welcome to Rule" << endl;
	cout << "1-New Game" << endl;
	cout << "2-Contunie" << endl;
	cout << "3-Rules" << endl;
	cout << "4-Exit" << endl;
	cout << "Choice:";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		coardination();
		system("cls");
		ofstream("Player1.txt", ios::out);
		ofstream("Player2.txt", ios::out);
		ofstream("Player1Lands.txt", ios::out);
		ofstream("Player2Lands.txt", ios::out);
		nations();
		break;
	}
	case 2:
	{
		system("cls");
		ifile.open("Player2Lands.txt", ios::in);
		if (ifile.is_open())
		{
			ifile.close();
			ifile.open("t.txt", ios::in);
			if (ifile.is_open())
			{
				turn = 0;
			}
			else
				turn = 1;
			ifile.close();
			takeinf();
			takeland();
			game();
		}
		else 
		{
			cout << "There isnt any game!" << endl;
			system("pause");
			system("cls");
		}
		start();
		break;
	}
	case 3:
	{
		system("cls");
		cout << "                      *****WELCOME TO RULE*****" << endl;
		cout << "Rules:" << endl;
		cout << "1-You will choose a nation, every nation has a different abilities." << endl;
		cout << "2-At the end of your turn you will win food and money(changes with nations and how many lands you have)." << endl;
		cout << "3-When you attack somewhere you have to choose how many soldiers do you want to attack with." << endl;
		cout << "4-1 soldier use 4 food in attack and use 2 food in defense, you have to be careful." << endl;
		cout << "                         *****GOOD LUCK*****" << endl;
		system("pause");
		system("cls");
		start();

	}
	case 4:
	{
		system("cls");
		break;
	}
	default:
	{
		cout << "EROR" << endl;
		break;
	}
	}
}

};

int main()
{
	Rule rule;
	rule.start();	
	system("pause");
    return 0;
}



