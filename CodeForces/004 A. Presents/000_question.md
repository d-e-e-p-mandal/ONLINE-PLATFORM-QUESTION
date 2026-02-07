# A. Presents

**Time Limit:** 2 seconds  
**Memory Limit:** 256 megabytes  
**Problem Link:** https://codeforces.com/problemset/problem/136/A  

Little Petya loves gifts. At a New Year party, he invited **n** friends and watched them exchange gifts among themselves.

Petya numbered his friends from `1` to `n`. He remembers that **friend `i` gave a gift to friend `p_i`**, and each friend received **exactly one gift**.

Now Petya wants to know: **for each friend `i`, who gave a gift to them**.

---

## Input

- The first line contains one integer `n` (`1 ≤ n ≤ 100`) — the number of friends.
- The second line contains `n` space-separated integers `p₁, p₂, ..., pₙ`, where `pᵢ` is the friend who received a gift from friend `i`.

Notes:
- Every friend receives exactly one gift.
- Some friends may give gifts to themselves.

---

## Output

- Print `n` space-separated integers.
- The `i`-th number should be the friend who gave a gift to friend `i`.

---

## Examples

### Input

4
2 3 4 1

### Output

4 1 2 3

---

### Input

3
1 3 2

### Output

1 3 2

---

### Input

2
1 2

### Output

1 2

---

## Explanation

- If friend `i` gives a gift to friend `pᵢ`, then **friend `pᵢ` received a gift from friend `i`**.
- We simply reverse the mapping to find the giver for each friend.