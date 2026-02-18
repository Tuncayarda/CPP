#include <iostream>
#include <string>
#include <fstream>

int main(int ac , char **av)
{
    if (ac != 4 || std::string(av[2]).empty())
    {
        std::cout << "Usage: ./program <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string str1 = av[2];
    std::string str2 = av[3];
    
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::ofstream output(filename.append(".replace").c_str());
    if (!output.is_open())
    {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);
        size_t pos = 0;
        while ((pos = line.find(str1, pos)) != std::string::npos)
        {
            line.erase(pos, str1.length());
            line.insert(pos, str2);
            pos += str2.length();
        }
        output << line;
        if (!file.eof())
            output << std::endl;
    }

    file.close();
    output.close();

    return 0;
}
