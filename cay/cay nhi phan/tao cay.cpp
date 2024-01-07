#include<stdio.h>
#include<stdlib.h>

struct Node
{
	char data;
	struct Node *left,*right;
};
typedef struct Node *NODE;
struct Tree
{
	NODE Root;
};
typedef struct Tree TREE; 
void Init(TREE*t)
{
	t->Root=NULL;
}
NODE CreateNODE(char x)
{
	NODE p=(NODE)malloc(sizeof(struct Node));
	p->data=x;
	p->left=p->right=NULL;
	return p;
}
struct Nodecuaqueue
{
   NODE x;
   struct Nodecuaqueue *pNext;	
};
typedef struct Nodecuaqueue* NODEQUEUE;
struct Queue
{
	NODEQUEUE pHead,pTail; 
};
typedef struct Queue QUEUE;
void khoitao(QUEUE*q)
{
	q->pHead=q->pTail=NULL;
}
NODEQUEUE getnode(NODE dulieu)
{
	NODEQUEUE p=(NODEQUEUE)malloc(sizeof(struct Nodecuaqueue));
	p->x=dulieu;
	p->pNext=NULL;
	return p;
}
void push(QUEUE*q,NODE dulieu)
{
	NODEQUEUE p=getnode(dulieu);
	if(q->pHead==NULL)
	{
		q->pHead=q->pTail=p;
	}
	else
	{
		q->pTail->pNext=p;
		q->pTail=p;
	}
}
void pop(QUEUE*q)
{
	q->pHead=q->pHead->pNext;
}
char top(QUEUE*q)
{
	return q->pHead->x->data;
}
NODE nhapdulieu(char*s)
{
	fflush(stdin);
	printf("\nnhap du lieu cho node %s:",s);
	char x;
	scanf("%c",&x);
	NODE p=CreateNODE(x);
	return p;
}
void input(TREE*t,QUEUE*q)
{
   t->Root=nhapdulieu("goc");
   NODE p=t->Root;
   push(q,p);
   while(q->pHead!=NULL)
   {
   	printf("\nBan muon node %c co bao nhieu con:",q->pHead->x->data);
   	int socon;
   	scanf("%d",&socon);
   	if(socon==1)
   	{
   		printf("\nBan muon la con trai hay phai, nhap t hoac p:");
   	    char loaicon;
   	    fflush(stdin);
   	    scanf("%c",&loaicon);
   	    if(loaicon=='t')
   	      {
   	    	NODE trai=nhapdulieu("con trai");
		    push(q,trai);
		    q->pHead->x->left=trai;
		   }
		   else
		   {
		   	NODE phai=nhapdulieu("con phai");
		    push(q,phai);
		    q->pHead->x->right=phai;
		   }
	   }
	   else if(socon==2)
	   {
	   	  	NODE trai=nhapdulieu("con trai");
		    push(q,trai);
		    q->pHead->x->left=trai;
         	NODE phai=nhapdulieu("con phai");
		    push(q,phai);
		    q->pHead->x->right=phai;
	   }
	   	    pop(q);

   }
}


int main()
{
	TREE t;
	QUEUE q;
	input(&t,&q);
	printf("\nRoot->left->left->data=%c",t.Root->left->left->data);
	return 0;
}
