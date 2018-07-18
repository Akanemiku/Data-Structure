# SqStack
typedef struct{
	SElemType   *base;	//栈底
	SElemType   *top;	//栈顶
}SqStack;

# LinkStack
typedef struct LNode{
	SElemType data;
	struct LNode *next;
}StackNode, *LinkStack;