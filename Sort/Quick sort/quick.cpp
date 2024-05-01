#include <iostream>
#include <stdlib.h>
using namespace std;



void quick_sort(int arr[], int l, int r);
int partition1(int arr[], int l, int r);
int partition2(int arr[], int l, int r);
void swap(int &a, int &b);
void output(int arr[], int size);
int main(){
    int size = 11;
    int arr[11] = {11, 4, 5, 7 ,9, 2, 1, 6, 3, 10, 8};

    quick_sort(arr, 0, size-1);

    output(arr, size);

    system("echo. &pause");
    return 0;
}
//Hoare partition
int partition1(int arr[], int l, int r){
    int p = arr[l];
    int i = l, j = r;
    while(true){
        while(arr[i] < p) ++i;
        while(arr[j] > p) --j;
        if(i < j){
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }else{
            return j;
        }
    }
}
//lomuto
int partition2(int arr[], int l, int r){
    int p = arr[r];
    int i = l-1;
    for (int j = l; j < r; j++){
        if(arr[j] <= p){
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    ++i;
    swap(arr[i], arr[r]);
    return i;
}

void quick_sort(int arr[], int l, int r){
    if (l >= r) return;
    int p = partition2(arr, l, r);
    quick_sort(arr, l, p-1);
    quick_sort(arr, p+1, r);
}

void swap(int &a, int &b){
    if(a == b) return;
    a += b;
    b = a - b;
    a = a - b;
}

void output(int arr[], int size){
    for (int i = 0; i < size; i++){
            cout << arr[i] << " "; 
        }
}