# std::vector<bool> Performance Gotcha in C++

This repository demonstrates a common performance pitfall in C++ when using `std::vector<bool>`.  `std::vector<bool>` is specialized to save space, but this specialization comes at the cost of performance. It's often significantly slower and less memory-efficient than alternatives for large vectors of booleans.

## The Problem

The standard library's `std::vector<bool>` is *not* a simple array of bits. Each element is an object, requiring more overhead than a direct bit representation.  This leads to: 

* **Slower access:** Accessing individual elements is more time-consuming.
* **Higher memory usage:**  Memory usage can be much larger than expected, especially with a large number of booleans.
* **Inefficient operations:** Operations on the vector are often slower than using other data structures.

## The Solution

To optimize for better performance and memory efficiency when dealing with many boolean values, consider alternatives such as:

* **`std::bitset`:**  Provides compact bit storage and efficient bitwise operations.
* **`boost::dynamic_bitset`:** Offers a dynamic version of `std::bitset`, more suitable when the size of the bit vector is not known at compile time.
* **Custom bit manipulation with raw arrays:**  For maximal control over memory layout and access, you can use raw arrays and bit manipulation operations, however this requires more manual handling and is more error prone.

This example demonstrates this performance difference.