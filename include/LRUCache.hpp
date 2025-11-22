#pragma once
#include "ICache.hpp"
#include <unordered_map>

class LRUCache : public ICache {
private :
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k,int v) : key(k),value(v),prev(nullptr),next(nullptr) {}
    };
    
    int capacity;
    std::unordered_map<int,Node*> mp;

    Node* head;
    Node* tail;

    void addToFront(Node* node);
    void removeNode(Node* node);
    void moveToFront(Node* node);
    Node* removeLast();

public :
    LRUCache(int cap);
    int get(int key) override;
    void put(int key,int value) override;

};