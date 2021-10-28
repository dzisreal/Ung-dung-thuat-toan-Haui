#include<bits/stdc++.h>
using namespace std;

struct Call
{
	int n;
	char a;
	char b;
	char c;
};

struct Stack
{
	int top;
	Call *e;
};

void init(Stack &s) //Khoi tao ngan xep rong
{
	s.top = -1;
	s.e = NULL;
}

bool empty(Stack s) // Kiem tra ngan xep rong
{
	return s.top == -1;
}

void push(Stack &s, Call call_in) // Day mot phan tu(loi goi) vao ngan xep
{
	//Cap phat bo nho cho mang e
	if (empty(s))
		s.e = new Call[1]; //Cap phat moi
	else
		//Cap phat them 1 phan tu cho moi loi goi
		s.e = (Call*) realloc(s.e, (s.top+2) * sizeof(Call)); // top + 2 = n+1
	s.top++;
	s.e[s.top] = call_in;
}

void pop(Stack &s, Call &call_out)//Lay mot phan tu(loi goi) o dinh ngan xep de xu ly
{
	if (empty(s)) return;
	call_out = s.e[s.top];
	if (s.top==0) //Lay ra va het, khoi tao ngan xep rong
	{
		delete []s.e;
		init(s);
	}
	else
	{
		//Van con, cap phat giam 1 phan tu
		s.e = (Call*) realloc(s.e, s.top * sizeof(Call)); // top = n-1
		s.top--;
	}
}

void tower(Call first_call)
{
	Call call_in,call_out;
	Stack s;
	//Day loi goi dau tien vao ngan xep
	init(s);
	call_in = first_call;
	push(s, call_in);
	while(!empty(s))
	{
		pop(s,call_out);
		if (call_out.n == 1)
			cout << "Chuyen 1 dia tu coc " << call_out.a << " sang coc " << call_out.c << endl;
		else
		{
			call_in.n = call_out.n-1;
			call_in.a = call_out.b;
			call_in.b = call_out.a;
			call_in.c = call_out.c;
			push(s,call_in); // Day loi goi chuyen(n-1,B,A,C);

			//Chuyen 1 dia tu coc A sang coc C
			call_in = call_out;
			call_in.n = 1;
			push(s,call_in); // Day loi goi chuyen (1,A,B,C)

			//Chuyen n-1 dia tu coc a sang coc b
			call_in.n = call_out.n-1;
			call_in.a = call_out.a;
			call_in.b = call_out.c;
			call_in.c = call_out.b;
			push(s,call_in); // Day loi goi chuyen(n-1,A,C,B)
		}
	}
}

main()
{
	Call first_call = {3, 'A', 'B', 'C'};
	tower(first_call);
}