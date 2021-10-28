#include<bits/stdc++.h>
using namespace std;

int a[9] = {1,2,3,4,5,6,7,8,9};

int search(int a[], int l, int r, int x)
{
	if (l>r) return 0;
	int m = (l+r)/2;
	if (a[m]==x) return m;
	if (a[m]>x) return search(a,l,m-1,x);
	return search(a,m+1,r,x);
}

int main()
{
	int x;
	cout << "Nhap x muon tim: "; cin >> x;
	if (int s=search(a,0,9,x)) 
		cout << "Vi tri cua " << x << " trong mang la: " <<  s << endl;
	else cout << "Khong tim thay trong mang" << endl;
}