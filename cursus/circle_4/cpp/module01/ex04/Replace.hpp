#pragma once
#ifndef __REPLACE_HPP__
# define __REPLACE_HPP__
# include <iostream>
# include <string>
# include <fstream>

class Replace {
    public:
        std::string replace(const std::string& input, const std::string& s1, const std::string& s2);
};

#endif