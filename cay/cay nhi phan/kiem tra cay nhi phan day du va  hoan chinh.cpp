#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<vector>
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
void demsoNODEtrentangthuK(NODE head,int K,int level,int *dem)
{
	if(head==NULL)
	return;
	++level;
	if(level==K)
	++(*dem);
	demsoNODEtrentangthuK(head->left,K,level,dem);
	demsoNODEtrentangthuK(head->right,K,level,dem);
}
void chocacNODEtrentangthuKvaotrongvector(NODE head,int K,int level,vector<NODE>&a)
{
	if(head==NULL)
	return;
	++level;
	if(level==K)
	a.push_back(head);
	chocacNODEtrentangthuKvaotrongvector(head->left,K,level,a);
	chocacNODEtrentangthuKvaotrongvector(head->right,K,level,a);

	
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
bool kiemtracaydaydu(NODE head)
{
	int K=1;
	int levelmax=0;
	docaocuacay(head,0,&levelmax);
	while(K<=levelmax)
	{
		int dem=0;
		demsoNODEtrentangthuK(head,K,0,&dem);
		if(dem!=pow(2,K-1))
		return false;
		++K;
	}
	return true;
}
bool kiemtracayhoanchinh(NODE head)
{
	int K=1;
	int levelmax=0;
	docaocuacay(head,0,&levelmax);
	vector<NODE>a,b;
	while(K<levelmax)
	{
		int dem=0;
		demsoNODEtrentangthuK(head,K,0,&dem);
		if(dem!=pow(2,K-1))
		return false;
		++K;
		if(K==levelmax-1)
			chocacNODEtrentangthuKvaotrongvector(head,K,0,a);
		if(K==levelmax)
			chocacNODEtrentangthuKvaotrongvector(head,K,0,b);
	}
	for(int i=0;i<b.size();i++)
	{
		if(i%2==0)
		{
		if(a[i/2]->left==NULL)
		return false;
		if(b[i]->data!=a[i/2]->left->data)
		return false;
		}
		if(i%2!=0)
		{
		if(a[i/2]->right==NULL)
		return false;
		if(b[i]->data!=a[i/2]->right->data)
		return false;
		}
	}
	return true;
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
    int dem=0;
    if(kiemtracaydaydu(A)==true)
    printf("Cay day du\n");
    else printf("Cay khong day du\n");
    if(kiemtracayhoanchinh(A)==true)
    printf("Cay hoan chinh");
    else printf("Cay khong hoan chinh");
	return 0;
}
