#include<bits/stdc++.h>
using namespace std;
main()
{
	int s=0, n;
	cout << "Nhap n: "; cin >> n;
	while(n>0)
	{
		s+=n%10;
		n/=10;
	}
	cout << "Tong cac chu so cua n la: " << s << endl;
}