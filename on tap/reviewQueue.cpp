#include<stdio.h>
#include<stdlib.h>
#define n 10
struct node{
	int data;
	struct node*next;	
};
typedef struct node*NODE;
struct queue{
	NODE pHead;
};
typedef struct queue QUEUE;
void Init(QUEUE *q)
{
	q->pHead=NULL;
}
NODE createNODE(int x)
{
	NODE p=(NODE)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;
	return p;
}
void push(int x,QUEUE *q)
{
	NODE p=createNODE(x);
	if(q->pHead==NULL)
	{
		q->pHead=p;
	}
	else
	{
		p->next=q->pHead;
		q->pHead=p;
	}
}
void pop(QUEUE *q)
{
	q->pHead=q->pHead->next;
}
void out(QUEUE q)
{
	NODE p=q.pHead;
	while(p!=NULL)
	{
		printf("%3d",p->data);
		p=p->next;
	}
}
int main()
{
	QUEUE q;
	Init(&q);
	for(int i=0;i<n;i++)
	{
		push(i,&q);
	}
	out(q);
	return 0;
}