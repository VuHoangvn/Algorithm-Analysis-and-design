#include <bits/stdc++.h>

using namespace std;

bool is_even(int n)
{
    return n % 2 == 0;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int min_even = 0;
    int min_odd = 0;
    int sum_even = 0;
    int sum_odd = pow(10, 6);
    int sum[n];
    int result[n];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (!is_even(sum[i]))
        {
            if (sum_odd != pow(10, 6))
            {
                result[i] = sum[i] - sum_odd;
            }
            sum_odd = min(sum_odd, sum[i]);
        }

        if (is_even(sum[i]))
        {
            result[i] = sum[i] - sum_even;
            sum_even = min(sum_even, sum[i]);
        }
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        if(max < result[i])
            max = result[i];
    }

    if(n == 1 && !is_even(arr[0]))
        cout << -pow(10, 6);
    else
    {
        cout << max;
    }
    
}