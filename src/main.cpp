#include "bf_trivial.h"
#include <stdio.h>
#include <string>

using bf::trivial::Interpreter;

int main (int argc, char** argv)
{
    if (argc < 2)
    {
        printf("temp : arg[1] need file name\n");
        return 0;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == nullptr)
    {
        printf("temp : error open file : %s\n", argv[1]);
        return 0;
    }

    std::string content;
    fseek(file, 0, SEEK_END);
    auto size = ftell(file);
    content.resize(size);
    rewind(file);
    fread(content.data(), size, 1, file);

    fclose(file);

    Interpreter interpreter;
    interpreter.exec(content);
    return 0;
}
