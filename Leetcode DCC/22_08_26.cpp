#include <iostream>
#include <vector>
using namespace std;

bool checkDivisibility(int n)
{
    int temp = n;
    int sum = 0;
    int product = 1;

    while (temp != 0)
    {
        int dig = temp % 10;

        sum = sum + dig;
        product = product * dig;

        temp = temp / 10;
    }

    int val = sum + product;

    return ((n % val)==0);
}

int main()
{

    cout << checkDivisibility(99) << endl;
    cout << checkDivisibility(10) << endl;
    cout << checkDivisibility(97) << endl;
    cout << checkDivisibility(23) << endl;

    return 0;
}