#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<stdio.h>
using namespace std;
ifstream filein;
struct date {
	int min;
	int hour;
	int day;
	int mon;
	int year;

};

typedef struct date DATE;

void DocDate(ifstream& filein, DATE& date)
{
	//filein.seekg(1, ios_base::cur);
	filein >> date.day;
	filein.ignore();
	//filein.seekg(1, ios_base::cur); //dich sang phai 1 byte de bo qua ky tu /
	filein >> date.mon;
	filein.ignore();
	//filein.seekg(1, ios_base::cur); //dich sang phai 1 byte de bo qua ky tu /
	filein >> date.year;
	filein.ignore();
	//filein.seekg(1, ios_base::cur); //dich sang phai 1 byte de bo qua ky tu /
	filein >> date.hour;
	filein.ignore();
	//filein.seekg(1, ios_base::cur); //dich sang phai 1 byte de bo qua ky tu /
	filein >> date.min;
	//filein.seekg(1, ios_base::cur);
}


struct ve
{
	string HangBay;
	string MaChuyenBay;
	string TenKhachHang;
	long cccd;
	string SoGhe;
	string DiemDi;
	string DiemDen;
	int cua;
	DATE ThoiGianKhoiHanh;
	float ThoiGianBay;
	

};
typedef struct ve VE;


struct node
{
	VE data;
	struct node* Next;
	struct node* Pre;
};
typedef struct node NODE;

struct list
{
	NODE* Head;
	NODE* Tail;
};

typedef struct list LIST;

void KhoiTaoDanhSach(LIST& ds)
{
	ds.Head = NULL;
	ds.Tail = NULL;
}

NODE* TaoNode(VE x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "Dat ve khong thanh cong";
	}
	else
	{
		p->data = x;
		p->Next = NULL;
		p->Pre = NULL;
	}
	return p;
}
int TongSoLuongVe(LIST ds)
{
	int dem = 0;
	for (NODE* i = ds.Head;i != NULL;i = i->Next)
	{
		dem++;
	}
	return dem;
}

void Nhap(LIST& ds, NODE *p)
{

	cin.ignore();
	int n;
	cout << "\nNhap hang may bay: ";
	cout << "\n1. Vietnam Airlines";
	cout << "\n2. Jetstar Pacific";
	cout << "\n3. VietJet Air";
	cout << "\n4. Bamboo Airways"<<endl;
	cin >> n;
	while (true)
	{
		if (n == 1)
		{
			p->data.HangBay = "Vietnam Airlines";
			break;
		}
		else if (n == 2)
		{
			p->data.HangBay = "Jetstar Pacific";
			break;
		}
		else if (n == 3)
		{
			p->data.HangBay = "VietJet Air";
			break;
		}
		else if (n == 4)
		{
			p->data.HangBay = "Bamboo Airways";
			break;
		}
	}
	cin.ignore();
	cout << "\nNhap ma chuyen bay: ";
	getline(cin, p->data.MaChuyenBay);
	cout << "\nNhap ten hanh khach: ";
	getline(cin, p->data.TenKhachHang,'\n');
	cout << "\nNhap CMND hoac CCCD: ";	
	cin >> p->data.cccd;
	cin.ignore();
	cout << "\nNhap vi tri ghe: ";
	getline(cin, p->data.SoGhe);
	cout << "\nNhap Noi khoi hanh: ";
	getline(cin, p->data.DiemDi);
	cout << "\nNhap noi den: ";
	getline(cin, p->data.DiemDen);
	p->data.cua = rand() % (10 - 1 + 1) + 1;
	cout << "\nNhap thoi gian dat ve: ";
	cout << "\nNhap ngay: ";
	cin >> p->data.ThoiGianKhoiHanh.day;
	cout << "\nNhap thang: ";
	cin >> p->data.ThoiGianKhoiHanh.mon;
	cout << "\nNhap nam: ";
	cin >> p->data.ThoiGianKhoiHanh.year;
	fflush(stdin);
	p->data.ThoiGianKhoiHanh.hour = rand() % (24 - 00 + 0) + 0;
	do {
		p->data.ThoiGianKhoiHanh.min = rand() % (60 - 0 + 0) + 0;
	} while (p->data.ThoiGianKhoiHanh.min % 10 != 0);
	p->data.ThoiGianBay = rand() % (24-0+0)+0;
}

