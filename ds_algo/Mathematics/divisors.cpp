#include<iostream>

using namespace std;

/* Time: Ø (n)*/
void printDivisorsNaive(int n)
{
    for(int i=1; i<=n; i++) {
        if(n%i == 0) cout << i << " ";
    }
    cout << endl;
    return;
}

/* Efficient Solution*/
void printDivisorsEfficient(int n)
{
    for(int i=1; i*i<=n; i++) {
        if(n%i == 0) {
            cout << i << " ";
            if(i != n/i) {
                cout << (n/i) << " ";
            }
        }
    }
    cout << endl;
    return;
}

/* Efficient Solution*/
void printDivisorsEfficientSorted(int n)
{
    int i;
    for(i=1; i*i<=n; i++) {
        if(n%i == 0) {
            cout << i << " ";
        }
    }
    for( ; i>=1; i--) {
        if(n%i == 0 && i != n/i) {
            cout << n/i << " ";
        }
    }
    cout << endl;
    return;
}

int main() 
{
    printDivisorsNaive(6);
    printDivisorsEfficient(25);
    printDivisorsEfficientSorted(25);
    printDivisorsEfficientSorted(15);
}
