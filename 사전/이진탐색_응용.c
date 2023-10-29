#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>


void findElement(int* a, int* b, int* mid, char yn) {

	*mid = (*a + *b) / 2;

	if (yn == 'Y') {
		*a = *mid + 1;
	}

	else if (yn == 'N') {
		*b = *mid;
	}

	if (*a == *b) {
		printf("%d", *a);
	}
}

void main() {
	int a, b, m, n;

	char YN[10000];

	scanf("%d %d %d", &a, &b, &n);

	getchar();

	for (int i = 0; i < n; i++) {
		scanf("%c", &YN[i]);
	}
	for (int i = 0; i < n; i++) {
		findElement(&a, &b, &m, YN[i]);
	}
}