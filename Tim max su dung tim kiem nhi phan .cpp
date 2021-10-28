#include<bits/stdc++.h>
using namespace std;

int a[10] = {1,10,2,9,3,8,4,7,5,6};

int mx(int a[], int l, int r, int &max)
{
	int max1,max2;
	if (l==r) max = a[l];
	else
	{
		int m = (l+r)/2;
		mx(a,l,m,max1);
		mx(a,m+1,r,max2);
		if(max1>max2) max = max1;
		else max = max2;
	}
	return max;
}

int main()
{
	int max;
	cout << "Day ban dau la: " ;
	for(int i=0; i<10; i++)
		cout << a[i] << " ";
	cout << "\nSo lon nhat trong day la: " << mx(a,0,9,max) << endl;
}