// usestack.cpp 
// Luis Valdivia, 10 Nov. 2018

#include "intstack.h"
#include <iostream>
using namespace std;

int main() {
    // evaluating "4 5 * 3 +"

    // start with an empty stack
    Stack numbers;

    // first two tokens all numbers to push "4 5":
    numbers.push(4);
    numbers.push(5);

    // third token is calculation to do "*":
    int right = numbers.top();
    numbers.pop();
    int left = numbers.top();
    numbers.pop();
    numbers.push(left * right);

    // fourth token is number to push "3":
    numbers.push(3);

    // last token is another calculation "+":
    right = numbers.top();
    numbers.pop();
    left = numbers.top();
    numbers.pop();
    numbers.push(left + right);

    // done - print result:
    cout << numbers.top() << endl;

    return 0;
}