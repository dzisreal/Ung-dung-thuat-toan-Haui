#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	float *s,*f;
	cin >> n;
	s = new float[n];
	f = new float[n];

	queue<int>opt;

	for(i=0; i<n; i++)
		cin >> s[i];

	for(i=0; i<n; i++)
		cin >> f[i];

	float lf = 0;

	for(i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if (s[i] > s[j])
			{
				swap(s[i],s[j]);
				swap(f[i],f[j]);
			}
			
	for(i=0; i<n; i++)
	{
		if(s[i] >= lf)
		{
			opt.push(1);
			lf = f[i];
		}
		else
		{
			opt.push(0);
		}
	}

	while(!opt.empty())
	{
		i = opt.front();
		cout << i << " ";
		opt.pop();
	}
	cout << endl;
}