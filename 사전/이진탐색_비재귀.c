#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>


int* arr, min = -1;

int find(int n, int k) {
	int mid, l = 0, r = n - 1;

	while (1) {

		if (l > r) {
			return -1;
		}

		mid = (l + r) / 2;

		if (arr[mid] == k) {
			return mid;
		}

		else if (k < arr[mid]) {

			if (min == -1) {
				min = mid;
			}

			else if (arr[mid] < arr[min]) {
				min = mid;
			}
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
}

void main() {
	int n, k;

	scanf("%d %d", &n, &k);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	if (find(n, k) == -1) {
		if (min == -1) {
			printf(" %d", n);
		}
		else {
			printf(" %d", min);
		}
	}

	else {
		printf(" %d", find(n, k));
	}

	free(arr);
}