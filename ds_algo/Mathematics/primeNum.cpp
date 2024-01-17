#include<iostream>

using namespace std;

//Prime Number  : 2, 3, 7, 11, 13, 17, 19 ...
//Composite Number : 4, 5, 6, 8, 9, 10 .....


bool isPrimeNive(int n)
{
    if(n <= 1) {
        return false;
    }
    for(int i=2; i<n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}


/* Time : O(sqr(n))*/
bool isPrimeEfficient(int n)
{
    if(n <= 1) {
        return false;
    }
    for(int i=2; (i*i)<=n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

/* Time : O(sqr(n))*/
bool isPrimeMoreEfficient(int n)
{
    if(n <= 1) {
        return false;
    }
    if(n == 2 || n == 3) {
        return true;
    }

    if(n%2 == 0 || n%3 == 0) {
        return false;
    }
    
    for(int i=5; (i*i)<=n; i=i+6) {
        if(n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

/***** Prime Factor *******/
void primeFactorsNive(int n) {
    for(int i=2; i<n; i++) {
        if(isPrimeMoreEfficient(i)) {
            int x = i;
            while(n%x == 0) {
                cout << i << " " << endl;
                x = x*i;
            }
        }
    }
}


/***** Prime Factor *******/
void primeFactorsEfficient(int n) {
    if(n <= 1) {
        return;
    }
    for(int i=2; (i*i)<=n; i++) {
        while(n%i == 0) {
             cout << i << " ";
             n = n/i;
        }
    }
    if(n > 1) {
        cout << n << endl;
    } else {
        cout << endl;
    }
}

/***** Prime Factor *******/
void primeFactorsMoreEfficient(int n) {
    if(n <= 1) {
        return;
    }
    while(n%2 == 0) {
        cout << 2 << " ";
        n = n/2;
    }

    while(n%3 == 0) {
        cout << 3 << " ";
        n = n/3;
    }

    for(int i=5; (i*i)<=n; i = i+6) {
        while(n%i == 0) {
             cout << i << " ";
             n = n/i;
        }
        while(n%(i+2) == 0) {
            cout << (i+2) << " ";
            n = n/(i+2);
        }
    }
    if(n > 1) {
        cout << n << endl;
    } else {
        cout << endl;
    }
}

/* Simple Implementation */
void sieveOfEratosthense(int n) {
    vector <bool> isPrime(n+1, true);

    for(int i=2; i*i<=n; i++) {
        if(isPrime[i]) {
            for(int j=2*i; j<=n; j=j+i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

/* Efficient Implementation 
Time : O{log log n} */
void sieveOfEratosthenseEfficient(int n) {
    vector <bool> isPrime(n+1, true);

    for(int i=2; i<=n; i++) { /* Loop normally with i<=n */
        if(isPrime[i]) {
            cout << i << " ";  /* Print the prime */
            for(int j=i*i; j<=n; j=j+i) {  /* relpace j=2*i to j=i*i */
                isPrime[j] = false;
            }
        }
    }
    cout << endl;
}


int main()
{
    //cout << "is Prime : " << isPrimeNive(65) << endl;
    //cout << "is Prime : " << isPrimeEfficient(37) << endl;
    //primeFactorsNive(24);
    //primeFactorsEfficient(84);
    //primeFactorsMoreEfficient(450);
    sieveOfEratosthense(9);
    sieveOfEratosthenseEfficient(16);
    return 0;
}