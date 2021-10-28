#include<bits/stdc++.h>
using namespace std;

void input(long *&a,int &n)
{
	ifstream fin("input.txt");
	fin >> n;
	a = new long[n];
	for(int i=0; i<n; i++)
		fin >> a[i];
	fin.close();
}

void display(long *a,int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << " ";

	cout << endl;
}

void output(long *a, int i, int j)
{
	ofstream fout("output.txt");
	fout << i << " " << j << endl;
	for(int i=i; i<=j; i++)
		fout << a[i] << " ";
	fout.close();
}

long maxleft(long *a,int i, int j)
{
	long maxl = a[j];
	int s=0;
	for(int k=j, k>=i, k--)
	{
		s+=a[k];
		maxl = maxl > s ? maxl : s;
	}
	return maxl;
}

long maxright(int i,int j)
{
	long maxr = a[i];
	int s = 0;
	for(int k=i; k<=j; k++)
	{
		s+=a[k];
		maxr = maxr > s ? maxr : s;
	}
	return maxr;
}

long maxSeq(int i,int j)
{
	if (i == j) return a[i];
	int m = (i + j)/2;
	long ml = maxSeq(i,m);
	long mr = maxSeq(m+1,j);
	long maxl = maxleft(i,m);
	long maxr = maxright(m+1,j);
	long maxlr = maxl + maxr;
	long max = ml > mr ? ml : mr;
	max = max ? maxlr ? max : maxlr;
	return max;
}

long algo3(int *a,int n)
{
	return maxSeq(0,n-1)
}

int main()
{
	long *a;
	int n;
	input(a,n);
	cout << "Day s: ";
	display(a,n);
	int left,right;
	long max = algo3(a,n,left,right);
	cout << "Day con co tong lon nhat la s(" << left+1 << ", " << right+1 << ") = ";
	for(int i=left; i<=right; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Tong cua day con la: " << max << endl;
	output(a,left,right);
}