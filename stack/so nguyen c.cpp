#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node*pNext;	
};
typedef struct Node* NODE;
struct List
{
	NODE pHead;
	NODE pTail;
};
typedef struct List LIST;
void Init(LIST*l)
{
	l->pHead=NULL;
	l->pTail=NULL;
}
NODE CreateNode(int x)
{
	NODE p=(NODE)malloc(sizeof(struct Node));
	p->data=x;
	p->pNext=NULL;
	return p;
}
void addHead(LIST*l,int x)
{
    NODE p=CreateNode(x);
    if(l->pHead==NULL)
    {
    	l->pHead=p;
    	l->pTail=p;
	}
	else
	{
		p->pNext=l->pHead;
		l->pHead=p;
	}
}
//them cuoi
void addTail(LIST*l,int x)
{
	NODE p=CreateNode(x);
	if(l->pHead==NULL)
	{
		l->pHead=p;
		l->pTail=p;
	}
	else
	{
		l->pTail->pNext=p;
		l->pTail=p;
		p->pNext=NULL;
	}
}
void ThemNodeTruoc(LIST*l,NODE X,NODE q)
{
	NODE temp;
  	//them node x truoc node q
  	for(NODE p =l->pHead;p!=NULL;p=p->pNext)
  	{
  		if(q->data==p->data)
  		{
  			X->pNext=temp->pNext;
  			temp->pNext=X;
  			return;
		  }
		  temp=p;
	  }
}
void ThemNodeSau(LIST*l,NODE X,NODE q)
{
	//Them node X sau node q
  	for(NODE p =l->pHead;p!=NULL;p=p->pNext)
	{
		if(p->data==q->data)
		{
			X->pNext=p->pNext;
			p->pNext=X;
			return;
		}
	}
}
void xoadaudanhsach(LIST*l)
{
	NODE p=l->pHead;
	l->pHead=l->pHead->pNext;
	free(p);
}
void xoacuoidanhsach(LIST*l)
{
	NODE truoc;
	for(NODE p=l->pHead;p!=NULL;p=p->pNext)
	{
		if(p==l->pTail)
		{
			truoc->pNext=NULL;
			l->pTail=truoc;
			break;
		}
		truoc=p;
	}
}
void xoaphantu(LIST*l,NODE q)
{
	NODE temp;
	//xoa node q
	for(NODE p=l->pHead;p!=NULL;p=p->pNext)
	{
		if(q->data==p->data)
		{
			temp->pNext=p->pNext;
			return;
		}
		temp=p;
	}
	
}

void xoatatcasochan(LIST*l)
{
	while(l->pHead->data%2==0)
	{
		xoadaudanhsach(l);
	}
	NODE temp;
	NODE g;
	for(NODE p=l->pHead;p!=NULL;p=p->pNext)
	{
		if(p->data%2==0)
		{
			temp->pNext=p->pNext;
			p=temp;
		}
		temp=p;
	}
} 

void input(LIST*l)
{
	Init(l);
	int n;
	printf("enter to n:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		printf("nhap phan tu thu %d:",i);
		scanf("%d",&x);
		NODE p=CreateNode(x);
		addTail(l,x);
	}
}
void output(LIST*l)
{
	for(NODE p=l->pHead;p!=NULL;p=p->pNext)
	{
	  printf("%3d",p->data);	
	}
}

int main()
{
	LIST l;
	input(&l);
	NODE X=CreateNode(0);
	NODE q=CreateNode(3);
    xoatatcasochan(&l);
	output(&l);
	return 0;
}