//Them
void ThemDau(LIST& ds, NODE* p)
{
	if (ds.Head == NULL)
	{
		ds.Head = p;
		ds.Tail = p;
	}
	else
	{
		p->Next = ds.Head;
		ds.Head->Pre = p;
		ds.Head = p;
	}
} 

void ThemCuoi(LIST& ds, NODE* p)
{
	if (ds.Head == NULL)
	{
		ds.Head = p;
		ds.Tail = p;
	}
	else
	{
		ds.Tail->Next = p;
		p->Pre = ds.Tail;
		ds.Tail = p;
	}
}

void ThemGiua(LIST& ds, NODE* p, int vt)
{
	int n = 0;
	for (NODE* i = ds.Head;i != NULL;i = i->Next)
	{
		n++;
	}
	if (ds.Head == NULL || vt == 1)
	{
		ThemDau(ds, p);
	}
	else if(vt==n+1)
	{
		ThemCuoi(ds, p);
	}
	else
	{
		int dem = 0;
		for (NODE* i = ds.Head;i != NULL;i = i->Next)
		{
			dem++;
			if (dem == vt)
			{
				NODE* g = i->Pre;
				p->Next = i;
				i->Pre = p;
				g->Next = p;
			}
		}
	}
}
//Xoa
void XoaDau(LIST& ds)
{
	if (ds.Head == NULL)
	{
		return;
	}
	else
	{
		NODE* p = ds.Head;
		ds.Head = ds.Head->Next;
		ds.Head->Pre = NULL;
		delete p;
	}
}

void XoaCuoi(LIST& ds)
{
	if (ds.Head == NULL)
	{
		return;
	}
	else
	{
		NODE* p = ds.Tail;
		ds.Tail = ds.Tail->Pre;
		ds.Tail->Next = NULL;

		delete p;
	}
}
void XoaViTriK(LIST &ds, int k)
{
	int TongVe = TongSoLuongVe(ds);
	int dem=0;
	if (k <= 1)
		XoaDau(ds);
	else if (k >= TongVe)
	{
		XoaCuoi(ds);
	}
	else
	{
		for (NODE* i = ds.Head;i != NULL;i = i->Next)
		{
			dem++;
			if (dem == k)
			{
				NODE* P = i->Pre;
				NODE* N = i->Next;
				P->Next = N;
				N->Pre = P;
				delete i;
			}
		}
	}
}

void QuickSort(LIST& ds)
{
	LIST l1, l2;
	NODE* tag, * p;
	if (ds.Head == ds.Tail)
		return;
	KhoiTaoDanhSach(l1);
	KhoiTaoDanhSach(l2);
	tag = ds.Head;
	ds.Head = tag->Next; //cap nhat ds.head
	tag->Next = NULL;
	while (ds.Head != NULL)
	{
		p = ds.Head;
		ds.Head = p->Next;
		p->Next = NULL;
		if (p->data.ThoiGianKhoiHanh.day <= tag->data.ThoiGianKhoiHanh.day)
			ThemDau(l1, p);
		else if (p->data.ThoiGianKhoiHanh.day > tag->data.ThoiGianKhoiHanh.day)
			ThemDau(l2, p);
	}
	QuickSort(l1);
	QuickSort(l2);
	if (l1.Head != NULL)
	{
		ds.Head = l1.Head;
		l1.Tail->Next = tag;
	}
	else
	{
		ds.Head = tag;
		tag->Next = l2.Head;
	}
	if (l2.Head != NULL)
	{
		ds.Tail = l2.Tail;
	}
	else
	{
		ds.Tail = tag;
	}
}

