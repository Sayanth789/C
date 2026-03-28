  ## Dynamic Programming (DP)
🧱 🧱 🧱 🧱 🧱 🧱 🧱 🧱 🧱 🧱 🧱 🧱 

**Dynamic Programming** is an algorithm design technique used to solve problems by breaking them into smaller overlapping subproblems and storing the results to avoid recomputation.

Instead of solving the same subproblem multiple times, DP **stores the solution of each subproblem** (usually in a table or memoization cache) and reuses it when needed.

### Key Ideas

1. **Overlapping Subproblems**
   The problem can be divided into smaller subproblems that are solved repeatedly.

2. **Optimal Substructure**
   The optimal solution of the main problem can be constructed from the optimal solutions of its subproblems.

### Two Common Approaches

**1. Memoization (Top-Down)**
Solve the problem recursively and store the results of subproblems.
(The name come form the term "memo" (remembering something)).
Take  this example it calculate the 5th Fibonnaci number (which is either 3 or 5 - depending on 
implementation)

fib(5)
 ├─ fib(4)
 │   ├─ fib(3)
 │   └─ fib(2)
 └─ fib(3)

Here you can see fib(3) is computed twice, With memoization: 
      fib(3) → computed once
      store result
      next time → reuse stored value

**2. Tabulation (Bottom-Up)**
Build a table and solve smaller subproblems first, then use them to solve larger ones.

It start from **smallest subproblems**
Build the solutions **step by step** 
Uses **loops and tables.**

Here is an example: 
dp[0] = 0
dp[1] = 1
dp[2] = dp[1] + dp[0]
dp[3] = dp[2] + dp[1]
dp[4] = dp[3] + dp[2]
dp[5] = dp[4] + dp[3]

### Examples of Dynamic Programming Algorithms

* Fibonacci sequence
* Knapsack problem
* Longest Common Subsequence
* Matrix Chain Multiplication
* Shortest path algorithms

Dynamic Programming is widely used to **optimize recursive algorithms and reduce time complexity**.
