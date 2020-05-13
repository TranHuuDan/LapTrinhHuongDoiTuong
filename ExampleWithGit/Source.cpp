#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<vector>


using namespace std;
int tong;
float dtb;
class SinhVien
{
private:
	string name;
	long mssv;
	float point_cpp;
	float point_ktb;
	float point_vlsi;
	float point_mnc; 
	float dtb;

public:
	void setname(string name);
	string getname();
	void setmssv(long mssv);
	long getmssv();
	void setpoint_cpp(float point_cpp);
	float getpoint_cpp();
	void setpoint_ktb(float point_ktb);
	float getpoint_ktb();
	void setpoint_vlsi(float point_vlsi);
	float getpoint_vlsi();
	void setpoint_mnc(float point_mnc);
	float getpoint_mnc();
	float DTB();
	void show();
	void Input();
};

void SinhVien::setname(string nameIn)
{
	name = nameIn;
}
string SinhVien::getname()
{
	return name;
}
void SinhVien::setmssv(long mssvIn)
{
	mssv = mssvIn;
}
long SinhVien::getmssv()
{
	return mssv;
}
void SinhVien::setpoint_cpp(float point_cppIn)
{
	point_cpp =  point_cppIn;
}
float SinhVien::getpoint_cpp()
{
	return point_cpp;
}
void SinhVien::setpoint_ktb(float point_ktbIn)
{
	point_ktb = point_ktbIn;
}
float SinhVien::getpoint_ktb()
{
	return point_ktb;
}
void SinhVien::setpoint_vlsi(float point_vlsiIn)
{
	point_vlsi = point_vlsiIn;
}
float SinhVien::getpoint_vlsi()
{
	return point_vlsi;
}
void SinhVien::setpoint_mnc(float point_mncIn)
{
	point_mnc = point_mncIn;
}
float SinhVien::getpoint_mnc()
{
	return point_mnc;
}
float SinhVien::DTB()
{
	dtb = (point_cpp + point_ktb + point_vlsi + point_mnc) / 4;
	return dtb ;
}
void SinhVien::show()
{
	cout << "\nHo va ten sinh vien: " << getname();
	cout << "\nMa so sinh vien: " << getmssv();
	cout << "\nDiem mon c++  : " << getpoint_cpp();
	cout << "\nDiem mon kien truc bus: " << getpoint_ktb();
	cout << "\nDiem mon vlsi : " << getpoint_vlsi();
	cout << "\nDiem mon mang nang cao: " << getpoint_mnc();
	cout << "\nDiem so trung binh cua sinh vien "<<getname()<<" la : " <<fixed<<setprecision(2)<< DTB();
}
void SinhVien::Input()
{

	cout << "\nHo va ten sinh vien: ";
	cin.ignore();
	getline(cin,name);
	cout << "\nMa so sinh vien: ";
	cin>> mssv;
	cout << "\nDiem mon c++  : " ;
	cin >> point_cpp;
	cout << "\nDiem mon kien truc bus: ";
	cin >> point_ktb;
	cout << "\nDiem mon vlsi : " ;
	cin >> point_vlsi;
	cout << "\nDiem mon mang nang cao: " ;
	cin >> point_mnc;
}

class Menu {
private:
	int tong=2;
	vector <SinhVien> sv;
public:
	void NhapDanhSachSv();
	void XuatDanhSachSv();
	void SapXepTheoMSSV();
	void SapXepTheoDTB();
	void XoaSv();
	void ThemSv();
	void TimKiemMSSV();
	void LietKeSVGioi();
	void Inmenu();
};
void Menu::XoaSv()
{
	long Mso;
	int index;
	cout << "Nhap MSSV can xoa:";
	cin >> Mso;
	for (int i = 0; i < sv.size(); i++)
	{
		if(sv[i].getmssv() == Mso)
		 {
			 index = i;
			
			break;
		 }
	}
	sv.erase(sv.begin()+index);
}
void Menu::ThemSv()
{
	
	cout << "Nhap thong tin sinh vien can them:";
	sv.resize(tong + 1);
	sv[sv.size()-1].Input();
	sv.push_back(sv[sv.size()-1]);
	sv.pop_back();
}
void Menu::NhapDanhSachSv()
{
	sv.resize(tong);
	for (int i = 0; i < sv.size(); i++)
	{
		sv[i].Input();
	}
}
void Menu::SapXepTheoDTB()
{
	sv.resize(tong);
	for (int i = 0; i < sv.size()-1; i++)
	{
		for (int j = i + 1; j < sv.size(); j++)
		{
			float d1 = sv[i].DTB();
			float d2 = sv[j].DTB();
			if ( d1< d2)
			{
				float temp = d1;
				d1= d2;
				d2 = temp;
			}
		}
	}
}
void Menu::SapXepTheoMSSV()
{
	sv.resize(tong);
	for (int i = 0; i < sv.size() - 1; i++)
	{
		for (int j = i + 1; j < sv.size(); j++)
		{
			float d1 = sv[i].getmssv();
			float d2 = sv[j].getmssv();
			if (d1> d2)
			{
				float temp = d1;
				d1 = d2;
				d2 = temp;
			}
		}
	}
}
void Menu::LietKeSVGioi()
{
	for (int i = 0; i < sv.size(); i++)
	{
		if (sv[i].DTB() >=8.0)
		{
			sv[i].show();
		}
	}
}
void Menu::TimKiemMSSV()
{
	sv.resize(tong);
	long MaSo;
	cout << "Nhap MSSV muon tim kiem:";
	cin >> MaSo;
	for (int i = 0; i < sv.size(); i++)
	{
		if  (sv[i].getmssv()== MaSo)
		{
			sv[i].show();
			break;
		}
	}
	cout << "khong tim thay sinh vien!!!!";
}

void Menu::XuatDanhSachSv()
{

	for (int i = 0; i < sv.size(); i++)
	{
		sv[i].show();
		
	}
}
void Menu::Inmenu()
{
	int k;
	do 
	{
		system("cls");
		cout << "\n		1-Nhap danh sach sinh vien";
		cout << "\n		2-Xuat danh sach sinh vien";
		cout << "\n		3-sap xep danh sach sinh vien theo DTB";
		cout << "\n		4-sap xep danh sach sinh vien theo MSSV";
		cout << "\n		5-Tim kiem sinh vien theo MSSV";
		cout << "\n		6-Danh sach SV gioi";
		cout << "\n		7-Them 1 sinh vien moi";
		cout << "\n		8-Xoa sinh vien ra khoi danh sach";
		cout << "\n		9-Thoat";
		cout << "\nNhap su lua chon muon thuc hien:";
		cin >> k;
		switch (k) 
		{
		case 1:
			NhapDanhSachSv();
			break;
		case 2:
			XuatDanhSachSv();
			system("pause");
			break;
		case 3:
			SapXepTheoDTB();
			break;
		case 4:
			SapXepTheoMSSV();
			break;
		case 5:
			TimKiemMSSV();		
			system("pause");
			break;
		case 6:
			LietKeSVGioi();
			system("pause");
			break;
		case 7:
			ThemSv();
			break;
		case 8:
			XoaSv();
			break;

		}
	} while (k != 9);
}
int main()
{
	int tong;
	Menu me;
	me.Inmenu();
	cout << endl;
	return 0;
}