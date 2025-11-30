# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: [Szu-Hsien Lee]  
Email: [alice0701lee@gmail.com]  

## My Hash Function
### Integer Keys 
- Formula:
  ```text
  h(k) = floor(m*(k*A mod 1)), 0 < A < 1
  - k = key (integer)
  - m = table size
  - A = 0.6180339887 ≈ (golden ratio - 1)
  - kA mod 1 = fractional part of kA
  ```
- Pseudocode:
  ```text
  A <- 0.6180339887
  temp <- key * A
  fractional <- temp - floor(t)
  index <- floor(m * fractional)
  ```
- Rationale: 
  - 參考課程所學 Multiplication Method 因為比起 Division Method 容易產生規律性碰撞，它不依賴資料特徵，能在各種 key 分佈下保持穩定表現。
  - 使用 golden ratio (0.6180339887) 作為乘數 A，是因為不規則的無理數不會與 key 的某種規律產生共鳴，能減少碰撞。

### Non-integer Keys
- Formula:
  ```text
  h(s) = ( sum of ASCII(str[i]) * p^i ) mod m
  - str[i] = 第i個字元
  - p = 基底
  - m = table size
  ```
  - Pseudocode:
  ```text
  hash <- 0
  p <- 31
  power <- 0
  
  For each character ch in str:
    hash <- (hash + ASCII(ch) * power) mod m
    power <- (power* p) mod m
  ```
- Rationale:
  - 字串無法直接變成整數，所以要轉換成一個唯一的數值，參考 Polynomial Rolling Hash 技術，將每個字元依照位置計算權重。
  - 為了避免 overflow，在p^i的部分加上 % m的步驟。
  - p 選 31，是因為它是質數，能有效降低碰撞機率。

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence                                                            | Observation                |
|----------------|---------------------------------------------------------------------------|----------------------------|
| 10             |  9, 5, 2, 8, 4, 0, 6, 3, 9, 5, 5, 1, 7, 3, 9, 6, 2, 8, 4, 0               | 出現重複 9 和 5，碰撞仍然存在  |
| 11             | 10, 6, 2, 9, 4, 0, 7, 3, 10, 5, 5, 1, 8, 4, 10, 6, 2, 9, 5, 0             | 分布比 10 好，但仍有碰撞 |
| 37             | 36, 22, 7, 30, 16, 2, 25, 11, 34, 20, 19, 5, 27, 13, 36, 22, 8, 31, 17, 3 | 幾乎沒有規律，分布最均勻，碰撞最少  |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  .\Makefile.bat
  
  # Build only C version
  .\Makefile.bat c
  
  # Build only C++ version
  .\Makefile.bat c++
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  C/hash_function.exe
  ```
  or
  ```bash
  CXX/hash_function_cpp.exe
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...
  ```

- Observations: 整數與字串雜湊顯示，質數且較大的表格分布最均勻，碰撞最少。
- Example output for integers:
  ```
  Hash table (m=10): [9, 5, 2, 8, 4, 0, 6, 3, 9, 5, 5, 1, 7, 3, 9, 6, 2, 8, 4, 0]
  Hash table (m=11): 10, 6, 2, 9, 4, 0, 7, 3, 10, 5, 5, 1, 8, 4, 10, 6, 2, 9, 5, 0]
  Hash table (m=37): [36, 22, 7, 30, 16, 2, 25, 11, 34, 20, 19, 5, 27, 13, 36, 22, 8, 31, 17, 3]
  ```
- Example output for strings:
  ```
  Hash table (m=10): [2, 4, 1, 9, 3, 8, 0, 5, 0, 3]
  Hash table (m=11): [6, 4, 5, 1, 0, 8, 3, 1, 6, 8]
  Hash table (m=37): [30, 34, 29, 17, 24, 29, 20, 17, 8, 19]
  ```
- Observations: 整數與字串雜湊顯示，質數且較大的表格分布最均勻，碰撞最少。
## Analysis
<<<<<<< HEAD
- Prime vs non-prime `m`: 
  - 比對 m = 10 與 m = 11 可觀察到，在 Multiplication Method 中無論是整數還是字串其實質數與非質數沒有太大的區別，分布都沒有規律，都有碰撞存在。
  - 比對 m = 10 與 m = 37 可觀察到，在 m = 37 時無論是整數還是字串，分布都非常均勻，幾乎沒有碰撞存在。
  - 所以推測在使用 Multiplication Method 時不需要要求 m 是否為質數，只要 m 越大就能讓碰撞越少。

## Reflection
1. 設計雜湊函式時，需要在簡單性與有效性之間取得平衡，才能減少碰撞。
2. 表格大小對分布均勻性影響明顯，本次實驗中使用 Multiplication Method 時，即使 m 不是質數，只要 m 夠大，碰撞就會減少。
3. 使用線性轉換公式搭配較大的表格，可以產生最均勻的索引分布，對整數與字串雜湊皆適用。
=======
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
  - 從實驗結果可觀察到，當 m = 10（非質數）時，不論是整數或字串，都出現明顯碰撞 (e.g. bee & pig → index = 0)，分佈規律明顯。
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
>>>>>>> 04d004ff687ab6a5b8d870e436c903e161f6a329
