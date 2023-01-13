#include<iostream>
using namespace std;
#define MAX 100
struct atm
{
	string ht;
	char stk[15], mk[6];
	int sodu;
};
struct list
{
	int n;
	atm ds[MAX];	
};
void nhap(atm &x)
{
	cout << "Ho va ten : "; cin.ignore(); getline(cin, x.ht);
	cout << "So tai khoan : "; cin >> x.stk;
	cout << "Mat khau : "; cin >> x.mk;
	cout << "So du tai khoan : "; cin >> x.sodu;
}
void nhaplist(list &x)
{
	cout << "Nhap so luong the atm : "; cin >> x.n;
	for(int i = 0; i < x.n; i++)
	{
		nhap(x.ds[i]);
	}
}
// Bug: khong tim duoc stk da nhap
int DangNhap(list &x)
{
	char acount[15], pass[6];
	cout << "Moi quy khach nhap so tai khoan : " ; cin >> acount;
	cout << "Moi quy khach nhap mat khau : "; cin >> pass;
	for(int a = 0; a < x.n; a++)
	{
		cout << x.ds[a].stk << " " << x.ds[a].mk << "\n";
		if(acount == x.ds[a].stk && pass == x.ds[a].mk)
		{
			cout << "Xin chào mung " << x.ds[a].ht << " den voi ATM LeanBank\n";
			return a;
		}
	}
	return -1;
}

int menu(list &x)
{
	int choice;
	cout << "1. Xem so du" << endl;
	cout << "2. Rut tien" << endl;
	cout << "3. Nhap tien" << endl;
	cout << "4. Chuyen tien" << endl;
	cout << "0. Thoat" << endl;
	cout << "Moi quy khach chon chuc nang : ";
	while(choice > 4 || choice < 0)
	{
		cin >> choice;
		cout << "Quy khach chi chon tu 0 -> 4 !!!" << endl;
		cout << "Moi quy khach chon lai : ";
	}
	return choice;
}
void sodu(list &x, atm &me)
{
	char tt;
	cout << "So du trong tai khoan cua ban hien tai la : " << me.sodu << " VND\n";
	cout << "Ban co muon tiep tuc thuc hien giao dich khac (Y/N) : "; cin >> tt;
	if(tt == 'Y') menu(x);
}
void ruttien(list &x, atm &me)
{
	int y;
	cout << "So tien ban muon rut : ";
	while(me.sodu < y)
	{
		cin >> y;
		cout << "So du tai khoan cua ban khong du de rut tien!!!\n";
		cout << "Vui long nhap lai so tien ban muon rut : ";
	}
	me.sodu -= y;
	cout << "Ban da rut so tien la : " << y << " VND, so du tai khoan hien tai la : " << me.sodu << " VND\n";
	char tt;
	cout << "Ban co muon tiep tuc thuc hien giao dich khac (Y/N) : "; cin >> tt;
	if(tt == 'Y') menu(x);
}
void naptien(list &x, atm &me)
{
	int y;
	cout << "So tien ban muon nap : "; cin >> y;
	me.sodu += y;
	cout << "Ban da nap so tien la : " << y << " VND, so du tai khoan hien tai la : " << me.sodu << " VND\n";
	char tt;
	cout << "Ban co muon tiep tuc thuc hien giao dich khac (Y/N) : "; cin >> tt;
	if(tt == 'Y') menu(x);
}
void chuyentien(list &x, atm &me)
{
	char tk[15];
	int flag = 0, y;
	cout << "So tai khoan nguoi dung can chuyen den : "; cin >> tk;
	for(int i = 0; i < x.n; i++)
	{
		if(x.ds[i].stk == tk)
		{
			cout << "So tien ban muon chuyen : ";
			while(me.sodu < y)
			{
				cin >> y;
				cout << "So du tai khoan cua ban khong du de chuyen tien!!!\n";
				cout << "Vui long nhap lai so tien ban muon chuyen : ";
			}
			me.sodu -= y;
			x.ds[i].sodu += y;
			flag = 1;
			break;
		}
	}
	if(flag == 0) cout << "Khong ton tai so tai khoan nguoi dung hop le!!!\n";
	char tt;
	cout << "Ban co muon tiep tuc thuc hien giao dich khac (Y/N) : "; cin >> tt;
	if(tt == 'Y') menu(x);
}
int main()
{
	list x;
	nhaplist(x);
	int index = DangNhap(x);
	/*
	if(index == -1)
	{
		for(int i = 0; i < 3; i++)
		{
			index = DangNhap(x);
			if(index != -1) break;
		}
	}
	*/
	cout << index;
	/*
	int bottom;
	while(bottom != 0)
	{
		bottom = menu(x);
	    switch(bottom)
	    {
			case 1:sodu(x, x.ds[index]); break;
			case 2:ruttien(x, x.ds[index]); break;
			case 3:naptien(x, x.ds[index]); break;
			case 4:chuyentien(x, x.ds[index]); break;
			default: (bottom == 1||bottom == 2||bottom == 3||bottom == 4||bottom == 0);
		}
	}
	*/
	return 0;
}
