#include <string>
#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
//#include "MyStack.h"
#include <vector>
int main()
{
    /*char ch;

    MyStack<char> stack(100);
    while (true)
    {
        std::cin >> ch;
        if (ch != '-')
        {
            stack.push(&ch);
        }
        else if (!stack.isEmpty())
        {
            std::cout << stack.pop() << ' ' << stack.size() << " left on stack";
        }
        
    }*/
    //MyStack<int> stack(1);

    //stack.push(0);
    std::vector<int> ve;
    ve.pop_back();
    //stack.push(1);
    //stack.isEmpty();
    //<< stack.pop() << ' ' << stack.pop();
    return 0;
}

template <typename Item>
struct _Stack_base
{

    struct _Stack_impl
    {
        Item _M_start;
        Item _M_finish;
        Item _M_end_of_storage;
    };

public:
    _Stack_impl _M_impl;
};

typedef unsigned long int size_type;

template <typename Item>
class MyStack : public _Stack_base<Item>
{
private:
    void resize(size_type __new_size);
    void _M_default_append(size_type __n);
    size_type _M_check_len(size_type __n, const char *__s) const;

public:
    MyStack(int cap);
    bool isEmpty() const;
    int size() const;
    Item pop();
    void push(const Item item);
    ~MyStack();
};

template <typename Item>
size_type MyStack<Item>::_M_check_len(size_type __n, const char *__s) const
{
    if (max_size() - size() < __n)
        __throw_length_error(__N(__s));

    const size_type __len = size() + std::max(size(), __n);
    return (__len < size() || __len > max_size()) ? max_size() : __len;
}

template <typename Item>
void MyStack<Item>::_M_default_append(size_type __n)
{
    if (__n != 0)
    {
        size_type __size = size();
        size_type __navail = size_type(this->_M_impl._M_end_of_storage - this->_M_impl._M_finish);

        if (__navail >= __n)
        {
            _GLIBCXX_ASAN_ANNOTATE_GROW(__n);
            this->_M_impl._M_finish =
                std::__uninitialized_default_n_a(this->_M_impl._M_finish,
                                                 __n, _M_get_Tp_allocator());
            _GLIBCXX_ASAN_ANNOTATE_GREW(__n);
        }
        else
        {
            const size_type __len =
                _M_check_len(__n, "vector::_M_default_append");
            const size_type __old_size = __size;
            pointer __new_start(this->_M_allocate(__len));
            pointer __new_finish(__new_start);
            __try
            {
                __new_finish = std::__uninitialized_move_if_noexcept_a(this->_M_impl._M_start, this->_M_impl._M_finish,
                                                                       __new_start, _M_get_Tp_allocator());
                __new_finish =
                    std::__uninitialized_default_n_a(__new_finish, __n,
                                                     _M_get_Tp_allocator());
            }
            __catch(...)
            {
                std::_Destroy(__new_start, __new_finish,
                              _M_get_Tp_allocator());
                _M_deallocate(__new_start, __len);
                __throw_exception_again;
            }
            _GLIBCXX_ASAN_ANNOTATE_REINIT;
            std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
                          _M_get_Tp_allocator());
            _M_deallocate(this->_M_impl._M_start,
                          this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
            this->_M_impl._M_start = __new_start;
            this->_M_impl._M_finish = __new_finish;
            this->_M_impl._M_end_of_storage = __new_start + __len;
        }
    }
}

template <typename Item>
void MyStack<Item>::resize(size_type __new_size)
{
    if (__new_size > size())
        _M_default_append(__new_size - size());
    else if (__new_size < size())
        _M_erase_at_end(this->_M_impl._M_start + __new_size);
}

template <typename Item>
int MyStack<Item>::size() const
{
    return this->N;
}
template <typename Item>
bool MyStack<Item>::isEmpty() const
{
    return this->_Stack_base._Stack_impl == 0;
}

template <typename Item>
void MyStack<Item>::push(const Item item)
{
    int current_size = sizeof(this->entry) / sizeof(Item);

    if (this->N == current_size)
    {
        resize(current_size * 2);
    }
    entry[N++] = item;
}

template <typename Item>
Item MyStack<Item>::pop()
{
    N--; //N是size所以要先--
    if (N > 0 && N == (sizeof(this->entry) / sizeof(this->entry[0])) / 4)
    {
        resize((sizeof(this->entry) / sizeof(Item)) / 2);
    }
    return this->entry[N];
}

template <typename Item>
MyStack<Item>::MyStack(int cap)
{
    this->entry = new Item[cap];
    this->N = 0;
}

template <typename Item>
MyStack<Item>::~MyStack()
{
    delete[] this->entry;
}
