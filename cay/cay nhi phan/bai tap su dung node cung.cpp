#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
using namespace std;

struct Node
{
	char data;
	struct Node *left,*right;
};
typedef struct Node *NODE;
struct Tree
{
	NODE Root;
};
typedef struct Tree TREE; 
void Init(TREE*t)
{
	t->Root=NULL;
}
NODE CreateNODE(char x)
{
	NODE p=(NODE)malloc(sizeof(struct Node));
	p->data=x;
	p->left=p->right=NULL;
	return p;
}
int docaocua1cay(NODE Root)
{
	int dem=0;
	int max=0;
	queue<NODE>q;
	q.push(Root);
	++dem;
	while(q.front()!=NULL)
	{
	  if(sqrt(dem)>max)
	  max=sqrt(dem);
	  if(q.front()->left!=NULL)
      q.push(q.front()->left);
      if(q.front()->left!=NULL||q.front()->right!=NULL)
      ++dem;
	  if(q.front()->right!=NULL)
	  q.push(q.front()->right);
	  if(q.front()->left!=NULL||q.front()->right!=NULL)
	  ++dem;
	  q.pop();
	}
	return max+1;
}
void docaocuacay(NODE Root,int level,int*levelmax)
{
	if(Root==NULL)
	return;
	++level;
	if(level>(*levelmax))
	*levelmax=level;
	docaocuacay(Root->left,level,levelmax);
	docaocuacay(Root->right,level,levelmax);	
}
void kiemtranodecotontai(NODE Root,NODE x,int check,int level,int *levelmax)
{
	if(Root==NULL)
	return;
	if(Root->data==x->data){
	printf("\nCo ton tai node x");
	check=1;
    }
    if(check==1){
    level++;
    if(level>*levelmax)
    *levelmax=level;
	}
	kiemtranodecotontai(Root->left,x,check,level,levelmax);
	kiemtranodecotontai(Root->right,x,check,level,levelmax);
}
void xuatcacnuttrentangthukcuacay(int K,NODE Root,int level)
{
	if(Root==NULL)
	return;
	level++;
	if(level==K)
    printf("%3c",Root->data);
	xuatcacnuttrentangthukcuacay(K,Root->left,level);
	xuatcacnuttrentangthukcuacay(K,Root->right,level);

}
int main()
{
	TREE t;
	NODE A =CreateNODE('A');
	NODE B =CreateNODE('B');
	NODE C =CreateNODE('C');
	NODE D =CreateNODE('D');
	NODE E =CreateNODE('E');
	NODE F =CreateNODE('F');
	NODE G =CreateNODE('G');
	NODE H =CreateNODE('H');
	NODE I =CreateNODE('I');
	NODE K =CreateNODE('K');
	NODE L =CreateNODE('L');
	NODE J =CreateNODE('J');
    A->left=B;
    A->right=C;
    B->left=D;
    B->right=E;
    C->left=F;
    C->right=G;
    D->left=H;
    D->right=I;
    E->right=J;
    F->left=K;
    G->right=L;
    int levelmax=0;
    printf("\nDo cao cua cay la:%d",docaocua1cay(A));
    docaocuacay(A,0,&levelmax);
    printf("\nDo cao cua cay cach 2 la:%d",levelmax);
    NODE x=CreateNODE('B');
	int levelmaxofnode=0;
    kiemtranodecotontai(A,x,0,0,&levelmaxofnode);
    printf("\nDo cao cua node can tim la:%d",levelmaxofnode);
    printf("\nNhap tang k cua cay de xuat cac node tren do:");
    int p;scanf("%d",&p);
    printf("\nCac node tren tang thu %d cua cay la: ",p);
    xuatcacnuttrentangthukcuacay(p,A,0);
}
