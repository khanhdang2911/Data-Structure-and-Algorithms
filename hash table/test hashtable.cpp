#include<stdio.h>
#include<stdlib.h>
#define max 100
struct node{
	int data;
	struct node*pNext;
};
typedef struct node*NODE;

void init(NODE Head[])
{
	for(int i=0;i<100;i++)
	Head[i]=NULL;
}
NODE createnode(int x)
{
	NODE p=(NODE)malloc(sizeof(struct node));
	p->data=x;
	p->pNext=NULL;
	return p;
}

int hashfunction(int value)
{
	return value%max;
}

void insert(int x,NODE Head[])
{
	int i=hashfunction(x);
	NODE p=createnode(x);
	if(Head[i]==NULL)
		Head[i]=p;
	else
	{
		NODE k=Head[i];
		if(x<=k->data)
		{
			p->pNext=Head[i];
			Head[i]=p;
			return;
		}
		
		while(k->pNext!=NULL && x>k->data)
			k=k->pNext;
		
		if(k->pNext==NULL)
			k->pNext=p;
		else
		{
			p->pNext=k->pNext;
			k->pNext=p;
		}	
	}
}
int search(int value,NODE Head[])
{
	int i=hashfunction(value);
	if(Head[i]!=NULL)
	{
		NODE k=Head[i];
		while(k!=NULL)
		{
			if(k->data==value)
				return 1;
			k=k->pNext;
		}
	}
	return 0;
}
void output(NODE Head[])
{
	for(int i=0;i<max;i++)
	{
		NODE k=Head[i];
		if(k!=NULL)
		{
			printf("\nBucket thu %d co cac phan tu:",i);
			while(k!=NULL)
			{
				printf("%5d",k->data);
				k=k->pNext;
			}
		}	
	}
}
int main()
{
	NODE Head[max];
	init(Head);
	insert(36,Head);
	insert(522,Head);
	insert(107,Head);
	insert(7,Head);
	insert(16,Head);
	insert(5,Head);
	insert(9,Head);
	insert(1,Head);
	insert(2,Head);
	insert(101,Head);
	insert(9,Head);
	insert(88,Head);
	insert(52,Head);
	
	if(search(5,Head)==1)
		printf("Da tim thay");
	else
		printf("Khong tim thay");
	
	output(Head);
	return 0;
}
