#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

void demsoluongnodecotrencay(NODE Root,int*dem )
{
	if(Root!=NULL)
	{
		++(*dem);
		demsoluongnodecotrencay(Root->left,dem);
		demsoluongnodecotrencay(Root->right,dem);
	}
}
void demsoluongnodela(NODE Root,int *dem)
{
	if(Root!=NULL)
	{
		if(Root->left==NULL&&Root->right==NULL)
		++(*dem);
		demsoluongnodela(Root->left,dem);
		demsoluongnodela(Root->right,dem);
	}
}
void demsoluongnodecodu2con(NODE Root,int *dem)
{
	if(Root!=NULL)
	{
		if(Root->left!=NULL&&Root->right!=NULL)
		++(*dem);
		demsoluongnodecodu2con(Root->left,dem);
		demsoluongnodecodu2con(Root->right,dem);
	}
}
void demsoluongcacnodechico1con(NODE Root,int *dem)
{
	if(Root!=NULL)
	{
	if((Root->left==NULL&&Root->right!=NULL)||(Root->left!=NULL&&Root->right==NULL))
	++(*dem);
	demsoluongcacnodechico1con(Root->left,dem);
	demsoluongcacnodechico1con(Root->right,dem);
   }
}
int docaocuanodebatki(NODE Root,QUEUE*q,char DataCuaNodeCanTimDoCao)
{
	int dem=0;
	push(q,Root);
	++dem;
	while(1)
	{
		if(q->pHead->x->left!=NULL)
		{
	       push(q,q->pHead->x->left);
	      ++dem;
	       if(q->pHead->x->left->data==DataCuaNodeCanTimDoCao)
	       break;
	   }
	   		if(q->pHead->x->right!=NULL)
		{
		    push(q,q->pHead->x->right);
	        ++dem;
	   	   if(q->pHead->x->right->data==DataCuaNodeCanTimDoCao)
	        break;
	    }
	   pop(q);
	}
	return sqrt(dem)+1;
}
int main()
{
	TREE t;
	QUEUE q;
	input(&t,&q);
	int dem=0;
	demsoluongnodecotrencay(t.Root,&dem);
	printf("\nSo luong cac not co tren cay la:%d",dem);
	int dem1=0;
	demsoluongnodela(t.Root,&dem1);
	printf("\nSo luong cac node la co tren cay la:%d",dem1);
	int dem2=0;
	demsoluongnodecodu2con(t.Root,&dem2);
	printf("\nSo luong cac node co du 2 con la:%d",dem2);
	int dem3=0;
	demsoluongcacnodechico1con(t.Root,&dem3);
	printf("\nSo luong cac node chi co 1 con la:%d",dem3);
	char data;
	printf("\nNhap data cua node can kiem tra:");
	fflush(stdin);
	scanf("%c",&data);
	printf("\nChieu cao cua node do la:%d",docaocuanodebatki(t.Root,&q,data));
	return 0;
}
