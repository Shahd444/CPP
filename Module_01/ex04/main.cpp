#include <iostream>
#include <fstream>
#include <sys/stat.h>

bool    is_directory(const std::string &f)
{
    struct stat f_stat;
    if (stat(f.c_str(), &f_stat) != 0)
        return (0);
    return (S_ISDIR(f_stat.st_mode));    
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "wrong number of parameters, try: filename string1 string2\n";
        return(1);
    }
    std::ifstream infile(av[1]);
    if (!infile)
    {
        std::cerr << "invalid file\n";
        return (1);
    }
    if (is_directory(av[1]))
    {
        std::cerr << "it's a directory not a file\n";
        return (1);
    }
    std::string file = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (s1 == "")
    {
        std::cerr << "invalid string\n";
        return (1);
    }
    std::string secondfile = file + ".replace";
    std::ofstream outfile(secondfile.c_str());
    if (!outfile)
    {
        std::cerr << "failed creating file.\n";
        return (1);
    }
    std::string line;
    while (std::getline(infile, line))
    {
        std::string result;
        int start = 0;
        size_t pos;
        while ((pos = line.find(s1, start)) != std::string::npos)
        {
            result += line.substr(start, pos - start);
            result += s2;
            start = pos + s1.length();
        }
        result += line.substr(start);
        outfile << result << '\n';   
    }
}
