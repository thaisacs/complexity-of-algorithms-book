#!/usr/bin/python3
import numpy as np

s = "babad"
s = "forgeeksskeegfor"
size = len(s)

memo = np.ones((size, size), int)*-1

def palindromic(s, i, j):
    if(memo[i][j] == -1):
        if(i == j):
            memo[i][j] = 1
        else:
            if(s[i] == s[j]):
                if(i + 1 == j):
                    memo[i][j] = 2
                else:
                    memo[i][j] = 2 + palindromic(s, i+1, j-1)
            else:
                x = palindromic(s, i+1, j)
                y = palindromic(s, i, j-1)
                if(x < y):
                    memo[i][j] = y
                else:
                    memo[i][j] = x
    return memo[i][j]


def main():
    x = palindromic(s, 0, size-1)
    print(memo)


if __name__ == "__main__":
    main()

