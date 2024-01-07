#include<stdio.h>
#define max 7
struct item{
	int data;
	int next;
};
typedef item item;
struct hashtable{
	item t[max];
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
void insert(hashtable *h,int x)
{
	if(h->r>=0)
	{
		int idx=hashfunction(x);
		if(h->t[idx].data==-1)
			h->t[idx].data=x;
		else
		{
			h->t[h->r].data=x;
			while(h->t[idx].next!=-1)
				idx=h->t[idx].next;
			h->t[idx].next=h->r;
			while(h->t[h->r].data>=0&&h->r>=0)
				(h->r)--;
		}
    }
}
void output(hashtable h)
{
	for(int i=0;i<max;i++)
	{
		if(h.t[i].data>=0)
		printf("%d : %d :%d\n",i,h.t[i].data,h.t[i].next);
	}
}
void search(hashtable h,int x)
{
	int idx=hashfunction(x);
	if(h.t[idx].data==-1)
	{
		printf("\nKhong tim thay %d",x);
		return;
	}
	if(h.t[idx].data==x)
	{
		printf("\nDa tim thay %d ",x);
    	return;
	}
	else
	{
		while(h.t[idx].next!=-1){
		idx=h.t[idx].next;
		if(h.t[idx].data==x)
		{
			printf("\nDa tim thay %d ",x);
			return ;
		}
		printf("%d   ",h.t[idx].data);
		}
	}
	printf("\nKhong tim thay %d",x);
}
int main()
{
	hashtable h;
	init(&h);
	insert(&h,12);
	insert(&h,8);
	insert(&h,1);
	insert(&h,6);
	insert(&h,15);
	output(h);
	search(h,22);
	return 0;
}

