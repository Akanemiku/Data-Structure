# SqQueue
```
typedef struct{
	QElemType   *base;	//存储空间的基地址 
	int front;		// 队头
	int rear;		// 队尾 
}SqQueue;
```

# LinkQueue
```
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
	QueuePtr front;	// 队头  
	QueuePtr rear;	// 队尾 
} LinkQueue;
```
