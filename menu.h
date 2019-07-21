#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <time.h>
//#include "mylib.h"
#include "ve.h"
#include "tendetai.h"
using namespace std;


const int so_item_main = 6;
const int so_item_mb = 5;
const int so_item_cb = 5;
const int so_item_hk = 5;
const int so_item_dscb =5;
const int so_item_dshk =3;
const int so_item_sua_cb = 6;
const int so_item_yn =2;
//const int y =20;
//const int x = 50;
const int Up = 72;
const int Down = 80;
char thucdon [so_item_main][50] = {"||> QUAN LY MAY BAY       ",
			                  		   "||> QUAN LY CHUYEN BAY    ",
			                           "||> QUAN LY HANH KHACH    ",
			                           "||> DAT VE                ",
			                           "||> HUY VE                ",
			                           "||> THOAT     "};
char thucdon_mb [so_item_mb][50] = {"||> THEM MAY BAY       ",
			                  		   "||> SUA THONG TIN MAY BAY    ",
			                           "||> XOA MAY BAY    ",
			                           "||> DANH SACH MAY BAY                ",
			                           "||> THOAT                   "};
char thucdon_cb [so_item_mb][50] = {"||> THEM CHUYEN BAY       ",
			                  		   "||> SUA THONG TIN CHUYEN BAY    ",
			                           "||> XOA CHUYEN BAY    ",
			                           "||> DANH SACH CHUYEN BAY                ",
			                           "||> THOAT                   "};
char thucdon_hk [so_item_mb][50] = {"||> THEM HANH KHACH       ",
			                  		   "||> SUA THONG TIN HANH KHACH    ",
			                           "||> XOA HANH KHACH    ",
			                           "||> DANH SACH HANH KHACH                 ",
			                           "||> THOAT                   "};
char thucdon_dscb [so_item_dscb][100] = {"||> DANH SACH TAT CA CHUYEN BAY     ",
			                  		   "||> DANH SACH CHUYEN BAY CO CUNG NOI DEN && CUNG NGAY    ",
			                           "||> DANH SACH CHUYEN BAY BAY CUNG NGAY    ",
			                           "||> THONG KE CHUYEN BAY CUA TUNG MAY BAY ",
			                           "||> THOAT                   "};
char thucdon_dshk [so_item_dshk][50] = {"||> DANH SACH TAT CA KHACH HANG    ",		
									   "||> DANH SACH HANH KHACH CUNG CHUYEN BAY       ",
			                           "||> THOAT                   "};
char thucdon_sua_cb[so_item_sua_cb][50]={"||> MA CHUYEN BAY            ",
										"||> THOI GIAN BAY           ",
										"||> NOI DEN                 ",
										"||> SO HIEU MAY BAY          ",
										"||> TINH TRANG               " ,
										"||> THOAT                     " };
										
char thucdon_yn[so_item_yn][50]={">> YES",
								">> NO"};
