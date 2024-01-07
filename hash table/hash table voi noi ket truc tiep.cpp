#include<stdio.h>
#define max 7
struct item{
	int data;
	int next;
};
typedef item item;
struct hashtable{
	item t[];
	int r;
};
typedef struct hashtable hashtable;
void init(hashtable *h)
{
	for(int i=0;i<max;i++)
	{
		h->t[i].data=-1;
		h->t[i].next=-1;
	}
	h->r=max-1;
}
int hashfunction(int value)
{
	return value%max;
}
void insert(hashtable *h,int value)
{
	int temp=hashfunction(value);
	if(h->t[value].data==-1)
	h->t[value].data=value;
	else if(h->t[value].data!=-1)
	{
		int p=h->t[value].next;
		while(p!=-1)
		{
			p=h->t[h->t[value].next].next;
		}
		while(h->r!=-1)
		(h->r)--;
		h->t[h->r].data=value;
		h->t[value].next=h->r;
	}
}
int main()
{
	
	
	return 0;
}
