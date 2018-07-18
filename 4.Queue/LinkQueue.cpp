void init(LinkQueue &q)		// ��ʼ��һ���ն���
{
	q.front = q.rear = new QNode;
	q.front->next = NULL;
} 
Status enqueue(LinkQueue &q, QElemType e) 	// Ԫ��e��� 
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
Status dequeue(LinkQueue &q)					// ���� 
{
	QueuePtr p;
	if(q.front==q.rear) return ERROR;
	p = q.front->next;
	q.front->next = p->next;
	if(q.rear==p) q.rear=q.front;
	delete p;
	return OK;
}
Status getFront(LinkQueue q, QElemType &e)	// ����ͷԪ�ظ�ֵ��e 
{
	if(q.front!=q.rear)
	{
		e = q.front->next->data;
		return OK;
	}
	else if(q.front == q.rear)  
		return 0;
		
}
void clear(LinkQueue &q)					// ��ն��� 
{
	q.front = q.rear;
}
void printLinkQueue(LinkQueue q)	//�������˳���ӡ�����е�Ԫ��
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