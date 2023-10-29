#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Max(int* arr, int n) {

	int max = arr[0];
	int index = 0;
	for (int k = 0;k <= n;k++) {
		if (arr[k] > max) {
			max = arr[k];
			index = k;
		}
	}
	return index;
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

	for (int i = n - 1;i >= 0;i--) {

		tmp = arr[i];
		arr[i] = arr[Max(arr, i)];
		arr[Max(arr, i)] = tmp;

	}
	for (int i = 0;i < n;i++) {

		printf(" %d", arr[i]);

	}


	free(arr);

}