#!/usr/bin/python3

n = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
p = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]

def rod_cut(n, p):
    if(n == 0):
        return 0
    else:
        s = 0
        for i in range(1, n):
            r = rod_cut(n - i, p)
            t = p[i-1] + r
            if(t > s):
                s = t
    return s

def main():
    s = rod_cut(len(n)+1, p)
    print(s)

if __name__ == "__main__":
    main()

