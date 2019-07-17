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
	Normal();
	resizeConsole(1250,800);
//		chuyenBay cb= nhap_cb(l_cb,l_mb);
//	ten_de_tai();
//	menu_chinh(l_mb,l_cb);
//	mayBay mb  = nhap_ds_mb(l_mb);
//		addMb(l_mb,mb);
//		xuat_ds_mb(l_mb);
}

