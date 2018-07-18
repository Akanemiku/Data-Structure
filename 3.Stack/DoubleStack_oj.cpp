/**多行输入。
 * 每行包含2-3个输入。
 * 第一个是数字，代表栈的操作（1代表入栈，2代表出栈）；第二个也是数字，代表栈的编号（1或2）。
 * 如果是入栈操作，则每行有3个输入，第三个输入是一个字符，代表入栈的元素；否则如果是出栈操作则每行只有2个输入。
 * 详见样例输入。
 */
/**输入示例
1 1 a
1 1 b
1 1 c
1 1 d
1 2 e
1 2 f
1 2 g
1 2 h
1 2 i
1 1 i
2 2
2 2
2 2
2 2
2 2
2 1
2 1
2 1
2 1
2 1
*/
/**输出示例
Push a into stack 1.
Push b into stack 1.
Push c into stack 1.
Push d into stack 1.
Push e into stack 2.
Push f into stack 2.
Push g into stack 2.
Push h into stack 2.
Full.
Full.
Pop from stack 2.
Pop from stack 2.
Pop from stack 2.
Pop from stack 2.
Stack 2 is empty.
Pop from stack 1.
Pop from stack 1.
Pop from stack 1.
Pop from stack 1.
Stack 1 is empty.
*/

#include<stdio.h>
#include<stdlib.h>
#define M 8
typedef  struct {
  char *base;  // 数据存储的基地址
  char *top1, *top2;  // 两个栈的栈顶指针
}DoubleStack; // 双栈

void init(DoubleStack &s){
	s.base = new char[M];
	if(!s.base) return;
	s.top1 = s.base;
	s.top2 = s.base + M;
}

int push(DoubleStack &s,int a,char c){
	if(s.top1 == s.top2){
		return 0;
	}
	if(a == 1){
		*s.top1++ = c;
	}
	else{
		*s.top2-- = c;
	}
	return 1;
}

int pop(DoubleStack &s,int a){
	if(a == 1){
		if(s.base == s.top1){
			return 0;
		}
		else{
			--s.top1;
			return 1;
		}
	}
	if(a == 2){
		if(s.base + M== s.top2){
			return 0;
		}
		else{
			++s.top2;
			return 1;
		}
	}
}

int main(){
	int cmd;
	DoubleStack s;
	init(s);
	while(scanf("%d",&cmd)!=EOF){
		if(cmd == 1){
			int a,c;
			scanf("%d %c",&a,&c);
			if(push(s,a,c)){
				printf("Push %c into stack %d.\n",c,a);
			}
			else{
				printf("Full.\n");
			}
		}
		else if(cmd == 2){
			int a;
			scanf("%d",&a);
			if(pop(s,a)){
				printf("Pop from stack %d.\n",a);
			}
			else{
				printf("Stack %d is empty.\n",a);
			}
		}
	}
}