# A. Watermelon

**Time Limit:** 1 second  
**Memory Limit:** 64 megabytes  
**Problem Link:** https://codeforces.com/problemset/problem/4/A  

Pete and Billy bought a watermelon weighing **w** kilos. They want to divide it into **two parts**, such that:

- Each part has **positive weight**
- Each part has an **even number of kilos**
- The two parts do **not** need to be equal

Your task is to determine whether such a division is possible.

---

## Input

- A single integer `w` (`1 ≤ w ≤ 100`) — the weight of the watermelon.

---

## Output

- Print `"YES"` if the watermelon can be divided into two **positive even** parts.
- Otherwise, print `"NO"`.

---

## Example

### Input

8

### Output

YES

---

## Explanation

For `w = 8`, possible divisions include:

- `2 + 6`
- `4 + 4`

Both parts are positive and even, so the answer is **YES**.

---

## Key Idea

To split `w` into two positive even numbers:

- `w` must be **even**
- `w` must be **greater than 2**

If `w > 2` and `w` is even → print `"YES"`  
Otherwise → print `"NO"`