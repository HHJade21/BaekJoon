//N개의 정수를 오름차순으로 정렬하는 문제. 시간복잡도가 O(nlogn)인 정렬 방식으로 풀어야 한다. 퀵정렬, 병합정렬, 힙정렬 다 해보기


#include<iostream>
using namespace std;



//퀵 정렬로 풀어보기 - 실패...
/*int partition(int a[], int begin, int end) {
	int piv = (begin + end) / 2;
	int L = begin;
	int R = end;
	int temp;

	while (L < R) {
		while (a[L] < a[piv] && L < R)
			L++;
		while (a[R] >= a[piv] && L < R)
			R--;
		if (L < R) {
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
			if (L == piv)
				piv = R;
		}
	}
	
	temp = a[piv];
	a[piv] = a[R];
	a[R] = temp;


	return R;

}


void quickSort(int a[], int begin, int end) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end);
		quickSort(a, begin, p - 1);
		quickSort(a, p + 1, end);
	}
}*/

//병합정렬로 풀어보기
void merge(int a[], int sorted[], int begin, int middle, int end) {
	int k = begin;
	int i = begin;
	int j = middle + 1;
	while (i <= middle && j <= end) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int x = j; x <= end; x++) {
			sorted[k] = a[x];
			k++;
		}
	}
	else {
		for (int x = i; x <= middle; x++) {
			sorted[k] = a[x];
			k++;
		}
	}

	for (int z = begin; z <= end; z++) //개멍청하게 이거 안해줘서 틀렸었음
		a[z] = sorted[z];

}

void mergeSort(int a[], int sorted[], int begin, int end) {
	int middle;
	if (begin < end) {
		middle = (begin + end) / 2;
		mergeSort(a, sorted, begin, middle);
		mergeSort(a, sorted, middle + 1, end);
		merge(a, sorted, begin, middle, end);
	}
}





int main() {
	int N;
	cin >> N;
	int* a = new int[N];
	int* sorted = new int[N];
	for (int i = 0; i < N; i++)
		cin >> a[i];

	mergeSort(a, sorted, 0, N - 1);

	for (int i = 0; i < N; i++)
		cout << a[i] << "\n";
	delete[] a;
	delete[] sorted;
}