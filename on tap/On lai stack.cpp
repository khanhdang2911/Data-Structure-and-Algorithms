#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char data;
	struct node*pNext;
};
typedef struct node *NODE;
struct stack{
	NODE pHead;
};
typedef struct stack STACK;
void Init(STACK *s)
{
	s->pHead=NULL;
}
NODE CreateNode(char c)
{
	NODE temp=(NODE)malloc(sizeof(struct node));
	temp->data=c;
	temp->pNext=NULL;
	return temp;
}
void push(char x,STACK *s)
{
	NODE p=CreateNode(x);
	if(s->pHead==NULL)
	{
		s->pHead=p;
	}
	else
	{
		p->pNext=s->pHead;
		s->pHead=p;
	}
}
void pop(STACK *s)
{
	s->pHead=s->pHead->pNext;
}
bool EmptyStack(STACK s)
{
	if(s.pHead==NULL)
	return true;
	return false;
}
void check()
{
	char a[100];
	printf("Enter to string:");
	fflush(stdin);
	gets(a);
	STACK s;
	Init(&s);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='(')
		push(a[i],&s);
		if(a[i]==')')
		pop(&s);
	}
	if(EmptyStack(s)==true)
	printf("Balance String");
	else
	printf("Unbalance String");
}
int main()
{
	check();
	return 0;
}

