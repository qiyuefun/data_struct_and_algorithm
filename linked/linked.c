 struct stlistNode
 {
	int val;
	struct listNode *next;
 }listNode;

 /*��ת����*/
 listNode reverseList(listNode *head)
 {
	listNode *prev = NULL;
	listNode *next = NULL;
  // ���� ��ʽ
	while(head != NULL)
	{
		next = head->next; //��¼��ǰ������һ����� 
		head->next = prev; //����ǰ���ָ��pre
		prev = head;       //ǰ����� ��ǰ��һ���� ��ǰ���
		head = next;       // ��ǰ��� ��ǰһ���� ��һ�����
	}

	return prev;
 }

 /*�ж������Ƿ��л�*/
 int hasCycle(listNode *head)
 {
	listNode * fast = head;
	listNode * low = head;

	while(fast != NULL && fast->next != NULL)
	{
		low = low->next; // ��ָ�� ��һ��
		fast = fast->next->next; // ��ָ�������� 
		if (low == fast) // ������� ���л�
		{
			return 1;
		}
	}

	return 0; // ��ָ�� ��βָ�� û�л�
 }
 /*�ϲ���������*/
 listNode *mergeTwoLists(listNode *l1,listNode *l2)
 {
	listNode head = {0};
	listNode *pRes = &head;

	while((l1 != NULL) && (l2 != NULL))
	{
		if(l1 == NULL)// ���L1�ǿ� �ϲ�����L2
		{
			pRes->next = l2;
		}

		if (l2 == NULL)// ���L2�ǿ� �ϲ�����L1
		{
			pRes->next = l1;
		}

     	if(l1->val < l2->val) // l1 С�� l2 ȡС�� 
		{
			pRes->next = l1; // Сֵ��������
			l1 = l1->next; //֮��Сֵ����ָ����һ�����
		}
		else
		{
			pRes->next = l2; 
			l2 = l2->next;
		}
		pRes = pRes->next; // �ظ�֪�� ĳ����Ϊ�� ����
	}

	return head;
 }


 /*
  *ɾ����������n���ڵ㣬����������ͷ�ڵ� */


 class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // ����һ���½ڵ�����ָ���������ͷ�ڵ㡣
      ListNode node = new ListNode(0);
        // ���½ڵ�ָ��ǰ�����ͷ�ڵ㡣
        node.next = head;
        // ���峤�� len ����¼ԭ����ĳ��ȡ�
        int len = 0;
        // ���� p ָ���������ÿ��һ���ڵ��򳤶� +1 ��
        ListNode p = head;
        while (p != null) {
            len++;
          p = p.next;
        }
        // ������ n ���ڵ�������� len - n ����һ���ڵ㡣
        len -= n;
        p = node;
       // ����ԭ�����ҵ��� len - n ���ڵ㡣
       for (int i = 0; i < len; i++) {
            p = p.next;
        }
        // ɾ��ԭ����� len - n ����һ���ڵ㡣
        p.next = p.next.next;
        return node.next;
    }
 }


 /*��������м�ڵ�*/ // ����ָ�� ��ָ�������� ��ָ����һ��
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