// backSkill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void setpnt(int &ppnt, int setingamnt, string name) {
	if (ppnt < setingamnt) {
		ppnt = setingamnt;
		cout << name << " has been set to " << ppnt << "\n";
	}
}
void totalclk(int &item, int max, int &item1, int max1, int &item2, int max2, int total, string name, string name1, string name2) {

	int totAlo = total;
	if (item + item1 + item2<total) {
		cout << "you have a total of " << total << " piolet points you need to place in " << name << ", " << name1 << " and, " << name2 << "\n";
		cout << "what ever you dont place in " << name << " or " << name1 << " will be placed in " << name2 << "\n";
		cout << "how many do you want to place in " << name << "\n";
		cout << "alocate Piolet points:";
		cin >> item;
		if (item>max) {
			item = max;
		}
		if (item >= totAlo) {
			item = totAlo;
			return;
		}
		else {
			totAlo = total - item;

			cout << "how many do you want to place in " << name1 << "\n";
			cout << "alocate Piolet points:";
			cin >> item1;
			if (item1>max1) {
				item1 = max1;
			}

			if (item1 >= totAlo) {
				item1 = totAlo;
				return;
			}
			else {
				totAlo -= item1;


				item2 = totAlo;
				if (item2>max2) {
					item2 = max2;
					item1 += total - max2;
				}

				cout << item2 << " piolet points were placed in " << name2;
				cout << "\n\n\n";
			}
			if (item2) {

			}
		}
	}
}
void totalclk(int &itnum, int &itnum2, int total, string name1, string name2) {
	if (itnum + itnum2<total) {

		cout << "you have a total of " << total << " piolet points you need to place in " << name1 << " and " << name2 << "\n";
		cout << "what ever you dont place in " << name1 << " will be placed in " << name2 << "\n";
		cout << "alocate Piolet points:";
		cin >> itnum;
		if (itnum>total)
			itnum = total;

		itnum2 = total - itnum;
		cout << itnum2 << " Piolet points were placed in " << name2 << "\n";
	}
}
void pickone(int &d, int &c, int &a, string dname, string cname, string aname) {
	if (d + a + c == 0) {
		cout << "\nchoose wich spot to place your piolet point \n";
		cout << "1: " << dname << "\n2: " << cname << "\n3: " << aname << "\n";
		int select = 0;
		cout << "selectoun: ";
		cin >> select;
		if (select == 1) {
			d = 1;
		}
		else
			if (select == 2) {
				c = 1;
			}
			else
				if (select == 3) {
					a = 1;
				}
				else {
					d = 1;
				}
	}
}
void defenceCalk(int d[][7], int c[][9], int a[][9], string dname[], string cname[], string aname[]) {
	string Poilet = "piolet points";
	if (d[0][6] != 0) {

		setpnt(d[0][3], 2, dname[3]);
		setpnt(d[0][5], 3, dname[5]);

	}
	if (d[0][5] != 0) {
		setpnt(d[0][4], 3, dname[4]);

	}
	if (d[0][4] != 0) {
		setpnt(d[0][0], 2, dname[0]);
		cout << "\n\n\n";
	}
	if (d[0][3] + a[0][3] != 0) {
		if (d[0][2] + a[0][2]<2) {
			totalclk(d[0][2], a[0][2], 2, dname[2], aname[2]);

		}
	}
	if (d[0][2] + a[0][2] != 0) {
		pickone(d[0][1], a[0][1], c[0][1], dname[1], cname[1], aname[1]);
	}
	if (d[0][1] + a[0][1] + c[0][1] != 0) {
		pickone(d[0][0], a[0][0], c[0][0], dname[0], cname[0], aname[0]);
	}
}
void attackCalk(int d[][7], int c[][9], int a[][9], string dname[], string cname[], string aname[]) {
	cout << "\n";

	if (a[0][8] != 0) {
		setpnt(a[0][3], 2, aname[3]);

		totalclk(a[0][7], c[0][6], 3, aname[7], cname[6]);
	}
	if (a[0][7] + c[0][6] != 0) {
		cout << "\n\n\n";
		totalclk(d[0][5], d[1][5], c[0][5], c[1][5], a[0][6], a[1][6], 5, dname[5], cname[5], aname[6]);
	}
	if (a[0][6] + c[0][5] != 0) {
		cout << "\n\n\n";
		totalclk(a[0][5], c[0][4], 3, aname[5], cname[4]);
	}
	if (c[0][4] != 0) {
		cout << "\n\n\n";
		totalclk(d[0][4], d[1][4], c[0][3], c[1][3], a[0][4], a[1][4], 2, dname[4], cname[3], aname[4]);
	}
	if (a[0][5] != 0) {
		cout << "\n\n\n";
		if (a[0][4]<2)
			a[0][4] = 2;
		if (c[0][3]<2)
			c[0][3] = 2;
		cout << aname[4] << " has been set to " << a[0][4] << "\n";
		cout << cname[3] << " has been set to " << c[0][3] << "\n";
	}
	if (a[0][6] != 0) {
		a[0][0] = 2;
	}

}
void setPoiletPnts(int &chang, int max, string name) {
	cout << "what is the amount you want to place in " << name << "you may place no more than " << max << "\n";
	cout << "alocate Piolet points:";
	cin >> chang;
	if (chang>max)
		chang = max;
}
void colectCalk(int d[][7], int c[][9], int a[][9], string dname[], string cname[], string aname[]) {
	if (c[0][8] != 0) {
		setpnt(a[0][8], 3, aname[8]);
		setpnt(d[0][6], 3, dname[6]);
		setpnt(c[0][2], 2, cname[2]);
	}
	if (c[0][3] != 0) {
		totalclk(d[0][3], d[1][3], c[0][2], c[1][2], a[0][3], a[1][3], 2, dname[2], cname[2], aname[3]);
	}
	if (c[0][2] != 0) {
		setpnt(c[0][1], 2, cname[1]);
	}

}
string selectfile() {
	ifstream myFile("file.txt", ios::in);
	
	
		cout << "reading file";
		string str="";
		while (getline(myFile, str))
		{
			cout << str;
			cout << endl;
		}
	
	string select = "";
	cout << "selection: ";
	cin >> select;
	select += ":";
	myFile.open("file.txt", ios::in);
	if (myFile.good())
	{
		string str = "";

		while (getline(myFile, str))
		{

			if (str.find(select) == 0) {
				return str.substr(str.find(":") + 1);
				myFile.close();
			}
		}
	}
	myFile.close();
	return "";
}
void delSelectFile(string str1) {

	ofstream tempF("temp.txt", ios_base::ate);
	ifstream myFile("file.txt", ios::in);
	if (myFile.good())
	{
		string str;

		while (getline(myFile, str))
		{

			if (str.find(str1) == string::npos) {
				tempF << str << "\n";
			}
		}
	}
	tempF.close();
	myFile.close();
	remove("file.txt");
	rename("temp.txt", "file.txt");
}
void open(int d[][7], int c[][9], int a[][9]) {
	string fn = selectfile();
	cout << fn << "\n\n";
	if (fn != "") {
		ifstream myFile(fn, ios::in);
		string str = "";
		int k = 0;
		if (myFile.good()) {
			cout << "why restart";
			while (getline(myFile, str))
			{

				for (unsigned i = 0; i < str.length(); ++i)
				{
					if (k == 0)
						d[0][i] = str.at(i) - 48;
					if (k == 1)
						c[0][i] = str.at(i) - 48;
					if (k == 2)
						a[0][i] = str.at(i) - 48;
				}
				k++;
			}
			cout << "\n\n";
		}
	}

}
void save(int d[][7], int c[][9], int a[][9]) {
	cout << "\n\n";
	ifstream myFile("file.txt", ios::in);
	if (myFile.good())
	{
		string str;
		while (getline(myFile, str))
		{
			cout << str;
			cout << endl;
		}
	}

	ofstream oMyfile("file.txt", ios_base::app);
	string fname = "";
	cout << "\nwhat do you want to call your file\nName: ";
	cin.ignore();
	getline(cin, fname);
	if (fname.find(".txt") == string::npos)
		fname += ".txt";

	myFile.open("file.txt", ios::in);
	string str = "";
	bool found = false;
	int lnNum = 0;
	while (getline(myFile, str) && !found)
	{
		lnNum++;
		if (str.find(fname) != string::npos) {
			found = true;
		}
	}
	if (!found)
		oMyfile << "\n" << lnNum + 1 << ":" << fname;

	ofstream newfile(fname, ios_base::ate);
	for (int i = 0; i < 7; i++) {
		newfile << d[0][i];
	}
	newfile << "\n";
	for (int i = 0; i < 9; i++) {
		newfile << c[0][i];
	}
	newfile << "\n";
	for (int i = 0; i < 9; i++) {
		newfile << a[0][i];
	}
	newfile << "\n";
}
string spase(int sp) {
	string stp = "";
	for (int i = 0; i < sp; i++) {
		stp += " ";
	}
	return stp;
}
void deleatFile() {
	string fn = selectfile();
	delSelectFile(fn);
	if (fn != "") {

		if (remove(fn.c_str()) != 0)
		{
			perror("Error deleting file");
		}
		else
		{
			puts("File successfully deleted");
		}

	}
}
string arrTostring(int d[], int c[], int a[], string dname[], string cname[], string aname[]) {
	string rst = "";
	int totpnt = 0;
	string attak = " Attack ";
	string colect = " Colect ";
	cout << endl << colect << spase(33 - colect.length()) << attak << spase(33 - attak.length()) << " Defence \n\n";

	for (int i = 0; i < 9; i++) {
		cout << cname[i] << " = " << c[i] << spase(27 - cname[i].length());
		cout << aname[i] << " = " << a[i] << spase(27 - aname[i].length());
		if (i < 7) {
			cout << dname[i] << " = " << d[i];
			totpnt += d[i] + c[i] + a[i];
		}
		else {
			totpnt += c[i] + a[i];
		}
		cout << "\n";
	}
	cout << "the total piolet points used were " << totpnt << "\n\n";
	return rst;
}

