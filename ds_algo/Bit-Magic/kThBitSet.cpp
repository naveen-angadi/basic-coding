#include<iostream>

using namespace std;


void kThBitSite(int n, int k)
{
#if 0
    /* Left Shift*/
    if((n & (1 << (k-1))) != 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl; 
    }
#else
    /* Right Shift */
    if((n >> (k-1)) & 0x1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl; 
    }
#endif
}



/* Count Set Bit*/

int countSetBitNive(int n)
{
    int count = 0;
    int bits = sizeof(n)*8;
    while(n > 0) 
    {
        count += n&1;
        n = n >> 1;
    }
    return count;
}

int countBitsBrainKerningam(int n) {
    int count = 0;
    while(n > 0) {
        n = n & (n-1);
        count++;
    }
    return count;
}

/* Lookup Table Method*/

int table[256];

void initTable()
{
    table[0] = 0;
    for(int i=1; i<256; i++){
        table[i] = (i&1) + table[i/2];
    }
}

int countBitsLookupTable(int n) {
    int count = 0;
    int bytes = sizeof(n);
    while(bytes) {
        count += table[n & 0xFF];
        n = n >> 8;
        bytes--;
    }
    return count;
}


int main() {
    initTable();
    kThBitSite(5, 1);
    cout << "Count set bits " << countSetBitNive(2) << endl;
    cout << "Count set bits " << countBitsBrainKerningam(126) << endl;
    cout << "Count set bits " << countBitsLookupTable(7) << endl;
    return 0;
}