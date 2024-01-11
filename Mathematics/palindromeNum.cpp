#include<iostream>

using namespace std;

bool isPalindromeNum(int num)
{
    int rev = 0;
    int temp = num;
    while(temp != 0) {
        rev = (rev*10) + (temp%10);
        temp = temp/10;
    }
    
    return (rev == num);
}

int main()
{
    cout << "is PalindromeNum : " << isPalindromeNum(12321) << endl;
    return 0;
}