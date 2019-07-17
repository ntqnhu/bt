#include "chuyenbay.h"
#include "hanhkhach.h"
#define MAX_VE 100
using namespace std;
string tt_ve[2]={"Da ban","Trong"};
struct NodeVe{
	int tinh_trang_ve;
	chuyenBay *cb = new chuyenBay;
	hanhKhach *hk= new hanhKhach;
};
struct List_ve{
	int n;
	NodeVe node_ve[MAX_VE];
};

void Dat_ve(NODEHKPTR l_hk){
	
}
