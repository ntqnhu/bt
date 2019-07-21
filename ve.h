#include "hanhkhach.h"
#define MAX_DS_VE 3000
using namespace std;
string tt_ve[2]={"Da ban","Trong"};
struct NodeVe{
	int tinh_trang_ve;
	string ten_ve;
	chuyenBay *cb = new chuyenBay;
	hanhKhach *hk= new hanhKhach;
};
struct List_ve{
	int n=-1;
	NodeVe node_ve[MAX_DS_VE];
};
void add_ve(List_ve &l_ve,NodeVe ve){
	if(l_ve.n==3000){
		cout<<"DANH SACH DAY!";
	}
	else{
		l_ve.n++;
		l_ve.node_ve[l_ve.n]=ve;
	}
}
void xuat_DSHK_macb(List_ve &l_ve,string x)//SHOW TAT CAC CAC HANH KHACH CO TRONG DANH SACH
{
	int t=0;
	if(l_ve.n==0){
		cout<<"DANH SACH RONG!";
	}
	else{
		for (int i =0; i <= l_ve.n ; i++){
  	 		if ( strcmp(l_ve.node_ve[i].cb->ma_CB.c_str(),x.c_str())==0) {
  	 			cout<<t;
  	 			cout<<l_ve.node_ve[i].ten_ve;
  	 			cout<<l_ve.node_ve[i].hk->CMND;
  	 			cout<<l_ve.node_ve[i].hk->ho;
  	 			cout<<l_ve.node_ve[i].hk->ten;
  	 			cout<<gioiTinh[l_ve.node_ve[i].hk->phai-1];
			   }
  		}
	}
}
//xuat danh sach chuyen bay den y ngay x, con ve
void xuat_dscb(List_ve &l_ve, Datetime x,string y){
	if(l_ve.n==0){
		cout<<"DANH SACH TRONG!";
	}
	else{
		for(int i=0;i<l_ve.n;i++){
			if((l_ve.node_ve[i].cb->time.ngay==x.ngay)&&(l_ve.node_ve[i].cb->time.thang==x.thang)&&(l_ve.node_ve[i].cb->time.nam==x.nam)&&strcmp(l_ve.node_ve[i].cb->san_bay_den.c_str(),y.c_str())==0&&l_ve.node_ve[i].tinh_trang_ve==2){
				cout<<l_ve.node_ve[i].cb->ma_CB;
				cout<<l_ve.node_ve[i].cb->time.gio;
				cout<<l_ve.node_ve[i].cb->time.phut;
				cout<<l_ve.node_ve[i].cb->time.ngay;
				cout<<l_ve.node_ve[i].cb->time.thang;
				cout<<l_ve.node_ve[i].cb->time.nam;
				cout<<l_ve.node_ve[i].cb->san_bay_den;
				cout<<tt_chuyen_bay[l_ve.node_ve[i].cb->trang_thai-1];
			}
		}
	}
}
////xuat ds ve cua chuyen bay co ma x
//void xuat_dsve_trong(List_ve &l_ve, string x){
//	if(l_ve.n==0){
//		cout<<"DANH SACH TRONG!";
//	}
//	else{
//		for(int i=0;i<l_ve.n;i++){
//			if(strcmp(l_ve.node_ve[i].cb->ma_CB.c_str(),x.c_str())==0){
//				for(int j=0;j<l_ve.node_ve[i].cb->mb->ve.n;j++){
//					if(strcmp(l_ve.node_ve[i].ten_ve.c_str(),l_ve.node_ve[i].cb->mb->ve[j].ten_ve.c_str())!=0){
//						cout<<l_ve.node_ve[i].cb->mb->ve[j].ten_ve;
//					}
//					
//				}
//			}
//		}
//	}
//}
//tim kiem theo cmnd
int Search_ve_cmnd(List_ve &l_ve, string x) {
  for (int i =0; i <= l_ve.n ; i++){
  	 if (strcmp(l_ve.node_ve[i].hk->CMND.c_str(),x.c_str())==0) return i;
  	}
  return -1;
}
//tim kiem theo ma chuyen bay
int Search_ve_maCB(List_ve &l_ve,string y) {
  for (int i =0; i <= l_ve.n ; i++){
  	 if ( strcmp(l_ve.node_ve[i].cb->ma_CB.c_str(),y.c_str())==0) return i;
  	}
  return -1;
}
//tim kiem ket hop cmnd+macb
int Search_ve(List_ve &l_ve, string x,string y) {
  for (int i =0; i <= l_ve.n ; i++){
  	 if (strcmp(l_ve.node_ve[i].hk->CMND.c_str(),x.c_str())==0 && strcmp(l_ve.node_ve[i].cb->ma_CB.c_str(),y.c_str())==0) return i;
  	}
  return -1;
}
//xoa 1 ve theo so CMND + macb
void xoa_ve(List_ve &l_ve, string x, string y){
	if(l_ve.n==0) cout<<"DS RONG!";
   int i = Search_ve(l_ve,x,y) ;
   if (i==-1) cout<<"KHONG TON TAI VE NAY!";
   else  
   {
     for (int j=i+1; j <l_ve.n; j++)
       l_ve.node_ve[j-1]=l_ve.node_ve[j];
     l_ve.n--;  
     system("cls");
//    khung(50,40);
//	gotoxy(55,40);
	cout<<"DA XOA!";
	}
}
void Huy_ve(List_ve &l_ve){
	if(l_ve.n==0) cout<<"DS VE RONG!";
	else{
		string x,y;
		cout<<"NHAP CMND NGUOI DAT:";
		getline(cin,x);
		int i= Search_ve_cmnd(l_ve,x);
		if(i==-1) cout<<"KHONG CO THONG TIN NGUOI NAY!";
		else{
			cout<<"NHAP MA CHUYEN BAY:";
			getline(cin,y);
			int j= Search_ve_maCB(l_ve,y);
			if(i==-1) cout<<"KHONG TON TAI VE NAY!";
			else{
				xoa_ve(l_ve,x,y);
			}
		}
	}
}
NodeVe Dat_ve(List_hk &l_hk,List_ve &l_ve,ListCB &l_cb){
	NodeVe ve;
	int x= cot;
	int y=dong;
	string cmnd, noi_den,ghe, ma_cb;
	cout<<"NHAP CMND:";
	getline(cin,cmnd);
	List_hk hk = KiemTraHK(l_hk,cmnd);
	if(hk!=NULL){
		//cho nay de hien ra thong tin ba khach hang 
		cout<<"NHAP NOI DEN:";
		getline(cin,noi_den);
		NODECB *p ;
		int j=0;
		for(p=l_cb.pHead;p!=NULL;p=p->next){
			if(p->data.san_bay_den==noi_den &&p->data.trang_thai==2){
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
		cout<<"NHAP MA CHUYEN BAY DA CHON";
		getline(cin,ma_cb);
		p= Search_cb(l_cb,ma_cb);
	//viet ham kiem tra da chon chuyen bay roi hay chua: trung khong
		if(p!=NULL){
			ve.hk = &hk->data;
			ve.cb=&p->data;
			tenGhe(p->data.mb);
			cout<<"CHON GHE:";
			getline(cin,ghe);
			ve.ten_ve=ghe;
			ve.tinh_trang_ve =0;
			return ve;
		}
		else{
			cout<<"KHONG CO CHUYEN BAY DEN "<<noi_den;
			return ve;
		}
	}
	else{
		hk->data = nhap_hk(l_hk);
		InsertHanhKhach(l_hk,hk->data);
		cout<<"NHAP NOI DEN:";
		getline(cin,noi_den);
		NODECB *p ;
		int j=0;
		for(p=l_cb.pHead;p!=NULL;p=p->next){
			if(p->data.san_bay_den==noi_den &&p->data.trang_thai==2){
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
		cout<<"NHAP MA CHUYEN BAY DA CHON";
		getline(cin,ma_cb);
		p= Search_cb(l_cb,ma_cb);
		if(p!=NULL){
			ve.hk =&hk->data;
			ve.cb= &p->data;
			tenGhe(p->data.mb);
			cout<<"CHON GHE:";
			getline(cin,ghe);
			ve.ten_ve=ghe;
			ve.tinh_trang_ve =0;
			return ve;
		}
		else{
			cout<<"KHONG CO CHUYEN BAY DEN "<<noi_den;
			return ve;
		}
		
	}
}

