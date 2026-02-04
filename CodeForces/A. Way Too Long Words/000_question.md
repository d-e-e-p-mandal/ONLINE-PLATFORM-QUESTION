# A. Way Too Long Words

**Time Limit:** 1 second  
**Memory Limit:** 256 megabytes  

Sometimes some words like `"localization"` or `"internationalization"` are so long that writing them many times in one text is quite tiresome.

Let's consider a word **too long** if its length is **strictly more than 10 characters**. All too long words should be replaced with a special abbreviation.

The abbreviation is made as follows:
- Write the **first letter** of the word
- Write the **number of letters between** the first and last letter
- Write the **last letter** of the word

The number is written in decimal and contains no leading zeroes.

Examples:
- `"localization"` → `l10n`
- `"internationalization"` → `i18n`

Words that are not too long should remain unchanged.

---

## Input

The first line contains an integer `n` (`1 ≤ n ≤ 100`).  
Each of the following `n` lines contains one word.

- All words consist of lowercase Latin letters.
- Each word has a length from `1` to `100`.

---

## Output
6

Print `n` lines.  
The `i`-th line should contain the transformed version of the `i`-th word.

---

## Example

### Input
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis

### Output
word
l10n
i18n
p43s

