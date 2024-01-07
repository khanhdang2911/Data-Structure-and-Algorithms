#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
struct hocsinh
{
  char maso[10];
  char ten[30];
  double diem;
  char lop[10];	
};
typedef hocsinh HOCSINH;
//khai bao node
struct Node
{
     HOCSINH data;
     struct Node*pNext;
};
typedef struct Node *NODE;
struct list
{ 
   NODE pHead;
   NODE pTail;
};
typedef struct list LIST;
//Khoi tao node
NODE CreateNode(HOCSINH x)
{ 
    NODE temp=(NODE)malloc(sizeof(struct Node));
    temp->pNext=NULL;
    temp->data=x;
    return temp;   
}
//Them vao dau
NODE AddHead(LIST&l,HOCSINH x)
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
NODE AddTail(LIST&l,HOCSINH x)
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
void nhaphocsinh(HOCSINH &x)
{
	    printf("\nnhap ma so sv:");
	    fflush(stdin);
        scanf("%s",&x.maso);
        printf("nhap ten sinh vien:");
        fflush(stdin);
		scanf("%s",&x.ten);
        printf("nhap lop:");
        fflush(stdin);
        scanf("%s",&x.lop);
        printf("nhap diem sinh vien:");
        fflush(stdin);
		scanf("%lf",&x.diem);
		printf("\n-------------\n");
}
void xuathocsinh(HOCSINH x)
{
	printf("\nMa so sinh vien :%s",x.maso);
      printf("\nLop cua sinh vien :%s",x.lop);
      printf("\nHo ten sinh vien la :%s",x.ten);
      printf("\nDiem so sinh vien la %lf:",x.diem);
      printf("\n---------------\n");
}
void themphantu(LIST &l)
{

	for(int i=1;i<=4;i++)
	{
		HOCSINH x;
		printf("Nhap thong tin cua hoc sinh:\n");
		nhaphocsinh(x);
        CreateNode(x);
		NODE temp=AddTail(l,x);
	}
}
void xuatphantu(LIST l)
{
	int dem=1;
	for(NODE p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("\nThong tin hoc sinh thu %d la:",dem++);
      xuathocsinh(p->data);
	 }
}
void hoanvi(HOCSINH*a,HOCSINH*b)
{
	HOCSINH temp=*a;
	*a=*b;
	*b=temp;
	
}
void xeptheodiemso(LIST &l)
{
    for(NODE p=l.pHead;p!=l.pTail;p=p->pNext)
    {
        for(NODE q=p->pNext;q!=NULL;q=q->pNext)
        {
            if((p->data).diem >(q->data).diem)
            {
             hoanvi(&p->data,&q->data);
            }
        }
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
          if((p->data).diem==(l.pTail->data).diem)
          {
            g->pNext=NULL;
            l.pTail=g;
            free(temp);
            return;
          }
           g=p;
     }
}
void xoahocsinhduoi5diem(LIST &l)
{
	
	NODE temp=l.pHead;
	for(NODE p=l.pHead->pNext;p!=l.pTail;p=p->pNext)
	{
		if((p->data).diem<5.0)
		{
			temp->pNext=p->pNext;
			p=temp;
		}
	   temp=p;
		
	}
	if((l.pHead->data).diem<5.0)
	{
		xoadaudanhsach(l);
	}
	if((l.pTail->data).diem<5.0)
	{
		xoacuoidanhsach(l);
	}
}
                                                                 



int main()
{   

    LIST l;
    themphantu(l);
    //xuatphantu(l);
    xeptheodiemso(l);
    //xuatphantu(l);
    xoahocsinhduoi5diem(l);
    xuatphantu(l);
    return 0;
  
}
