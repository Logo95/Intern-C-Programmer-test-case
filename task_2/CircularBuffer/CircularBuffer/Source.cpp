#include "CircularBufferList.h"
#include "CircularBufferArray.h"


#define sep(s) std::cout << std::string(15, '.') + s + std::string(15, '.') + '\n'

template <typename T>
void fill_int(T& buffer, size_t count) {

    for (int i = 1; i <= count; ++i) {
        std::cout << "Pushed: " << i << std::endl;
        buffer.push(i);
        std::cout << "Buffer container: ";
        buffer.view();
        std::cout << std::endl;
    }
}

template <typename T>
void fill_char(T& buffer, size_t count) {

    for (int i = 1; i <= count; ++i) {
        std::cout << "Pushed: " << static_cast<char>('a' + i - 1) << std::endl;
        buffer.push(static_cast<char>('a' + i - 1));
        std::cout << "Buffer container: ";
        buffer.view();
        std::cout << std::endl;
    }
}

template <typename T>
void clear(T& buffer) {
    while (!buffer.empty()) {
        std::cout << "Poped: " << buffer.pop() << std::endl;
        std::cout << "Buffer container: ";
        buffer.view();
        std::cout << std::endl;
    }
}


int main() {
    CircularBufferList<int> lbufferInt(5);

    sep("List<int>");
    fill_int(lbufferInt, 7);
    std::cout << '\n';
    clear(lbufferInt);
    
    /////////////////////////////////////////////////////////////////
    CircularBufferArray<int> abufferInt(5);
    
    sep("Array<int>");
    
    fill_int(abufferInt, 7);
    std::cout << '\n';
    clear(abufferInt);
    
    /////////////////////////////////////////////////////////////////
    CircularBufferList<char> lbufferChar(5);

    sep("List<char>");

    fill_char(lbufferChar, 7);
    std::cout << '\n';
    clear(lbufferChar);

    return 0;
}
