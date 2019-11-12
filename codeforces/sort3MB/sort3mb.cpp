#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    float *arr = new float[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        scanf("%f", &arr[i]);
    }

    sort(arr, arr + n / 2);
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

    sort(arr, arr + remain);
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