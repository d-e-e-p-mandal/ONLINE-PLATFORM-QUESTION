# ATM

**Problem Link:** https://www.codechef.com/problems/HS08TEST  

Pooja wants to withdraw **X** dollars from an ATM. The transaction will be successful only if:

- **X** is a multiple of `5`
- Pooja has enough balance to cover **X + 0.50** (bank charge)

For every successful withdrawal, the bank deducts **0.50 dollars** as a transaction fee.

Your task is to calculate the account balance after the attempted transaction.

---

## Input Format

- A positive integer **X** (`0 < X ≤ 2000`) — the amount Pooja wants to withdraw.
- A non-negative number **Y** (`0 ≤ Y ≤ 2000`) with exactly two digits of precision — the initial account balance.

---

## Output Format

- Print the account balance after the attempted transaction.
- The output should have **exactly two digits of precision**.
- If the transaction cannot be completed, print the **original balance**.

---

## Sample Input

30 120.00

## Sample Output

89.50

---

## Explanation

- `30` is a multiple of `5`
- Total deduction = `30 + 0.50 = 30.50`
- Remaining balance = `120.00 - 30.50 = 89.50`

---

## Sample Input

42 120.00

## Sample Output

120.00

### Reason  
Withdrawal amount is **not** a multiple of `5`.

---

## Sample Input

300 120.00

## Sample Output

120.00

### Reason  
Insufficient balance to complete the transaction.

---

## More Info

- **Time Limit:** 1 second  
- **Memory Limit:** 1.5 GB  
- **Source Limit:** 50000 Bytes