#!/usr/bin/python3

p = [7,6,4,3,1]

def word_break(s, word_dict):
    dp = [False] * (len(s) + 1)
    dp[len(s)] = True

    for i in range(len(s) -1, -1, -1):
        for w in word_dict:
            if((i + len(w)) <= len(s) and s[i : i + len(w)] == w):
                dp[i] = dp[i + len(w)]
            if(dp[i]):
                break
    return dp[0]


def main():
    s = "leetcode"
    word_dict = ["leet", "code"]
    r = word_break(s, word_dict)
    print(r)

if __name__ == "__main__":
    main()