int main(int argc, char *argv[]) {

	string dname[7] = { "\"Ship hull 1\"", "\"Enginearing\"","\"Shield enginearing\"", "\"Evasive maneuvers 1\"","\"Ship hull 2\"", "\"shield mechanics\"", "\"Evasive maneuvers 2\"" };
	string cname[9] = { "\"Tactics\"","\"Logistics\"", "\"Luck 1\"", "\"Cruelty 1\"","\"Tractor beam 1\"", "\"gread\"","\"Tractor beam 2\"","\"Cruelty 2\"", "\"luck 2\"" };
	string aname[9] = { "\"Detonation 1\"", "\"Explosives\"", "\"Heat-seeking missiles\"", "\"Bounty hunter 1\"","\"Rocket fusion\"", "\"Alien hunter\"",  "\"Detonation 2\"","\"Electro-optics\"","\"Bounty hunter 2\"" };
	int selection = 1;
	while (selection == 1 || selection == 2 || selection == 3)
	{
		int totPPnt = 0;
		int d[2][7] = { { 0 },{ 2,5,5,2,3,5,3 } };
		int c[2][9] = { { 0 },{ 5,5,2,2,5,5,5,3,3 } };
		int a[2][9] = { { 0 },{ 2,5,5,2,5,5,3,5,3 } };
		cout << "1: open document\n";
		cout << "2: build skill tree\n";
		cout << "3: deleat file\n";
		cout << "4: end\n";
		cin >> selection;
		if (selection == 1) {
			open(d, c, a);
			arrTostring(d[0], c[0], a[0], dname, cname, aname);
		}
		if (selection == 2) {
			setPoiletPnts(d[0][6], d[1][6], dname[6]);
			setPoiletPnts(c[0][8], c[1][8], cname[8]);
			setPoiletPnts(a[0][8], a[1][8], aname[8]);
			setPoiletPnts(a[0][5], a[1][5], aname[5]);
			colectCalk(d, c, a, dname, cname, aname);
			attackCalk(d, c, a, dname, cname, aname);
			defenceCalk(d, c, a, dname, cname, aname);

			arrTostring(d[0], c[0], a[0], dname, cname, aname);
			char decide;
			cout << "would you like to save y for yes n for no\n";
			cin >> decide;
			if (decide == 'y')
				save(d, c, a);
		}
		if (selection == 3) {
			deleatFile();
		}

	}
}
