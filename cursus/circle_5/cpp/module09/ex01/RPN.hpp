#ifndef __RPN_HPP__
# define __RPN_HPP__
# include <iostream>
# include <sstream>
# include <stack>

class RPN {
    private:
        std::stack<int> s;

    public:
        RPN();
        ~RPN();
        RPN(RPN &RPN);
        RPN &operator=(RPN& RPN);

        int calculate(char *argv[]);
};

#endif