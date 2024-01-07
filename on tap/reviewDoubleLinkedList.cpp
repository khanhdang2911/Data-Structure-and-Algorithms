#include<stdio.h>
#include<stdlib.h>
#define n 10
struct node{
	int data;
	struct node*next;
	struct node*prev;	
};
typedef struct node*NODE;
struct doubleLinkedList{
	NODE pHead,pTail;
};
typedef struct doubleLinkedList DOUBLELINKEDLIST;
void Init(DOUBLELINKEDLIST *l)
{
	l->pHead=NULL;
	l->pTail=NULL;
}
NODE createNODE(int x)
{
	NODE p=(NODE)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void addFirst(int x,DOUBLELINKEDLIST *l)
{
	NODE p=createNODE(x);
	if(l->pHead==NULL)
	{
		l->pHead=l->pTail=p;
		
	}
	else
	{
		p->next=l->pHead;
		l->pHead->prev=p;
		l->pHead=p;
	}
}
void addLast(int x,DOUBLELINKEDLIST*l)
{
	NODE p=createNODE(x);
	if(l->pHead==NULL)
	{
		l->pHead=l->pTail=p;
		
	}
	else
	{
		l->pTail->next=p;
		p->prev=l->pTail;
		l->pTail=p;
	}
}
void out(DOUBLELINKEDLIST l)
{
	NODE p=l.pHead;
	while(p!=NULL)
	{
		printf("%3d",p->data);
		p=p->next;
	}
}
int main()
{
	DOUBLELINKEDLIST l;
	Init(&l);
	for(int i=0;i<15;i++)
	{
		addLast(i,&l);
	}
	out(l);
	return 0;
}