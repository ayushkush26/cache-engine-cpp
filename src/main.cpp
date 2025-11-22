#include <iostream>
#include <string>
#include "LRUCache.hpp"
#include "LFUCache.hpp"

int main() {
    std::string type;
    std::cout << "Choose cacheType ('lru' or 'lfu'): ";
    std::cin >> type;

    ICache* cache = nullptr;
    if (type == "lru") {
        cache = new LRUCache(5);
    }
    else if (type == "lfu") {
        cache = new LFUCache(5);
    }
    else {
        std::cout << "Invalid cacheType \n";
        return 0;
    }

    std::cout <<"Cache ready. Enter commands: \n";
    std::cout <<"put <key> <value> \n";
    std::cout <<"get <key> \n";
    std::cout <<"exit \n";

    while (true) {
        std::string operation;
        std::cout<<"> ";
        std::cin >>operation;

        if (operation == "put") {
            int key, value;
            std::cin>>key;
            std::cin>>value;
            cache->put(key,value);
            std::cout<<"Inserted \n";
        }
        else if (operation == "get") {
            int key;
            std::cin>>key;
            std::cout<<cache->get(key)<<"\n";
        }
        else if (operation == "exit") {
            break;
        }
        else {
            std::cout<<"Unknown command \n";
        }
    }

    delete cache;
    return 0;
}
