#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
};
typedef struct node*NODE;
struct tree{
	NODE Root;
};
typedef struct tree TREE;
void Init(TREE *t)
{
	t->Root=NULL;
}
NODE CreateNode(int x)
{
	NODE p=(NODE)malloc(sizeof(struct node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void Insert(NODE *Root,int x)
{
	if(*Root==NULL)
	{
		NODE p=CreateNode(x);
		*Root=p;
	}
	if(x>(*Root)->data)
	Insert( &(*Root)->right,x);
	else if(x<(*Root)->data)
	Insert(&(*Root)->left,x);
}
void Inoder(NODE Root)
{
	if(Root==NULL)
	return;
	Inoder(Root->left);
	printf("%3d",Root->data);
	Inoder(Root->right);
}
int Search(NODE Root,int x)
{
	if(Root==NULL)
	return 0;
	if(x>Root->data)
	Search(Root->right,x);
	else if(x<Root->data)
	Search(Root->left,x);
	else //luc nay Root->data=x
	return 1;
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void change(NODE *temp,NODE*Root)
{
	if((*temp)->left!=NULL)
	change(&(*temp)->left,Root);
	else if((*temp)->left==NULL)
	{
		swap(&(*temp)->data,&(*Root)->data);
		*temp=(*temp)->right;
		return;
	}
}
void xoaNode(NODE *Root,int x)//xoa gia tri x
{
	if(x>(*Root)->data)
	xoaNode(&(*Root)->right,x);
	else if(x<(*Root)->data)
	xoaNode(&(*Root)->left,x);
	else//luc nay tim thay gia tri x de xoa
	{
		if((*Root)->left==NULL)
		*Root=(*Root)->right;
		else if((*Root)->right==NULL)
		*Root=(*Root)->left;
		else //truong hop co 2 node con
		{
			NODE p=*Root;
			change(&(*Root)->right,&p);
		}
	}
}
int main()
{
	TREE t;
	Init(&t);
	int a[100];
	for(int i=0;i<10;i++)
	{
		int x;
		scanf("%d",&x);
		Insert(&t.Root,x);
	}
	/*for(int i=0;i<10;i++)
	{
		int x;
		scanf("%d",&x);
		xoaNode(&t.Root,x);
		Inoder(t.Root);
	}*/
	printf("%d",Search(t.Root,5));
	
	
	return 0;
}
