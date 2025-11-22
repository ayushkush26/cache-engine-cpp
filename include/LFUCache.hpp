#pragma once
#include "ICache.hpp"
#include <unordered_map>
#include <list>

class LFUCache : public ICache {
private :
    struct Node{
        int key;
        int value;
        int freq;
        Node(int k,int v) : key(k),value(v),freq(1){}
    };

    int capacity;
    int minFreq;

    std::unordered_map<int,Node*> keyNode;                                              // key -> node
    std::unordered_map<int,std::list<Node*>> freqList;                                  // freq -> nodes list
    std::unordered_map<Node*,std::list<Node*>::iterator> nodeIter;                      // node -> iterator

    void increaseFreq(Node* node);
    void removeNode(Node* node);

public :
    LFUCache(int cap);
    int get(int key) override;
    void put(int key, int value) override;
    
};