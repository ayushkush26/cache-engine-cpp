#include <iostream>
#include "LFUCache.hpp"

int main() {
    LFUCache cache(2);

    cache.put(1, 10); 
    cache.put(2, 20); 
    std::cout << cache.get(1) << "\n"; 

    cache.put(3, 30); 
    std::cout << cache.get(2) << "\n"; 
    std::cout << cache.get(3) << "\n"; 

    return 0;
}
