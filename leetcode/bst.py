#!/usr/bin/python3

def numberOfBST(n):
    dp = [0] * (n + 1)
    dp[0], dp[1] = 1, 1
    for i in range(2, n + 1):
        for j in range(1, i + 1):
            dp[i] = dp[i] + (dp[i - j] * dp[j - 1])
    return dp[n]

def main():
    x = numberOfBST(5)
    print(x)

if __name__ == "__main__":
    main()

