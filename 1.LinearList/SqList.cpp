Status createList(SqList &L, int n)    // 根据用户输入，创建n个元素的表 
{
	L.elem = new ElemType[MAXSIZE];
	if(!L.elem)exit(OVERFLOW);
	L.length = 0;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&L.elem[i]);
		L.length++;
	}
}
void traverseList(SqList L)    // 遍历，打印表中元素 
{
	int i;
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	puts("");
}
Status getElem(SqList L, int i, ElemType &e)    // 取值，将序号i的元素存入e 
{
	if(i<1 || i>L.length)return ERROR;//注意getElem也需要判断是否超出范围
	e = L.elem[i-1];
	return OK;
}
int locateElem(SqList L, ElemType e)        // 查找，返回元素e的序号
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(L.elem[i] == e)
			return i+1;
	}
	return 0;	
} 
Status listInsert(SqList &L, int i, ElemType e)    // 插入
{
	int j;
	if(i<1 || i>L.length+1)
		return ERROR;
	if(L.length == MAXSIZE)
		return ERROR;
	for(j=L.length-1;j>=i-1;j--)
		L.elem[j+1] = L.elem[j];
	L.elem[i-1] = e;
	L.length++;
	return OK;
} 
Status listDelete(SqList &L, int i)             // 删除 
{
	int j;
	if(i<1 || i>L.length)
		return ERROR;
	for(j=i;j<L.length;j++)
		L.elem[j-1] = L.elem[j];
	L.length--;
	return OK;
}