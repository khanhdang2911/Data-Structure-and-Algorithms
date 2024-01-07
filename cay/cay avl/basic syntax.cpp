#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
};
typedef struct node *NODE;

struct tree{
	NODE Root;
};
typedef struct tree TREE;

void init(TREE*t)
{
	t->Root=NULL;
}

NODE createnode(int x)
{
	NODE temp=(NODE)malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int tinhchieucaocay(NODE Root)
{
	if(Root==NULL)
	return 0;
	int left=tinhchieucaocay(Root->left);
	int right=tinhchieucaocay(Root->right);
	if(left>right)
		return left+1;	
	else return right+1;
}
void quaytrai(NODE &Root)
{
	NODE pivot=Root->right;
	Root->right=pivot->left;
	pivot->left=Root;
	Root=pivot;
}
void quayphai(NODE &Root)
{
	NODE pivot=Root->left;
	Root->left=pivot->right;
	pivot->right=Root;
	Root=pivot;
}
void xetcanbang(NODE &Root)
{
	if(Root==NULL)
	return;
		int heightleft=tinhchieucaocay(Root->left);
		int heightright=tinhchieucaocay(Root->right);
		if(heightleft-heightright>1)
		{
			if(tinhchieucaocay(Root->left->left)>=tinhchieucaocay(Root->left->right))
				quayphai(Root);
			else
				{
					quaytrai(Root->left);
					quayphai(Root);
				}			
		}
		else if(heightright-heightleft>1)
		{
			if(tinhchieucaocay(Root->right->right)>=tinhchieucaocay(Root->right->left))
				quaytrai(Root);
			else
				{
					quayphai(Root->right);
					quaytrai(Root);
				}			
		}
}
int CreateTree(int x,NODE&Root)
{
	if(Root==NULL)
	{
		NODE p=createnode(x);
		Root=p;
		return 1;
	}	
	int res=0;	
	if(x<Root->data)
		res=CreateTree(x, Root->left);
	else
		res=CreateTree(x, Root->right);
	
	if(res==1)
	{
		xetcanbang(Root);
		return 1;// tiep tuc xet ve cac node cha truoc do de kiem tra tinh can bang
	}
}
int search(int x,NODE Root)
{
	if(Root->data==x)
	return 1;
	
	while(Root!=NULL)
	{
		if(x>Root->data)
		Root=Root->right;
		else if(x<Root->data)
		Root=Root->left;
		else
		return 1;//luc nay Root->data=x
	}
	return 0;
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;b=temp;
}
void change(NODE &p,NODE &Root)
{
	if(p->left!=NULL)
		change(p->left,Root);	
	else if(p->left==NULL)
	{
		Root->data=p->data;
		p=p->right;
	}
}
void deleteNODE(char x,NODE &Root)
{
	if(Root==NULL)
	return;
	if(x>Root->data)
		deleteNODE(x,Root->right);
	else if(x<Root->data)
		deleteNODE(x,Root->left);
	else
	{
		if(Root->left==NULL)
		{
			Root=Root->right;
		}
		else if(Root->right==NULL)
		{
			Root=Root->left;
		}
		else
		{
			NODE p=Root;
			change(p->right,Root);
			xetcanbang(Root);
		}
		return;		
	}
	xetcanbang(Root);	
		
}

void leftnoderight(NODE Root)
{
	if(Root==NULL)
	return;
	leftnoderight(Root->left);
	printf("%3d",Root->data);
	leftnoderight(Root->right);
}
void nodeleftright(NODE Root)
{
	if(Root==NULL)
	return;
	printf("%3c",Root->data);
	nodeleftright(Root->left);
	nodeleftright(Root->right);
}
int main()
{
	TREE t;
	init(&t);
	CreateTree('A',t.Root);
	CreateTree('B',t.Root);
	CreateTree('C',t.Root);
	CreateTree('D',t.Root);
	CreateTree('E',t.Root);
	CreateTree('F',t.Root);
	CreateTree('W',t.Root);
	CreateTree('Z',t.Root);
	CreateTree('U',t.Root);
	CreateTree('T',t.Root);
	CreateTree('K',t.Root);
	deleteNODE('D',t.Root);
	nodeleftright(t.Root);
	printf("\nChieu cao cay la:%d",tinhchieucaocay(t.Root));
	return 0;
}
