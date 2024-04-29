#!/usr/bin/python3

import numpy as np

nums = [-2,1,-3,4,-1,2,1,-5,4]
nums = [5,4,-1,7,8]
memo = np.zeros(len(nums), int)

def maximum_subarray(nums, n):
    memo[0] = nums[0]
    for x in range(1, n): 
        if(nums[x] + memo[x-1] > nums[x]):
            memo[x] = nums[x] + memo[x-1]
        else:
            memo[x] = nums[x]
    m = memo[0]
    for x in range(1, n): 
        if(memo[x] > m):
            m = memo[x]
    return m

def main():
    m = maximum_subarray(nums, len(nums))
    print(m)

if __name__ == "__main__":
    main()

