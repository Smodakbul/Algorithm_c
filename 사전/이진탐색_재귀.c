#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>


int* arr, tmp;

int findElement(int k, int l, int r) {
	int mid = 0;
	if (l > r) {

		return -1;
	}

	mid = (l + r) / 2;

	if (arr[mid] == k) {
		return mid;
	}

	else if (arr[mid] > k) {
		return findElement(k, l, mid - 1);
	}

	else {
		if ((tmp == NULL) || (arr[tmp] < arr[mid])) {

			tmp = mid;
		}
		return findElement(k, mid + 1, r);
	}
}

void main() {
	int n, k;
	scanf("%d %d", &n, &k);
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	if (findElement(k, 0, n - 1) == -1) {

		if (tmp == NULL) {
			printf(" %d", findElement(k, 0, n - 1));
		}

		else {

			printf(" %d", tmp);
		}
	}
	else {

		printf(" %d", findElement(k, 0, n - 1));
	}

	free(arr);
}