# DNA Storage

**Problem Link:** https://www.codechef.com/problems/DNASTORAGE  

You are given an even-length binary string **S**.  
To encode it into a DNA sequence, process the string from **left to right** in pairs of two characters:

| Binary Pair | Encoded As |
|-------------|------------|
| `00`        | `A`        |
| `01`        | `T`        |
| `10`        | `C`        |
| `11`        | `G`        |

Your task is to generate the encoded sequence.

---

## Input Format

- The first line contains an integer **T** — number of test cases.
- For each test case:
  - First line contains integer **N** — length of the binary string.
  - Second line contains the binary string **S** of length **N**.

---

## Output Format

- For each test case, print the encoded DNA string in a single line.
- Output is **case-sensitive**.

---

## Constraints

- `1 ≤ T ≤ 100`
- `2 ≤ N ≤ 1000`
- `N` is even
- Sum of `N` over all test cases ≤ `1000`
- `S` contains only `'0'` and `'1'`

---

## Sample Input

4
2
00
4
0011
6
101010
4
1001

## Sample Output

A
AG
CCC
CT

---

## Explanation

- **Test Case 1:**  
  `00 → A`

- **Test Case 2:**  
  `00 → A`  
  `11 → G`  
  Result: `AG`

- **Test Case 3:**  
  `10 → C`  
  `10 → C`  
  `10 → C`  
  Result: `CCC`

- **Test Case 4:**  
  `10 → C`  
  `01 → T`  
  Result: `CT`

---

## Key Idea

- Traverse the string in steps of `2`.
- Convert each pair using the given mapping.
- Append the corresponding character to the result string.