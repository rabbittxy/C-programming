#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct _node* pnode;
typedef struct _node {
	ElementType Data;
	pnode Next;
} node;
typedef struct _stack {
	pnode Top;
	int len;
	int maxsize;
	int max;
} Stack;

Stack Stackmake(int M);
int push(Stack* pstack, ElementType Data);
			//成功压栈（没满）返回1，否则返回0
int pop(Stack* pstack, ElementType* p);
			//成功出栈（非空）返回1，否则返回0
int PushN(Stack* pstack, int N);
			//将数组入栈，整个数组入栈返回1，否则返回0

int main(void)
{
	//M是堆栈的最大容量，N是一组数据的个数，K是数据的行数
	int M, N, K;
	scanf_s("%d %d %d", &M, &N, &K);
	Stack stack = Stackmake(M);
	int i = 0, n = 0, k = 0;		//三个计数器
	int* Judge = (int*)malloc(K * sizeof(int));
	for (n = 0;n < K; n++) {
		Judge[n] = 1;		//判断顺序是否正确
		ElementType* p = (ElementType*)malloc(N * sizeof(ElementType));
		for (i = 0;i < N;i++) {
			scanf_s("%d", &p[i]);
		}
		int Thisitem = 0;//将要处理的数据
		int Max = 0;//前面输入的最大值

		for (i = 0;i < N;i++) {//i是现在的列号
			Thisitem = p[i];
			int NumToPush = 0;
			//???==max-1
			if (Max) {
				int Found = 1;
				for (stack.max = Max - 1;Found;) {
					Found = 0;
					for (k = 0;k <= i - 1;k++) {
						if (p[k] == stack.max) {
							stack.max--;
							Found = 1;
						}
					}
				}
			}

			if (Thisitem > Max) {
				NumToPush = Thisitem - Max;
				Max = Thisitem;
			}
			else if (Thisitem == Max) {
				Judge[n] = 0;
			}
			else {
				if (p[i] != stack.max) {
					Judge[n] = 0;
				}
			}
			int a = PushN(&stack, NumToPush);
			if (!a) {
				Judge[n] = 0;
			}
			int z = 0;
			pop(&stack, &z);
			
		}
		free(p);
	}

	for (n = 0;n < K;n++) {
		if (Judge[n]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}

Stack Stackmake(int M)
{
	Stack stack;
	stack.len = 0;
	stack.maxsize = M;
	stack.Top = NULL;
	stack.max = 0;
	return stack;
}

int push(Stack* pstack, ElementType Data)
{
	if (pstack->len == pstack->maxsize) {
		return 0;
	}
	else {
		pnode newnode = (pnode)malloc(sizeof(node));
		newnode->Data = Data;
		newnode->Next = pstack->Top;
		pstack->Top = newnode;
		pstack->len += 1;
		return 1;
	}
}
int pop(Stack* pstack, ElementType* p)
{
	if (pstack->len == 0) {
		p = NULL;
		return 0;
	}
	else {
		*p = pstack->Top->Data;
		pstack->len--;
		pnode Tobefree = pstack->Top;
		pstack->Top = pstack->Top->Next;
		free(Tobefree);
		return 1;
	}
}

int PushN(Stack* pstack, int N)
{
	int i = 0;
	int ret = 1;
	for (i = 0;i < N;i++) {
		int a = push(pstack, 0);
		if (!a) {
			ret = 0;
			return ret;
		}
	}
	return ret;
}