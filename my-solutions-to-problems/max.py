#!/usr/bin/python3
import math

def Max(A, n):
    if(n == 0):
        return A[0]
    else:
        v = Max(A, n - 1)
        if(v < A[n]):
            return A[n]
        else:
            return v

def main():
    A = [50, 3, 1, 5, 7, 8, 100, 2, 3]
    M = Max(A, len(A)-1)
    print(M)


if __name__ == "__main__":
    main()

