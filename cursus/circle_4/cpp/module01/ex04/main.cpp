#include "Replace.hpp"

int main(int argc, char* argv[])
{
	std::ifstream fin;
	std::ofstream fout;
	std::string filename;
	std::string s1;
	std::string s2;
	std::string buf;
	Replace replace;

	if (argc != 4)
		exit(EXIT_FAILURE);
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	fin.open(filename);
	fout.open(filename.append(".replace"));

	if (fin.is_open() && fout.is_open())
	{
		while (true)
		{
			std::getline(fin, buf);
			fout << replace.replace(buf, s1, s2);
			if (fin.eof())
				break;
			fout << std::endl;
		}
	}

	fin.close();
	fout.close();

	return 0;
}