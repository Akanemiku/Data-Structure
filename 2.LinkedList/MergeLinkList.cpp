#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;	// 元素数据类型 

typedef struct LNode{
     ElemType   data;       //数据域
     struct LNode  *next;   //指针域
}LNode,*LinkList;  

void createLinkList(LinkList &list, int n); // 创建n个整数链表，顺序与用户输入一致 
void printLinkList(LinkList list);			// 打印顺序表	
void mergeLinkList(LinkList &la, LinkList lb);// 实现 A=AUB 

int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		LinkList la, lb, lc;
		createLinkList(la, a);
		createLinkList(lb, b);
		mergeLinkList(la, lb);
		printf("la: ");
		printLinkList(la);
		printf("lb: ");
		printLinkList(lb);
	}
}
void createLinkList(LinkList &list, int n) // 创建n个整数链表，顺序与用户输入一致
{
    LinkList p,r;
	int i;
	list = new LNode;
	r = list;
	for(i=0;i<n;i++)
	{
		p = new LNode;
		scanf("%d",&p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
void printLinkList(LinkList list)			// 打印顺序表
{
    LNode *p = list->next;
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void mergeLinkList(LinkList &la, LinkList lb){
	LinkList a = la,b = lb;
	int x = 0;
	while(lb){
		x = 0;
		la = a;
		while(la->next){
			if(la->data == lb->data){
				x = 1;
			}
			la = la->next;
		}
		if(la->data == lb->data){
			x = 1;
		}
		if(x == 0){
			la->next = (LinkList)malloc(sizeof(LNode));
			la = la->next;
			la->data = lb->data;
			la->next = NULL;
		}
		lb = lb->next;
	}
	la = a;
}