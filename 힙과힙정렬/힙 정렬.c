#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int H[100] = { 0 }, n = 0, x = 0;

void downHeap(int i) {

	int tmp; //swap 하기위한 변수
	int child = 2 * i; //i의 자식노드 설정
	if ((n < child) && (n < child + 1)) { //자식노드가 없으면 return

		return;

	}

	if (n >= child + 1 && H[2 * i + 1] >= H[2 * i]) { //오른쪽 자식노드가 존재하고 오른쪽 자식노드와 왼쪽자식노드 크기 비교
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

void inplaceHeapSort() { //최대 힙을 가장 마지막 노드로 변경 후 노드 삭제

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