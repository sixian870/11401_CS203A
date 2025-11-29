/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/12/24: Integer hash (Division Method), String hash (Polynomial Rolling Hash) — by Szu-Hsien Lee
    - 2025/12/29: Integer hash (Multiplication Method), revised Polynomial Rolling Hash — by Szu-Hsien Lee

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
   Developer: Szu-Hsien Lee <alice0701lee@gmail.com>
 */

#include "hash_fn.h"

// multiplication method
int myHashInt(int key, int m) { // key = int, m = table size
    if (m <= 0) return -1; // avoid 0
    double A = 0.6180339887; // golden ratio
    double t = key * A;
    double fractional = t - (int)t;
    return (int)(m * fractional); // return index (0 ~ m-1)
}

// polynomial rolling hash 
int myHashString(const char* str, int m) {
    if (m <= 0) return -1; // avoid 0
    unsigned long hash = 0; // The value of the accumulated string converted to an integer
    long long p = 31;
    long long power = 1; // p^0 = 1
    // Traversing the string
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        hash = (hash + (long long)ch * power) % m;
        power = (power * p) % m; // (p^0) * p = p^1 // mod m -> avoid overflow
    }
    return (int)hash; // return index (0 ~ m-1)
}