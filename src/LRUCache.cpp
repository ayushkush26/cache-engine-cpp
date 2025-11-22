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
    return -1;
}

void LRUCache::put(int key,int value){

}