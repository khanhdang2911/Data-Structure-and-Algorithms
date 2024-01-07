#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
};
typedef struct node *NODE;

struct tree{
	NODE Root=NULL;
};
typedef struct tree TREE;

NODE createnode(int x)
{
	NODE temp=(NODE)malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;b=temp;
}
void CreateTree(int data,TREE*t)//them gia tri data vao cay
{
	NODE x=createnode(data);
	if(t->Root==NULL)
		t->Root=x;
		
	else{
		NODE temp=t->Root;
		while(1)
		{
			if(x->data>temp->data)
			{
				if(temp->right!=NULL)
				temp=temp->right;
				else{
				temp->right=x;
				break;
				}
			}
			else if(x->data<temp->data)
			{
				if(temp->left!=NULL)
				temp=temp->left;
				else{
					temp->left=x;
					break;
				}
			}
		}
	}	
}
void CreateTree2(int data,NODE &Root)
{
	if(Root==NULL)
	{
		NODE x=createnode(data);
		Root=x;
		return;
	}
	if(data>Root->data)
		CreateTree2(data,Root->right);
	else
		CreateTree2(data,Root->left);
}
void leftnoderight(NODE Root)
{
	if(Root==NULL)
	return;
	leftnoderight(Root->left);
	printf("%4d",Root->data);
	leftnoderight(Root->right);
}

int searchkhudequy(int x,NODE Root)
{
	if(Root->data==x)
	return 1;

	while(Root!=NULL)
		{
			if(x>Root->data)
			Root=Root->right;
			else if(x<Root->data)
			Root=Root->left;
			else //Luc nay Root->data=x
			return 1;
		}
		return 0;
}
bool searchdequy(int x,NODE Root)
{
	if(Root==NULL)
		return false;
	if(Root->data==x)
		return true;
	if(x>Root->data)
		return searchdequy(x,Root->right);
	else
		return searchdequy(x,Root->left);
}
void delete1node(int x,TREE*t)
{
	NODE p,k;
	if(t->Root->data==x)
	p=t->Root;
		
	else{
		NODE temp=t->Root;
		while(1)
		{
			if(x>temp->data)
			{
				if(temp->right!=NULL){
				k=temp;	
				temp=temp->right;
				if(temp->data==x)
				{
				p=temp;
				break;
				}
				}
				
			}
			else if(x<temp->data)
			{
				if(temp->left!=NULL){
				k=temp;
				temp=temp->left;
				if(temp->data==x)
				{
				p=temp;
				break;
				}
			}
				
			}
		}
	}	
	if(p->left==NULL&&p->right==NULL){
	if(k->left==p)
	k->left=NULL;
	else
	k->right=NULL;
	}
	else if(p->left!=NULL&&p->right==NULL)
		k->left=p->left;
	else if(p->left==NULL&&p->right!=NULL)
		k->right=p->right;
	else
	{
		NODE l=p->left;
		while(l->right!=NULL)
		{
		k=l;	
		l=l->right;
		}
		p->data=l->data;
		if(k->left==l)
		k->left=NULL;
		else
		k->right=NULL;
		
	}	
}
void timnodethaythe(NODE&Root,NODE &p)
{
	if(Root->right!=NULL)
	timnodethaythe(Root->right,p);
	else if(Root->right==NULL)
	{
	p->data=Root->data;
	Root=Root->left;
	}
}
void delete1nodeusedequy(NODE &Root,int x)
{
	if(Root==NULL)
		return;
	if(x>Root->data)
		delete1nodeusedequy(Root->right,x);
	else if(x<Root->data)
		delete1nodeusedequy(Root->left,x);
	else //tim thay node can delete
	{
		if(Root->left==NULL)
		Root=Root->right;
		else if(Root->right==NULL)
		Root=Root->left;
		else
		{
			NODE p=Root;
			timnodethaythe(Root->left,p);
		}
	}	

}
int main()
{
	TREE t;
	t.Root=createnode(5);
	CreateTree(7,&t);
	CreateTree(16,&t);
	CreateTree(8,&t);
	CreateTree(27,&t);
	CreateTree(6,&t);
	CreateTree(2,&t);
	CreateTree(3,&t);
	CreateTree(1,&t);
	CreateTree(4,&t);
	CreateTree(10,&t);
	CreateTree(15,&t);
	CreateTree(11,&t);
	leftnoderight(t.Root);
	if(searchkhudequy(14,t.Root)==1)
	printf("\nTim thay\n");
	else printf("\nKhong tim thay\n");
	delete1nodeusedequy(t.Root,16);
	leftnoderight(t.Root);
	
	//t.Root=createnode(10);
/*	CreateTree2(5,t.Root);
	CreateTree2(16,t.Root);
	CreateTree2(4,t.Root);
	CreateTree2(19,t.Root);
	CreateTree2(7,t.Root);
	CreateTree2(17,t.Root);
	leftnoderight(t.Root);
	if(searchkhudequy(16,t.Root)==1)
		printf("\nTim thay.");
	else printf("\nKhong tim thay.");*/
	return 0;
}
