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
    int number;
    char op;

    int i = 0;
    // 공백으로 구분된 단어(토큰) 추출하여 벡터에 저장
    // while (std::getline(is, token, ' ')) {
    while (is >> number) {
        // int num = std::atoi(token.c_str());
        s.push(number);
        std::cout << number << std::endl;
        // 문자인 경우
        // if (num == 0 && token.front() != '0') {
        // if (is >> op) {
        // std::cout << op << std::endl;
        //     if (s.size() < 2) {
        //         std::cout << "Error" << std::endl;
        //         exit(1);
        //     }
        //     switch (op) {
        //         int top;
        //         int bottom;
        //         case '+':
        //             top = s.top();
        //             s.pop();
        //             bottom = s.top();
        //             s.push(top + bottom);
        //         case '-':
        //             top = s.top();
        //             s.pop();
        //             bottom = s.top();
        //             s.push(bottom - top);
        //         case '*':
        //             top = s.top();
        //             s.pop();
        //             bottom = s.top();
        //             s.push(top * bottom);
        //         case '/':
        //             top = s.top();
        //             s.pop();
        //             bottom = s.top();
        //             s.push(bottom / top);
        //     }
        // }
    }

    return s.top();
}




