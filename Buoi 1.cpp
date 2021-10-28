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

long algo1(long *a, int n, int &left, int &right)
{
	long max = a[0];
	for(int i=0; i<n; i++)
	{
		long s = 0;
		for(int j=i; j<n; j++)
		{
			s+=a[j];
			if (max < s) 
			{
				max = s;
				left = i;
				right = j;
			}
		}

	}
	return max;
}

void output(long *a, int left, int right)
{
	ofstream fout("output.txt");
	fout << left << " " << right << endl;
	for(int i=left; i<=right; i++)
		fout << a[i] << " ";
	fout.close();
}

int main()
{
	long *a;
	int n;
	input(a,n);
	cout << "Day s: ";
	display(a,n);
	int left,right;
	long max = algo1(a,n,left,right);
	cout << "Day con co tong lon nhat la s(" << left+1 << ", " << right+1 << ") = ";
	for(int i=left; i<=right; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Tong cua day con la: " << max << endl;
	output(a,left,right);
}