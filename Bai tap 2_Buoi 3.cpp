#include<bits/stdc++.h>
using namespace std;
int **d;
long C(int k, int n)
{
	if (k==0 || k==n)
		d[k][n] = 1;
	else if (d[k][n] < 0)
		d[k][n] = C(k,n-1) + C(k-1, n-1);
	return d[k][n];
}

main()
{
	int n,k;
	cout << "Nhap so dong: "; cin >> k;
	cout << "Nhap so cot: "; cin >> n;
	d = new int*[k+1];
	for(int i=0; i<=k; i++)
		d[i] = new int[n+1];
	for(int i=0; i<=k; i++)
		for(int j=0; j<=n; j++)
			d[i][j]=-1;
	cout << C(k,n) << endl;
}