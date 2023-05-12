#include <iostream>
using namespace std;

void merge(int array[], int left, int mid, int right){
    int array1 = mid - left + 1;
    int array2 = right - mid;
    int *l = new int[array1], *r = new int[array2];
    for (int i = 0; i < array1; i++) l[i] = array[left + i];
    for (int j = 0; j < array2; j++) r[j] = array[mid +1+ j];
    int i = 0, j = 0, k = left;
    while (i < array1 && j < array2){
        if (l[i] <= r[j]){
            array[k] = l[i];
            i++;
        }
        else{
            array[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < array1){
        array[k] = l[i];
        i++;
        k++;
        while (j < array2){
            array[k] = r[j];
            j++;
            k++;
        }
        delete[] l;
        delete[] r;
    }
}
void mergeSort(int array[], int const begin, int const end){
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void printArray(int A[], int size){
    for (auto i = 0; i < size; i++) cout << A[i]<< " ";
}
int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, arr_size - 1);
    printArray(arr, arr_size);
    return 0;
}
