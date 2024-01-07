#include<stdio.h>
#include<stdlib.h>

#define max 7

struct Item{
	int value;
	int next;
};

typedef struct Item Item;

struct Hashtable{
	Item t[max];
	int r;
};
typedef struct Hashtable Hashtable;

void Init(Hashtable *h)
{
	for(int i=0;i<max;i++)
	{
		h->t[i].value=-1;
		h->t[i].next=-1;
	}
	h->r=max-1;
}
int hashfunc(int value)
{
	return value%max;
}
void insert(int x,Hashtable*h)
{
	int i=hashfunc(x);
	if(h->r>=0)
	{
		if(h->t[i].value==-1)
		{
			h->t[i].value=x;
			return;
		}
		else
		{
			h->t[h->r].value=x;
			while(h->t[i].next>-1)
			{
				i=h->t[i].next;
			}
			h->t[i].next=h->r;
			
			while(h->r>=0&&h->t[h->r].value>=0)
				h->r--;
		}
	}
}
void output(Hashtable h)
{
	for(int i=0;i<max;i++)
	{
		printf("%d: ",i);
		printf("%3d%3d",h.t[i].value,h.t[i].next);
		printf("\n");
	}
}
int search(int x,Hashtable h)
{
	int i=hashfunc(x);
	while(i>=0)
	{
		if(h.t[i].value==x)
			return 1;
		i=h.t[i].next;	
	}
	return 0;
	
}
int main()
{
	Hashtable h;
	Init(&h);
	insert(21,&h);
	insert(15,&h);
	insert(1,&h);
	insert(36,&h);
	insert(8,&h);
	insert(7,&h);
	insert(12,&h);
	insert(5,&h);
	insert(19,&h);
	insert(3,&h);
	
	output(h);
	
	if(search(5,h)==1)
	printf("\nDa tim thay");
	else printf("\nKhong tim thay");
	return 0;
}
