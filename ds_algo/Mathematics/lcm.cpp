#include<iostream>

using namespace std;

int lcmNaive(int a, int b)
{
    int res = max(a, b);
    while(true) {
        if(res%a == 0 && res%b == 0) {
            return res;
        }
        res++;
    }
    return res;
}

// Moduler Division 
int modulerDivisionGCD(int a, int b)
{
    if(b == 0) return a;
    return modulerDivisionGCD(b, a%b);
}

/* Formula : a*b = gcd(a, b) * lcm(a, b)
*/
int efficientLCM(int a, int b)
{ 
    return ((a*b)/modulerDivisionGCD(a, b));
}

int main()
{
    cout << "LCM : " << lcmNaive(7, 6) << endl;
    cout << "LCM : " << efficientLCM(4, 6) << endl;
}