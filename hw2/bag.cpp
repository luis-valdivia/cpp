#include<iostream>
#include "bag.h"
#include <cstdlib>
using namespace std;

bool operator == (bag& b1, bag& b2){
	if(size(b1) != size(b2))
		return false;
	sort(b1);
	sort(b2);
	for(int c = 0; c < size(b1); c++)
		if(b1.get_value(c) != b2.get_value(c))
			return false;
	return true;
}

int main(){
	
	return 0;
}

