#include<iostream>

using namespace std;

long factNum(int n)
{
    int fact = 1;

    for(int i = 2; i<=n; i++) {
        fact = fact*i;
    }
    return fact;
}

long recFactNum(int n) 
{
    if(n == 1)
        return n;
    
    return n * recFactNum(n-1);
}

/*Overflow issue in this logic for heigher value*/
int trailingZeroInFact(int n) 
{
    int count = 0;
    long fact = factNum (n);
    while(fact%10 == 0) {
        count++;
        fact = fact/10;
    }
    return count;
}

/* Efficient Method
   5th Form factor method
*/
int trailingZeroInFactWith5(int n) 
{
    int count = 0;
    long fact = factNum (n);
    for(int i=5; i<=n; i=i*5)
    {
        count += n/i;

    }
    return count;
}


int main()
{
    cout << "Factorial of Num " << factNum(4) << endl;
    cout << "Factorial of Num " << recFactNum(5) << endl;
    cout << "Trailing Zeros in Fact " << trailingZeroInFact(10) << endl;
    cout << "Trailing Zeros with 5th form factor in Fact " << trailingZeroInFactWith5(25) << endl;

}
