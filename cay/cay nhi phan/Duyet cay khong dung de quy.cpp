#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node
{
	char data;
	struct Node *left,*right;
	struct Node *prev;
	int tinhtrangduyet;
	int solanduyet;
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
	p->prev=NULL;
	p->tinhtrangduyet=1;
	p->solanduyet=0;
	return p;
}
/*void leftnoderight(NODE Root)
{
    if(Root == NULL) return;
    NODE temp = Root;
    while(temp != NULL)
    {
        if(temp->left == NULL)
        {
            printf("%3c",temp->data);
            temp = temp->right;
        }
        else
        {
            NODE pre = temp->left;
            while(pre->right != NULL && pre->right != temp)
                pre = pre->right;
            if(pre->right == NULL)
            {
                pre->right = temp;
                temp = temp->left;
            }
            else
            {
                pre->right = NULL;
                printf("%3c",temp->data);
                temp = temp->right;
            }
        }
    }
}
*/
void leftnoderight(NODE Root)
{
	NODE t=Root;
	NODE k;
	while(t->right!=NULL)
	t=t->right;
	
	
	while(1)
	{
		
		k=Root;
		if(k==t){
		printf("%3c",k->data);
		break;
		}
		while(k->left!=NULL)
		{
			if(k->left->tinhtrangduyet==1)
			{
			k->left->prev=k;
			if(k->right!=NULL)
			k->right->prev=k;
			k=k->left;
			}
			else break;
		}
		if(k->left!=NULL)
		{
			if(k->left->tinhtrangduyet==1)
			{
			printf("%3c",k->left->data);
			k->left->tinhtrangduyet=0;
			
			}
		}
		if(k->tinhtrangduyet==1)
			{
			printf("%3c",k->data);
			k->tinhtrangduyet=0;
			}
	
		if(k->right!=NULL)
		{
			if(k->right->tinhtrangduyet==1)
			{
			Root=k->right;
			}	
		}
		else
		{
			Root=k->prev;
			while(Root->tinhtrangduyet!=1)
			Root=Root->prev;			
		}
		
	}
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
    B->prev=A;
    
    A->right=C;
    C->prev=A;
    
    B->left=D;
    D->prev=B;
    
    B->right=E;
    E->prev=B;
    
    C->left=F;
    F->prev=C;
    
    C->right=G;
    G->prev=C;
    
    D->left=H;
    H->prev=D;
    
    D->right=I;
    I->prev=D;
    
    E->right=J;
    J->prev=E;
    
    F->left=K;
    K->prev=F;
    
    G->right=L;
    L->prev=G;
    leftnoderight(A);
   	return 0;
}
