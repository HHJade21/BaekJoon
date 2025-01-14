#include<iostream>
using namespace std;
//이분탐색 연습용
//일단 정렬을 해야 한다. 그리고 이분탐색하자.

void merge(int* array, int* temp, int begin, int middle, int end) {
	int i = begin, j = middle + 1, k = begin;
	while (i <= middle && j <= end) {
		if (array[i] <= array[j]) {
			temp[k] = array[i++];
		}
		else {
			temp[k] = array[j++];
		}
		k++;
	}
	if (i > middle) {
		for (int p = j; p <= end; p++)
			temp[k++] = array[p];
	}
	else {
		for (int q = i; q <= middle; q++)
			temp[k++] = array[q];
	}

	for (int r = begin; r <= end; r++)
		array[r] = temp[r];
}

void mergeSort(int* array, int* temp, int begin, int end) {
	if (begin < end) {
		int middle = (begin + end) / 2;
		mergeSort(array, temp, begin, middle);
		mergeSort(array, temp, middle + 1, end);
		merge(array, temp, begin, middle, end);
	}
}

int binarySearch(int* array, int target, int numSize) {
	int begin = 0, end = numSize - 1, middle;
	while (begin <= end) {
		middle = (begin + end) / 2;
		if (array[middle] == target)
			return 1;
		else if (array[middle] > target)
			end = middle - 1; //그냥 middle로 설정하면?
		else if (array[middle] < target)
			begin = middle + 1;
	}
	return 0;
}

int main() {
	int numSize, searchSize;
	cin >> numSize;
	
	int* temp = new int[numSize];

	int* array = new int[numSize];
	for (int i = 0; i < numSize; i++) {
		cin >> array[i];
	}	
	mergeSort(array, temp, 0, numSize - 1);
	//test code
	//cout << "array sorted. : ";
	//for (int i = 0; i < numSize; i++)
	//	cout << array[i] << " ";

	cin >> searchSize;
	int* searchArray = new int[searchSize];
	for (int i = 0; i < searchSize; i++) {
		cin >> searchArray[i];
	}

	for (int i = 0; i < searchSize; i++) {
		cout << binarySearch(array, searchArray[i], numSize) << "\n";
	}

	delete[] array;
	delete[] temp;
	delete[] searchArray;
}

