#!/usr/bin/python3

import math

def maximum(S):
    return S[0]

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

def extract_max(S):
    S[0] = S[len(S) - 1]
    S = S[:len(S) - 1]
    max_heapify(S, len(S), 0)
    return S

def increase_max(S, x, p):
    S[x] = p
    x_l = math.floor((x+1)/2) - 1
    while(x_l >= 0 and S[x_l] < S[x]):
        buff = S[x_l]
        S[x_l] = S[x]
        S[x] = buff
        x = x_l
        x_l = math.floor((x+1)/2) - 1

def insert(S, p):
    S.append(-1)
    increase_max(S, len(S)-1, p)

def main():
    S = []
    insert(S, 2)
    insert(S, 4)
    insert(S, 5)
    insert(S, 8)
    insert(S, 9)
    insert(S, 11)
    S = extract_max(S)
    print(S)

if __name__ == "__main__":
    main()

