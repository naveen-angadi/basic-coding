#include<iostream>

using namespace std;


/* Time O(min(a,b)) */
int gcdNaive(int a, int b)
{
    int res = min(a, b);
    while (res > 0)
    {
        if(a%res == 0 && b%res == 0) {
            break;
        }
        res--;
    }
    return res;
}

int euclideanGCD(int a, int b) 
{
    while (a!=b) {
        if(a > b) { a = a-b; } 
        else { b = b-a; }
    }
    return a;
}

// Moduler Division 
int modulerDivisionGCD(int a, int b)
{
    if(b == 0) return a;
    return modulerDivisionGCD(b, a%b);
}

int main()
{
    cout << "GCD : " << gcdNaive(10, 15) << endl;
    cout << "GCD : " << euclideanGCD(12, 36) << endl;
    cout << "GCD : " << modulerDivisionGCD(8, 6) << endl;
    return 0;
}