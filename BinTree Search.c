#include<stdio.h>
#include<stdlib.h>
#define ElementType int

typedef struct _bintree* BinTree;
struct _bintree{
	ElementType value;
	BinTree Left;
	BinTree Right;
	BinTree lFather;
	BinTree rFather;
};

BinTree TreeMake(void);
void Insert(BinTree BST,ElementType x);
BinTree Find(BinTree BST,ElementType x);
BinTree FindMax(BinTree BST);
BinTree FindMin(BinTree BST);
BinTree Delete(BinTree BST,ElementType x);
void DeleteAll(BinTree BST);
void PrintAll(BinTree BST);

int main(void)
{
	BinTree BST=TreeMake();
	printf("请输入一个整数作为第一个数据的值：");
	scanf("%d",&BST->value );
	while(1){
		int i=0;
		int TypeOfOperation=0;
		printf("插入数据请输入1，查找请输入2，删除请输入3，查询全体请输入4，删除全体请输入5\n");
		scanf("%d",&TypeOfOperation);
		int NumberOfInsert=0;
		int NumberOfDelete=0;
		int NumberOfInquire=0;
		switch (TypeOfOperation){
			case 1:
				printf("请输入要插入的数据的个数：\n");
				if(scanf("%d",&NumberOfInsert)){
					printf("请输入%d个数据\n",NumberOfInsert);
					for(i=0;i<NumberOfInsert;i++){
						ElementType thisinsert=0;
						if(scanf("%d",&thisinsert)){
							Insert(BST,thisinsert);
						}else{
							printf("输入的数据格式错误\n");
							break;
						}
					}
					printf("插入结束\n\n");
				}
				break;
			case 2:
				printf("请输入要查询的数据的个数：\n");
				if(scanf("%d",&NumberOfInquire)){
					printf("请输入%d个要查找的数据\n",NumberOfInquire);
					for(i=0;i<NumberOfInquire;i++){
						ElementType X=0;
						if(scanf("%d",&X)){
							if(Find(BST,X)){
								BinTree address=Find(BST,X);
								printf("%d的地址为%p\n",X,address);
							}else{
								printf("%d没找到\n",X);
							}
						}else{
							printf("要查找的数据格式错误\n");
						}
					}
					printf("查找结束\n\n");
				}
				break;
			case 3:
				printf("请输入要删除的数据的个数：\n");
				if(scanf("%d",&NumberOfDelete)){
					printf("请输入%d个数据\n",NumberOfDelete);
					for(i=0;i<NumberOfDelete;i++){
						ElementType thisdelete=0;
						if(scanf("%d",&thisdelete)){
							BST=Delete(BST,thisdelete);
						}else{
							printf("输入的数据格式错误\n");
							break;
						}
					}
					printf("删除结束\n\n");
					if(!BST){
						BST=TreeMake();
					}
				}
				break;
			case 4:
				PrintAll(BST);
				printf("\n");
				break;
			case 5:
				DeleteAll(BST);
				printf("全部删除成功\n\n");
				return 0;
		}
	} 
	
	return 0;
}

BinTree TreeMake(void)
{
	BinTree ret=(BinTree)malloc(sizeof(struct _bintree));
	ret->Left =NULL;
	ret->Right =NULL;
	ret->lFather =NULL;
	ret->rFather =NULL;
	ret->value=0;
	return ret;
}

void Insert(BinTree BST,ElementType x)
{
	BinTree p=BST;
	while(1){
		if(x==p->value ){
			printf("这个数据已经存入\n");
			return;
		}else if(x> p->value ){
			if(p->Right ){
				p=p->Right ;
			} else {
				BinTree newtree=TreeMake();
				newtree->lFather =p;
				p->Right =newtree;
				newtree->value =x;
				return;
			}
		}else{
			if(p->Left  ){
				p=p->Left ;
			} else {
				BinTree newtree=TreeMake();
				newtree->rFather =p;
				p->Left =newtree;
				newtree->value =x;
				return;
			}
		}
	}
}

BinTree Find(BinTree BST,ElementType x)
{
	BinTree p=BST;
	if(p){
		while(1){
			if(x==p->value ){
				return p;
			}else if(x> p->value ){
				if(p->Right ){
					p=p->Right ;
				} else {
					return NULL;
				}
			}else{
				if(p->Left  ){
					p=p->Left ;
				} else {
					return NULL;
				}
			}
		}
	}else{
		printf("树是空的\n");
		return NULL;
	}
}

BinTree FindMax(BinTree BST)
{
	while(BST->Right ){
		BST=BST->Right ;
	}
	return BST;
}

BinTree FindMin(BinTree BST)
{
	while(BST->Left  ){
		BST=BST->Left ;
	}
	return BST;
}

BinTree Delete(BinTree BST,ElementType x)
{
	BinTree Tmp=NULL;
	if(Find(BST,x)){
		BinTree p=Find(BST,x);
		if(p->Left &&p->Right ){
			Tmp=FindMin(p->Right );
			p->value =Tmp->value ;
			p->Right =Delete(p->Right ,p->value );
		}else{
			Tmp=p;
			if(!p->Left ){
				p=p->Right ;
				if(p){
					p->lFather =NULL;
				}
				if(Tmp->lFather ){
					(Tmp->lFather )->Right=p;
				}else if(Tmp->rFather ){
					(Tmp->rFather )->Left=p;
				}else{
					BST=p; 
				} 
			}else if(!p->Right ){
				p=p->Left ;
				if(p){
					p->rFather =NULL;
				}
				if(Tmp->lFather ){
					(Tmp->lFather )->Right=p;
				}else if(Tmp->rFather ){
					(Tmp->rFather )->Left=p;
				}
			}
			free(Tmp);
		}
	}else{
		printf("没找到删除值\n");
	}
	return BST;
}

void DeleteAll(BinTree BST)
{
	BinTree t1=BST->Left ,t2=BST->Right ;
	if(t1){
		DeleteAll(t1);
	}
	if(t2){
		DeleteAll(t2);
	}
	Delete(BST,BST->value );
}

void PrintAll(BinTree BST)
{
	BinTree t1=BST->Left ,t2=BST->Right ;
	if(t1){
		PrintAll(t1);
	}
	if(t2){
		PrintAll(t2);
	}
	printf("%d ",BST->value);
}
