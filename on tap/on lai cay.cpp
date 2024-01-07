#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node*left;
	struct Node*right;
};
typedef struct Node*NODE;
struct Tree{
	NODE Root;
};
typedef struct Tree TREE;
void Init(TREE *t)
{
	t->Root=NULL;
}
NODE createNODE(int x)//them node x vao cay
{
	NODE p=(NODE)malloc(sizeof(struct Node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void Insert(TREE *t,int x)//them gia tri x vao cay
{
	if(t->Root==NULL)
	{
		t->Root=createNODE(x);
		return;
	}
	NODE p=t->Root;
	while(true)
	{
		if(x>p->data)
		{
			if(p->right==NULL){
			p->right=createNODE(x);
			return;
			}
			p=p->right;
		}
		else if(x<p->data)
		{
			if(p->left==NULL){
			p->left=createNODE(x);
			return;
		    }
		    p=p->left;
		}
    }
}
void insert2(NODE *Root,int x)
{
	if(*Root==NULL)
	{
		*Root=createNODE(x);
		return;
	}
	if(x>(*Root)->data)
	insert2( &(*Root)->right , x);
	else if(x < (*Root)->data)
	insert2( &(*Root)->left , x);
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void change(NODE *p,NODE *Root)
{
	if( (*p)->left!=NULL)
	change( &(*p)->left,Root);
	else if( (*p)->left==NULL)
	{
		swap( (*p)->data,(*Root)->data);
		*p=(*p)->right;
	}
}
void xoaNode(int k,NODE *Root)
{
	if(k>(*Root)->data)
	xoaNode(k, &(*Root)->right);
	else if(k < (*Root)->data)
	xoaNode(k, &(*Root)->left);
	else
	{
		if((*Root)->left == NULL)
		*Root=(*Root)->right;
		else if((*Root)->right == NULL)
		*Root=(*Root)->left;
		else
		{
			NODE p=*Root;
			change(&(*Root)->right,&p);
		}
	}
}
void posOrder(NODE Root)
{
	if(Root==NULL)
	return;
	posOrder(Root->left);
	posOrder(Root->right);
	printf("%3d",Root->data);
}
void Inorder(NODE Root)
{
	if(Root==NULL)
	return;
	Inorder(Root->left);
	printf("%3d",Root->data);
	Inorder(Root->right);
}
int main()
{
	TREE t;
	Init(&t);
	for(int i=0;i<10;i++)
	{
		int k;scanf("%d",&k);
		insert2(&t.Root,k);
	}
	xoaNode(5,&t.Root);
	Inorder(t.Root);
	return 0;
}

