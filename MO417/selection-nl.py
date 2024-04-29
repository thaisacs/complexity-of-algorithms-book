#!/usr/bin/python3
import math
import sys
sys.setrecursionlimit(1500000)

def swap(A, x, y):
    buff = A[x]
    A[x] = A[y]
    A[y] = buff

def partition(A, p, r):
    pivo = A[r]
    i = p - 1
    j = p
    while(j < r):
        if(A[j] < pivo):
            i = i + 1
            swap(A, i, j)
        j = j + 1
    i = i + 1
    swap(A, i, j)
    return i

def selection(A, p, r, i):
    if(p == r):
        return A[p]
    q = partition(A, p, r)
    k = q - p + 1
    if(i == k):
        return A[q]
    else:
        if(i < k):
            return selection(A, p, q-1, i)
        else:
            return selection(A, q+1, r, i-k)

def main():
    A = [50, 3, 1, 5, 7, 8, 10, 2, 4]
    x = selection(A, 0, len(A)-1, 4)
    print(x)

if __name__ == "__main__":
    main()