// Doc du lieu 1 ve tu file
void Doc1Ve(ifstream& filein, VE& v)
{
	getline(filein, v.MaChuyenBay, ',');
	getline(filein, v.TenKhachHang, ',');
	filein >> v.cccd;
	filein.ignore();
	getline(filein, v.SoGhe, ',');
	getline(filein, v.DiemDi, ',');
	getline(filein, v.DiemDen, ',');
	filein >> v.cua;
	filein.ignore();
	DocDate(filein, v.ThoiGianKhoiHanh);
	filein.ignore();
	filein >> v.ThoiGianBay;
}

void DocDanhSachVe(ifstream& filein, LIST& ds)
{
	VE v;

	while (getline(filein,v.HangBay,','))
	{
		filein.ignore();
		Doc1Ve(filein, v);
		NODE* p = TaoNode(v);
		ThemCuoi(ds, p);
		
	}
}

void Xuat(VE v)
{
	cout << "\nHang Bay: " << v.HangBay;
	cout << "\nMa chuyen bay: " << v.MaChuyenBay;
	cout << "\nTen hanh khach: " << v.TenKhachHang;
	cout << "\nCan cuoc cong dan: " << v.cccd;
	cout << "\nSo ghe: " << v.SoGhe;
	cout << "\nNoi Khoi Hanh: " << v.DiemDi;
	cout << "\nNoi den: " << v.DiemDen;
	cout << "\nCua: " << v.cua;
	cout << "\nThoi gian khoi hanh: " << v.ThoiGianKhoiHanh.day << "/" << v.ThoiGianKhoiHanh.mon << "/" << v.ThoiGianKhoiHanh.year << "\t" << v.ThoiGianKhoiHanh.hour << ":" << v.ThoiGianKhoiHanh.min;
	cout << "\nThoi gian bay: " << v.ThoiGianBay<<" tieng"<<endl;
}

void XuatDanhSachVe(LIST ds)
{
	int dem = 1;
	NODE* i = ds.Head;
	while (i != NULL)
	{
		cout << "\n" << dem << ". ";
		Xuat(i->data);
		i = i->Next;
		dem++;
	}
}



void GiaiPhongVungNho(LIST& ds)
{
	NODE* k = new NODE;
	while (ds.Head != NULL)
	{
		k = ds.Head;
		ds.Head = ds.Head->Next;
		ds.Head->Pre = NULL;
		delete k;
	}
}

void menu(LIST& ds)
{

	int luachon;
	while (true)
	{
		
		system("cls");
		cout << "\n\n\t\t========== MENU ==========";
		cout << "\n\t1. Dat ve";
		cout << "\n\t2. In cac ve da dat";
		cout << "\n\t3. Huy ve";
		cout << "\n\t4. Doc danh sach ve tu file";
		cout << "\n\t5. Sap xep danh sach ve";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t========== END ==========";


		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon>10)
		{
			cout << "\nLua chon khong hop le!!!";
			system("pause");
		}
		else if (luachon == 1)
		{
			NODE* p = new node;
			Nhap(ds, p);
			ThemCuoi(ds, p);
		}
		else if (luachon == 2)
		{
			XuatDanhSachVe(ds);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "Nhap Thu vu ve can huy ";
			cin >> x;
			XoaViTriK(ds, x);
		}
		else if (luachon == 4)
		{
			filein.open("input.txt", ios::in);
			DocDanhSachVe(filein, ds);
			XuatDanhSachVe(ds);
			filein.close();
		}
		else if (luachon == 5)
		{
			QuickSort(ds);
		}
		else
		{
			
			system("pause");
			break;
		}
	}
}


int main()
{
	LIST ds;
	VE v;
	KhoiTaoDanhSach(ds);
	menu(ds);
	
	return 0;
}
