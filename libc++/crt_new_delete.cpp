#include <cstdlib>

void* operator new(unsigned long size) {
    return std::malloc(size);
}

void operator delete(void* p ) {
    std::free(p);
}

void* operator new[](unsigned long size) {
    return std::malloc(size);
}

void operator delete[](void* p ) {
    std::free(p);
}
