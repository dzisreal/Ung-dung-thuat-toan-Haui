#include<bits/stdc++.h>
using namespace std;

int somien = 0;
int a[5][6];
bool flag[10][10];

void loang(int i, int j)
{
	flag[i][j] = true;
	if (a[i-1][j]==a[i][j] && !flag[i-1][j] && i > 0)
		loang(i-1,j);
	if (a[i+1][j]==a[i][j] && !flag[i-1][j] && i < 4)
		loang(i+1,j);
	if (a[i][j-1]==a[i][j] && !flag[i][j-1] && j > 0)
		loang(i,j-1);
	if (a[i][j+1]==a[i][j] && !flag[i][j+1] && j < 5)
		loang(i,j+1);
}

main()
{
	for(int i=0; i<5; i++)
		for(int j=0; j<6; j++)
			flag[i][j] = false;
	for(int i=0; i<5; i++)
		for(int j=0; j<6; j++)
			if (!flag[i][j])
			{
				somien++;
				loang(i,j);
			}
	cout << "So mien lien thong: " << somien << endl;
}