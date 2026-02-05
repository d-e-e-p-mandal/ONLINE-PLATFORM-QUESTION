# A. Helpful Maths

**Time Limit:** 2 seconds  
**Memory Limit:** 256 megabytes  
**Problem Link:** https://codeforces.com/problemset/problem/339/A  

Xenia is a beginner mathematician who is learning addition. To make calculations easier, she can only calculate sums if the numbers are arranged in **non-decreasing order**.

The sum written on the board consists only of the numbers `1`, `2`, and `3`, separated by `'+'`. Your task is to **rearrange the summands** so that Xenia can easily calculate the sum.

---

## Input

- A single non-empty string `s` representing the sum.
- The string contains only digits (`1`, `2`, `3`) and the `'+'` character.
- The length of the string is at most **100**.
- The input is guaranteed to be a valid sum.

---

## Output

- Print the rearranged sum where the numbers are in **non-decreasing order**, separated by `'+'`.

---

## Examples

### Input

3+2+1

### Output

1+2+3

---

### Input

1+1+3+1+3

### Output

1+1+1+3+3

---

### Input

2

### Output

2

---

## Explanation

- Extract all numbers from the sum.
- Sort them in non-decreasing order.
- Join them back using `'+'`.

This rearranged sum can now be easily calculated by Xenia.