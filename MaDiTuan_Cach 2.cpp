#include<bits/stdc++.h>
using namespace std;

int X[9] = {0, -2, -2, -1, -1,  1, 1,  2, 2};
int Y[9] = {0, -1,  1, -2,  2, -2, 2, -1, 1};
//Với mỗi vị trí đứng của quân cờ ta có thể có nhiều nhất 8 vị trí nhảy có thể chọn

int **H;
int n;
void Try(int k, int x, int y, int &success)
{
	int u,v,suc1;
	int i=0;
	do
	{
		i++;
		suc1=0;
		u = x + X[i];
		v = y + Y[i];
		if (1<=u && u<=n && 1<=v && v<=n && H[u][v]==0)
		{
			H[u][v] = k;
			if (k < n*n)
			{
				Try(k+1,u,v,suc1);
				if (!suc1) H[u][v]=0;
			}
			else suc1 = 1;
		}
	}
	while (!suc1 && (i<8));
	success = suc1;
}

main()
{
	int x,y,suc;
	cout << "Nhap n: "; cin >> n;
	H = new int*[n+1];
	for(int i=1; i<=n; i++)
		H[i] = new int[n+1];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			H[i][j]=0;
	cout << "Nhap toa do diem xuat phat: "; cin >> x >> y;
	H[x][y] = 1;
	Try(2,x,y,suc);
	if (suc)
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
				cout << H[i][j] << "\t";
			cout << endl << endl;
		}
	}
	else cout << "Khong co duong di nao" << endl; 
}