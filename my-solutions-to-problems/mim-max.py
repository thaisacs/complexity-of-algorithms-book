#!/usr/bin/python3
import math

def MinMax(A, i, j):
    if(i == j):
        Max = A[i]
        Min = A[i]
    elif(i + 1 == j):
        if(A[i] <= A[j]):
            Max = A[j]
            Min = A[i]
        else:
            Max = A[i]
            Min = A[j]
    else:
        mid = math.floor((i+j)/2)
        Min, Max = MinMax(A, i, mid)
        Min2, Max2 = MinMax(A, mid + 1, j)
        Max = Max2
        print(Min, Max2)
    return Min, Max

def main():
    A = [50, 3, 1, 5, 7, 8, 10, 2, 3]
    Min, Max = MinMax(A, 0, len(A)-1)
    print(Min, Max)


if __name__ == "__main__":
    main()

