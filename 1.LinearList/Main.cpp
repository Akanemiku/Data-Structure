#include<stdio.h>
#include<stdlib.h> 

// 函数结果状态码 
typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE 1024	// 顺序表可能达到的最大长度 

typedef int ElemType;	// 元素数据类型 

typedef  struct {
	ElemType  *elem;     //指向数据元素的基地址
	int      length;     // 当前长度
} SqList;  // 顺序表

// 顺序表基本操作，序号i从1开始 
Status createList(SqList &L, int n);	// 根据用户输入，创建n个元素的表 
void traverseList(SqList L);	// 遍历，打印表中元素 
Status getElem(SqList L, int i, ElemType &e);	// 取值，将序号i的元素存入e 
int locateElem(SqList L, ElemType e);		// 查找，返回元素e的序号 
Status listInsert(SqList &L, int i, ElemType e);	// 插入 
Status listDelete(SqList &L, int i); 			// 删除 

void destroyList(SqList &L){
	free(L.elem);
	L.elem = NULL;
}

int main(){
	SqList list;
	int e, n, m;
	scanf("%d", &n); 
	createList(list, n);
	scanf("%d", &m);
	if(getElem(list,m,e) == OK){  //把 e 赋值为链表里的第 m 个数 
		printf("The value of e is %d\n",e);
	}else{
		printf("There is no m number in the list.\n");
	}
	scanf("%d", &e);
	if(locateElem(list,e)){
		printf("The index of %d is %d\n",e,locateElem(list,e));
	}else{
		printf("There is no number %d in the list.\n",e);
	}
	scanf("%d %d",&m,&e); // 插入元素 e 到第 m 个位置 
	if(listInsert(list,m,e) == OK){
		traverseList(list); 
	}else{
		printf("Insert Error\n");
	}
	scanf("%d",&m); // 删除第 m 个元素 
	if(listDelete(list,m) == OK){
		traverseList(list); 
	}else{
		printf("Delete Error\n");
	}
	
	destroyList(list);
}