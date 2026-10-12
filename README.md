# interviewer-code-archive

These are coding problems I used as a reference when interviewing software engineering candidates. I worked through them as I moved from software engineer to software engineering manager, and later to senior software engineering manager. Before asking a problem in an interview, I coded it myself in C++ to understand it better: where the tricky parts were, the different ways to approach it, and what a strong answer looks like.

## Problems by category

| Category | Problems |
|---|---|
| [Dynamic programming](dynamic-programming/) | Decode Ways, Edit Distance (Dictionary Distance), Longest Common Subsequence, Optimal Strategy for a Game (Max Winning Sum), Maximum Vacation Days, Minimum Path Sum, Palindrome Partitioning |
| [Backtracking](backtracking/) | N-Queens, Graph Coloring, String Permutations, Phone Keypad Letter Combinations, Remove Invalid Parentheses, Strobogrammatic Numbers |
| [Graphs and search](graphs-and-search/) | Depth-First Search, Number of Islands, Word Ladder |
| [Trees](trees/) | Print Range in a Binary Search Tree, Serialize and Deserialize a Binary Tree |
| [Arrays and strings](arrays-and-strings/) | Add One (big integer stored as a digit array), Decimal to Binary, Read N Characters Given Read4, Bold Words in a String |

Each `.cpp` file is self-contained with its own `main`, so you can compile and run it directly:

```bash
g++ -std=c++17 dynamic-programming/DecodeWays.cpp -o decode-ways && ./decode-ways
```
