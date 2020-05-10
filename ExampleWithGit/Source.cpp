#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>

using namespace std;
int n,dtb;
class SinhVien
{
private:
	string name;
	string mssv;
	float point_cpp;
	float point_ktb;
	float point_vlsi;
	float point_mnc; 
	float dtb;

public:
	SinhVien(string name=" ", string mssv=" ",float point_cpp=0,float point_ktb=0,float point_vlsi=0,float point_mnc=0);
	void setname(string name);
	string getname();
	void setmssv(string mssv);
	string getmssv();
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
	void nhap();
};
SinhVien::SinhVien(string nameIn, string mssvIn, float point_cppIn, float point_ktbIn, float point_vlsiIn, float point_mncIn)
{
	name = nameIn;
	mssv = mssvIn;
	point_cpp = point_cppIn;
	point_ktb = point_ktbIn;
	point_vlsi = point_vlsiIn;
	point_mnc = point_mncIn;
}
void SinhVien::setname(string nameIn)
{
	name = nameIn;
}
string SinhVien::getname()
{
	return name;
}
void SinhVien::setmssv(string mssvIn)
{
	mssv = mssvIn;
}
string SinhVien::getmssv()
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
	return dtb;
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
void SinhVien::nhap()
{
	cout << "\nHo va ten sinh vien: ";
	getline(cin,name);
	cout << "\nMa so sinh vien: ";
	getline(cin, mssv);
	cout << "\nDiem mon c++  : " ;
	cin >> point_cpp;
	cout << "\nDiem mon kien truc bus: ";
	cin >> point_ktb;
	cout << "\nDiem mon vlsi : " ;
	cin >> point_vlsi;
	cout << "\nDiem mon mang nang cao: " ;
	cin >> point_mnc;
}

int main()
{
	string name;
	string mssv;
	float point_cpp;
	float point_ktb;
	float point_vlsi;
	float point_mnc;
	float dtb;
	int n,index=0;
	//SinhVien sv("Tran Huu Dan","1720040",5,9,7,9);
	//sv.show();
	//SinhVien sv1;
	//sv1.nhap();
	//sv1.show();
	cout << "Nhap so luong sinh vien can quan li:";
	cin >> n;
	
	float max = 0;
	SinhVien *sv2 = new SinhVien[n];
	for (int i = 0; i < n; i++)
	  {
		cin.ignore();
		string name;
		string mssv;
		float point_cpp;
		float point_ktb;
		float point_vlsi;
		float point_mnc;
		float dtb;
		cout << "			Thong tin cua sinh vien thu "<<i+1 <<":";
		cout << "\nHo va ten sinh vien: ";
		getline(cin, name);
		sv2[i].setname(name);
		cout << "\nMa so sinh vien: ";
		getline(cin, mssv);
		sv2[i].setmssv(mssv);
		cout << "\nDiem mon c++  : ";
		cin >> point_cpp;
		sv2[i].setpoint_cpp(point_cpp);
		cout << "\nDiem mon kien truc bus: ";
		cin >> point_ktb;
		sv2[i].setpoint_ktb(point_ktb);
		cout << "\nDiem mon vlsi : ";
		cin >> point_vlsi;
		sv2[i].setpoint_vlsi(point_vlsi);
		cout << "\nDiem mon mang nang cao: ";
		cin >> point_mnc;
		sv2[i].setpoint_mnc(point_mnc);
		dtb = sv2[i].DTB();
		if (max < dtb)
		{
			max = dtb;
			index = i;
		}
		
	  }
	cout << "\nSinh vien co diem so trung binh cao nhat :";
	for (int i = 0; i < n; i++)
	{
		if (i == index)
		{	
	    	sv2[i].show();
		    break;
	    }
	}
	delete[] sv2;
	cout << "\n\n\n\n";
	return 0;
}