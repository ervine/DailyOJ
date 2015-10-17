// Remove Nth Node From End of List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
//struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//	struct ListNode *p = head, **pv = (struct ListNode**)malloc(1000 * sizeof(struct ListNode*));
//	int num, max = 1000; // num of nodes
//	for (num = 0; p; num++, p = p->next) {
//		if (num >= max) {
//			max *= 2;
//			realloc(pv, max);
//		}
//		pv[num] = p;
//	}
//
//	if (num - n)
//		pv[num - n - 1]->next = pv[num - n - 1]->next->next;
//	else if (num>1)
//		return pv[1];
//	else
//		return NULL;
//	return head;
//}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	if (!head) return NULL;
	ListNode *f = head, *s = head;
	while (f->next) {
		f = f->next;
		if (!n--) s = s->next;
	}
	if (n>0)
		return head->next;
	else {
		s->next = s->next->next;
		return head;
	}
}
int main()
{
	ListNode head, n1, n2;
	head.next = &n1;
	n1.next = &n2;
	n2.next = NULL;
	
	head.val = 1;
	n1.val = 2;
	n2.val = 3;
	
	head = *(ListNode*)removeNthFromEnd(&head, 3);

	for (; ; ) {
		printf("%d\n", head.val);
		if (head.next) head = *head.next;
		else break;
	}

	printf("END\n");
	scanf_s("%d", &n1.val);
    return 0;
}

