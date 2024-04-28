#!/usr/bin/python3
import math

def Min(A, n):
    if(n == 0):
        return A[0]
    else:
        v = Min(A, n - 1)
        if(v > A[n]):
            return A[n]
        else:
            return v

def main():
    A = [50, 3, 1, 5, 7, 8, 100, 2, 3]
    M = Min(A, len(A)-1)
    print(M)


if __name__ == "__main__":
    main()

