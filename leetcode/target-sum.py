import numpy as np

def findTargetSumWays(memo, nums, target):
    if(len(nums) == 0 and target == 0):
        return 1
    if(len(nums) == 0):
        return 0
    print(memo)
    print(len(nums))
    print(target)
    if(memo[len(nums)][target] == -1):
        r1 =  findTargetSumWays(memo, nums[1:len(nums)], target - nums[0])
        r2 =  findTargetSumWays(memo, nums[1:len(nums)], target + nums[0])
        memo[len(nums)][target] = r1 + r2
    return memo[len(nums)][target]

def main():
    nums = [1000]
    target = -1000
    if(target < 0):
        target = -1*target
    memo = np.ones((len(nums)+1, sum(nums)+target+1), dtype=int)*-1
    r = findTargetSumWays(memo, nums, target)
    print(r)

if __name__ == "__main__":
    main()