void Normal () {
	SetColor(65);
	SetBGColor(15);
}
void HighLight () {
	SetColor(15);
	SetBGColor(65);
}
int Menu_yes_no(char td [so_item_yn][50], int d, int c){
  Normal();
//  system("cls"); 
  int chon =0;
  int i; 
  for ( i=0; i< so_item_yn ; i++)
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
  	case Down :if (chon+1 <so_item_yn)
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
int Menu_chinh(char td [so_item_main][50], int d, int c){
  Normal();
//  system("cls"); 
  int chon =0;
  int i; 
  for ( i=0; i< so_item_main ; i++)
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
  	case Down :if (chon+1 <so_item_main)
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
int Menu(char td [so_item_main][50], int d, int c){
  Normal();
  system("cls"); 
  int chon =0;
  int i; 
  for ( i=0; i< so_item_main ; i++)
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
  	case Down :if (chon+1 <so_item_main)
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
void sua_tt_cb(List_mb &l_mb,ListCB &l_cb,string x){
	Normal();
	NODECB *p = Search_cb(l_cb,x);
   if (p==NULL){
   	gotoxy(cot+20,dong+5);
    cout<<"KHONG CO MA CHUYEN BAY NAY!";
     system ("cls");
    }
   else  
   {
   		 int chon;
   		 int x=cot;
	    int y=dong;
	  do
	  {
	  	system ("cls");
	  	Normal();
	  	chon = Menu(thucdon_sua_cb,dong,cot+10);
	    switch (chon ){
	    case 1: {
	    	 system ("cls");
	    	Normal();
	    	gotoxy(cot,dong);
	    	cout<<"NHAP MA CHUYEN BAY MOI:";
	    	khung(cot+20,dong);
	    	gotoxy(cot+30,dong);
			getline(cin,p->data.ma_CB);
			break;
		};
	    case 2:{
	    	 system ("cls");
	   		Normal();
	    	//nhap ngay
			gotoxy(x-5,y+ 8);
			cout<<"NHAP NGAY KHOI HANH (dd/mm/yy): ";
			khung(x+30,y+8);
			gotoxy(x+40,y+8);
			cin>>p->data.time.ngay;
			while(p->data.time.ngay>31||p->data.time.ngay<=0){
				gotoxy(x+40,y+8);
				cout<<"   ";
				gotoxy(x+40,y+8);
				cin>>p->data.time.ngay;
			}
			gotoxy(x+42,y+8);
			cout<<"//";
			gotoxy(x+45,y+8);
			cin>>p->data.time.thang;
			while(p->data.time.thang>13||p->data.time.thang<=0){
				gotoxy(x+45,y+8);
				cout<<"   ";
				gotoxy(x+45,y+8);
				cin>>p->data.time.thang;
			}
			gotoxy(x+48,y+8);
			cout<<"//";
			gotoxy(x+50,y+8);
			cin>>p->data.time.nam;
			while(p->data.time.nam>2030||p->data.time.nam<2019){
				gotoxy(x+50,y+8);
				cout<<"       ";
				gotoxy(x+50,y+8);
				cin>>p->data.time.nam;
			}
			gotoxy(x-5,y+12);
			cout<<"NHAP GIO KHOI HANH (hh/mm): ";
			khung(x+30,y+12);
			gotoxy(x+40,y+12);
			cin>>p->data.time.gio;
			while(p->data.time.gio>25||p->data.time.gio<=0){
				gotoxy(x+40,y+12);
				cout<<"   ";
				gotoxy(x+40,y+12);
				cin>>p->data.time.gio;
			}
			gotoxy(x+43,y+12);
			cout<<":";
			gotoxy(x+45,y+12);
			cin>>p->data.time.phut;
			while(p->data.time.phut>60||p->data.time.phut<=0){
				gotoxy(x+45,y+12);
				cout<<"   ";
				gotoxy(x+45,y+12);
				cin>>p->data.time.phut;
			}
			break;
		};
	    case 3: { 
	    	system ("cls");
				Normal();
				gotoxy(x-5,y+16);
				cout<<"NHAP SAN BAY DEN:";
				khung(x+30,y+16);
				gotoxy(x+40,y+16);
				cin.ignore();
				getline(cin,p->data.san_bay_den);	
				while(ktra_chuoi(p->data.san_bay_den)==0){
				 	gotoxy(x+40,y+16);
				 	cout<"                      ";
					gotoxy(x,y);
					cout<<"NHAP SAN BAY DEN:";
					gotoxy(x+40,y+16);
					getline(cin,p->data.san_bay_den);
				}
				break;
		    };
		case 4: {
			 	system ("cls");
				Normal();
		  		return;
		    	  break;
		    };    
	    case 5:{
	    		system ("cls");
				Normal();
		  		gotoxy(x-5,y+20);
				cout<<"NHAP TRANG THAI\n\t\t\t\t(1:Huy chuyen  2:Con ve  3:Het ve  4:Hoan tat):";
				gotoxy(x+40,y+19);
				cout<<"----------";
				gotoxy(x+40,y+20);
				cout<<"|        |";
				gotoxy(x+40,y+21);
				cout<<"|________|";
				gotoxy(x+45,y+20);
				cin>>p->data.trang_thai;
		      	break;
		}
		case 6:{
			return;
			break;
		}
	   }
	  } while (chon!=27);
	    system ("cls");
	}
}
void sua_tt_mb(List_mb &l_mb,string x){
	Normal();
	int i = Search_mb(l_mb,x ) ;
   if (i==-1){
   	gotoxy(cot+20,dong+5);
    cout<<"KHONG CO SO HIEU MAY BAY NAY!";
     system ("cls");
    }
   else  
   {
   		 int chon;
	  do
	  {
	  	chon = Menu(menu_sua_mb,dong,cot+10);
	    system ("cls");
	    switch (chon ){
	    case 1: {
	    	Normal();
	    	gotoxy(cot,dong-10);
	    	cout<<"NHAP SO HIEU MOI:";
	    	khung(cot+20,dong-10);
	    	gotoxy(cot+30,dong);
			getline(cin,l_mb.mb[i]->so_hieu_MB);
			break;
		};
	    case 2:{
	    	 system ("cls");
	   		Normal();
	   		gotoxy(cot,dong);
	    	cout<<"NHAP LOAI MOI:";
	    	khung(cot +20,dong);
	   		gotoxy(cot+30,dong);
			getline(cin,l_mb.mb[i]->loai_may_bay);
			break;
		};
	    case 3: { 
	    	system ("cls");
	    	Normal();
	    	gotoxy(cot,dong);
	    	cout<<"NHAP SO DAY MOI:";
	    	khung(cot +20,dong);
	    	gotoxy(cot+30,dong);
	    	cin>>l_mb.mb[i]->so_day;
		      break;
		    };
		case 4: {
			 	system ("cls");
				Normal();
				gotoxy(cot,dong);
				cout<<"NHAP SO DONG MOI:";
				khung(cot +20,dong);
				gotoxy(cot+30,dong);
	    		cin>>l_mb.mb[i]->so_dong;
		      break;
		    };    
	    case 5:{
	    	return;
			break;
		}
	   }
	  } while (chon!=27);
	    system ("cls");
	}
}
void menu_mb(List_mb &l_mb){
	int chon;
	  do
	  {
	    chon = Menu (thucdon_mb,dong,cot+10);
	    system ("cls");
	    switch (chon ){
	    case 1: {
	    	//them may bay
	    	Normal();
           	gotoxy(cot,dong);
	    	mayBay mb  = nhap_ds_mb(l_mb);
			addMb(l_mb,mb);
			break;
		};
	    case 2:{
	    	Normal();
	    	 system ("cls");
	    	gotoxy(cot-30,dong);
	    	cout<<"NHAP SO HIEU MAY BAY CAN SUA";
	    	string tt;
//	    	cin.ignore();
	    	khung(cot+10,dong);
	    	gotoxy(cot+20,dong);
	    	getline(cin,tt);
	    	sua_tt_mb(l_mb,tt);
			break;
		} ;
	    case 3: {
	    	Normal();
	    	system ("cls");
	    	gotoxy(cot-30,dong);
	    	cout<<"NHAP SO HIEU MAY BAY CAN XOA";
	    	string tt;
	    	khung(cot+10,dong);
	    	gotoxy(cot+20,dong);
	    	getline(cin,tt);
	    	xoa_mb(l_mb,tt);
		    break;
		    };
		case 4: { xuat_ds_mb(l_mb);
			return;
		      break;
		    };    
	    case 5:{
	    	int chon_yn;
	    		Normal();
	    	do{
	    		system("cls");
	    		gotoxy(cot+5,dong);
	    		cout<<"LUU LAI THONG TIN MAY BAY VAO FILE";
	    		chon_yn= Menu_yes_no(thucdon_yn,dong+3,cot+20);
	    		switch(chon_yn){
	    			case 1:{
	    				Normal();
	    				Save_DSMB(l_mb);
	    				system("cls");
	    				return;
						break;
					}
					case 2:{
						Normal();
						system("cls");
						return;
						break;
					}
				}
			}while(chon!=27);
			return;
			break;
		};
	   }
	  } while (chon!=27);
}
void menu_hk(ListCB &l_cb, List_hk &l_hk, List_ve &l_ve){
	int chon;
	KhoiTaoCay(l_hk);
	do{
		chon= Menu( thucdon_hk,dong,cot+10);
		system("cls");
		switch(chon){
			case 1:{
				//them hanh khach
				system("cls");
				Normal();
				hanhKhach hk= nhap_hk(l_hk);
				InsertHanhKhach(l_hk,hk);
				break;
			}
			case 2:{
				system("cls");
				Normal();
				string x;
				cout<<"NHAP CMND HANH KHACH CAN SUA:";
				getline(cin,x);
				sua_tt_hk(l_hk,x);
				break;
			}
			case 3:{
				system("cls");
				Normal();
				string x;
				cout<<"NHAP CMND HANH KHACH CAN XOA:";
				getline(cin,x);
				xoa_1_hk(l_hk,x);
				break;
			}
			case 4:{
				system("cls");
				Normal();
				int l_chon;
				cout<<"1. DANH SACH TOAN BO HANH KHACH";
				cout<<"2. DANH SACH HANH KHACH THEO MA CHUYEN BAY";
				do{
					cin>>l_chon;
					switch(l_chon){
						case 1:{
							system("cls");
							xuat_DSHK(l_hk);
							break;
						}
						case 2:{
							system("cls");
							string x;
							cout<<"NHAP MA CHUYEN BAY";
							getline(cin,x);
							 xuat_DSHK_macb(l_ve,x);
							break;
						}
					}
				}while(l_chon!=27);
			}
			case 5:{
				return;
				break;
			}
		}
	}while(chon!=27);
}
void menu_cb(List_mb &l_mb,ListCB &l_cb){
	int chon;
	  do
	  {
	    chon = Menu (thucdon_cb,dong,cot+10);
	    system ("cls");
	    switch (chon ){
	    case 1: { //them chuyen bay
	    	system ("cls");
	    	Normal();
	    	chuyenBay cb =  nhap_cb(l_cb,l_mb);
	    	them_cb_co_tt(l_cb,cb);
			break;
		};
	    case 2:{
	    	system ("cls");
	    	Normal();
	    	gotoxy(cot-30,dong);
	    	cout<<"NHAP SO HIEU MAY BAY CAN SUA";
	    	string tt;
//	    	cin.ignore();
	    	khung(cot+10,dong);
	    	gotoxy(cot+20,dong);
	    	getline(cin,tt);
	    	sua_tt_cb(l_mb,l_cb,tt);
			break;
		} ;
	    case 3: {
	    	system ("cls");
	    	Normal();
	    	gotoxy(cot-30,dong);
	    	cout<<"NHAP MA MAY BAY CAN XOA";
	    	string ma;
	    	khung(cot+10,dong);
	    	gotoxy(cot+20,dong);
	    	getline(cin,ma);
			xoa_cb(l_cb,ma);
		      break;
		    };
		case 4: {
				xuat_ds_cb(l_cb);
				return;
		      break;
		    };    
	    case 5:{
	    	int chon_yn;
	    		Normal();
	    	do{
	    		system("cls");
	    		gotoxy(cot+5,dong);
	    		cout<<"LUU LAI THONG TIN MAY BAY VAO FILE";
	    		chon_yn= Menu_yes_no(thucdon_yn,dong+3,cot+20);
	    		switch(chon_yn){
	    			case 1:{
	    				Normal();
//	    				Save_DSMB(l_mb);
	    				system("cls");
	    				return;
						break;
					}
					case 2:{
						Normal();
						system("cls");
						return;
						break;
					}
				}
			}while(chon!=27);
			return;
			break;
		};
	   }
	  } while (chon!=27);
}
void menu_chinh(List_mb &l_mb,ListCB &l_cb,List_hk &l_hk,List_ve &l_ve){
	int chon;
	KhoiTaoCay(l_hk);
	  do
	  {
	    
	    chon = Menu_chinh (thucdon,dong,cot+10);
	   system ("cls");
	    switch (chon ){
	    case 1: {
	    	menu_mb(l_mb);
			break;
		};
	    case 2:{
	    	menu_cb(l_mb,l_cb);
			break;
		} ;
	    case 3: {
	    	menu_hk(l_cb, l_hk,l_ve);
		      break;
		    };
		case 4: { 
			hanhKhach hk= nhap_hk(l_hk);
			InsertHanhKhach(l_hk,hk);
		      break;
		    };    
	    case 5:  break;
	   }
	  } while (1);
}




