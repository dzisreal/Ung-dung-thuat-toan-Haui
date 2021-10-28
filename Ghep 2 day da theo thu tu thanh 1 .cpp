#include<bits/stdc++.h>
using namespace std;

int c[100];

void tron2(int a[50], int n, int b[50], int m)
{
	int Max = a[n-1];
	if (Max<b[m-1]) Max=b[m-1];
	a[n] = b[m] = Max+1;
	int i=0, j=0;
	for(int k=0; k<n+m; k++)
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
		}
		else
		{
			c[k]=b[j];
			j++;
		}
}

int main()
{
	int n,m,a[50],b[50];
	cout << "Nhap do dai day A: "; cin >> n;
	cout << "Nhap day A: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "Nhap do dai day B: "; cin >> m;
	cout << "Nhap day B: ";
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	tron2(a,n,b,m);
	cout << "Day lon sau khi sap xep la: ";
	for (int i = 0; i < n+m; ++i)
	{
		cout << c[i] << " ";
	}
}