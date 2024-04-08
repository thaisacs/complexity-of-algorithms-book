#!/usr/bin/python3

def heap_max(A, n):
    return A[0]

def heap_extract_max(A, n):
    A_l = A[0:n-1]
    A_l[0] = A[n-1]
    max_heapify(A_l, n-1, 0)
    return A_l

def heap_increase_key(A, i, chave):
    A[i] = chave
    k = int(i/2)
    while(k >= 0 and A[k] < A[i]):
        buff = A[i]
        A[i] = A[k]
        A[k] = buff
        i = k
        k = int(i/2)


def max_heap_insert(A, n, chave):
    A.append(-1)
    heap_increase_key(A, n, chave)

def max_heapify(A, n, i):
    e = 2*i+1
    d = 2*i+2
    maior = i
    if(e < n and A[e] > A[maior]):
        maior = e
    if(d < n and A[d] > A[maior]):
        maior = d
    if(maior != i):
        buff = A[maior]
        A[maior] = A[i]
        A[i] = buff
        max_heapify(A, n, maior)

def build_max_heap(A, n):
    for i in range(int(n/2), -1, -1):
        max_heapify(A, n, i)
    return A

def heap_sort(A, n):
    for i in range(n-1, -1, -1):
        buff = A[i]
        A[i] = A[0]
        A[0] = buff
        max_heapify(A, i-1, 0)

def main():
    x = [6, 5, 4, 3, 10, 11, 12]
    print(x)
    build_max_heap(x, len(x))
    max_heap_insert(x, len(x), 100)
    print(x)

if __name__ == "__main__":
    main()

