#pragma once 
class ICache {
    public :
        virtual int get(int key) = 0;
        virtual void put(int key,int value) = 0;
        virtual ~ICache(){}
};