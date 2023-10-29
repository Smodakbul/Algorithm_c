#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int data;
	struct Node* next;
}node;

typedef struct {
	node* L1;
	node* L2;
}part;

node* addnode(int data) {
	node* new_node;

	new_node = (node*)malloc(sizeof(node));

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}
part partition(node* L, int k) {

	node* p = L;
	node* L1 = L;
	part result;
	for (int i = 0;i < k - 1;i++) {
		p = p->next;
	}

	node* L2 = p->next;
	p->next = NULL;

	result.L1 = L1;
	result.L2 = L2;
	return result;
}

node* merge(node* L1, node* L2) {
	node* L = NULL;
	node* tail = NULL;

	while (L1 != NULL && L2 != NULL) {
		if (L1->data <= L2->data) {
			if (L == NULL) {
				L = L1;
				tail = L1;
			}
			else {
				tail->next = L1;
				tail = L1;
			}
			L1 = L1->next;
		}
		else {
			if (L == NULL) {
				L = L2;
				tail = L2;
			}
			else {
				tail->next = L2;
				tail = L2;
			}
			L2 = L2->next;
		}
	}

	if (L1 != NULL) {
		tail->next = L1;
	}
	else {
		tail->next = L2;
	}

	return L;
}

node* mergeSort(node* L, int n) {
	if (n > 1) {
		part div = partition(L, n / 2);
		node* L1 = div.L1;
		node* L2 = div.L2;

		L1 = mergeSort(L1, n / 2);
		L2 = mergeSort(L2, n - n / 2);

		return merge(L1, L2);
	}
	return L;
}

void printAll(node* L) {


	node* i = L;

	while (i != NULL) {
		printf(" %d", i->data);
		i = i->next;
	}
	printf("\n");
}
int main() {

	int n;
	scanf("%d", &n);
	int i;
	node* head;
	node* p;

	head = NULL;

	int data;
	for (i = 0, p = head;i < n;i++) {
		scanf("%d", &data);

		if (head == NULL) {
			head = addnode(data);
			p = head;
		}
		else {
			p->next = addnode(data);
			p = p->next;
		}
	}

	head = mergeSort(head, n);

	printAll(head);

	return 0;
}