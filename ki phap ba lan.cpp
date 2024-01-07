#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node1
{
	char* data;
	struct Node1*pNext;
  	
};
typedef struct Node1* NODE1;
struct Stack
{
	NODE1 Top;
};
typedef struct Stack STACK;
void init1(STACK&s)
{
	s.Top=NULL;
}
NODE1 CreateNODE1(char* data)
{
	NODE1 p=(NODE1)malloc(sizeof(struct Node1));
	p->data=data;
	p->pNext=NULL;
	return p;
}
bool checkstackrong(STACK&s)
{
	if(s.Top==NULL)return true;
	return false;
}
void PushS(STACK&s,char* data)
{
	NODE1 p=CreateNODE1(data);
	if(checkstackrong(s)==true)
	{
		s.Top=p;
	}
	else
	{
		p->pNext=s.Top;
		s.Top=p;
	}
}
void PopS(STACK&s,char data)
{
	NODE1 temp=s.Top;
	s.Top=s.Top->pNext;
	free(temp);
}
/////queue
struct Node2
{
	char* data;
	struct Node2*pNext;
  	
};
typedef struct Node2* NODE2;
struct Queue
{
	NODE2 pHead,pTail;
};
typedef struct Queue QUEUE;
void init2(QUEUE&q)
{
	q.pHead=q.pTail=NULL;
}
NODE2 CreateNODE2(char* data)
{
	NODE2 p=(NODE2)malloc(sizeof(struct Node2));
	p->data=data;
	p->pNext=NULL;
	return p;
}
bool checkqueuerong(QUEUE&q)
{
	if(q.pHead==NULL)return true;
	return false;
}
void PushQ(QUEUE&q,char* data)
{
	NODE2 p=CreateNODE2(data);
	if(checkqueuerong(q)==true)
	{
		q.pHead=q.pTail=NULL;
	}
	else
	{
		q.pTail->pNext=p;
		q.pTail=p;
	}
}
void PopQ(QUEUE &q,char data)
{
	NODE2 temp=q.pHead;
	q.pHead=q.pHead->pNext;
	free(temp);
}

void nhap(STACK&s,QUEUE&q,char*a)
{
	if(a[0]=='(')
	{
		PushS(s,(char*)a[0]);
	}
	else PushQ(q,strtok(a," ( ) + - * / "));
	
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>=0&&a[i]<=9)
		{
			PushQ(q,strtok(NULL," ( ) + - " ));
		}
		else if(a[i]=='(')
		{
			PushS(s,(char*)a[i]);
		}

		
	}
}

int main()
{
	
	return 0;
}
