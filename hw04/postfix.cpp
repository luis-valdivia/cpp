//Kelly Wang && Luis Valdivia
//11.22.18
//Turn infix expression into postfix (without solving)

#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char>Stack;

void postfix(string input){
	for(int i = 0; i < input.length(); i++){
		if(input[i] == '(' || isspace(input[i]))
			; //do nothing
		//if input[i] is anything but an operator then print
		else if(isalnum(input[i]))
			cout << input[i] << " ";
		//When input is an operator then push on stack 
		else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			Stack.push(input[i]);
		//print the stack in order
		else{
			cout << Stack.top() <<  " ";
			Stack.pop();
		}
	}
	cout << endl;
	return; 
}


int main(){
	string input;
	cout << "Enter a fully parenthesized input expression with no spaces: " << endl;
	cin >> input;

	cout << "The equivalent postfix expression is: " << endl;
	postfix(input);
	return 0;
}
