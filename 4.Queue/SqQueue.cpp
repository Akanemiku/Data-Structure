Status init(SqQueue &q)	// ��ʼ��һ���ն���
{
	q.base = new QElemType[MAXSIZE];
	if(!q.base) exit(OVERFLOW);
	q.front = q.rear = 0;
	return OK; 
} 
Status enqueue(SqQueue &q, QElemType e) 	// Ԫ��e���
{
	if((q.rear+1)%MAXSIZE==q.front)return ERROR;
	q.base[q.rear] = e;
	q.rear = (q.rear+1)%MAXSIZE;
	return OK; 
} 
Status dequeue(SqQueue &q)					// ���� 
{
	if(q.front==q.rear)return ERROR;
	q.front = (q.front+1)%MAXSIZE;
	return OK;
}
Status getFront(SqQueue q, QElemType &e)	// ����ͷԪ�ظ���e 
{
	if(q.front!=q.rear)
	{
		e = q.base[q.front];
		return e;
	}
	else return ERROR;	
}
void clear(SqQueue &q)					// ��ն��� 
{
	q.front = q.rear = 0;
}
void printSqQueue(SqQueue q)	//�������˳���ӡ�����е�Ԫ�� 
{
	int i;  
    i = q.front;
	if(q.front==q.rear) printf("empty");
    while(i!=q.rear)
    {
    	printf("%d ",q.base[i]);
    	i++;
    }
    puts("");
}