
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "chuyenbay.h"
using namespace std;
string gioiTinh[3]={"Nam","Nu","Khac"};
struct hanhKhach{
	string CMND;
	string ho;
	string ten;
	int phai;
};
struct node_hk{
	hanhKhach data;
	node_hk *pLeft;
	node_hk *pRight;
};
typedef struct node_hk NODEHK;
typedef NODEHK* List_hk;
int demHK;
void KhoiTaoCay(List_hk &TREE)
{
	TREE=NULL;
}
void xuat_DSHK(List_hk listhk)//SHOW TAT CAC CAC HANH KHACH CO TRONG DANH SACH
{
     if(listhk!=NULL)
     {
      xuat_DSHK(listhk->pLeft);
      ///show thong tin
      cout<<listhk->data.CMND<<endl;
      cout<<listhk->data.ho<<" "<<listhk->data.ten<<endl;
      cout<<listhk->data.phai<<endl;
      
      xuat_DSHK(listhk->pRight);
     }
}
//kitra hanh khach
List_hk KiemTraHK(List_hk T, string soCMND)//tra ve mot NODE *
{
	if(T == NULL)
	{
		return NULL;
	}
	else
	{
		if(strcmp(T->data.CMND.c_str(), soCMND.c_str()) > 0)
		{
			KiemTraHK(T->pLeft, soCMND);
		}
		
		else if(strcmp(T->data.CMND.c_str(), soCMND.c_str()) < 0)
		{
			KiemTraHK(T->pRight, soCMND);
		}
		
		else //T->data.CMND == CMND -> tim thay
		return T;
	}
}
//them theo cay nhi phan tim kiem
void InsertHanhKhach(List_hk &T,hanhKhach hk)
{//theo kieu LNR
	//chen mot node vao cay
	if(T == NULL)
	{
		NODEHK *p = new NODEHK;
		p->data.CMND=hk.CMND;
		p->data.ho=hk.ho;
		p->data.ten=hk.ten;
		p->data.phai = hk.phai;
		p->pLeft = NULL;
		p->pRight = NULL;
		T = p;//T cung la mot NODEHK va p cung la mot NODEHK
	}
	
	else
	{//TREE co ton tai phan tu
		if(T->data.CMND>hk.CMND)
		{
			return InsertHanhKhach(T->pLeft,hk);//chen vao node trai
		}
		else if(T->data.CMND<hk.CMND)
		{
			return InsertHanhKhach(T->pRight,hk);//chen voo node phai
		}
	}
}
hanhKhach nhap_hk(List_hk &l_hk){
	int x= cot;
	int y=dong;
	system ("cls");
	hanhKhach p;
	//nhap ma chuyen bay
	khung(x+30,y);	
	gotoxy(x-5,y);
	cout<<"NHAP CMND:";
	gotoxy(x+40,y);
	getline(cin,p.CMND);
	while(KiemTraHK(l_hk,p.CMND)!=NULL||ktra_chuoi(p.CMND)==0){
		khung(x+30,y);	
		gotoxy(x+40,y);
	 	cout<"                      ";
	 	gotoxy(x+40,y);
	 	cout<"                      ";
		gotoxy(x-5,y);
		cout<<"NHAP CMND:";
		gotoxy(x+40,y);
		getline(cin,p.CMND);
	}
	//NHAP HO
	gotoxy(x-5,y+4);
	cout<<"NHAP HO & TEN:";
	khung(x+30,y+4);
	gotoxy(x+40,y+4);
	cin.ignore();
	getline(cin,p.ho);	
	//NHAP TEN
	gotoxy(x+45,y+4);
	cin.ignore();
	getline(cin,p.ten);	
	while(ktra_chuoi(p.ho)==0 ||ktra_chuoi(p.ten)==0){
	 	gotoxy(x+40,y+4);
	 	cout<"                                  ";
		gotoxy(x,y);
		cout<<"NHAP HO & TEN:";
		gotoxy(x+40,y+4);
		cin.ignore();
		getline(cin,p.ho);	
		gotoxy(x+45,y+4);
		cin.ignore();
		getline(cin,p.ten);	
	}
	
	gotoxy(x-5,y+8);
	cout<<"NHAP GIOI TINH (1:NAM  2:NU  3:KHAC):";
	gotoxy(x+40,y+7);
	cout<<"----------";
	gotoxy(x+40,y+8);
	cout<<"|        |";
	gotoxy(x+40,y+9);
	cout<<"|________|";
	gotoxy(x+45,y+10);
	cin>>p.phai;
	return p;
}

void NodeThayThe(List_hk &T,List_hk &tam )//rp->right,rp
{
	
	// tim node trai nhat
	if(T->pLeft!=NULL)
	{
		NodeThayThe(T->pLeft,tam);
	}
	else 
	{
		tam->data=T->data; // lay du lieu cua node trai nhat cho vao bien tam
		tam=T;
		T=T->pRight;
		//return tam;
	}
}
void xoa_1_hk(List_hk T, string x){
	if(T==NULL){
		cout<<"DANH SACH HANH KHACH RONG!";
	}
	else{
		List_hk p = KiemTraHK(T,x);
		if(T->pLeft==NULL)   // neu hk chi co node con R
		{	
			T=T->pRight;
			
		}
		else if(T->pRight==NULL)	//neu hk chi co node con L
		{
			T=T->pLeft;
			}
		else // hk co 2 node con L & R
		{
	
			NodeThayThe(T->pRight,p);
		}
		delete p;
	}
}
void sua_tt_hk(List_hk &T, string x){
	if(T==NULL){
		cout<<"";
	}
}
