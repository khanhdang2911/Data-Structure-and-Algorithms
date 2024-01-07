#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//khai bao node
struct Node
{
     int data;
     struct Node*pNext;
};
typedef struct Node *NODE;
struct list
{ 
   NODE pHead;
   NODE pTail;
};
typedef struct list LIST;
void khoitaoNODE(LIST&l)
{
	l.pHead=l.pTail=NULL;
}
// tao node
NODE CreateNode(int x)
{ 
    NODE temp=(NODE)malloc(sizeof(struct Node));
    temp->pNext=NULL;
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
 		l.pTail=temp;
 	}
 	return l.pTail;
    
}
void themphantu(LIST &l)
{
    khoitaoNODE(l);
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
            p->pNext=x;
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
          temp->pNext=p->pNext;
          p->pNext=temp;
          p=p->pNext;
       }
     }
	 if(l.pTail->data%2==0)
	 {
	 	AddTail(l,phantucanthem);
	   }    
}
void themdangtruoc(LIST&l,NODE x,NODE q)
{//them node x truoc node q    
 
   NODE temp;
   for(NODE p=l.pHead->pNext;p!=NULL;p=p->pNext)
   {
     if(p->data==q->data)
   {
        x->pNext=temp->pNext;
        temp->pNext=x;
        return;
   }
    temp=p; 
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
     free(p);
     return;
}
void xoacuoidanhsach(LIST&l)
{
     NODE temp=l.pTail;
     NODE g;
     for(NODE p=l.pHead;p!=NULL;p=p->pNext)
     {
          if(p->data==l.pTail->data)
          {
            g->pNext=NULL;
            l.pTail=g;
            free(temp);
            return;
          }
           g=p;
     }
}
void Xoa1NutBatKi(LIST&l,NODE q)
{
     if(q->data==l.pHead->data)
     {
          xoadaudanhsach(l);
     }
     if(q->data==l.pTail->data)
     {
          xoacuoidanhsach(l);
     }
     NODE temp;
     for(NODE p=l.pHead;p!=NULL;p=p->pNext)
     {
       if(p->data==q->data)
       {
         temp->pNext=q->pNext;
         free(q);
         return;
       }
       temp=p;
     }
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
          NODE g=p;
          truoc->pNext=p->pNext;
          free(g);
           p=truoc;
       }
       truoc=p;
    }
}
int main()
{   

    LIST l;
    themphantu(l);
    xuatphantu(l);
    /*int tong=Tinhtong(l);
    printf("\nTong cac phan tu trong danh sach lien ket la:%d",tong);
    printf("\nSau khi sap xep tang dan:");
    sortLINKED(l);
    xuatphantu(l);*/
    /*NODE x,q;
    x=CreateNode(69);
    q=CreateNode(2);*/
    /*printf("\nsau khi them phan tu:\n");
    themNodeDangSau(l,x,q);
    xuatphantu(l);
    printf("\n");
    themsobatkivaosausochan(l,10);
    xuatphantu(l);*/
    /*printf("\n");
    themdangtruoc(l,x,q);
    xuatphantu(l);*/
    /*xoadaudanhsach(l);
    printf("\n");
    xuatphantu(l);*/
    /*printf("\n");
    NODE q=CreateNode(5);
    Xoa1NutBatKi(l,q);
    xuatphantu(l);*/
    /*printf("\n");
    xoacuoidanhsach(l);
    xuatphantu(l);*/
    /*NODE x,q;
    x=CreateNode(69);
    q=CreateNode(2);
   themNodeDangSau(l,x,q);
   xuatphantu(l);*/
   themsobatkivaosausochan(l,100);
   xuatphantu(l);
    
    return 0;
  
}
