#!/usr/bin/python3

def scm(x, n):
    if(n == -1):
        i = 1
        j = 1
        k = 1
        maxSuf = 0
        maxSeq = 0
    else:
        i, j, k, maxSuf, maxSeq = scm(x, n-1)
        maxSuf = maxSuf + x[n]
        if(maxSuf < 0):
            k = n + 1
            maxSuf = 0
        if(maxSeq < maxSuf):
            i = k
            j = n
            maxSeq = maxSuf
    return i, j, k, maxSuf, maxSeq

def main():
    x = [4, 2, -7, 3, 0, -2, 1, 5, -2]
    i, j, k, maxSuf, maxSeq = scm(x, 8)
    print(i, j)

if __name__ == "__main__":
    main()

