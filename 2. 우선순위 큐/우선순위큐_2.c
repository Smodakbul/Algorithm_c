#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void Insertsort(int* arr, int n) {

	int tmp;
	while (1) {
		if (arr[n] > arr[n - 1] || n == 0)
			break;

		else {
			tmp = arr[n];
			arr[n] = arr[n - 1];
			arr[n - 1] = tmp;
		}
		n--;

	}
}

void main() {
	int n;
	int* arr;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);

	}
	int tmp;

	for (int i = 1;i < n;i++) {
		Insertsort(arr, i);
	}

	for (int i = 0;i < n;i++) {

		printf(" %d", arr[i]);

	}


	free(arr);

}
