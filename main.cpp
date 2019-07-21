//#include "tendetai.h"
#include "menu.h"

using namespace std;
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int main(){
	List_mb l_mb;
	ListCB l_cb;
	List_hk l_hk;
	KhoiTaoCay(l_hk);
	Normal();
	resizeConsole(1250,800);
//		chuyenBay cb= nhap_cb(l_cb,l_mb);
	ten_de_tai();
//	menu_chinh(l_mb,l_cb,l_hk);
//	mayBay mb  = nhap_ds_mb(l_mb);
//		addMb(l_mb,mb);
////		xuat_ds_mb(l_mb);
//hanhKhach hk= nhap_hk(l_hk);
//			InsertHanhKhach(l_hk,hk);
//				xuat_DSHK(l_hk);
}

