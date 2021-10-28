#include<bits/stdc++.h>
using namespace std;

int pow(int a, int n)
{
	if (n==1) return a;
	else if (n==0) return 1;
	else
	{
		int temp = pow(a,n/2);
		if (n%2==0)
			return temp * temp;
		else
			return temp * temp * a;
	}
}

int main()
{
	int a,n;
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap n: "; cin >> n;
	cout << "Luy thua bac n cua a la: " << pow(a,n) << endl;
}