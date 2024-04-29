#!/usr/bin/python3

from merge_sort import merge_sort
import math

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

def partition_bfprt(A, p, r):
    l = p
    j = p
    while(j + 4 < r):
        merge_sort(A, j, j + 4)
        swap(A, l, j + 2)
        j = j + 5
        l = l + 1
    merge_sort(A, j, r)
    swap(A, l, math.floor((j + r) / 2))
    m = l - p + 1
    k = selection_bfprt(A, p, l, math.floor(m / 2))
    swap(A, k, r)
    return partition(A, p, r)

def selection_bfprt(A, p, r, i):
    if(p == r):
        return A[p]
    q = partition_bfprt(A, p, r)
    k = q - p + 1
    if(i == k):
        return A[q]
    else:
        if(i < k):
            return selection_bfprt(A, p, q - 1, i)
        else:
            return selection_bfprt(A, q + 1, r, i - k)

def main():
    A = [50, 3, 6, 5, 7, 8, 10, 2, 4]
    x = selection_bfprt(A, 0, len(A) - 1, 4)
    print(x)

if __name__ == "__main__":
    main()

