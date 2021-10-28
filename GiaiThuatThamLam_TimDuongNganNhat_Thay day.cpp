
#include<bits/stdc++.h>

using namespace std;

int n = 9; 

//Diem dau
int u = 1;

//Diem cuoi
int v = 8;

bool go[9] = {false,false,false,false,false,false,false,false,false};

//Duong di ngan nhat
int p[9], m = 0;

//Do thi
int c[9][9] =
{
			{-1,-1,10,10,9,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1,-1,8,12,5},
			{10,-1,-1,6,-1,-1,-1,20,-1},
			{10,-1,6,-1,7,7,8,-1,-1},
			{9,-1,-1,7,-1,-1,-1,-1,6},
			{-1,-1,-1,7,-1,-1,10,15,-1},
			{-1,8,-1,8,-1,10,-1,-1,5},
			{-1,12,20,-1,-1,15,-1,-1,-1},
			{-1,5,-1,-1,6,-1,5,-1,-1},
};

int cost = 0;

bool greedy_travel_sales_man()
{
	p[m] = u; //Tap muc tieu chua dinh xuat phat
	go[u] = true; //Dinh u da tham
	while(u!= v) //Chua toi dinh ket thuc
	{
		//Tim dinh ke voi u chua tham, co chi phi dat min
		//1.Tim dinh ke dau tien
		int w = 0;
		while (w<n && (go[w] == true||c[u][w] == -1))
		{
			w++;
		}
		//2.Kiem tra xem co dinh ke khong
		if(w == n) //Khong tim doc dinh ke nao --> Khong tim duoc duong di
			return false;
		else
		{
			//Co dinh ke
			u = w; //Di tam sang dinh w
			w++;
			while (w < n)
			{
				if(go[w] == false && c[p[m]][w]!=-1 && c[p[m]][w] < c[p[m]][u])
					u = w;
				w++;
			}
			cost += c[p[m]][u];
			m++;
			p[m] = u;
			go[u] = true;
		}	
	}
}

int main()
{
	if(greedy_travel_sales_man())
	{
		cout<<"Tim duong di: ";
		for (int i = 0; i <= m; i++)
		{
			cout<<(char)(p[i] + 65)<<" ";
		}
		cout<<"\nTong chi phi la: " << cost << endl;
	}
	else 
	{
		cout<<"Khong tim duoc duong di";
	}
}
