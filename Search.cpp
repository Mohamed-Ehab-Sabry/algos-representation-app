#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>

using namespace std;


int seqCounter; 

int seqSearch(int arr[], int n, int x)
{
    for (int i = 0; i <= n; i++)
    {
        seqCounter++; 
        if(arr[i] == x)
            return i;
    }
    return -1;
}


int rSeqCounter; 

int recSeqSearch(int arr[], int n, int x)
{
    rSeqCounter++; 
    if (n == -1)
        return -1;
    if (arr[n] == x)
        return n;
    return recSeqSearch(arr, n - 1, x);
}




int binaryCounter; 

int binarySearch(int arr[], int n, int x)
{
    int l = 0, r = n;
    while (l <= r)
    {
        binaryCounter++; 
        int mid = l + (r - l) /2;
        if(arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}




int rBinaryCounter; 

int recBinarySearch(int arr[], int l, int r, int x)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) /2;
    rBinaryCounter++; 
    if(arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        return recBinarySearch(arr, mid + 1, r, x);
    else
        return recBinarySearch(arr, l, mid-1, x);
}




int main()
{
    const int SIZE = 50;
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i)
        arr[i] = i + 1; 

    int choice = 0;
    while (true)
    {
        cout << "\nArray:\n";
        for (int i = 0; i < SIZE; ++i)
        {
            cout << arr[i] << (i % 10 == 9 ? '\n' : ' ');
        }

        cout << "\nChoose search method:\n"
             << "1. Sequential Search (iterative)\n"
             << "2. Sequential Search (recursive)\n"
             << "3. Binary Search (iterative)\n"
             << "4. Binary Search (recursive)\n"
             << "5. Exit\n"
             << "Enter choice: ";
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        if (choice == 5)
            break;
        if (choice < 1 || choice > 5)
        {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        int x;
        cout << "Enter number to search: ";
        if (!(cin >> x))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        int result = -1;
        switch (choice)
        {
            case 1:
                seqCounter = 0;
                result = seqSearch(arr, SIZE - 1, x);
                cout << "seqSearch entered: " << seqCounter << " times\n";
                break;
            case 2:
                rSeqCounter = 0;
                result = recSeqSearch(arr, SIZE - 1, x);
                cout << "recSeqSearch entered: " << rSeqCounter << " times\n";
                break;
            case 3:
                binaryCounter = 0;
                result = binarySearch(arr, SIZE - 1, x);
                cout << "binarySearch entered: " << binaryCounter << " times\n";
                break;
            case 4:
                rBinaryCounter = 0;
                result = recBinarySearch(arr, 0, SIZE - 1, x);
                cout << "recBinarySearch entered: " << rBinaryCounter << " times\n";
                break;
        }

        if (result != -1)
            cout << "Number found at index: " << result << '\n';
        else
            cout << "Number not found\n";
    }

    cout << "Exiting.\n";
    return 0;
}