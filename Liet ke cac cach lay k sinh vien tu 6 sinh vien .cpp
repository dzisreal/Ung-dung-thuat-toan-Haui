#include<bits/stdc++.h>
using namespace std;
string ten[6] = {"tam","toan","trang","cong","trung","tu"};
//Sinh cau hinh moi tu cau hinh dang co
void next_config(int x[], int k, int i)
{
	x[i] += 1;
	i ++;
	while (i <= k)
	{
	//x[i+1], …, x[k] = can duoi
	x[i] = x[i - 1] + 1;
	i ++;
	}
}
//Hien thi mot cau hinh
void view_config(int x[], int k,string ten[6])
{
	for (int i = 1; i <= k; i++)
		cout << ten[x[i]-1] << " ";
	cout << endl;
}

//Liet ke cac cau hinh
void listing_configs(int k, int n)
{
	int i, x[k + 1] = {0};
	//Cau hinh dau tien {1 2 … k}
	for (i = 1; i <= k; i++) 
		x[i] = i;
	do 
	{
	view_config(x, k,ten); //In một cấu hình
	//Tim phan tu dau tien chua dat gh tren
	i = k;
	while (i > 0 && x[i] == n - k + i)
	i--;
	if (i > 0) next_config(x, k, i);//Chua phai cau hinh cuoi
	
	} while (i > 0);
}

int main()
{
	int n,k;
	cout << "Nhap n: "; cin >> n;
	cout << "Nhap k: "; cin >> k;
	listing_configs(k,n);
}