# A. Carnival Wheel

**Time Limit:** 1 second  
**Memory Limit:** 256 megabytes  
**Problem Link:** https://codeforces.com/problemset/problem/2030/A  

You have a prize wheel divided into **l** sections, numbered from `0` to `l−1`, arranged in a circle.

- Initially, the pointer is at section **a**.
- Each spin moves the pointer **b** sections forward (modulo `l`).
- You may spin the wheel **any number of times**, including zero.
- After stopping, you receive a prize equal to the **number of the section** where the pointer lands.

Your goal is to determine the **maximum prize** you can obtain.

---

## Input

- The first line contains an integer `t` (`1 ≤ t ≤ 500`) — the number of test cases.
- Each test case contains three integers:
  - `l` — number of sections (`1 ≤ l ≤ 5000`)
  - `a` — starting section (`0 ≤ a ≤ l−1`)
  - `b` — number of sections moved per spin (`1 ≤ b ≤ 5000`)

---

## Output

- For each test case, output a single integer — the **maximum prize** that can be obtained.

---

## Example

### Input

4
5 3 2
2 0 6
8 2 4
100 0 1

### Output

4
0
6
99

---

## Explanation

- **Test case 1:**  
  Positions reached: `3 → 0 → 2 → 4 → 1 → ...`  
  Maximum reachable section = `4`

- **Test case 2:**  
  Pointer always stays at section `0`  
  Maximum prize = `0`

- **Test case 3:**  
  Reachable sections: `2 → 6 → 2 → ...`  
  Maximum prize = `6`

- **Test case 4:**  
  Since `b = 1`, all sections are visited  
  Maximum prize = `99`

---

## Key Idea

The pointer only visits sections of the form:

(a + k·b) mod l

This forms a cycle.  
The answer is the **maximum value** among all reachable sections in that cycle.