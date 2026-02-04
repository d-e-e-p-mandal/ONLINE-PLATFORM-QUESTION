# A. Tram

[Problem Link](https://codeforces.com/problemset/problem/116/A)

**Time Limit:** 2 seconds  
**Memory Limit:** 256 megabytes  

Linear Kingdom has exactly one tram line. It has **n** stops, numbered from `1` to `n` in the order of the tram's movement.

- At the *i-th* stop, `ai` passengers exit the tram.
- At the same stop, `bi` passengers enter the tram.

The tram is empty before it arrives at the first stop.  
When the tram arrives at the last stop, all passengers exit, so the tram becomes empty again.

At each stop, **all exiting passengers leave before any entering passengers enter**.

Your task is to calculate the **minimum capacity** of the tram such that the number of passengers inside the tram **never exceeds this capacity** at any moment.

---

## Input

- The first line contains a single integer `n` (`2 ≤ n ≤ 1000`) — the number of tram stops.
- The next `n` lines each contain two integers `ai` and `bi` (`0 ≤ ai, bi ≤ 1000`) — the number of passengers exiting and entering at the *i-th* stop.

Additional constraints:
- The number of exiting passengers never exceeds the number of passengers currently inside the tram.
- `a1 = 0`
- At the last stop, all passengers exit: `an` equals the number of passengers inside.
- No passengers enter at the last stop: `bn = 0`

---

## Output

Print a single integer — the minimum possible capacity of the tram (0 is allowed).

---

## Example

### Input
4
0 3
2 5
4 2
4 0
### Output
---

## Explanation

- **Stop 1:**  
  Passengers before arrival: `0`  
  Enter `3` → Current passengers: `3`

- **Stop 2:**  
  Exit `2` → Remaining: `1`  
  Enter `5` → Current passengers: `6`

- **Stop 3:**  
  Exit `4` → Remaining: `2`  
  Enter `2` → Current passengers: `4`

- **Stop 4 (last):**  
  Exit all remaining passengers → `0`

The maximum number of passengers at any time is `6`, so the minimum required capacity is **6**.