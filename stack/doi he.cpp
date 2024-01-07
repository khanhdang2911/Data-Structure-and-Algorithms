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

void input(STACK&s,int n,int hecandoi)
{
	khoitao(s);
	while(n!=0)
	{
		int du=n%hecandoi;
		n=n/hecandoi;
		Push(s,du);
	}
}
//output cung dong thoi giai phong khi lay ra tung node
void output(STACK &s)
{
	printf("\nket qua sau khi doi la:");
	while(kiemtrastackrong(s)==false)
	{
		int x=s.Top->data;
		Pop(s);//delete top di
        if(x==10)printf("A");
		else if(x==11)printf("B");
		else if(x==12)printf("C");
		else if(x==13)printf("D");
		else if(x==14)printf("E");
		else if(x==15)printf("F");
		else printf("%d",x);	
		}
		
}
int main()
{
	STACK s;
	int x;
	printf("\nnhap so can doi:");
	scanf("%d",&x);
	int hecandoi;
	printf("\nnhap he can doi:");
	scanf("%d",&hecandoi);
	input(s,x,hecandoi);
	output(s);
	return 0;
}
