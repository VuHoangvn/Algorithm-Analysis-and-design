#include <iostream>
#include <limits>

using namespace std;

int start = 0;
int stop = 0;
int st = 0;

int maximumSumSubarray(int arr[], int n)
{
    int min_prefix_sum = 0;
    int current_sum;
    int res = numeric_limits<int>::min();

    int prefix_sum[n];
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];

    for (int i = 0; i < n; i++)
    {
        current_sum = prefix_sum[i] - min_prefix_sum;
        if(res < current_sum){
            res = current_sum;
            stop = i;
            st = start+1;
        }
        // res = max(res, prefix_sum[i] - min_prefix_sum);
        if(min_prefix_sum > prefix_sum[i]){
            min_prefix_sum = prefix_sum[i];
            start = i;
        }
        // min_prefix_sum = min(min_prefix_sum, prefix_sum[i]);
    }

    return res;
}

void readData(int arr[], long num)
{
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
}

int arr[1000006];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    // Test case 1
    long num;
    cin >> num;
    readData(arr, num);
    cout << maximumSumSubarray(arr, num) << endl;
    cout << "start: " << st << endl;
    cout << "stop: " << stop << endl;

    return 0;
}