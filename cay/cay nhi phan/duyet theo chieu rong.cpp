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
NODE nhapdulieu(char s[])
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
	char a[100]="goc";
   t->Root=nhapdulieu(a);
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
   	      	char b[100]="con trai";
   	    	NODE trai=nhapdulieu(b);
		    push(q,trai);
		    q->pHead->x->left=trai;
		   }
		   else
		   {
		   	char c[100]="con phai";
		   	NODE phai=nhapdulieu(c);
		    push(q,phai);
		    q->pHead->x->right=phai;
		   }
	   }
	   else if(socon==2)
	   {
	   	char b[100]="con trai";
	   	  	NODE trai=nhapdulieu(b);
		    push(q,trai);
		    q->pHead->x->left=trai;
		    char c[100]="con phai";
         	NODE phai=nhapdulieu(c);
		    push(q,phai);
		    q->pHead->x->right=phai;
	   }
	   	    pop(q);
   }
}
void duyetcaytheochieurong(TREE t,QUEUE *q)
{
	push(q,t.Root);
	printf("%c ",q->pHead->x->data);
	while(q->pHead!=NULL)
	{
		if(q->pHead->x->left!=NULL)
		{
			NODE trai=q->pHead->x->left;
			printf("%c ",trai->data);
			push(q,trai);
		}
		if(q->pHead->x->right!=NULL)
		{
     		NODE phai=q->pHead->x->right;
			printf("%c ",phai->data);
			push(q,phai);
		}
		pop(q);
	}
}
//duyet truoc(NODE LEFT RIGHT)
void NLR(NODE Root)
{
	if(Root==NULL)
	return;
	printf("%c ",Root->data);
	NLR(Root->left);
	NLR(Root->right);
}
//duyet giua(LEFT NODE RIGHT)
void LNR(NODE Root)
{
	if(Root==NULL)
	return;
	LNR(Root->left);
	printf("%c ",Root->data);
	LNR(Root->right);
}
//duyet sau(RIGHT NODE LEFT)
void LRN(NODE Root)
{
	if(Root==NULL)
	return;
	LRN(Root->left);
	LRN(Root->right);
	printf("%c ",Root->data);
}
int main()
{
	TREE t;
	QUEUE q;
	input(&t,&q);

	
	printf("\n res=%c",t.Root->data);
	printf("Duyet truoc:\n");
    NLR(t.Root);
    printf("\nDuyet giua:\n");
    LNR(t.Root);
    printf("\nDuyet sau:\n");
    LRN(t.Root);
    printf("\nDuyet theo chieu rong:\n");
	duyetcaytheochieurong(t,&q);    
	return 0;
}
