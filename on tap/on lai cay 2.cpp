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
NODE CreateNODE(int x)
{
	NODE p=(NODE)malloc(sizeof(struct node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void Insert(TREE *t,int x)
{
	NODE p=CreateNODE(x);
	if(t->Root==NULL)
	{
		t->Root=p;
		return;
	}
	NODE k=t->Root;
	while(true)
	{
		if(x>k->data)
		{
			if(k->right==NULL)//kiem tra de them node p vao
			{
				k->right=p;
				return;
			}
			k=k->right;
		}
		else
		{
			if(k->left==NULL)
			{
				k->left=p;
				return;
			}
			k=k->left;
		}
	}
}
void Inoder(NODE Root)
{
	if(Root==NULL)
	return;
	Inoder(Root->left);
	printf("%3d",Root->data);
	Inoder(Root->right);
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void deleteNode(TREE *t,int x)//x la gia tri can xoa
{
	NODE p=t->Root;
	NODE k;
	while(true) {
		if(x>p->data)
		{
			k=p;//luu vet lai
			p=p->right;
		}
		else if(x<p->data)
		{
			k=p;//luu vet lai
			p=p->left;
		}
		else break;//luc nay x=p->data
		if(p==NULL)
		return;//khong tim thay
	}

	
		if(p->left==NULL)
		{
			if(k->left==p)
			k->left=p->right;
			else if(k->right==p)
			k->right=p->right;
			return;
		}
		else if(p->right==NULL)
		{
			if(k->left==p)
			k->left=p->left;
			else if(k->right==p)
			k->right=p->left;
			return;
		}
		else//truong hop co 2 con
		{
			NODE temp=p->right;
			k=p;
			while(temp->left!=NULL)
			{
				k=temp;
				temp=temp->left;
			}
			swap(temp->data,p->data);
			if(k==p)
				k->right=temp->right;
			else
			k->left=temp->right;
		}
}
int main()
{
	TREE t;
	Init(&t);
	for(int i=0;i<10;i++)
	{
		int k;scanf("%d",&k);
		Insert(&t,k);
	}
	for(int i=0;i<10;i++)
	{
		int x;
		scanf("%d",&x);
		deleteNode(&t,x);
		printf("\n");
		Inoder(t.Root);
	}
	Inoder(t.Root);
	return 0;
}
//5 1 3 2 6 8 7 4 9 10
