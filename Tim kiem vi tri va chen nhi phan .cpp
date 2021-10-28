#include<bits/stdc++.h>
using namespace std;

int *a,n,c;

void insert(int *&a, int &n, int c)
{
	int *b = new int[n+1];
	int i,j;
	if (c<a[n-1])
	{
		for(i=0; i<n; i++)
			if (a[i]>c) 
				break;
		for(j=0; j<i; j++)
			b[j] = a[j];
		b[i]=c;
		for(j=i+1; j<n+1; j++)
			b[j] = a[j-1];
		delete a;
		n++;
		for(i=0; i<n; i++)
			a[i] = b[i];
	}
	else
	{
		for(i=0; i<n; i++)
			b[i]=a[i];
		delete a;
		n++;
		for(i=0; i<n-1; i++)
			a[i]=b[i];
		a[n-1] = c;
	}
}

int search(int *a,int n, int c)
{
	int l=0,r=n-1,m;
	while (l<=r)
	{
		m = (l+r)/2;
		if (a[m]==c) return m;
		if (a[m]>c) r = m-1;
		else l = m+1;
	}
	return -1;
}



int main()
{
	cout << "Nhap n: "; cin >> n;
	a = new int[n];
	cout << "Nhap day: ";
	for(int i=0; i<n; i++)
		cin >> a[i];
	cout << "Nhap so can tim: "; cin >> c;
	if(search(a,n,c)!=-1) 
		cout << "Vi tri so " << c << " trong mang la: " << search(a,n,c) << endl;
	else 
	{
		insert(a,n,c);
		cout << "Day sau khi them la: ";
		for(int i=0; i<n; i++)
			cout << a[i] << " ";
		cout << endl;
	}

}