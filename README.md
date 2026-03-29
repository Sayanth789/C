# C Programming Algorithms & Experiments

![C](https://img.shields.io/badge/language-C-blue)
![Algorithms](https://img.shields.io/badge/topic-algorithms-green)
![License](https://img.shields.io/badge/license-MIT-orange)

A collection of **C programs, algorithms, and system-level experiments** written while learning and exploring the C programming language.

This repository contains implementations of **algorithms, data structures, utilities, and small experiments** designed to understand how low-level programming works.

The goal of this repository is to serve as a **reference and learning resource** for programmers interested in C and systems programming.

⭐ If you find this repository useful, please consider giving it a star.

---

# 📸 Repository Preview

This repository contains implementations of classic algorithms and systems programming experiments written in C.

Topics include:

* Sorting Algorithms
* Graph Algorithms
* Dynamic Programming
* Bit Manipulation
* Networking (TCP Client/Server)
* Pointer Experiments

---

# 📂 Repository Navigation

Click a folder below to explore the implementations.

* 📁 [DataStructures](./Datastructure)
* 📁 [Dynamic Programming](./DynamicProgramming)
* 📁 [Sorting Algorithms](./Sorting)
* 📁 [Graphs](./graphs)
* 📁 [Search Algorithms](./search)
* 📁 [Queues](./queue)
* 📁 [Pointers](./pointers)
* 📁 [Bit Manipulation](./bit_manipulation)
* 📁 [TCP Client-Server Example](./basic_client_server_tcp)
* 📁 [Mathematical Algorithms (x^y)](./x_power_y)

---

# 📚 Topics Covered

This repository includes implementations and experiments related to:

### Algorithms

* Sorting algorithms
* Search algorithms
* Graph algorithms
* Dynamic programming

### Data Structures

* Queues
* Linked list based implementations
* Basic structure implementations

### Low Level Programming

* Pointer experiments
* Memory manipulation
* Bit manipulation tricks

### Systems Programming

* TCP client/server communication in C

### Mathematical Algorithms

* Efficient power calculation (`x^y`)

---

# 🛠 Compiler Information

All programs are written in **standard C** and tested using the
entity["software","GNU Compiler Collection"] (**GCC**) on Linux.

Compile most programs with:

```bash
gcc program.c -o program
```

Some programs require linking with the math library:

```bash
gcc program.c -o program -lm
```

This is needed for functions like:

* `sqrt()`
* `pow()`
* `sin()`
* `tgamma()`

Programs may also compile with other compilers such as:

* entity["software","Clang","LLVM C compiler"]
* entity["software","Microsoft Visual C++","MSVC compiler"]

though examples are primarily tested with **GCC on Linux**.

---

# 🚀 Getting Started

Clone the repository:

```bash
git clone https://github.com/Sayanth789/C.git
cd C
```

Compile a program:

```bash
gcc program.c -o program
```

Run the program:

```bash
./program
```

---

# ⚡ Example: Binary Search

```c
int binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
```

---

# 🎯 Purpose of This Repository

This project was created to:

* Explore the **C programming language deeply**
* Implement classic **algorithms and data structures**
* Understand **low-level programming concepts**
* Practice **problem solving using C**

---

# 👨‍💻 Who This Repository Is For

This repository may be helpful for:

* Beginners learning C
* Students studying algorithms
* Developers exploring systems programming
* Anyone interested in low-level programming

---

# 🤝 Contributing

Contributions are welcome.

You can contribute by:

* Adding new algorithms
* Improving existing implementations
* Fixing bugs
* Adding explanations

---

# ⭐ Support

### 📜 “Those who know, do. Those that understand, teach.” — Aristotle

### 📜 “May thy curiosity guide thee, and may thy pursuit of knowledge never cease.”

## Good luck .... 🌹🌹🌹
