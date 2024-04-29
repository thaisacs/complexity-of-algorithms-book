#!/usr/bin/python3

p = [7,6,4,3,1]

def maxProfit(p, n):
    if(n == 0):
        i = 0
        j = 0
        k = 0
        MS = 0
        SS = 0
    else:
        i, j, k, MS, SS = maxProfit(p, n - 1)
        SS = p[n] - p[k]

        if(SS < 0):
            k = n
            SS = 0

        if(MS < SS):
            i = k
            j = n
            MS = SS

    return i, j, k, MS, SS


def main():
    i, j, k, MS, SS = maxProfit(p, len(p)-1)
    print(MS)

if __name__ == "__main__":
    main()

