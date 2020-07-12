#include <iostream>

using namespace std;



#define number 100
int sortedArr[number];
int givenArr[number];


void merge(int low, int mid, int high) {

  int i = low;
  int j = mid + 1;
  int k = low;

  while (i <= mid && j <= high) {
    if (givenArr[i] < givenArr[j]) {
      sortedArr[k++] = givenArr[i++];
    }
    else {
      sortedArr[k++] = givenArr[j++];
    }
  }

  if (i >= mid) 
    while (j <= high) sortedArr[k++] = givenArr[j++];
  
  

  if (j >= high) 
    while (i <= mid) sortedArr[k++] = givenArr[i++];
    
  for (int i = low; i <= high; i++) givenArr[i] = sortedArr[i];
}



void printArr(int a[], int n) {
  for (int i = 0; i < n; i++) cout <<a[i]<<" ";
}

void mergeSort(int low, int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, mid, high);
  }
}

int main(int argc, char* argv[]) {
  int i, n;

  cout << "몇개의 숫자로 정렬하시겠습니까?\n";
  cin >> n; 

  for (int i = 0; i < n; i++)
    givenArr[i] = rand() % 1000;

  cout<<"정렬전 배열 : ";
  printArr(givenArr, n);

  mergeSort(0, n - 1);

  cout<<"정렬후 배열 : ";
  printArr(givenArr, n);

  return 0;

}