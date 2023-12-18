#include "bf_trivial.h"

using bf::trivial::Interpreter;

int main (int argc, char** argv)
{
    Interpreter interpreter;
    interpreter.exec("++[->++++<]>[->++++>+++++++++>+++++++++++++<<<]>>.>---.+++++++..+++.<<.>>++++++++.--------.+++.------.--------.<<+.");
    return 0;
}
