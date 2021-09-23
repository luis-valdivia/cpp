// triangles.cpp - more recursive print functions
// Luis Valdivia, 30 Nov. 2018

#include <iostream>
using namespace std;

// recursively prints n asterisks ('*') on one line to cout
void stars(int n) {
    if(n > 0){
	cout << "*";
	stars(n-1);
    }
}

// recursively prints rows of '*', first n, then n-1, ... 1
void triangle(int n) {
    if(n > 0)
        stars(n);
    else
	return;
    if(n > 0)
	cout << endl;
	triangle(n-1);
}

// recursively prints rows of '*' in reverse: 1, 2, ... n
void rtriangle(int n) {
    if(n > 0)
	rtriangle(n-1);
    if(n > 0){
        stars(n);
        cout << endl;
    }
    else
	return;
}

int main() {
    int size;
    cout << "enter size: " << endl;
    cin >> size;

    triangle(size);
    rtriangle(size);

}