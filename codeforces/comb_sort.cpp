#include <iostream>
#include <algorithm>

using namespace std;

void swap(float *a, float *b)
{
    float t  = *a;
    *a = *b;
    *b = t;
}

// comb sort
int next_gap(int n){
    n = (n*10)/13;
    if(n < 1){
        return 1;
    }
    return n;
}

void combSort(float arr[], int n){
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

int main(){
    int n;
    scanf("%d", &n);
    float *arr = new float[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        scanf("%f", &arr[i]);
    }

    combSort(arr, n / 2);
    FILE *fp;
    fp = fopen("input.txt", "w");
    for (int i = 0; i < n / 2; i++)
    {
        fprintf(fp, "%f ", arr[i]);
    }

    fclose(fp);
    delete arr;
    int remain = n - n/2;
    arr = new float[remain];
    for (int i = 0; i < remain; i++)
    {
        scanf("%f", &arr[i]);
    }

    combSort(arr, remain);
    fp = fopen("input.txt", "r");
    float temp;
    int i = 0;
    while (1)
    {
        if( i >= remain)
            break;

        if (fscanf(fp, "%f", &temp) == -1)
        {
            break;
        }
        
        if (temp <= arr[i])
        {
            printf("%.2f ", temp);
        }
        else
        {
            while (temp > arr[i] && i < remain)
            {
                printf("%.2f ", arr[i]);
                i++;
            }
            printf("%.2f ", temp);
        }
    }

    while(fscanf(fp, "%f", &temp) != -1){
        printf("%.2f ", temp);
    }

    while (i < remain)
    {
        printf("%.2f ", arr[i]);
        i++;
    }
    fclose(fp);
    return 0;
}