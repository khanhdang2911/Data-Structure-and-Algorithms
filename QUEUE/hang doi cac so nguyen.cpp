#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node*pNext;	
};
typedef struct Node *NODE;
struct Queue
{
   NODE pHead,pTail;	
};
typedef struct Queue QUEUE;
void khoitao(QUEUE&q)
{
	q.pHead=q.pTail=NULL;
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
bool kiemtraqueuerong(QUEUE q)
{
	//neu rong tra ve true,nguoc lai tra ve false
	if(q.pHead==NULL)return true;
	return false;
}
void Push(QUEUE&q,int data)
{
	NODE p=createNODE(data);
	//them node p vao stack
	if(q.pHead==NULL)//danh sach khong co gi
	{
		q.pHead=q.pTail=p;
	}
	else
	{
		q.pTail->pNext=p;
		q.pTail=p;
	}
}
//Pop thanh cong tra ve true(xoa dau stack)
void Pop(QUEUE&q)
{
    NODE p=q.pHead;
    q.pHead=q.pHead->pNext;
    free(p);
}
int Top(QUEUE q,int &x)
{
   return q.pHead->data;	
}

void input(QUEUE&q)
{
	khoitao(q);
	int n;
	printf("\nnhap vao so luong node:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int data;
		printf("nhap vao node thu %d:",i);
		scanf("%d",&data);
		Push(q,data);
	}
}
//output cung dong thoi giai phong khi lay ra tung node
void output(QUEUE &q)
{
	while(kiemtraqueuerong(q)==false)
	{
		int x=q.pHead->data;
		Pop(q);//delete top di
		printf("%4d",x);
	}
}
int main()
{
	QUEUE q;
	input(q);
	output(q);
	return 0;
}
