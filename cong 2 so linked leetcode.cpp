#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node*pNext;	
};
typedef struct Node *NODE;
struct linked
{
   NODE pHead,pTail;	
};
typedef struct linked LINKED;
void init(LINKED*l)
{
	l->pHead=l->pTail=NULL;
}
NODE CreateNode(int data)
{
	NODE p=(NODE)malloc(sizeof(struct Node));
	p->data=data;
	p->pNext=NULL;
	return p;
}
void AddHead(LINKED*l,int data)
{
	NODE p=CreateNode(data);
	if(l->pHead==NULL)
	{
		l->pHead=l->pTail=p;
	}
	else 
	{
		p->pNext=l->pHead;
		l->pHead=p;
	}
}
void input(LINKED*a,LINKED *b,int n,int m)
{
	init(a);
	init(b);
	for(int i=1;i<=n;i++)
	{
		int data;
		scanf("%d",&data);
		AddHead(a,data);
	}
	for(int i=1;i<=m;i++)
	{
		int data;
		scanf("%d",&data);
		AddHead(b,data);
	}
}
void output(LINKED*l)
{
	for(NODE p=l->pHead;p!=NULL;p=p->pNext)
	{
		//printf("hellu");
		printf("%d",p->data);
	}
}
LINKED* sum(LINKED*a,LINKED*b)
{
	NODE p=a->pHead;
	NODE q=b->pHead;
	int nho=0;
	int sum;
	while(q!=NULL&&p!=NULL)
	{
		printf("hello");
		sum=q->data+p->data+nho;
		if(nho>0)nho=0;
		nho=sum/10;
		q->data=sum%10;
		q=q->pNext;
		p=p->pNext;
	}
    return b;
}
int main()
{
	LINKED a,b;
	int n;
	scanf("%d",&n);
    int m;
    scanf("%d",&m);
    input(&a,&b,n,m);
    sum(&a,&b);
	output(&b);
	return 0;
}
