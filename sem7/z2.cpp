#include <iostream>
#include <vector>
#include <string>

class StringStack 
{
public:
    void push(const std::string& str) 
    {
        stack_.emplace_back(str);
    }

    void push(std::string&& str) 
    {
        stack_.emplace_back(std::move(str));
    }

    std::string pop() 
    {
        if (isEmpty()) 
        {
            return {};
        }
        std::string topElement = std::move(stack_.back());
        stack_.pop_back();
        return topElement;
    }

    void print() const 
    {
        std::cout << "(";
        for (size_t i = 0; i < stack_.size(); ++i) 
        {
            std::cout << stack_[i];
            if (i < stack_.size() - 1) 
            {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }

    bool isEmpty() const 
    {
        return stack_.empty();
    }

private:
    std::vector<std::string> stack_;
};
