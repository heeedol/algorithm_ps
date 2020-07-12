#include <iostream>

using namespace std;

#define number 100

int givenArr[number];
int sortedArr[number];


int partition(int start, int end) {
	int first = start+1;
	int last = end;
	int sortNum = start;
	int pivot = givenArr[start];
	if (sortNum < last) {
		while (first-1!=end) {
			if (givenArr[first] <= pivot) sortedArr[sortNum++] = givenArr[first++];
			else sortedArr[last--] = givenArr[first++];
		}
		sortNum<last?sortedArr[last] = pivot :sortedArr[sortNum] =pivot;
		for (int i = start;i < end;i++) givenArr[i] = sortedArr[i];
	}
	return sortNum;
}

void quickSort(int start, int end) {
	if (start < end) {
		int pivotPos = partition(start, end);
		cout << endl;
	for (int i = 0; i < 15; i++) cout << sortedArr[i] << " ";
		quickSort(start, pivotPos - 1);
		quickSort(pivotPos + 1, end);
	}

}

int main() {
	int n;
	cout << "1~100의 숫자를 입력해주세요: ";
	cin >> n;
	for (int i = 0; i < n; i++) givenArr[i] = rand() % 100;
	for (int i = 0; i < n; i++) cout << givenArr[i] << " ";
	quickSort(0, n-1);
	cout << "\n";
	for (int i = 0; i < n; i++) cout << sortedArr[i] << " ";
	return 0;
}