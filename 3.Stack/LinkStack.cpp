void init(LinkStack &s)		// 初始化一个空栈 
{
	s = NULL;
}
Status push(LinkStack &s, SElemType e) 	// 元素e入栈 
{
	LinkStack p;
	p = new StackNode;
	p->data = e;
	p->next = s;
	s = p;
	return OK;
}
Status pop(LinkStack &s)					// 出栈 
{
	if(!s) return ERROR;
	LinkStack p;p = s;
	s = s->next;
	free(p);
	return OK;
}
Status getTop(LinkStack s, SElemType &e)	// 将栈顶元素赋值给e 
{
	if(!s) return ERROR;
	e = s->data;
	return OK;
		
}
void clear(LinkStack &s)					// 清空栈 
{
	LinkStack p,q;
	p = s;
	while(p){
		q = p;
		p = p->next;
		free(q);
	} 
	s = NULL;
}
void printLinkStack(LinkStack s)	//按输入的顺序打印栈中的元素 
{
	if(s==NULL)
	{
		printf("empty\n");return;
	}
	for(int i=0;i<99999;i++)
	{
		printf("%d ",s->data);
		s = s->next;
		if(s->next==NULL)
		{
			printf("%d\n",s->data);
			break;
		}
	}
}