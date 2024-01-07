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
int Top(STACK s)
{
   return s.Top->data;	
}

void inANDout(STACK&s)
{
	khoitao(s);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		int temp;
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&temp);
			Push(s,temp);
		}
		else if(x==2)
		{
			if(kiemtrastackrong(s)==true)
			continue;
			if(kiemtrastackrong(s)==false)
			{
				Pop(s);
			}
		}
		else if(x==3)
		{
			if(kiemtrastackrong(s)==true)
			printf("Empty!\n");
			else 
			{
				printf("%d\n",Top(s));
			}
		}
	}
}
//output cung dong thoi giai phong khi lay ra tung node

int main()
{
	STACK s;
	inANDout(s);
	return 0;
}
