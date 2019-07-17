#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "mylib.h"


using namespace std;



const int so_item_main = 5;
const int so_item_mb = 5;
const int so_item_cb = 5;
const int so_item_hk = 5;
const int so_item_dscb =7;
const int so_item_dshk =7;
const int dong =5;
const int cot = 30;
const int Up = 72;
const int Down = 80;
char thucdon [so_item_main][50] = {"||> QUAN LY MAY BAY       ",
			                  		   "||> QUAN LY CHUYEN BAY    ",
			                           "||> QUAN LY HANH KHACH    ",
			                           "||> DAT VE                ",
			                           "||> HUY VE                ",
			                           "||> ESC                   "};
char thucdon_mb [so_item_mb][50] = {"||> THEM MAY BAY       ",
			                  		   "||> SUA THONG TIN MAY BAY    ",
			                           "||> XOA MAY BAY    ",
			                           "||> DANH SACH MAY BAY                ",
			                           "||> ESC                   "};
char thucdon_cb [so_item_mb][50] = {"||> THEM CHUYEN BAY       ",
			                  		   "||> SUA THONG TIN CHUYEN BAY    ",
			                           "||> XOA CHUYEN BAY    ",
			                           "||> DANH SACH CHUYEN BAY                ",
			                           "||> ESC                   "};
char thucdon_hk [so_item_mb][50] = {"||> THEM HANH KHACH       ",
			                  		   "||> SUA THONG TIN HANH KHACH    ",
			                           "||> XOA HANH KHACH    ",
			                           "||> DANH SACH HANH KHACH                ",
			                           "||> ESC                   "};
char thucdon_dscb [so_item_dscb][50] = {"||> DANH SACH TAT CA CHUYEN BAY     ",
			                  		   "||> DANH SACH CHUYEN BAY CO CUNG NOI DEN && CUNG NGAY    ",
			                           "||> DANH SACH CHUYEN BAY BAY CUNG NGAY    ",
			                           "||> THONG KE CHUYEN BAY CUA TUNG MAY BAY               
			                           "||> ESC                   "};
char thucdon_dshk [so_item_dshk][50] = {"||> DANH SACH TAT CA KHACH HANG    ",		
									   "||> DANH SACH HANH KHACH CUNG CHUYEN BAY       ",
			                           "||> ESC                   "};
void Normal () {
	SetColor(WHITE);
	SetBGColor(8);
}
void HighLight () {
	SetColor(15);
	SetBGColor(3);
}



int MenuDong(char td [so_item][50], int d, int c){
  Normal();
  system("cls");   int chon =0;
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(c, d +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(c,d+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(c,d+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(c,d+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(c,d+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(c,d+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  }  // end switch
  } while (1);
}
void menu_mb(List_mb &l_mb){
	int chon;
	  do
	  {
	    chon = MenuDong (thucdon_mb,dong,cot+10);
	    system ("cls");
	    switch (chon ){
	    case 1: {
	    	mayBay mb  = nhap_ds_mb();
			addMb(l_mb,mb);
			break;
		};
	    case 2:{
	    	cout<<"NHAP SO HIEU MAY BAY CAN SUA";
	    	string tt;
	    	getline(cin,tt);
	    	sua_tt_mb(l_mb,tt)
			break;
		} ;
	    case 3: {
	    	cout<<"NHAP SO HIEU MAY BAY CAN XOA";
	    	string tt;
	    	getline.cin,tt);
	    	xoa_mb(l_mb,tt)
		      break;
		    };
		case 4: { xuat_ds_mb(l_mb);
		      break;
		    };    
	    case 5:  break;
	   }
	  } while (1);
}
void menu_chinh(List_mb &l_mb){
	int chon;
	  do
	  {
	    chon = MenuDong (thucdon,dong,cot+10);
	    system ("cls");
	    switch (chon ){
	    case 1: {
	    	menu_mb(l_mb);
			break;
		};
	    case 2:{
	    	cout<<"Nhap thong tin can sua";
	    	char *tt;
	    	cin>>tt;
	    	sua_tt_mb(l_mb,)
			break;
		} ;
	    case 3: { printf ("\n Ban nhap ma so sinh vien : ") ;
		      break;
		    };
		case 4: { printf ("\n Ban nhap ma so sinh vien muon xoa : ") ;
		      break;
		    };    
	    case 5:  break;
	   }
	  } while (1);
}

void showmaybay()
{
	cout<<"May bay"<<endl;
	system("pause");
}

void showchuyenbay()
{
	cout<<"cHUYEN bay 111"<<endl;
	system("pause");
}



