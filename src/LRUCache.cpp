#include "LRUCache.hpp"

LRUCache::LRUCache(int cap) : capacity(cap) {
    head = new Node(-1,-1);
    tail = new Node(-1,-1);

    head->next = tail;
    tail->prev = head;
}

void LRUCache::addToFront(Node* node){
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}

void LRUCache::removeNode(Node* node){
    LRUCache::Node* p = node->prev;
    LRUCache::Node* n = node->next;

    p->next = n;
    n->prev = p;
}

void LRUCache::moveToFront(Node* node){
    removeNode(node);
    addToFront(node);
}

LRUCache::Node* LRUCache::removeLast(){
    LRUCache::Node* lru = tail->prev;
    removeNode(lru);
    return lru;
}

int LRUCache::get(int key){
    if (mp.find(key) == mp.end()){
        return -1;
    }

    Node* node = mp[key];
    moveToFront(node);
    return node->value;
    
}

void LRUCache::put(int key,int value){
    // CASE 1 -> Key already exists
    if (mp.find(key) != mp.end()){

        Node* node = mp[key];
        node->value = value;
        moveToFront(node);
        return;
    }

    // CASE 2 -> New Key
    if (mp.size() == capacity){
        Node* lru = removeLast();     // it will remove the least recently used
        mp.erase(lru->key);
        delete lru;
    }

    Node* newNode = new Node(key,value);
    addToFront(newNode);
    mp[key] = newNode;
    
}