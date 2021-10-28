#include<bits/stdc++.h>
using namespace std;
int a[100];

int search(int a[],int n, int c)
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
	int n,c;
	cout << "Nhap so luong phan tu: "; cin >> n;
	cout << "Nhap cac phan tu: ";
	for(int i=0; i<n; i++)
		cin >> a[i];
	cout << "Nhap phan tu muon tim: "; cin >> c;
	if (search(a,n,c)!=-1) cout << "Vi tri so " << c << " trong mang la: " << search(a,n,c) << endl;
	else cout << "Khong tim thay so can tim trong mang!" << endl;
}