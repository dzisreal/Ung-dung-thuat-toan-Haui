#include<bits/stdc++.h>
using namespace std;

int n,vt[8][8],dem = 0;

int X[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int Y[8] = {-1,  1, -2,  2, -2, 2, -1, 1};
//Với mỗi vị trí đứng của quân cờ ta có thể có nhiều nhất 8 vị trí nhảy có thể chọn

void show()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << vt[i][j] << "\t";
		cout << endl << endl;
	}
	cout << endl;
}

void Try(int x, int y)
{
	dem++; //Tăng giá trị bước đi
	vt[x][y] = dem; //Đánh dấu đã đi
	for (int i = 0; i < 8; i++)    
	{
        //Kiểm tra xem mã đã đi hết bàn cờ chưa
        if (dem == n * n) 
        {
            cout << "Cac buoc di la: \n";
            show();
            exit(0);//kết thúc chương trình
        }
        //Nếu chưa đi hết bàn cờ thì tạo bước đi mới
        int u = x + X[i];//tạo một vị trí x mới
        int v = y + Y[i];//tạo một vị trí y mới
        //Nếu hợp lệ thì tiến hành di chuyển
        if (u >= 0 && u < n&&v >= 0 && v < n&& vt[u][v] == 0)
            Try(u, v);
    }
    //Nếu không tìm được bước đi thì ta phải trả lại các giá trị ban đầu
    dem--;
    vt[x][y] = 0;
}

main()
{
	cout << "Nhap n: "; cin >> n;
	int x,b;
	cout << "Nhap vi tri xuat phat: "; cin >> x >> b;
	Try(x,b);
}
