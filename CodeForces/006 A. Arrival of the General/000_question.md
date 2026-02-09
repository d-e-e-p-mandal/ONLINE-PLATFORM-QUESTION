# A. Arrival of the General

**Time Limit:** 2 seconds  
**Memory Limit:** 256 megabytes  
**Problem Link:** https://codeforces.com/problemset/problem/144/A  

A general comes to inspect a military squad of **n** soldiers lined up on a parade ground.

According to military rules, soldiers should be ordered by **non-increasing height**, but there’s no time for full sorting. Luckily, the general is short-sighted and considers the lineup **correct** if:

- The **first soldier** has the **maximum height**
- The **last soldier** has the **minimum height**

The order of the soldiers in between does **not** matter.  
If there are multiple soldiers with the same maximum or minimum height, **any one** of them is acceptable.

In one second, the colonel can swap **any two neighboring soldiers**.

Your task is to find the **minimum number of seconds** needed to make the lineup acceptable to the general.

---

## Input

- The first line contains an integer `n` (`2 ≤ n ≤ 100`) — the number of soldiers.
- The second line contains `n` integers `a₁, a₂, …, aₙ` (`1 ≤ aᵢ ≤ 100`) — the heights of the soldiers in their current order.

---

## Output

- Print a single integer — the **minimum number of seconds** required.

---

## Examples

### Input

4
33 44 11 22

### Output

2

---

### Input

7
10 10 58 31 63 40 76

### Output

10

---

## Explanation

### Key Idea
- Move the **tallest soldier** to the **front** using adjacent swaps.
- Move the **shortest soldier** to the **end** using adjacent swaps.
- Be careful: if the shortest soldier is **before** the tallest soldier initially, one move overlaps and should be subtracted by `1`.

---

### Example 1
Heights: `(33, 44, 11, 22)`

- Max height `44` → index `1` → needs `1` swap to reach front
- Min height `11` → index `2` → needs `1` swap to reach end

Total swaps = `1 + 1 = 2`

---

### Example 2
Heights: `(10, 10, 58, 31, 63, 40, 76)`

- Max height `76` → move to front
- Min height `10` → move to end
- Total minimum swaps required = `10`

---

This approach guarantees the minimum time needed for the colonel to satisfy the general.