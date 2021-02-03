#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct BiTNode   //���������
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
typedef struct BiTNodePost
{
	ElemType tag;
	BiTree bitree;
} BiTNodePost, * BiTreePost; void CreateBiTreeByPreOrder(BiTree* T)  //�������д�����  
{
	ElemType data;
	scanf_s("%c", &data);
	if (data == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = data;
		CreateBiTreeByPreOrder(&(*T)->lchild);//����������     
		CreateBiTreeByPreOrder(&(*T)->rchild);//����������
	}
}
void PostOrder(BiTree node)      //�������(�ݹ�)
{
	if (node != NULL)
	{
		PostOrder(node->lchild);
		PostOrder(node->rchild);
		printf("%c", node->data);
	}
}
void PostOrder2(BiTree T)                                        
{
	BiTreePost* stack = (BiTreePost*)malloc(sizeof(BiTreePost)); 
	BiTree p = T;                                                
	BiTreePost BT = (BiTreePost)malloc(sizeof(BiTreePost));
	int sp = 0;
	while (p || sp)                                            
	{
		while (p)                                                
		{
			BT->bitree = p;
			BT->tag = 'L';
			stack[sp] = BT;
			sp++;
			p = p->rchild;
		}
		while (sp)                                             
		{
			BT = stack[sp - 1];
			BT->tag = 'R';
			p = BT->bitree;
			p = p->rchild;
		}
		if (sp && stack[sp - 1]->tag == 'R')                       
		{
			sp--;
			BT = stack[sp];
			printf("%c", BT->bitree->data);
			free(BT);
		}
	}
	free(stack);
}

int main()
{
	BiTree ptree = NULL;
	CreateBiTreeByPreOrder(&ptree);
	printf("����������ݹ飩��      "); PostOrder(ptree);  printf("\n");
	printf("����������ǵݹ飩��    "); PostOrder2(ptree); printf("\n");
	return 0;
}
