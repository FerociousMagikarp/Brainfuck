#include "bf_trivial.h"
#include <conio.h>

namespace bf::trivial
{
    Paper::Paper() : m_origin_page(new Page), m_current_page(m_origin_page), m_current_pointer(reinterpret_cast<char*>(m_origin_page)) {}
    Paper::~Paper()
    {
        auto page = m_origin_page;
        while(page->prev) page = page->prev;
        while(page->next)
        {
            page = page->next;
            delete page->prev;
        }
        delete page;
    }

    void Paper::prev()
    {
        if (m_current_page->is_begin(m_current_pointer))
        {
            if (!m_current_page->prev)
            {
                m_current_page->prev = new Page;
                m_current_page->prev->next = m_current_page;
            }
            m_current_page = m_current_page->prev;
            m_current_pointer = m_current_page->end();
        }
        else
        {
            --m_current_pointer;
        }
    }

    void Paper::next()
    {
        if (m_current_page->is_end(m_current_pointer))
        {
            if (!m_current_page->next)
            {
                m_current_page->next = new Page;
                m_current_page->next->prev = m_current_page;
            }
            m_current_page = m_current_page->next;
            m_current_pointer = m_current_page->begin();
        }
        else
        {
            ++m_current_pointer;
        }
    }

    void Paper::plus()
    {
        ++*m_current_pointer;
    }

    void Paper::substract()
    {
        --*m_current_pointer;
    }

    void Paper::set(char val)
    {
        *m_current_pointer = val;
    }

    char Paper::get()
    {
        return *m_current_pointer;
    }

    Interpreter::Interpreter() = default;
    Interpreter::~Interpreter() = default;

    ExecStatus Interpreter::exec(std::string script)
    {
        size i = 0;
        const size N = script.size();
        while (i < N)
        {
            switch (script[i])
            {
                case '>': m_paper.next(); break;
                case '<': m_paper.prev(); break;
                case '+': m_paper.plus(); break;
                case '-': m_paper.substract(); break;
                case '.': putio(m_paper.get()); break;
                case ',': m_paper.set(getio()); break;
                case '[': if (!match_left_bracket(script, i)) return ExecStatus::UnmatchedRightBracket; break;
                case ']': if (!match_right_bracket(script, i)) return ExecStatus::UnmatchedRightBracket; break;
                default: break;
            }

            ++i;
        }

        if (!m_left_bracket_st.empty())
            return ExecStatus::UnmatchedLeftBracket;

        return ExecStatus::Success;
    }

    bool Interpreter::match_left_bracket(const std::string& script, size& index)
    {
        const size N = script.size();

        if (m_paper.get() != 0)
        {
            m_left_bracket_st.push(index);
            return true;
        }

        int left_bracket_count = 0;
        size j = index + 1;
        while (j < N)
        {
            if (script[j] == '[')
                ++left_bracket_count;
            else if (script[j] == ']')
            {
                if (left_bracket_count == 0)
                {
                    index = j;
                    return true;
                }
                else
                    --left_bracket_count;
            }
            ++j;
        }

        return false;
    }

    bool Interpreter::match_right_bracket(const std::string& script, size& index)
    {
        if (m_left_bracket_st.empty())
            return false;

        if (m_paper.get() == 0)
        {
            m_left_bracket_st.pop();
            return true;
        }

        index = m_left_bracket_st.top();
        return true;
    }

    void Interpreter::putio(char c)
    {
#ifdef _MSC_VER
        _putch(c);
#else
        putch(c);
#endif
    }

    char Interpreter::getio()
    {
#ifdef _MSC_VER
        return static_cast<char>(_getch());
#else
        return static_cast<char>(getch());
#endif
    }

}

