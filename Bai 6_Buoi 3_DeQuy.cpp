#include<bits/stdc++.h>
using namespace std;
int s=0;
int f(int n)
{
	if (n>0) return n%10 + f(n/10);
	return n;
}

main()
{
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << "Tong cac chu so cua " << n  << " la:" << f(n) << endl;
}