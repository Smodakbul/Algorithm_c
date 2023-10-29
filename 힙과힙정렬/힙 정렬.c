#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int H[100] = { 0 }, n = 0, x = 0;

void downHeap(int i) {

	int tmp; //swap �ϱ����� ����
	int child = 2 * i; //i�� �ڽĳ�� ����
	if ((n < child) && (n < child + 1)) { //�ڽĳ�尡 ������ return

		return;

	}

	if (n >= child + 1 && H[2 * i + 1] >= H[2 * i]) { //������ �ڽĳ�尡 �����ϰ� ������ �ڽĳ��� �����ڽĳ�� ũ�� ��
		child = 2 * i + 1;
	}

	if (H[i] < H[child]) {
		tmp = H[i];
		H[i] = H[child];
		H[child] = tmp;
		downHeap(child);
	}
}

void buildHeap() {
	for (int i = n / 2;i >= 1;i--) {
		downHeap(i);
	}
}

void rbuildHeap(int i) {

	if (i > n)
		return;

	rbuildHeap(2 * i);
	rbuildHeap(2 * i + 1);
	downHeap(i);

}

void printArray(int* H) {

	for (int i = 1;i <= x;i++) {

		printf(" %d", H[i]);

	}
	printf("\n");
}

void inplaceHeapSort() { //�ִ� ���� ���� ������ ���� ���� �� ��� ����

	int tmp;

	if (n == 1) {
		return;
	}

	tmp = H[n];
	H[n] = H[1];
	H[1] = tmp;
	n--;

	downHeap(1);

	inplaceHeapSort();
}

void main() {
	scanf("%d", &n);
	x = n;
	for (int i = 1;i <= n;i++) {

		scanf("%d", &H[i]);

	}
	rbuildHeap(1);
	inplaceHeapSort();
	printArray(H);


}