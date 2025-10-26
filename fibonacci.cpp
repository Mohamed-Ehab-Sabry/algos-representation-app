#include <iostream>

#define ll long long
using namespace std;

ll rec_fib(ll num)
{
    if (num < 0)
    {
        cerr << "Can not get the value at a negative position !!" << endl;
        cerr << "Terminating" << endl;
        return 0;
    }
    if (num < 2)
    {
        return num;
    }
    return rec_fib(num - 1) + rec_fib(num - 2);
}

ll int main()
{
    ll num;
    cout << "Hello dear user, please enter the order of the fib num you want to calc: ";
    cin >> num;
    cout << rec_fib(num);
}