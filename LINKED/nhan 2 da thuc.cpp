#include<stdio.h>
#include<stdlib.h>

struct element{
	int x;
	int pos;
};

typedef struct element data;

struct node{
	data t;
	struct node*pNext;
};

typedef struct node *NODE;

struct polynomial{
	NODE pHead;
};
typedef struct polynomial POLYNOMIAL;

void init1(POLYNOMIAL *l)
{
	l->pHead=NULL;
}
NODE createNode(data temp)
{
	NODE p=(NODE)malloc(sizeof(struct node));
	p->t.x=temp.x;
	p->t.pos=temp.pos;
	p->pNext=NULL;
	return p;
}
void insert(NODE p,POLYNOMIAL *l)
{
	if(l->pHead==NULL)
	l->pHead=p;
	else{
		if(p->t.pos > l->pHead->t.pos)
		{
			p->pNext=l->pHead;
			l->pHead=p;
			return;
		}
		NODE temp;
		NODE k=l->pHead;
		while(p->t.pos<k->t.pos&&k->pNext!=NULL)
		{
			temp=k;
			k=k->pNext;
		}
		if(k->t.pos==p->t.pos)
		k->t.x+=p->t.x;
		else if(k->pNext==NULL)
		{
			k->pNext=p;
		}
		else{
			p->pNext=k;
			temp->pNext=p;
		}
	}
}
void add(POLYNOMIAL a,POLYNOMIAL b,POLYNOMIAL*c)
{
	for(NODE p=a.pHead;p!=NULL;p=p->pNext)
	{
		int giatri=p->t.x;
		int bac=p->t.pos;
		data temp;
		temp.pos=bac;
		temp.x=giatri;
		NODE k=createNode(temp);
		insert(k,c);
	}
	for(NODE p=b.pHead;p!=NULL;p=p->pNext)
	{
		int giatri=p->t.x;
		int bac=p->t.pos;
		data temp;
		temp.pos=bac;
		temp.x=giatri;
		NODE k=createNode(temp);
		insert(k,c);
	}
}
void mul(POLYNOMIAL a,POLYNOMIAL b,POLYNOMIAL *c)
{
	for(NODE p=a.pHead;p!=NULL;p=p->pNext)
	{
		for(NODE k=b.pHead;k!=NULL;k=k->pNext)
		{
			int giatri=(p->t.x) * (k->t.x);
			int bac=(p->t.pos) + (p->t.pos);
			data temp;
			temp.pos=bac;
			temp.x=giatri;
			NODE p=createNode(temp);
			insert(k,c);
		}
	}
}
void output(POLYNOMIAL l)
{
	for(NODE p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%dx^%d+",p->t.x,p->t.pos);
	}
}
int main()
{
	POLYNOMIAL l,t,res1,res2;
	init1(&l);
	init1(&t);
	init1(&res1);
	init1(&res2);
	data temp1;
	temp1.pos=2;
	temp1.x=3;
	NODE p1=createNode(temp1);
	insert(p1,&l);
	
	data temp2;
	temp2.pos=1;
	temp2.x=1;
	NODE p2=createNode(temp2);
	insert(p2,&l);
	
	data temp3;
	temp3.pos=1;
	temp3.x=2;
	NODE p3=createNode(temp3);
	insert(p3,&l);
	
	output(l);
	
}
