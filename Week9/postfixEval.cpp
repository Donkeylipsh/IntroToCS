/***********************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/22/2017
** Description: postfixEval.cpp is a function that accepts a C-String postfix mathematical
**		expression and returns a double value equal to the evaluated expression
**********************************************************************************************/

#include <stack>
#include <vector>
#include <cctype>

double postfixEval(char postfix[]) {
    // postfix[] is the C-String postfix expression
    // infixEval is the mathematical evaluation of the C-String postfix expression
    // digits is a stack of doubles that holds all the numerical values of the expression
    // index is the index of the character being evaluated
    double infixEval;
    std::stack< double > digits;
    int index = 0;

    // Evaluate each character of postfix until the null terminater is reached 
    while (postfix[index] != '\0') {
        // Check if the current character is a digit
        if ( isdigit(postfix[index]) )
        {
            // If yes, add the digit to the digits stack

	    // nextIndex is the index of the next character 
	    int nextIndex = index + 1;

	    // Assign the integer value of the character at postfix[index] to someDouble
	    double someDouble = postfix[index] - 48;

	    // Check if the character at postfix[nextIndex] is a digit
	    while (isdigit(postfix[nextIndex]) ) {
	        // If yes, add the integer value of the character to someDouble
	        // Multiplying someDouble by 10 makes room for the next digit
	        someDouble = (someDouble * 10) + (postfix[nextIndex] - 48);

	        // Increment nextIndex 	
	        nextIndex++;
	    }

	    // Increment index for each digit added to someDouble
	    index = nextIndex - 1;

	    // Add someDouble to the digits stack
	    digits.push(someDouble);
        }
        else
        {
	    // If not, execute the operation

	    // left is the left operand
	    // right is the right operand 			
	    double left, right;

	    // matchOperator is the operator character  
	    char matchOperator = postfix[index];

	    // Check if matchOperator is a space
	    if (matchOperator != ' ') {
	        // If not, perform the operation

	        // Check if the digits stack is empty 
	        if (!digits.empty()) {
		    // If not, set the top value to left
		    right = digits.top();

		    // pop the top value off the stack
		    digits.pop();
	        }
	        else {
	            // If yes, exit the if block without performing the operation
	            break;
	        }

	        // Check if the digits stack is empty 
	        if (!digits.empty()) {
	            // If not, set the top value to right
	            left = digits.top();

	            // pop the top value off the stack
	            digits.pop();
	        }
	        else {
	            // If yes, exit the if block without performing the operation
	            break;
	        }

	        // Evaluate the matchOperator
	        switch (matchOperator) {
	        case '+':
	            // Assign operation result to infixEval
	            infixEval = left + right;

	            // push infixEval to the stack
	            digits.push(infixEval);
 
	            // Exit the switch
	            break;

	        case '-':
	            // Assign operation result to infixEval
	            infixEval = left - right;

	            // push infixEval to the digits stack
	            digits.push(infixEval);

	            // Exit the switch
	            break;

	        case '*':
	            // Assign the operation result to infixEval
	            infixEval = left * right;

	            // push infixEval to the digits stack
	            digits.push(infixEval);

	            // Exit the switch
	            break;

	        case '/':
	            // Assign operation result to infixEval
	            infixEval = left / right;

	            // push the infixEval to the digits stack
	            digits.push(infixEval);

	            // Exit the switch
                    break;
 
	        default:
	            // Do nothing
	            break;
	        };
            }
        }

        // Increment index	
        index++;
    }
	
    // Return the value of the last operation performed	
    return infixEval;
}
