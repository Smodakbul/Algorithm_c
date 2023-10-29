#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int H[100], n = 0; //�������� ����

void upHeap(int i) { //���� �� �θ� ��尡 �ڽĳ�庸�� ������ swap�ϴ� �Լ�
	int tmp;

	if (i <= 1) {
		return;
	}

	if (H[i] <= H[i / 2]) {
		return;
	}

	tmp = H[i];      //swap
	H[i] = H[i / 2];
	H[i / 2] = tmp;

	upHeap(i / 2); //���

}

void insertItem(int k) { //key ���� �Լ�

	n++; //���� ��ȣ
	H[n] = k; //���� ���� ���� key ����
	upHeap(n); 
}

void downHeap(int i) { //�ִ� �� ���� �� ���� �ٽ� �迭�ϴ� �Լ�

	int tmp;
	int child = 2 * i;
	if ((n < child) && (n < child + 1)) {

		return;

	}
	if (H[i] >= H[child] && H[i] >= H[child + 1]) {
		return;
	}
	if (H[2 * i + 1] >= H[2 * i]) {
		child = 2 * i + 1;
	}
	tmp = H[i];
	H[i] = H[child];
	H[child] = tmp;

	downHeap(child);

}

int removeMax() { //�ִ��� ����

	int key;
	key = H[1];
	H[1] = H[n];
	n = n - 1;
	downHeap(1);

	return key;
}

void printHeap() {

	for (int i = 1;i <= n;i++) {

		printf(" %d", H[i]);

	}
	printf("\n");
}

void main() {
	char cmd; //i,d,p,q
	int key;



	while (1) {

		scanf("%c", &cmd);

		if (cmd == 'i') {
			scanf("%d", &key);
			insertItem(key);
			printf("0\n");
			getchar();
		}

		else if (cmd == 'd') {
			printf("%d\n", removeMax());
			getchar();
		}

		else if (cmd == 'p') {
			printHeap();
			getchar();
		}

		else if (cmd == 'q') {
			break;
		}

	}

}