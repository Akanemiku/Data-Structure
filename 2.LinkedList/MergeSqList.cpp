#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10	// 顺序表可能达到的最大长度 
typedef int ElemType;	// 元素数据类型 
typedef  struct {
	ElemType  *elem;     //指向数据元素的基地址
	int      length;     // 当前长度
} SqList;  // 顺序表

void createSqList(SqList &list, int n); // 根据用户输入，创建n个整数顺序表 
void printSqList(SqList list);			// 打印顺序表	
void mergeSqList(SqList &la, SqList lb);// 实现 A=AUB 

int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		SqList la, lb, lc;
		createSqList(la, a);
		createSqList(lb, b);
		mergeSqList(la, lb);
		printf("la: ");
		printSqList(la);
		printf("lb: ");
		printSqList(lb);
	}
}
void createSqList(SqList &list, int n) // 根据用户输入，创建n个整数顺序表 
{
	list.elem = new ElemType[MAXSIZE];
	list.length = 0;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&list.elem[i]);
		list.length++;
	}
}
void printSqList(SqList list)			// 打印顺序表
{
	int i;
	for(i=0;i<list.length;i++)
		printf("%d ",list.elem[i]);
	puts("");
}	
void mergeSqList(SqList &la, SqList lb)// 实现 A=AUB 
{
	int m,n,i,j,e,flag=0;
	m = la.length;
	n = lb.length;
	for(i=1;i<=n;i++)
	{
		e = lb.elem[i-1];
		for(j=0;j<la.length;j++)
		{
			if(la.elem[j] == e)
				flag = 1;
		}
		if(flag == 0)
		{
			la.elem[m++] = e;
			la.length++;
		}
		flag = 0;
	}
}