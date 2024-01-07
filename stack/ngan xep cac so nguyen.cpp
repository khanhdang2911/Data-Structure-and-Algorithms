#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node*pNext;	
};
typedef struct Node *NODE;
struct Stack
{
   NODE Top;	
};
typedef struct Stack STACK;
void khoitao(STACK&s)
{
	s.Top=NULL;
}
NODE createNODE(int data)
{
	NODE temp=(NODE)malloc(sizeof(struct Node));
	temp->data=data;
	temp->pNext=NULL;
	return temp;
}
/*
B4:THEM NODE
Push->kiem tra node co rong hay khong
Pop->them 1 node vao
Top->xem node dau tien
*/
bool kiemtrastackrong(STACK s)
{
	//neu rong tra ve true,nguoc lai tra ve false
	if(s.Top==NULL)return true;
	return false;
}
void Push(STACK&s,int data)
{
	NODE p=createNODE(data);
	//them node p vao stack
	if(s.Top==NULL)//danh sach khong co gi
	{
		s.Top=p;
	}
	else
	{
		p->pNext=s.Top;
		s.Top=p;
	}
}
//Pop thanh cong tra ve true(xoa dau stack)
void Pop(STACK&s)
{
    NODE p=s.Top;
    s.Top=s.Top->pNext;
    free(p);
}
int Top(STACK s,int &x)
{
   return s.Top->data;	
}

void input(STACK&s)
{
	khoitao(s);
	int n;
	printf("\nnhap vao so luong node:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int data;
		printf("nhap vao node thu %d:",i);
		scanf("%d",&data);
		Push(s,data);
	}
}
//output cung dong thoi giai phong khi lay ra tung node
void output(STACK &s)
{
	while(kiemtrastackrong(s)==false)
	{
		int x=s.Top->data;
		Pop(s);//delete top di
		printf("%4d",x);
	}
}
int main()
{
	STACK s;
	input(s);
	output(s);
	return 0;
}
