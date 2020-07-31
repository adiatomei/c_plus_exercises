#include <iostream>

using namespace std;

const int MAX = 8;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for(int i = i; i < n; i++)
    {
        if(mx < arr[i])
        {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for(i = 0; i < n; i++)
    {
        count[ (arr[i]/exp)%10 ]++;
    }

    for(i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for(i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for(i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }


}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    for(int exp = 1; m/exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Driver program to test above functions
int main()
{
    int arr[MAX] = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr, MAX);
    print(arr, MAX);
    return 0;
}
