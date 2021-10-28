#include<bits/stdc++.h>
using namespace std;

int *dd,x[100],n;

void show()
{
	for(int i=1; i<=n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void Try(int k)
{
	dd = new int[n+1];
	for(int i=1; i<=n; i++)
		dd[i] = NULL;
	for(int i=1; i<=n; i++)
		if (dd[i]==0)
		{
			x[k]=i;
			if (k==n) show();
			else
			{
				dd[i]=1;
				Try(k+1);
				dd[i]=0;
			}
		}
}

main()
{
	cout << "Nhap n: "; cin >> n;
	Try(1);
}