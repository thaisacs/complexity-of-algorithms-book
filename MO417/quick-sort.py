#!/usr/bin/python3
import sys
sys.setrecursionlimit(1500000)
print(sys.getrecursionlimit())

import numpy as np
import random
import time

def swap(A, i, j):
    aux = A[i]
    A[i] = A[j]
    A[j] = aux

def partition_random(A, p, r):
    i = random.randint(p, r)
    swap(A, r, i)
    return partition(A, p, r)

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

def quick_sort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quick_sort(A, p, q - 1)
        quick_sort(A, q + 1, r)

def quick_sort_random(A, p, r):
    if p < r:
        q = partition_random(A, p, r)
        quick_sort(A, p, q - 1)
        quick_sort(A, q + 1, r)

def main():
    A = np.random.randint(100000, size=10000)
    print("unsorted:", A)
    quick_sort(A, 0, len(A)-1)
    print("  sorted:", A)
    start = time.time()
    quick_sort(A, 0, len(A)-1)
    end = time.time()
    print("  sorted:", A)
    print(end - start)
    start = time.time()
    quick_sort_random(A, 0, len(A)-1)
    end = time.time()
    print("  sorted:", A)
    print(end - start)

if __name__ == "__main__":
    main()

