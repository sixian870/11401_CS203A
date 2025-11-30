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
  - Based on the course material, the Multiplication Method was chosen because, compared to the Division Method, it is less prone to producing regular patterns of collisions. It does not depend on the characteristics of the data and can maintain stable performance across various key distributions.
  - The golden ratio (0.6180339887) was used as the multiplier A because an irregular irrational number does not resonate with any regularities in the keys, which helps reduce collisions.

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
  - Strings cannot be directly converted to integers, so they must be transformed into a unique numeric value. Using the Polynomial Rolling Hash technique, each character is assigned a weighted value based on its position in the string.
  - The multiplier p is chosen as 31 because it is a prime number, which helps effectively reduce the probability of collisions.
  - To prevent overflow, the p^i term is computed with a modulo m at each step.

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
| 10             |  9, 5, 2, 8, 4, 0, 6, 3, 9, 5, 5, 1, 7, 3, 9, 6, 2, 8, 4, 0               | Repeated values 9 and 5 appear, so collisions still exist. |
| 11             | 10, 6, 2, 9, 4, 0, 7, 3, 10, 5, 5, 1, 8, 4, 10, 6, 2, 9, 5, 0             | The distribution is better than for 10, but collisions remain. |
| 37             | 36, 22, 7, 30, 16, 2, 25, 11, 34, 20, 19, 5, 27, 13, 36, 22, 8, 31, 17, 3 | There is almost no pattern, the distribution is the most uniform, and collisions are minimal. |

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

  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_C%20(1).png)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_C%20(2).png)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_C%20(3).png)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_cpp%20(1).png)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_cpp%20(2).png)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_cpp%20(3).png)


- Example output for strings:
  - Hash Function Observation (C Version)

  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_Cs%20(1).png)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_Cs%20(2).png)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_Cs%20(3).png)

  - Hash Function Observation (C++ Version)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_cpps%20(1).png)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_cpps%20(2).png)
  
  ![image](https://github.com/sixian870/11401_CS203A/blob/main/OutputSnapShot/Output_cpps%20(3).png)

- Observations: The integer and string hash results show that prime and larger table sizes produce the most uniform distribution with the fewest collisions.
- Example output for integers:
  ```
  Hash table (m=10): [9, 5, 2, 8, 4, 0, 6, 3, 9, 5, 5, 1, 7, 3, 9, 6, 2, 8, 4, 0]
  Hash table (m=11): [10, 6, 2, 9, 4, 0, 7, 3, 10, 5, 5, 1, 8, 4, 10, 6, 2, 9, 5, 0]
  Hash table (m=37): [36, 22, 7, 30, 16, 2, 25, 11, 34, 20, 19, 5, 27, 13, 36, 22, 8, 31, 17, 3]
  ```
- Example output for strings:
  ```
  Hash table (m=10): [2, 4, 1, 9, 3, 8, 0, 5, 0, 3]
  Hash table (m=11): [6, 4, 5, 1, 0, 8, 3, 1, 6, 8]
  Hash table (m=37): [30, 34, 29, 17, 24, 29, 20, 17, 8, 19]
  ```
- Observations: The integer and string hash results show that prime and larger table sizes produce the most uniform distribution with the fewest collisions.
## Analysis
- Prime vs non-prime `m`: 
  - Comparing m = 10 and m = 11, the results show that using the Multiplication Method, there is no significant difference between prime and non-prime table sizes. Both integers and strings experience collisions, and the distribution exhibits some patterns.
  - Comparing m = 10 and m = 37, it can be observed that with a larger table size (m = 37), the distribution of indices for both integers and strings becomes very uniform, with almost no collisions. This indicates that the Multiplication Method’s performance is mainly influenced by table size rather than whether it is a prime number.
  - Overall, the experiment suggests that when using the Multiplication Method, it is not strictly necessary for m to be prime; choosing a larger table size alone can significantly reduce collisions and improve distribution uniformity.
- Collisions and Patterns:
  - For m = 11, integer indices repeat multiple times (e.g., 10, 5, 4), and string indices also collide (e.g., cat and pig both map to 6; cow and hen both map to 1), showing that small tables can still produce collisions even if the table size is prime.
  - For m = 37, integer and string indices rarely repeat, showing a highly uniform distribution and indicating that the Multiplication Method works best with large tables.
- Possible Improvements:
  - Selecting a larger table size significantly reduces collisions.
  - Using the linear transformation formula (h(k) = floor(m*(k*A mod 1))) produces uniform distribution for both integers and strings.
  - Additional collision reduction can be achieved using rehashing or open addressing techniques if needed.

## Reflection
1. Designing hash functions requires a balance between computational simplicity and hashing effectiveness to maintain efficiency while minimizing collisions.
2. Table size has a significant impact on hash distribution. The experiment shows that even if m is not prime, a sufficiently large table can significantly reduce collisions.
3. Using the Multiplication Method’s linear transformation formula with a large table produces the most uniform index distribution for both integers and strings, which explains the good results observed in this experiment.
