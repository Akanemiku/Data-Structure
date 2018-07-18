/* 两顺序栈共享一个地址连续的存储单元,一个栈的栈底为起始位置
 * 一个栈的栈底为末尾,压入数据时从两边向中间推进,如果指示栈
 * 顶的指针top1 + 1 等于另一个栈顶的指针top2时两栈已满,
 * 如果top1 == -1,top2 == MAXSIZE两栈为空                    
 */
#include <stdio.h>
#define INFINITY 65535  //β值表标无限大
#define MAXSIZE 1000  //存储单元的最大值
typedef int ElemType; //栈的数据类型
typedef struct {
    ElemType data[MAXSIZE];  //存储单元
    int top1;
    int top2;
}DoubleStack;

void InitStack(DoubleStack *s); //初始化两个栈

void Push(DoubleStack *s,int i,ElemType e); //将数据e压栈,参数i为栈的序号1或2

ElemType Top(DoubleStack *s,int i); //参数i为栈的序号,返回栈顶的元素

ElemType Pop(DoubleStack *s,int i); //参数i为栈的序号,返回并删除栈顶的元素

bool IsEmpty(DoubleStack *s);  //判断栈是否为空

void Clear(DoubleStack *s);     //清空两栈

void Print(DoubleStack *s,int i); //打印栈底到栈顶的数据,i为栈的序号

//**********************************************************************

void InitStack(DoubleStack *s)  //初始化两栈
{
    s->top1 = -1;
    s->top2 = MAXSIZE;
}
void Push(DoubleStack *s,int i,ElemType e) //将数据元素e压栈,i为栈的序号
{
    if(i == 1)
    {
        if(s->top1 + 1 == s->top2)
            return;
        s->data[++s->top1] = e;
    }
    else if(i == 2)
    {
        if(s->top2 - 1 == s->top1)
            return;
        s->data[--s->top2] = e;
    }
}

ElemType Top(DoubleStack *s,int i) //i为栈的序号,返回栈顶的元素
{
    if(i == 1)
    {
        if(s->top1 == -1)
            return INFINITY;
        return s->data[s->top1];
    }
    else if(i == 2)
    {
        if(s->top2 == MAXSIZE)
            return INFINITY;
        return s->data[s->top2];
    }
}

ElemType Pop(DoubleStack *s,int i) //i为栈的序号,返回并删除栈顶的元素
{
    if(i == 1)
    {
        if(s->top1 == -1)
            return INFINITY;
        return s->data[s->top1--];
    }
    else if(i == 2)
    {
        if(s->top2 == MAXSIZE)
            return INFINITY;
        return s->data[s->top2++];
    }
}

bool IsEmpty(DoubleStack *s) //判断栈是否为空
{
    if(s->top1 == -1 && s->top2 == MAXSIZE)
        return true;
    return false;
}

void Clear(DoubleStack *s) //清空栈
{
    s->top1 = -1;
    s->top2 = MAXSIZE;
}
void Print(DoubleStack *s,int i) //打印栈底到栈顶的元素,i为栈的序列
{
    if(i == 1)
    {
        for(int j = 0;j <= s->top1;++j)
            printf("%d ",s->data[j]);
        printf("\n");
    }
    else if(i == 2)
    {
        for(int j = MAXSIZE - 1;j >= s->top2;--j)
            printf("%d ",s->data[j]);
        printf("\n");
    }
}
//**********************************************************************
int main()
{
    DoubleStack s;
    InitStack(&s);
    int k,i;
    printf("请输入要压入的栈的序号(1或2)及元素:\n");
    while((scanf("%d%d",&i,&k)) != EOF)
    {
        Push(&s,i,k);
        fflush(stdin);
    }
    Print(&s,1);
    Print(&s,2);
    int top1 = Top(&s,1);
    printf("第一个栈顶的元素:%d\n",top1);
    int top2 = Top(&s,2);
    printf("第二个栈顶的元素:%d\n",top2);
    return 0;
}
