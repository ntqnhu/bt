
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "maybay.h"

using namespace std;
const string tt_chuyen_bay[4]={"Huy chuyen","Con ve","Het ve","Hoan tat"};
struct Datetime
{
	int nam = 0;
	int thang=0;
	int ngay=0;
	int gio=0;
	int phut=0;
	
};
struct chuyenBay{
	string ma_CB;
	Datetime time;
	string san_bay_den;
	int trang_thai;
	mayBay *mb= new mayBay;
};
struct NodeCB
{
	chuyenBay data;
	struct NodeCB *next;
};
typedef struct NodeCB NODECB;


struct ListCB
{
	NODECB *pHead;
	NODECB *pTail;
};

void Init(ListCB &l)
{
	l.pHead = l.pTail = NULL;
}
NODECB* GetNode(chuyenBay cb)
{
	NODECB *p = new NODECB;

	if(p == NULL)
	{
		return NULL;
	}
	p->data = cb;
	p ->next = NULL; // khoi tao moi lien ket
	return p;
}
//Sap xep ma chuyen bay theo Ma chuyen bay
void sap_xep_maCB(ListCB &Lcb){
	NODECB *p,*q,*pmin;
	chuyenBay min;
	for(p=Lcb.pHead;p->next!=NULL; p=p->next){
		min=p->data;
		pmin=p;
		for(q=p->next;q!=NULL;q=q->next){
			if(min.ma_CB>q->data.ma_CB){
				min=q->data;
				pmin=q;
			}
			pmin->data = p->data;
			p->data =min;
		}
	}
}
NODECB* Search_cb(ListCB l_cb,string x){
	for(NODECB *p=l_cb.pHead;p!=NULL;p=p->next){
		if(strcmp(p->data.ma_CB.c_str(),x.c_str())==0){
			return p;
		}
	}
	return NULL;
}
int Search_cb_yn(ListCB l_cb,string x){
	for(NODECB *p=l_cb.pHead;p!=NULL;p=p->next){
		if(strcmp(p->data.ma_CB.c_str(),x.c_str())==0){
			return 1;
		}
	}
	return 0;
}

void them_cb_co_tt(ListCB &l_cb, chuyenBay cb){
	NODECB *p,*t,*s;
	p= GetNode(cb);
	for(s=l_cb.pHead;s!=NULL&&s->data.ma_CB<p->data.ma_CB; t=s, s=s->next);
	if(s==l_cb.pHead){
		p->next = l_cb.pHead;
		l_cb.pHead=p;
	}
	else{
		p->next=s;
		t->next=p;
	}
	sap_xep_maCB(l_cb);
}
chuyenBay nhap_cb(ListCB &l_cb,List_mb &l_mb){
	int x= cot;
	int y=dong;
	system ("cls");
	chuyenBay p;
	//nhap ma chuyen bay
	khung(x+30,y);	
	gotoxy(x-5,y);
	cout<<"MA CHUYEN BAY:";
	gotoxy(x+40,y);
	getline(cin,p.ma_CB);
	while(Search_cb_yn(l_cb,p.ma_CB)==1||ktra_chuoi(p.ma_CB)==0){
		khung(x+30,y);	
		gotoxy(x+40,y);
	 	cout<"                      ";
	 	gotoxy(x+40,y);
	 	cout<"                      ";
		gotoxy(x-5,y);
		cout<<"MA CHUYEN BAY:";
		gotoxy(x+40,y);
		getline(cin,p.ma_CB);
	}
	//nhap so hieu may bay :dang loi~
//	gotoxy(x-5,y+4);
//	cout<<"NHAP SO HIEU:";
//	khung(x+30,y+4);
//	gotoxy(x+40,y+4);
//	getline(cin,p.mb->so_hieu_MB);
//	while(ktra_chuoi(p.mb->so_hieu_MB)==0){ //||Search_mb(l_mb,p.mb->so_hieu_MB)==-1
//	 		gotoxy(x+30,y+4);
//	 		cout<"                      ";
//	 		gotoxy(x+40,y+4);
//	 		cout<"                      ";
//	 		gotoxy(x-5,y+4);
//			cout<<"NHAP SO HIEU:";
//			khung(x+30,y+4);
//			gotoxy(x+40,y+4);
//			getline(cin,p.mb->so_hieu_MB);
//	}	
	//nhap ngay
	gotoxy(x-5,y+ 8);
	cout<<"NHAP NGAY KHOI HANH (dd/mm/yy): ";
	khung(x+30,y+8);
	gotoxy(x+40,y+8);
	cin>>p.time.ngay;
	while(p.time.ngay>31||p.time.ngay<=0){
		gotoxy(x+40,y+8);
		cout<<"   ";
		gotoxy(x+40,y+8);
		cin>>p.time.ngay;
	}
	gotoxy(x+42,y+8);
	cout<<"//";
	gotoxy(x+45,y+8);
	cin>>p.time.thang;
	while(p.time.thang>13||p.time.thang<=0){
		gotoxy(x+45,y+8);
		cout<<"   ";
		gotoxy(x+45,y+8);
		cin>>p.time.thang;
	}
	gotoxy(x+48,y+8);
	cout<<"//";
	gotoxy(x+50,y+8);
	cin>>p.time.nam;
	while(p.time.nam>2030||p.time.nam<2019){
		gotoxy(x+50,y+8);
		cout<<"       ";
		gotoxy(x+50,y+8);
		cin>>p.time.nam;
	}
	gotoxy(x-5,y+12);
	cout<<"NHAP GIO KHOI HANH (hh/mm): ";
	khung(x+30,y+12);
	gotoxy(x+40,y+12);
	cin>>p.time.gio;
	while(p.time.gio>25||p.time.gio<=0){
		gotoxy(x+40,y+12);
		cout<<"   ";
		gotoxy(x+40,y+12);
		cin>>p.time.gio;
	}
	gotoxy(x+43,y+12);
	cout<<":";
	gotoxy(x+45,y+12);
	cin>>p.time.phut;
	while(p.time.phut>60||p.time.phut<=0){
		gotoxy(x+45,y+12);
		cout<<"   ";
		gotoxy(x+45,y+12);
		cin>>p.time.phut;
	}
	gotoxy(x-5,y+16);
	cout<<"NHAP SAN BAY DEN:";
	khung(x+30,y+16);
	gotoxy(x+40,y+16);
	cin.ignore();
	getline(cin,p.san_bay_den);	
	while(ktra_chuoi(p.san_bay_den)==0){
	 	gotoxy(x+40,y+16);
	 	cout<"                      ";
		gotoxy(x-5,y+16);
		cout<<"NHAP SAN BAY DEN:";
		gotoxy(x+40,y+16);
		getline(cin,p.san_bay_den);
	}
	gotoxy(x-5,y+20);
	cout<<"NHAP TRANG THAI\n\t\t\t\t(1:Huy chuyen  2:Con ve  3:Het ve  4:Hoan tat):";
	gotoxy(x+40,y+19);
	cout<<"----------";
	gotoxy(x+40,y+20);
	cout<<"|        |";
	gotoxy(x+40,y+21);
	cout<<"|________|";
	gotoxy(x+45,y+20);
	cin>>p.trang_thai;
	return p;
}
void them_cb(ListCB &listcb, NODECB *p)///them chuyen bay thi them vao dau danh sach vi cac chuyen bay tao roi se duoc troi ve sau, neu them vao cuoi thi rat ton thoi gian
{
	if(listcb.pHead == NULL)
	{
		listcb.pHead=listcb.pTail=p;
	}
	else
	{
		/////CHUYEN LAI THANH THEM VAO DAU/////
		p->next = listcb.pHead;
		listcb.pHead = p;
	}
}
void xoa_cb(ListCB &listcb, string ma){
	NODECB *p, *q;
	p= listcb.pHead;
	while(p!=NULL&&p->data.ma_CB==ma){
		q=p;
		p=q->next;
		delete q;	
	}
}

