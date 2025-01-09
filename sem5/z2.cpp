#include <iostream>
#include <stack>
#include <string>

bool isCorrectParentheses(const std::string& s) 
{
    std::stack<char> stack;

    for (char ch : s) 
    {
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            stack.push(ch);
        } 
        else 
        {
            if (stack.empty()) 
            {
                return false;
            }
            char top = stack.top();
            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '[')) 
            {
                stack.pop();
            } 
            else 
            {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() 
{
    std::string input;
    std::cin >> input;

    if (isCorrectParentheses(input)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
