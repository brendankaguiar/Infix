//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>
#include "StackLinked.cpp"


//--------------------------------------------------------------------

bool delimitersOk(const string &expression);
bool isPaired(char open, char closed);

//--------------------------------------------------------------------

int main()
{
	string inputLine;            // Input line
	char   ch;                   // Holding pen for input chars

	cout << "This program checks for properly matched delimiters."
		<< endl;

	while (cin)
	{
		cout << "Enter delimited expression (# to quit) : "
			<< endl;

		// Read in one line
		inputLine = "";
		cin.get(ch);
		while (cin && ch != '\n')
		{
			inputLine = inputLine + ch;
			cin.get(ch);
		}

		if (inputLine == "#")              // Input # discovered: stop processing
			break;

		if (delimitersOk(inputLine))
			cout << "Valid" << endl;
		else
			cout << "Invalid" << endl;
	}
	return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 2.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below
bool delimitersOk(const string &expression)
{
	StackLinked<char> openDelimiterStack;
	int characterCount = expression.length();
	bool isBalanced = true;
	int index = 0;
	char nextCharacter;

	while (isBalanced && (index < characterCount))
	{
		nextCharacter = expression.at(index);
		switch (nextCharacter)
		{
		case '(': case '[': case '{':
			openDelimiterStack.push(nextCharacter);
			break;
		case ')': case ']': case '}':
			if (openDelimiterStack.isEmpty())
				isBalanced = false;
			else
			{
				char openDelimiter = openDelimiterStack.pop(); // assignes popped delimiter
				isBalanced = isPaired(openDelimiter, nextCharacter); // checks pairing
			} // end if
			break;
		default:
			break;
		} // end switch
		index++;
	} // end while
	if (!openDelimiterStack.isEmpty()) // checks for unnaccounted for delimiters
		isBalanced = false;
	return isBalanced;
} // end delimitersOk


// Returns true if the given characters, open and close, form a
// pair of parentheses, brackets, or braces
bool isPaired(char open, char close)
{
	return (open == '(' && close == ')')
		|| (open == '[' && close == ']')
		|| (open == '{' && close == '}');
}; // end isPaired