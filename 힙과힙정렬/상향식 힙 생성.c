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

void rbuildHeap(int i) { //상향식 힙 생성 재귀 버전

	if (i > n)
		return;

	rbuildHeap(2 * i); //왼쪽 자식 힙생성
	rbuildHeap(2 * i + 1); // 오른쪽 자식 힙생성

	downHeap(i);


}

void buildHeap() { // 비 재귀 버전 힙생성
	for (int i = n / 2;i >= 1;i--) { //마지막 내부노드부터 역방향으로 downHeap
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