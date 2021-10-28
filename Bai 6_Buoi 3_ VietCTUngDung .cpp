#include<bits/stdc++.h>
using namespace std;

main()
{
	srand(time(NULL));
	int n,m,s=0;
	cout << "Nhap n va m: "; cin >> n >> m;
	n+=rand()%(m-n+1);
	cout << "So duoc chon: " << n << endl;
	while(n>0)
	{
		s+=n%10;
		n/=10;
	}
	cout << "Tong cac chu so cua n la: " << s << endl;
}