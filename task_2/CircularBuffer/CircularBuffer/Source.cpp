#include "CircularBufferList\CircularBufferList.h"
#include "CircularBufferArray\CircularBufferArray.h"


int main() {
    CircularBufferList<int> lbuffer(5);
    
    std::string hashLine(15, '.');

    std::cout << hashLine << "List" << hashLine <<std::endl;

    for (int i = 1; i <= 7; ++i) {
        std::cout << "Pushed: " << i << std::endl;
        lbuffer.push(i);
        std::cout << "Buffer container: ";
        lbuffer.view();
        std::cout << std::endl;
    }

    std::cout << '\n';

    while (!lbuffer.empty()) {
        std::cout << "Poped: " << lbuffer.pop() << std::endl;
        std::cout << "Buffer container: ";
        lbuffer.view();
        std::cout << std::endl;
    }
    
    /////////////////////////////////////////////////////////////////

    std::cout << hashLine << "Array" << hashLine << std::endl;
    CircularBufferArray<int> abuffer(5);

    for (int i = 1; i <= 7; ++i) {
        std::cout << "Pushed: " << i << std::endl;
        abuffer.push(i);
        std::cout << "Buffer container: ";
        abuffer.view();
        std::cout << std::endl;
    }

    std::cout << '\n';

    while (!abuffer.empty()) {
        std::cout << "Poped: " << abuffer.pop() << std::endl;
        std::cout << "Buffer container: ";
        abuffer.view();
        std::cout << std::endl;
    }


    return 0;
}
