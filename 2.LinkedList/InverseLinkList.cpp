void inverseLinkList(LinkList &L){
	LinkList p, q; 
	// 将链表拆分成头结点L和一个不带头结点的链表
	p = L->next;	// p指向L的第一个节点 
	L->next = NULL;
	
	while(p){
		q = p; // 取出H中的第一个节点q
		p = p->next; 
		// 将q插入到L的第一个节点之前
		q->next = L->next;
		L->next = q;	 
	}
｝