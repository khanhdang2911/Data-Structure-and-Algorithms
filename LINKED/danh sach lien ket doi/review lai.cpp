 #include<stdio.h>
 #include<stdlib.h>
 
 struct Node 
 {
   int data;
   struct Node*pNext;
   struct Node*pRev;	
 };
 typedef struct Node *NODE;
 struct List
 {
  NODE pTail,pHead;	
 };
 typedef struct List LIST;
 void Init(LIST*l)
 {
 	l->pHead=NULL;
 	l->pTail=NULL;
 }
 NODE createNode(int x)
 {
 	NODE p=(NODE)malloc(sizeof(struct Node));
 	p->data=x;
 	p->pNext=NULL;
 	p->pRev=NULL;
 	return p;
 }
void addHead(LIST*l,int x)
{
	NODE p=createNode(x);
	if(l->pHead==NULL)
	{
		l->pHead=p;
		l->pTail=p;
	}
	else
	{
		p->pNext=l->pHead;
		l->pHead->pRev=p;
		l->pHead=p;
	}
}
void addTail(LIST*l,int x)
{
	NODE p=createNode(x);
	if(l->pHead==NULL)
	{
		l->pHead=p;
		l->pTail=p;
	}
	else
	{
		l->pTail->pNext=p;
		p->pRev=l->pTail;
		l->pTail=p;
	}
}
void themptu(LIST*l)
{
	Init(l);
	int n;
	printf("nhap n:");
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		NODE p=createNode(x);
		addTail(l,x);
		}	
}
void output(LIST*l)
{
	for(NODE p=l->pTail;p!=NULL;p=p->pRev)
	{
		printf("%3d",p->data);
	}
	printf("\n");
	for(NODE p=l->pHead;p!=NULL;p=p->pNext)
	{
		printf("%3d",p->data);
	}
	printf("\n");
}
void addsau(LIST*l,int pos,NODE temp)
{
	//them Node temp vao sau vi tri pos
	int dem=0;
	for(NODE p=l->pHead;p!=NULL;p=p->pNext)
	{
		++dem;
		if(dem==pos)
		{
			temp->pNext=p->pNext;
			p->pNext->pRev=temp;
			p->pNext=temp;
			temp->pRev=p;
		}
	}
}
void xoadau(LIST*l)
{
	l->pHead=l->pHead->pNext;
	l->pHead->pRev=NULL;
}
void xoacuoi(LIST*l)
{
	l->pTail->pRev->pNext=NULL;
	l->pTail=l->pTail->pRev;
}
void xoa(LIST *l,int vitrixoa)
{
	if(vitrixoa==1){
	xoadau(l);
	return;
	}
	int i=0;
	for(NODE p=l->pHead;p!=NULL;p=p->pNext)
	{
       ++i;
	   if(i==vitrixoa)
	   {
	   	if(p->pNext==NULL)
	   	xoacuoi(l);
	   	else{
	   p->pRev->pNext=p->pNext;
	   p->pNext->pRev=p->pRev;	
	   }
    }
	}
}
 int main()
 {
 	LIST l;
 	themptu(&l);
 	output(&l);
 	NODE temp=createNode(9);
    xoa(&l,3);
  	output(&l);

 	return 0;
 	}
 	
