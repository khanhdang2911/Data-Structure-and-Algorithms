#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
   char data;
   struct Node*pNext;	
};
typedef struct Node* NODE;
struct Stack
{
	NODE Top;
};
typedef struct Stack STACK;
void Init(STACK&s)
{
	s.Top=NULL;
}
bool kiemtrastackrong(STACK s)
{
	if(s.Top==NULL)
	return true;
	return false;
}
NODE CreateNode(char data)
{
	NODE p=(NODE)malloc(sizeof(struct Node));
    p->data=data;
    p->pNext=NULL;
    return p;
}
void Push(STACK &s,char data)
{
	NODE p=CreateNode(data);
	//them node p vao stack
	if(s.Top==NULL)//danh sach khong co gi
	{
		s.Top=p;
	}
	else
	{
		p->pNext=s.Top;
		s.Top=p;
	}
}
void Pop(STACK &s)
{
	NODE temp=s.Top;
	s.Top=s.Top->pNext;
	free(temp);
}
char checkTop(STACK s)
{
	return s.Top->data;
}
int kiemtra(STACK&s,char*a)
{
	Init(s);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]==' '||a[i]==',')
		continue;
		else if(a[i]=='{'||a[i]=='['||a[i]=='(')
		{
			Push(s,a[i]);
		}
		else if(a[i]=='}'||a[i]==']'||a[i]==')')
		{
			if(a[i]=='}')
			{
				if(checkTop(s)=='{')
				Pop(s);
				else return 0;
			}
			if(a[i]==')')
			{
				if(checkTop(s)=='(')
				Pop(s);
				else return 0;
			}
			if(a[i]==']')
			{
				if(checkTop(s)=='[')
				Pop(s);
				else return 0;
			}
			
			
		
		}
	}
	return 1;
}

int main()
{
	STACK s;
	char a[100];
    gets(a);
    if(kiemtra(s,a)==1)
    printf("can bang");
    else printf("khong can bang");
	return 0;
}
