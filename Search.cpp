#include <iostream>
using namespace std;

int seqSearch(int arr[], int n, int x)
{
    for (int i = 0; i <= n ; i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int recSeqSearch(int arr[], int n, int x)
{
    if (n == -1)
        return -1;
    if(arr[n] == x)
        return n;
    return recSeqSearch(arr, n-1, x);
}

int binarySearch(int arr[], int n, int x)
{
    int l = 0, r = n;
    while(l <= r)
    {
        int mid = l + (r - l) /2;
        if(arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

int recBinarySearch(int arr[], int l, int r, int x)
{
    if(l > r)
        return -1;
    int mid = l + (r - l) /2;
    if(arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        return recBinarySearch(arr, mid+1, r, x);
    else
        return recBinarySearch(arr, l, mid-1, x);
}

int main()
{
    

    return 0;
}