#!/usr/bin/python3

import numpy as np

nums = [-2,1,-3,4,-1,2,1,-5,4]

def maximum_subarray(nums, n):
    res = max(nums)
    curMin, curMax = 1, 1

    for n in nums:
        if n == 0:
            curMin, curMax = 1, 1
            continue
        tmp = curMax * n
        curMax = max(tmp, n * curMin, n)
        curMin = min(tmp, n * curMin, n)
        res = max(res, curMax)

    return res

def main():
    m = maximum_subarray(nums, len(nums))
    print(m)

if __name__ == "__main__":
    main()

