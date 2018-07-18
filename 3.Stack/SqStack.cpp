Status init(SqStack &s)	// 初始化一个空栈  
{
	s.base = new SElemType[MAXSIZE];
	if(!s.base) exit(OVERFLOW);
	s.top= s.base;
	return OK;
}
Status push(SqStack &s, SElemType e) 	// 元素e入栈 
{
	if(s.top-s.base == MAXSIZE)return ERROR;
	*s.top++ = e;
	return OK;
}
Status pop(SqStack &s)			// 出栈  
{
	if(s.top == s.base)return ERROR;
	 return *--s.top;
}
Status getTop(SqStack s, SElemType &e)	// 将栈顶元素赋值给e 
{
	if(s.top!=s.base)
	{
		e = *(s.top-1);
		return OK;	
	}	
}
void clear(SqStack &s)					// 清空栈 
{
	s.top = s.base;
}
void printSqStack(SqStack s)	//按输入的顺序打印栈中的元素 
{
	if(s.top == s.base) printf("empty\n");
	while(s.top!=s.base)
	{
		printf("%d ",*(s.top-1));
		s.top--;
	} 
	puts("");
}