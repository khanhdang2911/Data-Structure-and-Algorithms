#include<stdio.h>
#include<stdlib.h>
struct Node 
{
   int data;
   struct Node*pNext;	
};
typedef struct Node* NODE;
struct Stack
{
	NODE Top;
};
typedef struct Stack STACK;
void Init(STACK*s)
{
	s->Top=NULL;
}
NODE createNode(STACK*s,int x)
{
	NODE p=(NODE)malloc(sizeof(struct Node));
    p->pNext=NULL;
    p->data=x;
    return p;
}
int kiemtraStacktrong(STACK*s)
{
	if(s->Top==NULL)
	return 1;
	return 0;
}
void Push(STACK*s,int x)
{
	NODE p=createNode(s,x);
	if(s->Top==NULL)
	{
		s->Top=p;
	}
	else{
	p->pNext=s->Top;
	s->Top=p;
   }
}
void Pop(STACK*s)
{
	NODE p=s->Top;
	s->Top=s->Top->pNext;
    free(p);
}
void input(STACK*s)
{
	Init(s);
	int n;
	printf("nhap n:");
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	printf("nhap phan tu thu %d:",i);
    	int x;
    	scanf("%d",&x);
    	NODE p=createNode(s,x);
    	Push(s,x);
	}
}
void output(STACK*s)
{
   while(kiemtraStacktrong(s)==0)
   {
   	   printf("%3d",s->Top->data);
   	   Pop(s);
   }
}
int main()
{
    STACK s;
    input(&s);
    output(&s);
	return 0;
}