void xuat_ds_cb(ListCB listcb){
	NODECB *p;
	p=listcb.pHead;
	if(p==NULL){
		cout<<"danh sach rong";
	}
	int j=0;
	int x = 0;
	int y =0;
	khung(x,y+4);
	gotoxy(x+10,y+4);
	cout<<"MA CHUYEN BAY";
	khung(x+30,y+4);
	gotoxy(x+40,y+4);
	cout<<"THOI GIAN BAY";
	khung(x+60,y+4);
	gotoxy(x+70,y+4);
	cout<<"SAN BAY DEN";
	khung(x+90,y+4);
	gotoxy(x+100,y+4);
	cout<<"SO HIEU MAY BAY";
	khung(x+120,y+4);
	gotoxy(x+130,y+4);
	cout<<"TRANG THAI";
	while(p!=NULL){
		j++;
		khung(x,y+4+j*4);
		gotoxy(x+10,y+4+j*4);
		cout<<p->data.ma_CB;
		khung(x+30,y+4+j*4);
		gotoxy(x+40,y+3+j*4);
		cout<<p->data.time.gio;
		gotoxy(x+42,y+3+j*4);
		cout<<":";
		gotoxy(x+44,y+3+j*4);
		cout<<p->data.time.phut;
		gotoxy(x+37,y+4+j*4);
		cout<<p->data.time.ngay;
		gotoxy(x+39,y+4+j*4);
		cout<<"//";
		gotoxy(x+41,y+4+j*4);
		cout<<p->data.time.thang;
		gotoxy(x+43,y+4+j*4);
		cout<<"//";
		gotoxy(x+45,y+4+j*4);
		cout<<p->data.time.nam;
		
		khung(x+60,y+4+j*4);
		gotoxy(x+70,y+4+j*4);
		cout<<p->data.san_bay_den;
		khung(x+90,y+4+j*4);
		gotoxy(x+100,y+4+j*4);
		cout<<p->data.mb->so_hieu_MB;
		khung(x+120,y+4+j*4);
		gotoxy(x+130,y+4+j*4);
		cout<<tt_chuyen_bay[p->data.trang_thai-1];
		p=p->next;
	}
}


