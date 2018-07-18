void init(LinkQueue &q)		// 初始化一个空队列
{
	q.front = q.rear = new QNode;
	q.front->next = NULL;
} 
Status enqueue(LinkQueue &q, QElemType e) 	// 元素e入队 
{
	QueuePtr p;
	p = new QNode;
	if(!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return OK;
}
Status dequeue(LinkQueue &q)					// 出队 
{
	QueuePtr p;
	if(q.front==q.rear) return ERROR;
	p = q.front->next;
	q.front->next = p->next;
	if(q.rear==p) q.rear=q.front;
	delete p;
	return OK;
}
Status getFront(LinkQueue q, QElemType &e)	// 将队头元素赋值给e 
{
	if(q.front!=q.rear)
	{
		e = q.front->next->data;
		return OK;
	}
	else if(q.front == q.rear)  
		return 0;
		
}
void clear(LinkQueue &q)					// 清空队列 
{
	q.front = q.rear;
}
void printLinkQueue(LinkQueue q)	//按输入的顺序打印队列中的元素
{
	if(q.front == q.rear)  
		printf("empty\n");
	else
	{
		QueuePtr p;
		p = q.front->next;
		while(p->next!=NULL)
		{
			printf("%d ",p->data);
			p = p->next;
		} 
		printf("%d ",p->data);
		puts("");
	} 
} 