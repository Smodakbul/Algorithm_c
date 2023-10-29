#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int H[100], n = 0;


void downHeap(int i) {

	int tmp;
	int child = 2 * i;
	if ((n < child) && (n < child + 1)) {

		return;

	}

	if (n >= child + 1 && H[2 * i + 1] >= H[2 * i]) {
		child = 2 * i + 1;
	}

	if (H[i] < H[child]) {
		tmp = H[i];
		H[i] = H[child];
		H[child] = tmp;
		downHeap(child);
	}
}

void rbuildHeap(int i) { //����� �� ���� ��� ����

	if (i > n)
		return;

	rbuildHeap(2 * i); //���� �ڽ� ������
	rbuildHeap(2 * i + 1); // ������ �ڽ� ������

	downHeap(i);


}

void buildHeap() { // �� ��� ���� ������
	for (int i = n / 2;i >= 1;i--) { //������ ���γ����� ���������� downHeap
		downHeap(i);
	}
}

void printHeap() {

	for (int i = 1;i <= n;i++) {

		printf(" %d", H[i]);

	}
	printf("\n");
}


void main() {
	int key_cnt;
	scanf("%d", &key_cnt);

	for (int i = 1;i <= key_cnt;i++) {

		scanf("%d", &H[i]);
		n++;
	}

	buildHeap();

	printHeap();


}