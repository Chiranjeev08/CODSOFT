#include <iostream>
using namespace std;

int main()
{
    float a, b;
    char ch;

    cout << "===== SIMPLE CALCULATOR =====" << endl;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter operator (+,-,*,/): ";
    cin >> ch;

    cout << "Enter second number: ";
    cin >> b;

    if(ch == '+')
    {
        cout << "Answer = " << a + b;
    }
    else if(ch == '-')
    {
        cout << "Answer = " << a - b;
    }
    else if(ch == '*')
    {
        cout << "Answer = " << a * b;
    }
    else if(ch == '/')
    {
        if(b == 0)
        {
            cout << "Division by zero is not possible";
        }
        else
        {
            cout << "Answer = " << a / b;
        }
    }
    else
    {
        cout << "Invalid Operator";
    }

    return 0;
}