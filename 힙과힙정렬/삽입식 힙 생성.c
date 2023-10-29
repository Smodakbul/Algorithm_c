#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int H[100], n = 0; //전역변수 설정

void upHeap(int i) { //삽입 후 부모 노드가 자식노드보다 작으면 swap하는 함수
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

	upHeap(i / 2); //재귀

}

void insertItem(int k) { //key 삽입 함수

	n++; //힙의 번호
	H[n] = k; //가장 낮은 힙에 key 삽입
	upHeap(n); 
}

void downHeap(int i) { //최대 힙 삭제 후 힙을 다시 배열하는 함수

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

int removeMax() { //최대힙 삭제

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