#include<bits/stdc++.h>
using namespace std;

//Sinh cau hinh moi tu cau hinh dang co
void next_config(char x[], int n, int i)
{
	x[i] = 'a';
	i++;
	while (i <= n){//Dat x[i+1], …, x[n] = 0
	x[i] = 'b';
	i ++;
	}
}

//Hien thi mot cau hinh
void view_config(char x[], int n)
{
	for (int i = 1; i <= n; i++)
	cout<<x[i];
	cout<<endl;
}

void listing_configs(int n)
{
	int i;
	char x[n + 1]; //Cau hinh dau tien {00…0}
	for(int i=1; i<=n; i++) x[i] = 'b';
	do 
	{
	view_config(x, n); //In một cấu hình
	i = n;
	while (i > 0 && x[i] == 'a') i--;
	if (i > 0) 
	{ //Chua phai cau hinh cuoi
	next_config(x, n, i);
	}
	} while (i > 0);
}

int main()
{
	int n;
	cout << "Nhap n: "; cin >> n;
	listing_configs(n);
	return 0;
}