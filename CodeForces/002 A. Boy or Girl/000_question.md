# A. Boy or Girl

**Time Limit:** 1 second  
**Memory Limit:** 256 megabytes  

[Problem Link](https://codeforces.com/problemset/problem/236/A)

In online forums, it’s often hard to guess a user’s gender just by their avatar. So our hero devised a simple rule based on the **user name**.

### Hero’s Rule
- Count the number of **distinct characters** in the user name.
- If the count is **odd** → the user is **male**
- If the count is **even** → the user is **female**

Your task is to apply this rule and determine what should be printed.

---

## Input

- A single non-empty string consisting of **only lowercase English letters**.
- Length of the string is at most **100**.

---

## Output

- Print **`CHAT WITH HER!`** if the user is **female**.
- Print **`IGNORE HIM!`** if the user is **male**.

---

## Examples

### Input
wjmzbmr

### Output
CHAT WITH HER!

---

### Input
xiaodao
### Output
IGNORE HIM!

---

### Input
sevenkplus
### Output
CHAT WITH HER!

---

## Explanation

For the input `wjmzbmr`:

Distinct characters are:  
`w, j, m, z, b, r` → **6 distinct characters**

Since `6` is even, the user is considered **female**, so the output is:
CHAT WITH HER!