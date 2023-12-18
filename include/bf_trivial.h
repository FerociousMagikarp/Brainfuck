#pragma once

#include <string>
#include <stack>

namespace bf::trivial
{
    constexpr unsigned int PAGE_SIZE = 256; 

    struct Page
    {
        char  data[PAGE_SIZE] = { 0 };
        Page* prev = nullptr;
        Page* next = nullptr;

        bool is_begin(char* p) const noexcept { return p == &data[0]; }
        bool is_end(char* p) const noexcept { return p == &data[PAGE_SIZE - 1]; }
        char* begin() noexcept { return &data[0]; }
        char* end() noexcept { return &data[PAGE_SIZE - 1]; }
    };

    class Paper
    {
    public:
        Paper();
        ~Paper();

        Paper(const Paper&) = delete;
        Paper(Paper&&) = delete;
        Paper& operator=(const Paper&) = delete;
        Paper& operator=(Paper&&) = delete;

        void prev();
        void next();

        void plus();
        void substract();

        void set(char val);
        char get();

    private:
        Page* m_origin_page;
        Page* m_current_page;
        char* m_current_pointer;
    };

    enum class ExecStatus
    {
        Success,
        UnmatchedLeftBracket,
        UnmatchedRightBracket,
    };

    class Interpreter
    {
        using size = std::string::size_type;
        
    public:
        Interpreter();
        ~Interpreter();

        Interpreter(const Interpreter&) = delete;
        Interpreter(Interpreter&&) = delete;
        Interpreter& operator=(const Interpreter&) = delete;
        Interpreter& operator=(Interpreter&&) = delete;

        ExecStatus exec(std::string script);

    private:
        bool match_left_bracket(const std::string& script, size& cur_index);
        bool match_right_bracket(const std::string& script, size& cur_index);

    private:
        Paper m_paper;
        std::stack<size> m_left_bracket_st;
    };
}
