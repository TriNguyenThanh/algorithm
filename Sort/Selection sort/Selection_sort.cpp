#include <iostream>
using namespace std;

void tris_sort(int *arr, int l, int r);
int imin(int *arr,int l, int r);
void swap(int &a, int &b);
void output(int *arr, int size);

int main(){
    int size = 11;
    int arr[11] = {11, 4, 5, 7 ,9, 2, 1, 6, 3, 10, 8};

    tris_sort(arr, 0, size-1);
    output(arr, size);

    system("echo. &pause");
    return 0;
}

void tris_sort(int *arr, int l, int r){
    if(l >= r) return;
    int i = imin(arr, l, r);
    swap(arr[i], arr[l]);
    tris_sort(arr, l+1, r);
}

int imin(int *arr, int l, int r){
    int min = arr[l];
    int idex_min = l;
    for (int i = l+1; i <= r; i++){
        if(arr[i] < min){
            min = arr[i];
            idex_min = i;
        }
    }

    return idex_min;
}

void swap(int &a, int &b){
    if(a == b) return;
    a += b;
    b = a - b;
    a = a - b;
}

void output(int *arr, int size){
    for (int i = 0; i < size; i++){
            cout << arr[i] << " "; 
        }
}