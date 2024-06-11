#include <iostream>
#include "myStack.h"

using namespace std;

void postfixTest() {
	myStack operandStack(100);
	cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << endl;
	cout << "and enter '=' to indicate the end of the expression and to output the result." << endl;

	int num_count = 0;
    int operater_count = 0;

	while(1){
		char inputHolder;
		cin >> inputHolder;

		if (inputHolder >= '1' && inputHolder <= '9'){
            operandStack.push(inputHolder - '0');
            ++num_count;
		}else if (inputHolder == '+' || inputHolder == '-' || inputHolder == '*' || inputHolder == '/'){
            ++operater_count;
            int a = operandStack.pop();
            int b;
            int answer;

            if (!operandStack.isEmpty()){
                b = operandStack.pop();
            }else{
                cout << "Error! No sufficient operands." << endl;
                break;
            }

		    switch(inputHolder)
		    {
		        case '+':answer = a + b;
                         operandStack.push(answer);
                         break;
		        case '-':answer = b - a;
                         operandStack.push(answer);
                         break;
		        case '*':answer = a * b;
                         operandStack.push(answer);
                         break;
		        case '/':answer = b / a;
                         operandStack.push(answer);
                         break;
		    }
        }else{
		        int result = operandStack.pop();

		        if (operandStack.isEmpty() && operater_count == (num_count - 1)){
                    cout << "The entered post-fix expression results in " << result << endl;
                    break;
		        }else{
		            cout << "The entered post-fix expression was not a legal one." << endl;
		            break;
		        }
		    }
		}
}

int main()
{
    cout << "Testing the basic functions of the stack..." << endl;
	cout << "Please enter the max capacity of the testStack: ";
	int testSize;
	cin >> testSize;
	myStack testStack(testSize);

	cout << "Testing..." << endl;
	while(1) {
		cout << "Please enter 'p' for push, 'o' for pop, 'e' for exit:  ";
		char userChoice;
		cin >> userChoice;

		if(userChoice == 'e')
			break;

		switch (userChoice) {
			case 'p':
				if(!testStack.isFull()) {
					cout << "Please enter the integer you would like to push: ";
					int userInt;
					cin >> userInt;
					testStack.push(userInt);
				}
				else
					cout << "Nothing has been pushed in. The stack is full!" << endl;
				break;
			case 'o':
				if(!testStack.isEmpty())
					cout << testStack.pop() << " has been popped out" << endl;
				else
					cout << "Nothing has been popped out. The stack is empty!" << endl;
				break;
			default:
				cout << "Illegal user-input character. Please try again." << endl;
		}
	}

	cout << "Now, start to use a stack to evaluate postfix expressions..." << endl;
	postfixTest();

	return 0;
}

