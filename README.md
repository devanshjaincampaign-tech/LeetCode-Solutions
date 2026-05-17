# Two Sum — LeetCode #1

A beginner-friendly implementation of the classic **Two Sum** problem using both:

- Brute Force Approach
- Optimized Hash Map Approach

This repository is part of my **DSA + Backend Engineering Journey** focused on building strong problem-solving fundamentals and maintaining consistent GitHub progress.

---

# Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

### Example

```txt
Input:
nums = [2,7,11,15]
target = 9

Output:
[0,1]
```

---

# Approaches Implemented

## 1. Brute Force Approach

### Idea
Check every possible pair using nested loops.

### Complexity Analysis

| Complexity | Value |
|---|---|
| Time Complexity | O(n²) |
| Space Complexity | O(1) |

### File
```txt
brute-force.cpp
```

---

## 2. Optimized Hash Map Approach

### Idea
Use a hash map to store previously visited elements and find the complement in constant time.

### Complexity Analysis

| Complexity | Value |
|---|---|
| Time Complexity | O(n) |
| Space Complexity | O(n) |

### File
```txt
optimized.cpp
```

---

# Key Concepts Learned

- Arrays
- Time Complexity Analysis
- Hashing
- Space-Time Tradeoff
- Hash Maps (`unordered_map` in C++)

---

# Project Structure

```txt
day-1-two-sum/
│
├── README.md
├── brute-force.cpp
└── optimized.cpp
```

---

# Learning Outcome

This problem helped me understand:

- how brute force solutions work
- how optimization reduces time complexity
- how hashing enables constant-time lookup
- why space complexity sometimes increases for better performance

---

# Tech Stack

- Language: C++
- Platform: LeetCode
- Editor: VS Code

---

# Future Improvements

- Add multiple test cases
- Add dry run explanation
- Add input/output handling
- Add complexity comparison visuals

---

# Author

Devansh Jain  
B.Tech CSE Student | DSA + Backend Engineering Journey