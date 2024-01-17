#include <iostream>

using namespace std;


bool isPowerOfTwoNive(int n)
{
    if(n==0) {
        return false;
    }
    while (n!=1) {
        if(n%2 != 0) { 
            return false; 
        }
        n = n/2;
    }
    return true;
}

bool isPowerOfTwoEfficient(int n) {
    if(n<=0) {
        return false;
    }
    return ((n&(n-1))==0);
}


/**/

int main()
{
    cout << isPowerOfTwoNive(15) << endl;
    cout << isPowerOfTwoEfficient(7) << endl;
    return 0;
}