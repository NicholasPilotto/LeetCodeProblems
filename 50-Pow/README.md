# Pow(x, n)

Implement ```pow(x, n)```, which calculates ```x``` raised to the power ```n``` (i.e., $x^n$).

## Example 1

```c
Input: x = 2.00000, n = 10
Output: 1024.00000
```

## Example 2

```c
Input: x = 2.10000, n = 3
Output: 9.26100
```

## Example 3

```c
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

## Constraints

```c
-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= x^n <= 104
```

## Solution

My solution consists of a recursive function that takes the base and the exponent as input for the calculation.

Base case is when ```n == 0```, ```0``` is returned.
If we are in the case where ```n < 0```, the operation can be seen as ```1 /``` $x^n$, where ```n``` is the absolute number of itself.

Than we calculate ```halfPow = n / 2```.

The result is:

- ```halfPow * halfPow```, if ```n``` is even
- ```x * halfPow * halfPow```, if ```n``` is odd

Calculating pow on half exponent transform algorithm as ```O(nlog(n))```, instead of ```O(n)```
