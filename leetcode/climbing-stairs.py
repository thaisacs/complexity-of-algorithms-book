#!/usr/bin/python3

import numpy as np

nums = [-2,1,-3,4,-1,2,1,-5,4]

def climbing(n):
    one, two = 1, 1

    for i in range(n-1):
        temp = one
        one = one + two
        two = temp

    return one

def main():
    m = climbing(5)
    print(m)

if __name__ == "__main__":
    main()

