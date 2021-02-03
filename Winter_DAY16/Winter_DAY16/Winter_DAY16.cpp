#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct BiTNode   //二叉树结点
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
typedef struct BiTNodePost
{
	ElemType tag;
	BiTree bitree;
} BiTNodePost, * BiTreePost; void CreateBiTreeByPreOrder(BiTree* T)  //先序序列创建树  
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
		CreateBiTreeByPreOrder(&(*T)->lchild);//构造左子树     
		CreateBiTreeByPreOrder(&(*T)->rchild);//构造右子树
	}
}
void PostOrder(BiTree node)      //后序遍历(递归)
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
	printf("后序遍历（递归）：      "); PostOrder(ptree);  printf("\n");
	printf("后序遍历（非递归）：    "); PostOrder2(ptree); printf("\n");
	return 0;
}
