#include <iostream>
using namespace std;

void bubble_sort(int arr[], int sl);
void swap(int &a, int &b);
void print_array(int array[], int n);

void tong(int a, int b){
    a = 0;
    b = 0;
}

int main()
{
    int arr[11] = {11, 4, 5, 7 ,9, 2, 1, 6, 3, 10, 8};
    int n = 11;

    bubble_sort(arr, n);
    print_array(arr, n);

    system("echo. &pause");
    return 0;
}
void bubble_sort(int arr[], int sl)
{
    for(int i = 0; i < sl-1; i++){
        for(int j = i+1; j < sl; j++){
            if (arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void swap(int &a, int &b){
    a += b;
    b = a - b;
    a = a - b;
}

void print_array(int array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}