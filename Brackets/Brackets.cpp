#include <iostream>
#include <string>
#include <stack>

int bracket_balancing(std::string& text)
{
    int missing_brackets = 0;
    std::stack<char> brackets;
    for (auto& ch : text)
    {
        if (ch == '(')
        {
            brackets.push(ch);
        }
        if (ch == ')')
        {
            if (brackets.empty())
            {
                missing_brackets += 1;
            }
            else 
            {
                if (brackets.top() == '(')
                {
                    brackets.pop();
                }
            }
            
        }
    }
    missing_brackets += brackets.size();
    return missing_brackets;
}


int main()
{
    std::string test{ "()((test111))()))((" };
    int x = bracket_balancing(test);
    if (x == 0)
    {
        std::cout << "Brackets in expression are balanced." << "\n";
    }
    else
    {
        std::cout << "There are " <<x<<" missing brackets"<< "\n";
    }


}

