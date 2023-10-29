#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>


void merge(int* A, int start, int mid, int end) {
	int i = start;
	int k = start;
	int j = mid + 1;
	int* B;

	if (end > start) {
		B = (int*)malloc(sizeof(int) * (end - start + 1));
		while (i <= mid && j <= end) {
			if (A[i] <= A[j])
				B[k++] = A[i++];
			else
				B[k++] = A[j++];
		}

		while (i <= mid) {
			B[k++] = A[i++];
		}
		while (j <= end) {
			B[k++] = A[j++];
		}

		for (int x = start;x <= end;x++) {
			A[x] = B[x];
		}
	}

}
void rMergeSort(int* A, int start, int end) {

	int mid;

	if (start < end) {

		mid = (start + end) / 2;

		rMergeSort(A, start, mid);
		rMergeSort(A, mid + 1, end);
		merge(A, start, mid, end);
	}
	else
		return;

}
void mergeSort(int* A, int n) {
	rMergeSort(A, 0, n - 1);
}

int main() {

	int n;
	scanf("%d", &n);

	int* arr;
	arr = (int*)malloc(sizeof(int) * n);

	if (arr == NULL) {
		return 1;  // 에러 코드 반환
	}

	for (int i = 0;i < n;i++) {

		scanf("%d", &arr[i]);
	}
	mergeSort(arr, n);

	for (int i = 0;i < n;i++) {

		printf(" %d", arr[i]);
	}
	free(arr);

	return 0;
}