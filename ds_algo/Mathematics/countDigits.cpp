#include<iostream>
#include<math.h>
using namespace std;

/* Itterative Solution*/
int countDigit(long n)
{
    int count = 0;
    long temp = n;
    if (n < 0) return 0;
    while(temp != 0) {
	count++;
        temp = temp/10;
    }
    return count;
}

/* Recursive Solution */
int recCountDigit(long n) 
{
    if(n == 0) {
        return 0;
    }
    return 1+recCountDigit(n/10);
}

/* Log Solution */
int logCountDigit(long n) 
{
    return floor(log10(n))+1;
}


int main() 
{
    cout<< countDigit(0) << endl;
    cout<< recCountDigit(12345678) << endl;
    cout<< logCountDigit(123456780) << endl;
}
