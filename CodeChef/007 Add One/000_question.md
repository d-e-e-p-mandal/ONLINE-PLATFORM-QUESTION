# Add One

**Problem Link:** https://www.codechef.com/problems/ADDONE  

You are given a very large number **N**. Your task is to print **N + 1**.

⚠️ **Important:**  
The number **N** is too large to fit in standard integer data types, so you must treat it as a **string** and manipulate its digits manually.

---

## Input Format

- The first line contains an integer **T** — the number of test cases.
- For each test case, a single line contains a string **N** representing a large integer.

---

## Output Format

- For each test case, print a single line — the string representation of **N + 1**.

---

## Constraints

- `1 ≤ T ≤ 100`
- `1 ≤ N ≤ 10^(200000) − 1`
- The **total number of digits** across all test cases does not exceed `4 × 10^5`

---

## Sample Input

6
99
17
1
599
10000000000000000000
549843954323494990404

## Sample Output

100
18
2
600
10000000000000000001
549843954323494990405

---

## Explanation

- **Testcase 1:**  
  `99 + 1 = 100`

- **Testcase 2:**  
  `17 + 1 = 18`

- **Testcase 3:**  
  `1 + 1 = 2`

- **Testcase 4:**  
  `599 + 1 = 600`

- **Testcase 5:**  
  `10000000000000000000 + 1 = 10000000000000000001`

- **Testcase 6:**  
  `549843954323494990404 + 1 = 549843954323494990405`

---

## More Info

- **Time Limit:** 1 second  
- **Memory Limit:** 1.5 GB  
- **Source Limit:** 50000 Bytes