// stacks.cpp
// we just use the stack library
#include <iostream>
#include <stack>
#include <vector>
template<class T>

void printStackUtil(std::stack<T> &stk)
{	
	//
	T temp = stk.top();
	stk.pop();
	if (stk.size() > 0)
	{
		printStackUtil(stk);
	}
	std::cout << temp << " ";
	stk.push(temp);
}


template<class T>
void printStack(std::stack<T> &stk)
{
	std::cout << "[ ";
	printStackUtil(stk);
	std::cout << "]" << std::endl;
}


// print parentheis number: number each parentheses pair s.t. for each pair, opening and closing parentheses have the same number. Ex:
// In: (( (a+(b) )+(c+d) ))
// Out: [1,2,3,4,4,3,5,5,2,1] // WRONG
// Should be:
// Out: 1, 2, 3, 4, 4, 3, 3, 3, 2, 1 
void parenthesesCounts_no_stack(const std::string &expression)
{
	int size = expression.length();
	int depth = 0;
	char ch;

	std::cout << '[';

	for (int i = 0; i < size; i++) {
		ch = expression[i];

		// if we encounter a (, we increase, then print the count.
		if (ch == '('){
			depth += 1;
			std::cout << depth << ", "; 
		} 
		// if we encounter a ) we print then decrease the count
		else if (ch == ')') {
			if (i == size - 1){
				std::cout << depth << " "; 
			} 
			else {
				std::cout << depth << ", "; 	
			}
			depth -= 1;
		}
	}

	std::cout << ']' << std::endl;
	
}


void parenthesesCountsStack(const std::string &expression)
{
	std::stack<char> stk;

	int size = expression.length();
	int depth = 0;
	int maxDepth = 0;
	char ch;

	std::cout << '[';

	for (int i = 0; i < size; i++) {
		ch = expression[i];

		if (ch == '('){	
			stk.push(ch);
			depth += 1;
			std::cout << depth; 
		}
		else if (ch == ')'){
			std::cout << depth;
			stk.pop();
			depth -= 1;
		}

		if (depth > maxDepth)
			maxDepth = depth;
	}

	std::cout << ']' << std::endl;
}


// Stock analyst problem: Identify stock hike points from an infinite stream of stock prices. A stock hike point is a value that is greater than all previous values in a stream. Most recent values come first in provided data stream
void hikePoints(std::vector<int> &vec)
{
	std::stack<int> hike_points;

	int max_val = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		if (max_val < vec[i])
		{
			max_val = vec[i];
			hike_points.push(vec[i]);
		}
	}
	
	printStack(hike_points);
}


// Using a stack, find if a given string is a palindrome or not: does the string read the same forwards and backwords?
bool checkPalindrome(const std::string &nathaniel)
{
	bool check;
	int size = nathaniel.length();
	char ch;
	char popped_ch;

	std::stack<char> chars;

	// push each character onto a stack
	for (int i = 0; i < size; i++) 
	{
		chars.push(nathaniel[i]);
	}

	// take it off the stack and compare to original
	for (int i = 0; i < size; i++) 
	{
		ch = nathaniel[i];
		popped_ch = chars.top();
		if (ch != popped_ch)
		{
			std::cout << "Input: " << nathaniel << ". Not palindrome." << std::endl;
			return false;
		}
		chars.pop();
	}
	
	std::cout << "Input: " << nathaniel << ". A palindrome." << std::endl;
	return true;
}


// Write code that will Transform prefix "*+AB - CD" to infix conversion.
bool isOperator(char x) {
  switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
	case '^':
	case '%':
	return true;
  }

  return false;
}


std::string prefixToInfix(std::string prefix_exp)
{
	std::stack<std::string> str;

	// put string on stack


	int size = prefix_exp.size();

	// read from right to left
	for (int i = size - 1; i >= 0; i--) 
	{
		// check if symbol is operator
		if (isOperator(prefix_exp[i]))
		{
		  // pop two operands from stack
		  std::string op1 = str.top();   str.pop();
		  std::string op2 = str.top();   str.pop();

		  // concat the operands and operator
		  std::string temp = "(" + op1 + prefix_exp[i] + op2 + ")";

		  // Push string temp back to stack
		  str.push(temp);
		}

		// if symbol is an operand
		else 
		{
		  // push the operand to the stack
		  //str.push(prefix_exp[i]);
		}
	}

	// Stack now contains the Infix expression
	std::string ex = str.top();
	return ex;
}


int main(){
	// std::stack<int> stk;
	// stk.push(1);
	// stk.push(2);
	// stk.push(3);
	// std::cout << "top: " << stk.top() << std::endl;
	// std::cout << "size: " << stk.size() << std::endl;
	// std::cout << "empty: " << stk.empty() << std::endl;
	// stk.pop();
	// printStack(stk);

	std::cout << std::endl;
	std::cout << "Problem 1a: without stack" << std::endl;
	std::cout << "*********" << std::endl;
	std::string expression = "(( ( a+(b) )+(c+d) ))";
	std::cout << expression << std::endl;
	parenthesesCounts_no_stack(expression);
	std::cout << "This is correct" << std::endl;

	std::cout << std::endl;
	std::cout << "Problem 1b: with stack" << std::endl;
	std::cout << "*********" << std::endl;
	std::cout << expression << std::endl;
	parenthesesCountsStack(expression);
	std::cout << "This is correct" << std::endl;


	std::cout << std::endl;
	std::cout << "Problem 2:" << std::endl;
	std::cout << "*********" << std::endl;
	std::vector<int> prices = {20, 19, 10, 21, 40, 35, 39, 50, 45, 42};
	//final output
	std::cout << "[ ";
	for (int i = 0; i < prices.size()-1; i++) {
		std::cout << prices[i] << ", " ;
	}
	std::cout << prices[prices.size()];  //get rid of comma on final output
	std::cout << "]" << std::endl;
	hikePoints(prices);


	std::cout << std::endl;
	std::cout << "Problem 3:" << std::endl;
	std::cout << "*********" << std::endl;
	std::string pal_1 = "AAABBBCCBBBAAA";
	std::string pal_2 = "AAABBBCCBBzAAA";
	checkPalindrome(pal_1);
	checkPalindrome(pal_2);


	std::cout << std::endl;
	std::cout << "Problem 4:" << std::endl;
	std::cout << "*********" << std::endl;
	std::string pre_exp = "*+AB - CD";
  	// std::cout << "Infix : " << prefixToInfix(pre_exp);
  	std::cout << "zsh: segmentation fault  ./stacks.app" << std::endl;

  	std::cout << "I am not sure what is wrong with this one" << std::endl;

	return 0;
}






