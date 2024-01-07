#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//khai bao node
struct Node
{
     int data;
     struct Node*pNext;
     struct Node*pRev;
};
typedef struct Node *NODE;
struct list
{ 
   NODE pHead;
   NODE pTail;
};
typedef struct list LIST;
//Khoi tao node
NODE CreateNode(int x)
{ 
    NODE temp=(NODE)malloc(sizeof(struct Node));
    temp->pNext=NULL;
    temp->pRev=NULL;
    temp->data=x;
    return temp;   
}
//Them vao dau
NODE AddHead(LIST&l,int x)
{
 NODE temp=CreateNode(x);
 if(l.pHead==NULL)
 	{
 		l.pHead=l.pTail=temp;
 	}
 	else{
 		temp->pNext=l.pHead;
 		l.pHead->pRev=temp;
 		l.pHead=temp;
 	}
 	return l.pHead;
}
//Them vao cuoi
NODE AddTail(LIST&l,int x)
{
	NODE temp=CreateNode(x);
	if(l.pHead==NULL)
 	{
 		l.pHead=l.pTail=temp;
 	}
 	else
 	{
 		l.pTail->pNext=temp;
 		temp->pRev=l.pTail;
 		l.pTail=temp;
 	}
 	return l.pTail;
    
}
void themphantu(LIST &l)
{

	for(int i=1;i<=5;i++)
	{
		int x;
		printf("nhap vao data:");
		fflush(stdin);
        scanf("%d",&x);
		NODE temp=AddTail(l,x);
	}
}
void xuatphantu(LIST l)
{
	for(NODE p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%4d",p->data);
	}
}
void xuatphantucach2(LIST l)
{
		for(NODE p=l.pTail;p!=NULL;p=p->pRev)
	{
		printf("%4d",p->data);
	}
}
int Tinhtong(LIST l)
{
   int tong=0;
   NODE p=l.pHead;
   while(p!=NULL)
   {  
    tong+=p->data;
    p=p->pNext;
   }
   return tong;

}
void SWAP(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sortLINKED(LIST &l)
{
    for(NODE p=l.pHead;p!=l.pTail;p=p->pNext)
    {
        for(NODE q=p->pNext;q!=NULL;q=q->pNext)
        {
            if(p->data>q->data)
            {
             SWAP(&p->data,&q->data);
            }
        }
    }
}
void themNodeDangSau(LIST&l,NODE x,NODE q)
{ 
    //them node x sau node q
    for(NODE p=l.pHead;p!=l.pTail;p=p->pNext)
    {
        if(p->data==q->data)
        {
            NODE g=p->pNext;
            x->pNext=g;
            g->pRev=x;
            p->pNext=x;
            x->pRev=p;
            return;
        }
    }
     if(l.pTail->data==q->data)
    {
    	AddTail(l,x->data);
    	return;
	}
}
void themsobatkivaosausochan(LIST &l,int phantucanthem)
{
    
     for(NODE p=l.pHead;p!=l.pTail;p=p->pNext)
     {
       if(p->data%2==0)
       {
        NODE temp=CreateNode(phantucanthem); 
        NODE g=p->pNext;
        temp->pNext=g;
        g->pRev=temp;
        p->pNext=temp;
        temp->pRev=p;
          p=p->pNext;
       }
     }
	 if(l.pTail->data%2==0)
	 {
	 	AddTail(l,phantucanthem);
	   }  
}
void themdangtruoc(LIST&l,NODE x,NODE q)
{
   //them node x truoc node q    
   NODE temp;
  
   for(NODE p=l.pHead->pNext;p!=NULL;p=p->pNext)
   {
     if(p->data==q->data)
   {
   	    temp=p->pRev;
   	    NODE g=temp->pNext;
        x->pNext=g;
        g->pRev=x;
        temp->pNext=x;
        x->pRev=temp;
        return;
   }
   }
    if(q->data==l.pHead->data)
   {
   	AddHead(l,x->data);
   }  
    
}
void xoadaudanhsach(LIST&l)
{
    
     NODE p=l.pHead;
     l.pHead=l.pHead->pNext;
     if(l.pHead==NULL)
     {
	 l.pHead->pRev=NULL;
	 l.pTail=NULL;
	 }
	 free(p);
     return;
}
void xoacuoidanhsach(LIST&l)
{
	if(l.pHead->pNext==NULL)
	{
		xoadaudanhsach(l);
		return;
	}
	NODE temp=l.pTail;
    l.pTail=l.pTail->pRev;
    l.pTail->pNext=NULL;
    free(temp);
}
void xoatatcasochan(LIST&l)
{
     if(l.pHead->data%2==0)
     {
          xoadaudanhsach(l);
     }
     if(l.pTail->data%2==0)
     {
          xoacuoidanhsach(l);
     }
    NODE truoc;
    for (NODE p=l.pHead;p!=NULL;p=p->pNext)
    {
       if(p->data%2==0)
       {
       	  truoc=p->pRev;
          truoc->pNext=p->pNext;
          (p->pNext)->pRev=truoc;
           p=truoc;
       }
       
    }
}
int main()
{   

    LIST l;
    themphantu(l);
    //xuatphantucach2(l);
    NODE x,q;
    q=CreateNode(2);
    x=CreateNode(69);
    /*
    themNodeDangSau(l,x,q);
    xuatphantucach2(l);*/
    /*themsobatkivaosausochan(l,100);
    xuatphantucach2(l);*/

	//xoadaudanhsach(l);
	/*xoacuoidanhsach(l);
	xuatphantu(l); 
	printf("\n");
	xuatphantucach2(l);*/
	xoatatcasochan(l);
	xuatphantucach2(l);
    return 0;
  
}
