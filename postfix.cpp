//--------------------------------------------------------------------
//
//   postfix.cpp
// 
//  postfix file to evaluate the postfix form of an expression
//  and print the results to the screen. Assumes the expression consists
//  of integers from '0' to '9'.
//
//--------------------------------------------------------------------

#include "StackLinked.cpp"
#include <iostream>

int evaluateExponent(int base, int power);

int main()
{
	bool endprogram = 0;
	while (endprogram == 0)
	{
		// variable declarations
		string postfix;
		StackLinked<int> operandStack; // takes operands and results for postfix evaluatino
		char nextcharacter; // holds the next character to be processed
		int lhs, rhs; // left hand side, right hand side
		int result; // holds all operation results. Works with operandStack
		cout << "This program evaluates postfix form: " << endl;
		cout << "Give me a postfix expression to evaluate separated by spaces" << endl;
		getline(cin, postfix);
		while (!postfix.empty()) // ends when all postfix characters have been processed
		{
			nextcharacter = postfix.front(); // pushes front of string
			postfix.erase(0, 1); // deletes front of string

			switch (nextcharacter)
			{
			case '0': case '1': case '2': case '3': case '4': // variable cases
			case '5': case '6': case '7': case '8': case '9':
				operandStack.push(nextcharacter - '0'); // difference in ascii values represents proper int
				break;
			case '+':   // operator cases
				rhs = operandStack.pop(); // rhs assigned first by postfix precedence
				lhs = operandStack.pop();
				result = lhs + rhs;
				operandStack.push(result); // pushes result as new operand
				break;
			case '-':
				rhs = operandStack.pop();
				lhs = operandStack.pop();
				result = lhs - rhs;
				operandStack.push(result);
				break;
			case '*':
				rhs = operandStack.pop();
				lhs = operandStack.pop();
				result = lhs * rhs;
				operandStack.push(result);
				break;
			case '/':
				rhs = operandStack.pop();
				lhs = operandStack.pop();
				result = lhs / rhs;
				operandStack.push(result);
				break;
			case '^':
				rhs = operandStack.pop(); // acts as power raised
										  // lhs acts as the base 
				lhs = operandStack.pop();
				result = evaluateExponent(lhs, rhs);
				operandStack.push(result);
				break;
			default : break; // takes empty cases
			} // end switch
		} // end while

		cout << "The result: " << result << endl;
		operandStack.clear();
		cout << "Would you like to restart the program? Type 0 for yes, 1 for no." << endl;
		cin >> endprogram;
		cin.ignore();
	}
	
	return 0;
}

int evaluateExponent(int base, int power) // recursive function to evaluate exponent
{
	if (power != 0)
		return (base * evaluateExponent(base, power - 1));
	else
		return 1;
}