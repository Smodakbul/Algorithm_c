#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>


int findPivot(int start, int end) {
	int pivot = start + rand() % (end - start + 1);
	return pivot;


}

int inPlacePartition(int* arr, int start, int end, int k) {

	int p = arr[k];
	int tmp;
	tmp = arr[k];
	arr[k] = arr[end];
	arr[end] = p;
	int i = start;
	int j = end - 1;

	while (i <= j) {
		while (i <= j && arr[i] <= p)
			i = i + 1;
		while (i <= j && arr[j] >= p)
			j = j - 1;
		if (i < j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i];
	arr[i] = arr[end];
	arr[end] = tmp;

	return i;
}

void inPlaceQuickSort(int* arr, int start, int end) {

	if (start >= end)
		return;
	int a, b;
	int k = findPivot(start, end);
	a = b = inPlacePartition(arr, start, end, k);

	inPlaceQuickSort(arr, start, a - 1);
	inPlaceQuickSort(arr, b + 1, end);

}
int main() {

	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0;i < n;i++) {

		scanf("%d", &arr[i]);
	}

	inPlaceQuickSort(arr, 0, n - 1);
	for (int i = 0;i < n;i++) {
		printf(" %d", arr[i]);
	}
	free(arr);

	return 0;

}