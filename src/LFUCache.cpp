#include "LFUCache.hpp"

LFUCache::LFUCache(int cap) : capacity(cap), minFreq(0) {}

void LFUCache::increaseFreq(Node* node) {
    int freq = node->freq;
    freqList[freq].erase(nodeIter[node]);

    if (freqList[freq].empty()) {
        freqList.erase(freq);
        if (minFreq == freq) {
            minFreq++;
        }
    }

    node->freq++;

    // Add to new frequency list
    freqList[node->freq].push_front(node);
    nodeIter[node] = freqList[node->freq].begin();

}

void LFUCache::removeNode(Node* node) {
    int freq = node->freq;

    freqList[freq].erase(nodeIter[node]);

    if (freqList[freq].empty()) {
        freqList.erase(freq);
        if (minFreq == freq) {
            
        }
    }

    nodeIter.erase(node);
    keyNode.erase(node->key);
    delete node;
}

int LFUCache::get(int key) {
    if (keyNode.find(key) == keyNode.end()) {
        return -1;
    }

    Node* node = keyNode[key];
    increaseFreq(node);
    return node->value;
}

void LFUCache::put(int key, int value) {
    if (capacity == 0) return;

    // CASE 1 -> key exists update & increase frequency
    if (keyNode.find(key) != keyNode.end()) {
        Node* node = keyNode[key];
        node->value = value;
        increaseFreq(node);
        return;
    }

    // CASE 2 -> Cache full evict least frequently used
    if (keyNode.size() == capacity) {
        Node* nodeToRemove = freqList[minFreq].back();
        removeNode(nodeToRemove);
    }

    // CASE 3 -> insert new node (freq = 1)
    Node* newNode = new Node(key, value);
    freqList[1].push_front(newNode);

    keyNode[key] = newNode;
    nodeIter[newNode] = freqList[1].begin();

    minFreq = 1;  // reset to lowest frequency

}