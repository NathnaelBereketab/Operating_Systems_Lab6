# Operating Systems Lab 6 — Function Pointers

**Author:** Nathnael Bereketab  

---

## Overview

This lab explores **Function Pointers in C** through two practical tasks:

- **Task 1:** Implement a custom comparison function to sort process structures using `qsort()` and function pointers.  
- **Task 2:** Build a simple calculator that performs mathematical operations using **function pointer arrays** instead of conditionals.

---

## 🧾 Task 1 — Process Sorting via Function Pointer

### Goal
Implement a comparer function, `my_comparer()`, to sort an array of `Process` structs using `qsort()`.

### Sorting Rules
1. Sort by **priority** in ascending order (lower number = higher priority).  
2. If priorities are equal, sort by **arrival time** in ascending order.  
3. If still equal, sort by **PID** in ascending order.  

---

### Run Instructions

\`\`\`bash
make
./task1/qsort task1/test-data/test1.csv
\`\`\`

### Example Output

\`\`\`
2 (0, 4)
7 (0, 14)
1 (1, 2)
3 (1, 6)
4 (2, 8)
5 (3, 10)
6 (3, 12)
\`\`\`

---

## Task 2 — Function Pointer Calculator 

### Goal

Create a calculator that performs different arithmetic operations based on user input, without using any conditional statements.

---

### Operations

| Input | Operation | Example Result |
|:------|:-----------|:---------------|
| 0 | Add | x = 9 |
| 1 | Subtract | x = 3 |
| 2 | Multiply | x = 18 |
| 3 | Divide | x = 2 |
| 4 | Exit | Program terminates |

---

### Run Instructions

\`\`\`bash
./task2/func_ptr
\`\`\`

### Example Output

\`\`\`
Operand 'a': 6 | Operand 'b': 3
Specify the operation to perform (0:add | 1:subtract | 2:multiply | 3:divide | 4:exit): 2
Multiplying 'a' and 'b'
x = 18
\`\`\`

---

## Compilation Commands

### Build all executables:

\`\`\`bash
make
\`\`\`

### Clean compiled binaries:

\`\`\`bash
make clean
\`\`\`

---

## Author

**Nathnael Bereketab**  
