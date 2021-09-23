#include <iostream>
#include <ctime>
using namespace std;

int foo(int n){
	clock_t begin = clock();
	int sum = 0;
	for(int i = 1; i<n ; i *= 2)
			for(int j=1; j <= i ; j *= 2)
					++sum;
	clock_t end = clock();
	double diff = double(end - begin) / CLOCKS_PER_SEC;
	cout << diff << endl;
	return 0;
}
int main(){
	for(int i=10; i <= 10000; i *= 10)
			foo(i);
	return 0;
}
