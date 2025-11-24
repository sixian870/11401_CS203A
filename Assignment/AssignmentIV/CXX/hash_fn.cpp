/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    - 2025/12/24: Implemented integer and string hash functions — by Szu-Hsien Lee

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) { // key = int, m = table size
    if (m <= 0) return -1; // avoid 0
    return key % m;  // basic division method // return index (0 ~ m-1)
}

int myHashString(const std::string& str, int m) {
    if (m <= 0) return -1; // avoid 0
    unsigned long hash = 0; // The value of the accumulated string converted to an integer
    for (char ch : str) {
        hash = hash * 31 + static_cast<unsigned char>(ch); // polynomial rolling hash // "cat" -> hash = 031+'c' = 99 → 99*31+'a' = 3086 → 3086*31+'t' = 95754
    }
    return static_cast<int>(hash % m);  // basic division method // return index (0 ~ m-1)
}