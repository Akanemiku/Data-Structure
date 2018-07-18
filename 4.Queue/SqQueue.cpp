Status init(SqQueue &q)	// 初始化一个空队列
{
	q.base = new QElemType[MAXSIZE];
	if(!q.base) exit(OVERFLOW);
	q.front = q.rear = 0;
	return OK; 
} 
Status enqueue(SqQueue &q, QElemType e) 	// 元素e入队
{
	if((q.rear+1)%MAXSIZE==q.front)return ERROR;
	q.base[q.rear] = e;
	q.rear = (q.rear+1)%MAXSIZE;
	return OK; 
} 
Status dequeue(SqQueue &q)					// 出队 
{
	if(q.front==q.rear)return ERROR;
	q.front = (q.front+1)%MAXSIZE;
	return OK;
}
Status getFront(SqQueue q, QElemType &e)	// 将队头元素赋给e 
{
	if(q.front!=q.rear)
	{
		e = q.base[q.front];
		return e;
	}
	else return ERROR;	
}
void clear(SqQueue &q)					// 清空队列 
{
	q.front = q.rear = 0;
}
void printSqQueue(SqQueue q)	//按输入的顺序打印队列中的元素 
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