#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,*a,s=0;
	cin >> n >> m;
	a = new int[m];
	for(int i=0; i<m; i++)
		cin >> a[i];
	for(int i=0; i<m-1; i++)
		for(int j=i+1; j<m; j++)
			if (a[i]>a[j]) swap(a[i],a[j]);
	int i=0;
	if (n<a[i] || m<1) cout << "Khong co chai nao co the do day." << endl;
	else
	{
		do
		{
			n-=a[i];
			i++;
			s++;
		} while (n>=a[i] && m > i);
		cout << "So chai toi da duoc do day: " << s << endl;
	}
}