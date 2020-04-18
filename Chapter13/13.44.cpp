#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <cstring>

class String
{
private:
    char *first;
    char *post_last;

private:
    std::allocator<char> alloc;
    void alloc_n_copy(const char *begin, const char *end)
    {
        auto data = alloc.allocate(end - begin);
        post_last = std::uninitialized_copy(begin, end, data);
        first = data;
    }

    void free()
    {
        for (auto iter = post_last; iter != first;)
        {
            alloc.destroy(--iter);
        }
        alloc.deallocate(first, post_last - first);
    }

public:
    String() : first(nullptr), post_last(nullptr) {}

    String(const char *c_str)
    {
        alloc_n_copy(c_str, c_str + strlen(c_str));
    }

    String(const String &ano)
    {
        alloc_n_copy(ano.first, ano.post_last);
    }

    String(const std::string &ano) : String(ano.c_str())
    {
    }

    String &operator=(const String &ano)
    {
        if (this != &ano)
        {
            free();
            alloc_n_copy(ano.first, ano.post_last);
        }
        return *this;
    }

    ~String()
    {
        free();
    }

    char &operator[](size_t index)
    {
        return *(first + index);
    }

    char &at(size_t index)
    {
        if (first + index >= post_last)
        {
            std::string msg("index out of boundary: ");
            throw std::out_of_range(msg + std::to_string(index));
        }
        return *(first + index);
    }

    size_t size() const
    {
        return post_last - first;
    }

    size_t length() const
    {
        return size();
    }

    char *begin() const
    {
        return first;
    }

    char *end() const
    {
        return post_last;
    }
};

std::ostream &operator<<(std::ostream &out, const String &str)
{
    std::for_each(str.begin(), str.end(), [&out](char ch) {
        out << ch;
    });
    return out;
}
using namespace std;
int main()
{
    String str("construct from string literal.");
    cout << str << endl;

    String str2(string("construct from std::string."));
    cout << str2 << endl;

    cout << str2[0] << endl;
    try{
        cout << str2.at(100) << endl;
    }catch(out_of_range err)
    {
        cerr << err.what() << endl;
        return -1;
    }
    return 0;
}