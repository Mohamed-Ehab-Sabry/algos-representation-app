#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>

using namespace std;

int seqSearch(int arr[], int n, int x)
{
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int recSeqSearch(int arr[], int n, int x)
{
    if (n == -1)
        return -1;
    if (arr[n] == x)
        return n;
    return recSeqSearch(arr, n - 1, x);
}

int binarySearch(int arr[], int n, int x)
{
    int l = 0, r = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int recBinarySearch(int arr[], int l, int r, int x)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        return recBinarySearch(arr, mid + 1, r, x);
    else
        return recBinarySearch(arr, l, mid - 1, x);
}

void test_search_functions()
{
    cout << string(80, '=') << endl;
    cout << setw(40) << "**SEARCH FUNCTIONS TEST**" << endl;
    cout << string(80, '=') << endl;

    // unsorted array for sequential search tests
    int unsorted[] = {7, 3, 5, 1, 9, 4};
    int n_unsorted = sizeof(unsorted) / sizeof(unsorted[0]) - 1; // last index

    cout << setw(30) << "SEQUENTIAL SEARCH (unsorted)" << endl;
    cout << string(80, '-') << endl;

    // present element
    int idx = seqSearch(unsorted, n_unsorted, 5);
    cout << "seqSearch for 5 -> " << idx << " (expected 2)" << endl;
    assert(idx == 2);

    idx = recSeqSearch(unsorted, n_unsorted, 5);
    cout << "recSeqSearch for 5 -> " << idx << " (expected 2)" << endl;
    assert(idx == 2);

    // absent element
    idx = seqSearch(unsorted, n_unsorted, 8);
    cout << "seqSearch for 8 -> " << idx << " (expected -1)" << endl;
    assert(idx == -1);

    idx = recSeqSearch(unsorted, n_unsorted, 8);
    cout << "recSeqSearch for 8 -> " << idx << " (expected -1)" << endl;
    assert(idx == -1);

    cout << string(80, '=') << endl;

    // sorted array for binary search tests
    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n_sorted = sizeof(sorted) / sizeof(sorted[0]) - 1; // last index

    cout << setw(30) << "BINARY SEARCH (sorted)" << endl;
    cout << string(80, '-') << endl;

    // edges and middle
    idx = binarySearch(sorted, n_sorted, 1);
    cout << "binarySearch for 1 -> " << idx << " (expected 0)" << endl;
    assert(idx == 0);

    idx = binarySearch(sorted, n_sorted, 9);
    cout << "binarySearch for 9 -> " << idx << " (expected 8)" << endl;
    assert(idx == 8);

    idx = binarySearch(sorted, n_sorted, 5);
    cout << "binarySearch for 5 -> " << idx << " (expected 4)" << endl;
    assert(idx == 4);

    idx = recBinarySearch(sorted, 0, n_sorted, 5);
    cout << "recBinarySearch for 5 -> " << idx << " (expected 4)" << endl;
    assert(idx == 4);

    // absent element
    idx = binarySearch(sorted, n_sorted, 10);
    cout << "binarySearch for 10 -> " << idx << " (expected -1)" << endl;
    assert(idx == -1);

    idx = recBinarySearch(sorted, 0, n_sorted, 10);
    cout << "recBinarySearch for 10 -> " << idx << " (expected -1)" << endl;
    assert(idx == -1);

    cout << string(80, '=') << endl;
    cout << "All search function tests passed successfully!" << endl;
    cout << string(80, '=') << endl;
}

int main()
{
    test_search_functions();
    return 0;
}