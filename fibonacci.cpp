#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

#define ll long long

// Colors Format for console output
#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */

// Bold and underline text formats
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define SEPARATE cout << MAGENTA << setw(50) << setfill('-') << "" << RESET << endl;

using namespace std;

// Shared global counters used by both implementations
static unsigned ll fun_calls = 0;
static unsigned ll fun_cur_depth = 0;
static unsigned ll fun_max_depth = 0;

void reset_counters() { fun_calls = fun_cur_depth = fun_max_depth = 0; }
unsigned ll get_calls() { return fun_calls; }
unsigned ll get_max_depth() { return fun_max_depth; }

ll rec_fib(ll num)
{
    fun_calls++;
    fun_cur_depth++;
    if (fun_cur_depth > fun_max_depth)
    {
        fun_max_depth = fun_cur_depth;
    }

    if (num < 0)
    {
        cerr << "Can not get the value at a negative position !!" << endl;
        cerr << "Terminating" << endl;
        fun_cur_depth--;
        return 0;
    }
    if (num < 2)
    {
        fun_cur_depth--;
        return num;
    }
    return rec_fib(num - 1) + rec_fib(num - 2);
}

ll dp_fib_memo(ll n, vector<ll> &memo)
{

    fun_calls++;
    fun_cur_depth++;
    if (fun_cur_depth > fun_max_depth)
    {
        fun_max_depth = fun_cur_depth;
    }

    if (n <= 1)
    {
        fun_cur_depth--;
        return n;
    }

    if (memo[n] != -1)
    {
        fun_cur_depth--;
        return memo[n];
    }

    memo[n] = dp_fib_memo(n - 1, memo) + dp_fib_memo(n - 2, memo);

    fun_cur_depth--;
    return memo[n];
}

ll dp_fib(ll n)
{
    vector<ll> memo(n + 1, -1);

    return dp_fib_memo(n, memo);
}

ll MOD = 1e15 + 7;

void matrix_multiplication(vector<vector<ll>> &A, vector<vector<ll>> &B)
{

    fun_calls++;
    fun_cur_depth++;
    if (fun_cur_depth > fun_max_depth)
    {
        fun_max_depth = fun_cur_depth;
    }

    vector<vector<ll>> Result(2, vector<ll>(2));
    Result[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    Result[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    Result[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    Result[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
    // Copy the result back to the first matrix
    A[0][0] = Result[0][0];
    A[0][1] = Result[0][1];
    A[1][0] = Result[1][0];
    A[1][1] = Result[1][1];

    fun_cur_depth--;
}

vector<vector<ll>> binary_expo(vector<vector<ll>> matrix, int expo)
{
    fun_calls++;
    fun_cur_depth++;
    if (fun_cur_depth > fun_max_depth)
    {
        fun_max_depth = fun_cur_depth;
    }

    vector<vector<ll>> ans = {{1, 0}, {0, 1}};

    while (expo)
    {
        if (expo % 2 != 0) // expo & 1 (The LSB is 1 (an odd number))
            matrix_multiplication(ans, matrix);
        matrix_multiplication(matrix, matrix);
        expo /= 2; // expo =>> 1; (divide by 2 in both cases)
    }

    fun_cur_depth--;
    return ans;
}

// function to find the nth fibonacci number
ll matrix_fib(ll n)
{
    fun_calls++;
    fun_cur_depth++;
    if (fun_cur_depth > fun_max_depth)
    {
        fun_max_depth = fun_cur_depth;
    }

    if (n == 0 || n == 1)
    {
        fun_cur_depth--;
        return n;
    }

    vector<vector<ll>> transformation_matrix = {{1, 1}, {1, 0}};

    // Multiply matrix M (n - 1) times
    vector<vector<ll>> res = binary_expo(transformation_matrix, n - 1);

    // fun_cur_depth--;
    return res[0][0] % MOD;
}

// --- simple tests ---
void run_simple_asserts()
{
    // check known Fibonacci values
    reset_counters();
    assert(dp_fib(0) == 0);
    assert(dp_fib(1) == 1);
    assert(dp_fib(5) == 5);
    assert(dp_fib(10) == 55);

    reset_counters();
    assert(matrix_fib(0) == 0);
    assert(matrix_fib(1) == 1);
    assert(matrix_fib(5) == 5);
    assert(matrix_fib(10) == 55);
    // naive recursion only for small n
    reset_counters();
    assert(rec_fib(0) == 0);
    assert(rec_fib(1) == 1);
    assert(rec_fib(5) == 5);
    assert(rec_fib(10) == 55);

    cout << "Simple tests passed successfully.\n";
}
// --- end asserts ---

int main()
{
    reset_counters();
    ll num;

    run_simple_asserts();
    reset_counters();

    cout << "Hello dear user, please enter the order of the fib num you want to calc: ";
    cin >> num;
    cout << endl;
    SEPARATE
    cout << "The fibonacci number with the order " << GREEN << BOLD << num << RESET << " is " << BLUE << BOLD << rec_fib(num) << RESET << RED << " (done using naive approach)" << RESET << endl;
    cout << "it costed us " << BOLD << RED << get_calls() << RESET << " calls, and it reached a maximum recursion depth of " << BOLD << RED << get_max_depth() << RESET << endl
         << endl;
    SEPARATE
    reset_counters();
    cout << "The fibonacci number with the order " << GREEN << BOLD << num << RESET << " is " << BLUE << BOLD << dp_fib(num) << RESET << YELLOW << " (done using memoization (dynamic programming))" << RESET << endl;
    cout << "it costed us " << BOLD << RED << get_calls() << RESET << " calls, and it reached a maximum recursion depth of " << BOLD << RED << get_max_depth() << RESET << endl
         << endl;
    SEPARATE
    reset_counters();

    cout << "The fibonacci number with the order " << GREEN << BOLD << num << RESET << " is " << BLUE << BOLD << matrix_fib(num) << RESET << GREEN << " (done using matrix multiplication)" << RESET << endl;
    cout << "it costed us " << BOLD << RED << get_calls() << RESET << " calls, and it reached a maximum recursion depth of " << BOLD << RED << get_max_depth() << RESET << endl
         << endl;
    reset_counters();
}