#include "Replace.hpp"

std::string Replace::replace(const std::string& input, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t lastPos = 0;
    size_t findPos = input.find(s1);

    while (findPos != std::string::npos) {
        result.append(input, lastPos, findPos - lastPos);
        result.append(s2);
        lastPos = findPos + s1.length();        
        findPos = input.find(s1, lastPos);
    }
    
    result.append(input, lastPos, input.length() - lastPos);
    
    return result;
}
