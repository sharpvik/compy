# Explanation | #2

This is a **very** easy problem, thus its explanation is going to be small. Here,

1. Bill can only consume cups in the exact order his coffee machine produced those.
2. We want to find the **maximum** number of cups he can consume until his caffeine level passes 100 CU.

We need to go through the input array and see if current cup's value, when added to Bill's current caffeine level will surpass the limit of 100 CU.

In pseudocode:

```txt
counter = 0
for cup in INPUT:
    if cup + K > 100:
        break
    else:
        K = K + cup
        counter = counter + 1
```