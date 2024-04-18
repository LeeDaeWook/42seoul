#include "RPN.hpp"

RPN::RPN()
{
    // std::cout << "Default RPN constructor called" << std::endl;
}

RPN::~RPN()
{
    // std::cout << "Default RPN destructor called" << std::endl;
}

RPN::RPN(RPN &RPN)
{
    // std::cout << "RPN Copy constructor called" << std::endl;
    *this = RPN;
}

RPN &RPN::operator=(RPN &RPN)
{
    // std::cout << "RPN Copy assignment operator called" << std::endl;

    (void)RPN;
    return *this;
}

int RPN::calculate(char *argv[]) {
    std::stack<int> s;
    std::istringstream is(argv[1]);
    std::string token;

    // 공백으로 구분된 단어(토큰) 추출
    while (std::getline(is, token, ' ')) {
        int num = std::atoi(token.c_str());
        if (num >= 10 || num < 0) {
            std::cout << "Error : only numbers from 1 to 9 are available" << std::endl;
            exit(1);
        }
        char op = token.c_str()[0];
        // 문자인 경우
        if (num != 0 || (num == 0 && token.front() == '0'))
            s.push(num);
        if (num == 0 && token.front() != '0') {
            if (s.size() < 2) {
                std::cout << "Error" << std::endl;
                exit(1);
            }
            switch (op) {
                int top;
                int bottom;
                case '+':
                    top = s.top();
                    s.pop();
                    bottom = s.top();
                    s.pop();
                    s.push(top + bottom);
                    break;
                case '-':
                    top = s.top();
                    s.pop();
                    bottom = s.top();
                    s.pop();
                    s.push(bottom - top);
                    break;
                case '*':
                    top = s.top();
                    s.pop();
                    bottom = s.top();
                    s.pop();
                    s.push(top * bottom);
                    break;
                case '/':
                    top = s.top();
                    s.pop();
                    if (top == 0) {
                        std::cout << "Error : Division by zero" << std::endl;
                        exit(1);
                    }
                    bottom = s.top();
                    s.pop();
                    s.push(bottom / top);
                    break;
                default:
                    std::cout << "Error : \'" << token << "\' is not proper argument" << std::endl;
                    exit(1);
            }
        }
    }

    return s.top();
}




