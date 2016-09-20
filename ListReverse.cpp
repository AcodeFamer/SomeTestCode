#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}NODE;
//头插法
void insert(NODE *head, NODE *node)
{
	if (head == NULL)
	{
		head->next = node;
		node->next = NULL;
	}
	else
	{
		node->next = head->next;
		head->next = node;
	}
}
//翻转链表
NODE* reverse(NODE *head)
{
	if (head == NULL)
		return NULL;
	NODE* node = head->next;
	head->next = NULL;
	while (node)
	{
		NODE* tmp = node;
		node = node->next;
		insert(head, tmp);
	}
	return head;
}

int main()
{
	NODE *head, n1, n2, n3;
	head = (NODE*)malloc(sizeof(NODE));
	n1.data = 1; 
	n2.data = 2;
	n3.data = 3;
	head->next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	head = reverse(head);
	while (head)
	{
		head = head->next;
		cout << head->data << " ";
	}
	cout << endl;
}
