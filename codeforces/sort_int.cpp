#include<iostream>

using namespace std;

void swap(int *a, int*b)
{
    int t  = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for(int j= low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+ 1;
}
int * quick_sort(int arr[], int low, int high){
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

// comb sort
int next_gap(int n){
    n = (n*10)/13;
    if(n < 1){
        return 1;
    }
    return n;
}

void combSort(int arr[], int n){
    int gap = n;
    bool swapped = true;

    while(gap != 1 || swapped == true){
        gap = next_gap(gap);
        swapped = false;
        for(int i = 0; i < n-gap; i++){
            if(arr[i] > arr[i+gap]){
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void printArray(int arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        cout<<arr[i] << " ";
    }
}
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    // quick_sort(arr, 0, n-1);
    combSort(arr, n);
    printArray(arr, n);
    return 0;
}