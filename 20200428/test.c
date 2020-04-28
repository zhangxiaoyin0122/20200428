#include <stdio.h>
#include <stdlib.h>

Swap(int* array, int min, int start) {
	int tmp = array[min];
	array[min] = array[start];
	array[start] = tmp;
}
void insertSort(int* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int key = array[end + 1];
		while (end >= 0 && array[end] > key) {
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
void shellSort(int* array, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 2;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key) {
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}

void selectSort(int* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		int start = i;
		for (int j = start + 1; j < n; j++) {
			if (array[j] < array[min])
				min = j;
		}
		Swap(array, min, start);
	}
}

void selectSort1(int* array, int n) {
	int begin = 0;
	int end = n - 1;
	while (begin < end) {		
		int min = begin;
		int max = begin;
		for (int i = begin + 1; i <= end; i++) {
			if (array[i] >= array[max])
				max = i;
			if (array[i] < array[min])
				min = i;
		}
		Swap(array, min, begin);
		if (max == begin)
			max = min;
		Swap(array, max, end);
		begin++;
		end--;
	}
}
//Ã°ÅİÅÅĞò(ÏòÇ°Ã°Åİ)
void bubbleSort(int* array, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j > i; j--) {
			if (array[j] < array[j - 1])
				Swap(array, j, j - 1);
		}
	}
}

int main() {
	int array[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int size = sizeof(array) / sizeof(array[0]);
	//shellSort(array, size);
	//selectSort(array, size);
	//insertSort(array, size);
	//selectSort1(array, size);
	bubbleSort(array, size);
	for (int i = 0; i < size; i++) {
		printf("%d ",array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}