#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "mylib.h"

using namespace std;
#define MAX_LIST_MB 300
#define MAX_DAY 20
#define MAX_DONG 50
#define MAX_VE 100
const int cot =50;
const int dong = 10;
string ten_day[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
char menu_sua_mb[5][50]={"1. SO HIEU",
						"2. LOAI",
						"3. SO DAY",
						"4.SO DONG",
						"5.THOAT"};
//khai bao mang ds ve
struct ds_ve{
	int n;
	string ten_ve[MAX_VE];
};
//khai bao kdl may bay
struct mayBay{
	string so_hieu_MB;
	string loai_may_bay;
	int so_day;
	int so_dong;
	ds_ve ve;
};
//khai bao mang con tro ds may bay
struct List_mb{
	int  n = -1;
	mayBay *mb[MAX_LIST_MB];
};


//luu 1 may bay vao file
void Save_1MB(ofstream &fileout, mayBay *mb)// ham ghi du lieu 1 may bay vao file
{
	
		fileout << endl;
		fileout << mb->so_hieu_MB << ",";
		fileout << mb->loai_may_bay << ",";
		fileout << mb->so_day <<",";
		fileout << mb->so_dong;
}
//luu danh sach may bay
void Save_DSMB( List_mb listmb)//ham ghi DSMB vao file
{
	ofstream fileout;
	fileout.open("DSMB.txt", ios::out);
	fileout<<listmb.n;
	for(int i = 0 ; i <= listmb.n ; i++)
	{
		Save_1MB(fileout, listmb.mb[i]);
	}
	fileout.close();
}
// ham doc du lieu 1 may bay tu file
void Read_1MB(ifstream &filein, mayBay *mb)
{
	string dau;
	filein>>dau;
	filein>>mb->so_hieu_MB;
	filein>>dau;
	filein>>mb->loai_may_bay;
	filein>>dau;
	filein>>mb->so_day;
	filein>>dau;
	filein>>mb->so_dong;
	// tao bien tam de doc cac ky tu xuong y o cuoi y //
	string temp;
	getline(filein, temp);
}


// ham doc danh sach may bay vao file - Luu y phai co it nhat 1 may bay trong file truoc
void Read_DSMB(ifstream &filein, List_mb &listmb){
	// doc den cuoi file thi dung
	while (!filein.eof())
{
		/*---Doc thong tin may bay---*/
		int so;
		filein>>so;
		for(int i = 0; i <= so ; i++ ){
			Read_1MB(filein,listmb.mb[i]);
		}
	}
	filein.close();
}

//sap xep may bay tang dan theo so hieu
void sapxep_mb(List_mb &l_mb){
	mayBay *tam;
	for(int i=0;i<l_mb.n;i++){
		for(int j=i+1;j<l_mb.n;j++){
			if(strcmp(l_mb.mb[i]->so_hieu_MB.c_str(),l_mb.mb[j]->so_hieu_MB.c_str())>0){
				tam = l_mb.mb[i];
				l_mb.mb[i] = l_mb.mb[j];
				l_mb.mb[j] = tam;
			}
		}
	}
}


//them may bao vao ds
void addMb(List_mb &lsMb, mayBay mb)
{
	if(lsMb.n==MAX_LIST_MB){
		cout<<"DANH SACH  DAY! KHONG THEM DUOC";
	}
	else{
			lsMb.n++;
			lsMb.mb[lsMb.n] =&mb;
			sapxep_mb(lsMb);
	}
}

void NhapChuoi (char *tieude, char *S) {
	cout << tieude ;  fflush(stdin);
    do
	  gets(S);
    while (strcmp(S,"")==0)  ;	
}
//tao khung
void khung(int x, int y){
	gotoxy(x,y-2);
	cout<<"_______________________________";
	gotoxy(x+30,y);
	cout<<"|";
	gotoxy(x,y-1);
	cout<<"|";
	gotoxy(x+30,y-1);
	cout<<"|";
	gotoxy(x+30,y);
	cout<<"|";
	gotoxy(x,y);
	cout<<"|";
	gotoxy(x,y+1);
	cout<<"|_____________________________|";
}
//kiem tra ki tu dau la khoang trang: chua vviet

//kiem tra chuoi rong
int ktra_chuoi(string x){
	if(x.empty()==true) return 0;
	else return 1;
	}
//tim kiem theo so hieu trong ds may bay
int Search_mb(List_mb &l_mb, string x) {
  for (int i =0; i <= l_mb.n ; i++){
  	 if (strcmp(l_mb.mb[i]->so_hieu_MB.c_str(),x.c_str())==0) return i;
  	}
  return -1;
}
//nhap thong tin1 may bay
mayBay nhap_1_mb(List_mb &l_mb){
	int x= cot;
	int y=dong;
	system ("cls");
	mayBay mb;
	khung(x+20,y);	
	gotoxy(x,y);
	cout<<"NHAP SO HIEU:";
	gotoxy(x+30,y);
	getline(cin, mb.so_hieu_MB);
	while((ktra_chuoi(mb.so_hieu_MB)==0||Search_mb(l_mb, mb.so_hieu_MB)!=-1)){
	 		khung(x+20,y);	
	 		gotoxy(x+20,y);
	 		cout<"                      ";
	 		gotoxy(x+30,y);
	 		cout<"                      ";
			gotoxy(x,y);
			cout<<"NHAP SO HIEU:";
			gotoxy(x+30,y);
			getline(cin, mb.so_hieu_MB);
	}
	gotoxy(x,y+4);
	cout<<"NHAP SO LOAI:";
	khung(x+20,y+4);
	gotoxy(x+30,y+4);
	getline(cin, mb.loai_may_bay);
	while(ktra_chuoi(mb.loai_may_bay)==0){
	 		gotoxy(x,y+4);
	 		gotoxy(x+20,y+4);
	 		cout<"                      ";
	 		gotoxy(x+30,y+4);
	 		cout<"                      ";
			cout<<"NHAP SO LOAI:";
			khung(x+20,y+4);
			gotoxy(x+30,y+4);
			getline(cin, mb.loai_may_bay);
	}	
	gotoxy(x,y+8);
	cout<<"NHAP SO DAY:";
		khung(x+20,y+8);
		gotoxy(x+30,y+8);
	cin>>mb.so_day;
	while(mb.so_day<=0||mb.so_day>=26){
		gotoxy(x+20,y+8);
		cout<<"                   ";
		gotoxy(x+30,y+8);
	 	cout<"                      ";
			gotoxy(x,y+8);
		cout<<"NHAP SO DAY:";
		khung(x+20,y+8);
		gotoxy(x+30,y+8);
		cin>>mb.so_day;
	}
	gotoxy(x,y+12);
	cout<<"NHAP SO DONG:";
		khung(x+20,y+12);
		gotoxy(x+30,y+12);
	cin>>mb.so_dong;
	while(mb.so_dong>100){
		gotoxy(x+20,y+12);
		cout<<"                   ";
		gotoxy(x+30,y+12);
	 	cout<"                      ";
		gotoxy(x,y+12);
		cout<<"NHAP SO DONG:";
		khung(x+20,y+12);
		gotoxy(x+30,y+12);
		cin>>mb.so_dong;		
	}
	return mb;
}
//ten ghe trong 1 may bay
void tenGhe(mayBay *mb){
	 int i = 0 ;
    	for(int j=0;j<mb->so_day;j++){
			for(int k=0;k<mb->so_dong;k++){
				mb->ve.ten_ve[i] =ten_day[j] + to_string(k);
					cout<<mb->ve.ten_ve[i]<<"\t";
				i++;
				mb->ve.n=i;	
			}
			cout<<"\n";
		}
		
}
//xuat thong tin 1 may bay
void xuat_1_mb(mayBay *p_mb,int x,int y){
	khung(x,y);
	gotoxy(x+10,y);
	cout<<p_mb->so_hieu_MB;
	khung(x+30,y);
	gotoxy(x+40,y);
	cout<<p_mb->loai_may_bay;
	khung(x+60,y);
	gotoxy(x+70,y);
	cout<<p_mb->so_day;
	khung(x+90,y);
	gotoxy(x+100,y);
	cout<<p_mb->so_dong;
	tenGhe(p_mb);
//	for(int i=0;i<p_mb->ve.n;i++){
//		cout<<p_mb->ve.ten_ve[i]<<"\t";
//		}
		
}
//nhap danh sach may bay
mayBay nhap_ds_mb(List_mb &l_mb){
		if(l_mb.n>MAX_LIST_MB) cout<<"DS DAY!";
		return nhap_1_mb(l_mb);
	
}
//xuat thong tin danh sach may bay
void xuat_ds_mb(List_mb &l_mb){
//	ifstream filein;
//	filein.open("DSMB.txt", ios::in);//doc ds mb
//	Read_DSMB(filein,l_mb);//MAYBAY
	int x = 10;
	int y =0;
	gotoxy(60,2);
	cout<<"DANH SACH MAY BAY";
	khung(x,y+4);
	gotoxy(x+10,y+4);
	cout<<"SO HIEU";
	khung(x+30,y+4);
	gotoxy(x+40,y+4);
	cout<<"LOAI";
	khung(x+60,y+4);
	gotoxy(x+70,y+4);
	cout<<"SO DAY";
	khung(x+90,y+4);
	gotoxy(x+100,y+4);
	cout<<"SO DONG";
	for(int i=0; i<= l_mb.n;i++){
		xuat_1_mb(l_mb.mb[i],x,y+7+(i*4));
	}
}
//xoa 1 may bay theo so hieu
void xoa_mb(List_mb &l_mb, string x){
	if(l_mb.n==0) cout<<"DS RONG!";
   int i = Search_mb(l_mb,x ) ;
   if (i==-1) cout<<"So hieu may bay khong co trong danh sach";
   else  
   {
     for (int j=i+1; j <l_mb.n; j++)
       l_mb.mb[j-1]=l_mb.mb[j];
     l_mb.n--;  
     system("cls");
    khung(50,40);
	gotoxy(55,40);
	cout<<"DA XOA!";
	}
}


