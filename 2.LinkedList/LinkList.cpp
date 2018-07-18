Status createList(LinkList &L, int n)	// 创建n个元素的表，与用户输入的顺序相同（后插）
{
	LinkList p,r;
	int i;
	L = new LNode;
	r = L;
	for(i=0;i<n;i++)
	{
		p = new LNode;
		scanf("%d",&p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
/*Status createList(LinkList &L, int n)//头插法
{
	LinkList p;
	int i;
	L = new LNode;
	L->next = NULL;
	for(i=0;i<n;i++)
	{
		p = new LNode;
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	}
}*/
Status getElem(LinkList L, int i, ElemType &e)	// 取值，将序号i的元素存入e 
{
	LinkList p;int j;
	p = L->next;j=1;
	while(p && j<i)
	{
		p = p->next;
		++j;
	}
	if(!p || j>i)return ERROR;
	e = p->data;
	return OK;
}
int locateElem(LinkList L, ElemType e)		// 查找，返回元素e的序号，失败返回0
{
	LinkList p;
	p = L->next;
	int i = 1
	while(p && p->data!=e)
	{
		p = p->next;
		i++;
	}
	if(p) return i;
	return 0;
	
} 
Status listInsert(LinkList &L, int i, ElemType e)	// 插入 
{
	int j;
	LinkList p,s;
	p = L;//注意创建p后要有指向
	j=1;
	while(p && j<i)
	{
		p = p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status listDelete(LinkList &L, int i) 			// 删除
{
	int j;
	LinkList p,q;
	p = L;
	j=1;
	while(p->next && j<i)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	free(q);
	return OK;
} 