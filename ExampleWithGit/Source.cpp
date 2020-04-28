
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
	int n; int s = 0;
	cout << "Nhap n=";
	cin >> n;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 6 + 1;
		cout << x << "\t";
		s += x;
	}
	cout << endl;
	cout << "s=" << s << endl;
	 return 0;
}