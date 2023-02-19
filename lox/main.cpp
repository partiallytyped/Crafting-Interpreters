#include <iostream>
#include <memory>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::string;

auto usage() -> void
{
    std::cerr << "Usage: lox [file]\n";
}

class Executioner
{
public:
    virtual auto run(int argc, char **argv) -> void = 0;
};

class Usage : public Executioner
{
    virtual auto run(int argc, char **argcv) -> void override
    {
        cerr << "Usage: lox [file] \n";
        exit(64);
    }
};

class Repl : public Executioner
{
    virtual auto run(int argc, char **argv) -> void override
    {
        auto echoRepl = [](){
            cout << "\\ox | ";
        };
        string line;
        for(echoRepl(); std::getline(cin, line); echoRepl())
        {
            
        }
    }
};

class File : public Executioner
{
    virtual auto run(int, char **) -> void override
    {
        std::cout << "File Exec\n";
    }
};

int main(int argc, char **argv)
{
    Executioner *executioner;
    switch (argc)
    {
    case 1:
        // repl
        executioner = new Repl();
        break;
    case 2:
        executioner = new File();
        break;
    default:
        executioner = new Usage();
        break;
    }
    executioner->run(argc, argv);
    delete executioner;
}