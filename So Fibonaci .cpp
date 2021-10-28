#include<bits/stdc++.h>
using namespace std;
int *d;
void khaibao(int n)
{
	d = new int[n];
	for(int i=1; i<=n; i++)
		d[i] = -1;
}
long f(int n)
{
	if (n==1 || n==2)
		d[n]=1;
	else if (d[n]<0)
	{
		d[n] = f(n-1) + f(n-2);
	}
	return d[n];
}

main()
{
	int n,s=0;
	cout << "Nhap n: "; cin >> n;
	khaibao(n);
	f(n);
	for(int i=1; i<=n; i++)
	{
		cout << "So Fibonaci thu " << i << " la: " << d[i] << endl;
		s+=d[i];
	}
	cout << "Tong day tren la: " << s << endl;
}