 struct stlistNode
 {
	int val;
	struct listNode *next;
 }listNode;

 /*反转链表*/
 listNode reverseList(listNode *head)
 {
	listNode *prev = NULL;
	listNode *next = NULL;
  // 迭代 方式
	while(head != NULL)
	{
		next = head->next; //记录当前结点的下一个结点 
		head->next = prev; //将当前结点指向pre
		prev = head;       //前驱结点 往前进一步到 当前结点
		head = next;       // 当前结点 往前一步到 下一个结点
	}

	return prev;
 }

 /*判断链表是否有环*/
 int hasCycle(listNode *head)
 {
	listNode * fast = head;
	listNode * low = head;

	while(fast != NULL && fast->next != NULL)
	{
		low = low->next; // 慢指针 走一步
		fast = fast->next->next; // 快指针走两步 
		if (low == fast) // 如果相遇 则有环
		{
			return 1;
		}
	}

	return 0; // 快指针 到尾指针 没有环
 }
 /*合并有序链表*/
 listNode *mergeTwoLists(listNode *l1,listNode *l2)
 {
	listNode head = {0};
	listNode *pRes = &head;

	while((l1 != NULL) && (l2 != NULL))
	{
		if(l1 == NULL)// 如果L1是空 合并链是L2
		{
			pRes->next = l2;
		}

		if (l2 == NULL)// 如果L2是空 合并链是L1
		{
			pRes->next = l1;
		}

     	if(l1->val < l2->val) // l1 小于 l2 取小的 
		{
			pRes->next = l1; // 小值给新链，
			l1 = l1->next; //之后小值的链指向下一个结点
		}
		else
		{
			pRes->next = l2; 
			l2 = l2->next;
		}
		pRes = pRes->next; // 重复知道 某个表为空 结束
	}

	return head;
 }


 /*
  *删除链表倒数第n个节点，并返回链表头节点 */


 class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // 定义一个新节点用来指向结果链表的头节点。
      ListNode node = new ListNode(0);
        // 将新节点指向当前链表的头节点。
        node.next = head;
        // 定义长度 len 来记录原链表的长度。
        int len = 0;
        // 定义 p 指针遍历链表，每有一个节点则长度 +1 。
        ListNode p = head;
        while (p != null) {
            len++;
          p = p.next;
        }
        // 倒数第 n 个节点就是正数 len - n 的下一个节点。
        len -= n;
        p = node;
       // 遍历原链表找到第 len - n 个节点。
       for (int i = 0; i < len; i++) {
            p = p.next;
        }
        // 删除原链表第 len - n 的下一个节点。
        p.next = p.next.next;
        return node.next;
    }
 }


 /*求链表的中间节点*/ // 快慢指针 快指针走两步 慢指针走一步
 listNode *middleNode(listNode *head)
 {
	listNode * fast = head;
	listNode * low = head;

	while(fast != NULL && fast->next != NULL)
	{
		low = low->next;
		fast = fast->next->next;
	}

	return low;
 }