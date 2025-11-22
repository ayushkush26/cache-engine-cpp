#include <iostream>
#include "LRUCache.hpp"

int main(){
    std::cout<<"Test LRUCache System\n";
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    std::cout << cache.get(1) << "\n";  // 10

    cache.put(3, 30);  // evicts key 2 (LRU)

    std::cout << cache.get(2) << "\n";  // -1
    std::cout << cache.get(3) << "\n";  // 30
    return 0;
    
}