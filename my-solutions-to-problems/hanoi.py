#!/usr/bin/python3

def hanoi(n, s, d, a):
    if(n == 0):
        return
    hanoi(n-1, s, a, d)
    print("=> {}: {} => {}".format(n, s, d))
    hanoi(n-1, a, d, s)


def main():
    n = 3
    hanoi(n, 'A', 'C', 'B')

if __name__ == "__main__":
    main()

