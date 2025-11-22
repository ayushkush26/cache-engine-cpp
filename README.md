# 🧰 Cache System (LRU + LFU)

This is a small C++ project where I implemented two caching algorithms: **LRU (Least Recently Used)** and **LFU (Least Frequently Used)**.  
I built this project mainly to understand how caches work internally and to practice data structures, pointers, and clean system-level design in C++.

The project also includes a simple **interactive CLI** so you can test the cache easily by typing commands.

---

## 🚀 Features

### 🔹 **LRU Cache**
- Removes the item that hasn’t been used for the longest time  
- Uses a combination of:
  - Hash map  
  - Doubly linked list  
- Supports `get()` and `put()` in **O(1)** time

### 🔹 **LFU Cache**
- Removes the item that is used the least frequently  
- If two keys have the same frequency, removes the least recently used among them  
- Implementation uses:
  - Hash map  
  - Frequency → list mapping  
  - A `minFreq` tracker  
- All operations are **O(1)**

### 🔹 **Interactive CLI**
Start the program and choose the cache type:

```
Choose cache type (lru/lfu):
```

Then use commands:

```
put <key> <value>
get <key>
exit
```

---

## 📂 Project Structure

```
include/
    ICache.hpp
    LRUCache.hpp
    LFUCache.hpp

src/
    LRUCache.cpp
    LFUCache.cpp
    main.cpp

CMakeLists.txt
```

Each cache implements a common interface (`ICache`) so both can be used interchangeably.

---

## 🔧 Build Instructions

Make sure you have **CMake** and a **C++17 compiler**.

### 1. Create a build folder
```
mkdir build
cd build
```

### 2. Generate build files
```
cmake ..
```

### 3. Build
```
cmake --build .
```

### 4. Run
```
./cache_system
```

---

## 🧪 Example Usage

```
Choose cache type (lru/lfu): lru
> put 1 100
Inserted.
> get 1
100
> exit
```

---

## 🎯 Why I Built This

I wanted to get hands-on practice with:
- System design and caching concepts  
- Low-level data structures  
- Pointers, memory, and C++  
- How real caching mechanisms (like Redis / CPU caches) work internally  

This project is a great learning tool and a good addition to my GitHub profile for placements.

---

## ✨ Author

**Ayush Kush**
