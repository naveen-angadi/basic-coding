#include<iostream>

using namespace std;

/* C++ Program for the binary 
 * representation of a given number
 */
void printBit(short n) 
{   int space = 0;
    int noBits = (sizeof(n)*8);
    cout << "0";
    for(int i = (0x1 << (noBits-2)); i>0; i = i>>1) {
        space++;
        if(space%4 == 0) cout << " ";
        if((n & i) != 0) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
}

int main()
{
    int x = 3, y =6;
    cout << "Bit-Magic" << endl;
    cout << "x = " << x << " ==> ";
    printBit(x);
    cout << "y = " << y << " ==> ";
    printBit(y);
    cout << " AND & " << (x&y) << " ==> ";
    printBit(x&y);
    cout << " OR | " << (x|y) << " ==> ";
    printBit(x|y);
    cout << " XOR ^ " << (x^y) << " ==> ";
    printBit(x^y);

    return 0;
}