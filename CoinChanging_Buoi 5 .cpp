#include<bits/stdc++.h>
using namespace std;
int *c,*s;
bool Cashiers_algorithm(int *c, int m, long n, int *&s)
{
	s = new int[m];
	for(int i=0; i<m; i++)
		s[i]=0;
	int i=0;
	while(n>0 && i<m)
	{
		s[i] = n/c[i];
		n%=c[i];
		i++;
	}
	if (n>0) return false;
	else return true;
}

int main()
{
	int n,m,sum=0;
	cout << "\nNhap so menh gia: "; cin >> m;
	cout << "\nXet cac truong hop co " << m << " loai menh gia: ";
	c = new int[m];
	for(int i=0; i<m; i++)
		cin >> c[i];
	cout << "\nCho so tien la: "; cin >> n;
	if (!Cashiers_algorithm(c,m,n,s)) cout << "No solution!";
	else
	{
		Cashiers_algorithm(c,m,n,s);
		cout << "So luong tung menh gia la: " << endl;
		for(int j=0; j<m; j++)
		{
			cout << c[j] << ": " << s[j] << endl;
			sum+=s[j];
		}
		cout << "Vay can it nhat " << sum << " dong xu." << endl;
	}

}