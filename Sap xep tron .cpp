#include<bits/stdc++.h>
using namespace std;

int a[7] = {5,15,10,25,20,30,35};
 
void MergeSort(int a[], int l, int r)
{
	int b[7];
	if (r>l)
	{
		int m = (l+r)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
	//sao chep nua dau cua a sang b
		for(int i=m; i>=l; i--)
			b[i] = a[i];
	//sao chep nua con lai cua a sang b theo thu tu nguoc lai
		for(int j=m+1; j<=r; j++)
			b[r+m+1-j] = a[j];
	//i chay tu dau bang b, j chay tu cuoi mang b va tron
		int i=l; 
		int j=r;
		for(int k=l; k<=r; k++)
			if(b[i]<b[j])
			{
				a[k]=b[i];
				i++;
			}
			else
			{
				a[k]=b[j];
				j--;
			}
	}
}

int main()
{
	cout << "Day ban dau la: ";
	for(int i=0; i<7; i++)
		cout << a[i] << " ";
	MergeSort(a,0,6);
	cout << "\nDay sau khi sap xep la: ";
	for(int i=0; i<7; i++)
		cout << a[i] << " ";
	cout << endl;
}