# interviewer-code-archive

These are coding problems I used as a reference when interviewing software engineering candidates. I worked through them as I moved from software engineer to software engineering manager, and later to senior software engineering manager. Before asking a problem in an interview, I coded it myself in C++ to understand it better: where the tricky parts were, the different ways to approach it, and what a strong answer looks like.

## Problems by category

| Category | Problems |
|---|---|
| [Dynamic programming](dynamic-programming/) | Decode Ways, Edit Distance (Dictionary Distance), Longest Common Subsequence, Optimal Strategy for a Game (Max Winning Sum), Maximum Vacation Days, Palindrome Partitioning |
| [Backtracking](backtracking/) | N-Queens, Graph Coloring, String Permutations |
| [Graphs and search](graphs-and-search/) | Depth-First Search, Number of Islands, Word Ladder |
| [Arrays and strings](arrays-and-strings/) | Add One (big integer stored as a digit array) |

Each `.cpp` file is self-contained with its own `main`, so you can compile and run it directly:

```bash
g++ -std=c++17 dynamic-programming/DecodeWays.cpp -o decode-ways && ./decode-ways
```
