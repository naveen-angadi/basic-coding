#include<iostream>

using namespace std;


/* Time Ø(n) */
int powerNaive(int x, int n)
{
    int res = 1;
    for(int i=0; i<n; i++)
    {
        res = res * x;
    }
    return res;
}

/*
Efficient Solution (Recursive)
if (n%2 == 0) { power(x, n/2) * power(x, n/2) }
else { power(x, n-1) * x }

Time : O(log(n))
*/
int powerEfficient(int x, int n)
{
    if(n==0) {
        return 1;
    }
    int temp = powerEfficient(x, n/2);
    temp = temp * temp;
    if(n%2 == 0) {
        return temp;
    } else {
        return temp*x;
    }
}


/* 
Iterative Power (Binary Exponentiation)
*/
/* Time : O(log(n))
*/
int powerEfficientIterative(int x, int n)
{
    int res = 1;
    while (n > 0) {
        if (n & 1)  // n%2 != 0
        {
            res = res * x;
        } 
        x = x * x;
        n = n >> 1; // n = n/2; 
    }
    return res;
}


int main()
{
    cout << powerEfficient(3, 5) << endl;
    cout << powerEfficientIterative(4, 5) << endl;
}