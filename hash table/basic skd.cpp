#include<stdio.h>
#include<stdlib.h>
#define max 7
struct Node{
	int data;
	struct Node*pNext;
};
typedef struct Node *NODE;

void InitHashtable(NODE head[])
{
	for(int i=0;i<max;i++)
	head[i]=NULL;
}
NODE createNode(int value)
{
	NODE p=(NODE)malloc(sizeof(struct Node));
	p->data=value;
	p->pNext=NULL;
	return p;
}
int Hashfuction(int value)
{
	return value%max;
}
void insert(NODE head[],int value)
{
	int h=Hashfuction(value);
	NODE p=head[h];
	NODE r=createNode(value);
	NODE prev=NULL;
    while(p!=NULL&&(p->data<value))
    {
    	prev=p;
    	p=p->pNext;
	}
	if(prev==NULL)
	{
		if(head[h]==NULL)
		   head[h]=r;
		else{
		r->pNext=head[h];
		head[h]=r;
	   }
	}
	else if(p==NULL)
	{
		prev->pNext=r;
	}
	else
	{
	   r->pNext=p;
	   prev->pNext=r;	
	}
}
void output(NODE head[])
{
	for(int i=0;i<max;i++)
	{
	    printf("\nBUCKET %d: ",i);
	    NODE p=head[i];
	    while(p!=NULL)
	    {
	    	printf("%3d",p->data);
	    	p=p->pNext;
		}
	}
}
int search(NODE head[],int value)
{
	int h=Hashfuction(value);
	NODE p=head[h];
	while(p!=NULL)
	{
		if(p->data==value)
		return 1;
		p=p->pNext;
	}
	return 0;
	
}
int main()
{
	NODE head[max];
	InitHashtable(head);
	insert(head,5);
	insert(head,6);
	insert(head,9);
	insert(head,18);
	insert(head,2);
	insert(head,4);
	insert(head,12);
	insert(head,25);
	output(head);
	if(search(head,8)==1)
	printf("\nTim thay 8");
	if(search(head,18)==1)
	printf("\ntim thay 18");
	if(search(head,22)==1)
	printf("\ntim thay 22");
	return 0;
}
