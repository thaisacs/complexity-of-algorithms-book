#!/usr/bin/python3

from math import floor

def find_max(x, i, j):
    if(i == j):
        return x[i]
    if(i == j + 1):
        if(x[i] > x[j]):
            return x[i]
        else:
            return x[j]
    else:
        q = floor((i + j)/2)
        left = q - 1
        right = q + 1
        if(x[left] < x[q] and x[right] > x[q]):
            return find_max(x, right, j)
        elif(x[left] > x[q] and x[right] < x[q]):
            return find_max(x, i, left)
        elif(x[left] == x[q]):
            return find_max(x, i, left)
        elif(x[right] == x[q]):
            return find_max(x, i, left)

    return x

def main():
    x = [1, 4, 4, 4, 11, 34, 32, 13, 10]
    x = [1, 4, 4, 4, 4, 4, 12, 13, 18, 30, 30, 30, 30, 1]
    r = find_max(x, 0, len(x)-1)
    print(r)

if __name__ == "__main__":
    main()

