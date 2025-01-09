#include <iostream>
#include <string>
#include <vector>

class CategorySeparator 
{
public:
    void pushLvalue(const std::string& str) 
    {
        lvalues_.emplace_back(str);
    }
    
    void pushRvalue(std::string&& str) 
    {
        rvalues_.emplace_back(std::move(str));
    }
    
    void printLvalues() const 
    {
        printValues(lvalues_);
    }
    
    void printRvalues() const 
    {
        printValues(rvalues_);
    }

private:
    void printValues(const std::vector<std::string>& values) const 
    {
        std::cout << "(";
        for (size_t i = 0; i < values.size(); ++i) 
        {
            std::cout << values[i];
            if (i < values.size() - 1) 
            {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }

    std::vector<std::string> lvalues_;
    std::vector<std::string> rvalues_;
};
