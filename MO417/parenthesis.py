#!/usr/bin/python3


def matrix_chain_mul(b, i, j):
    if(i == j):
        return 0
    else:
        s = 1e10
        for k in range(i, j):
            q = matrix_chain_mul(b, i, k) + matrix_chain_mul(b, k+1, j) + b[i-1]*b[k]*b[j]
            if(q < s):
                s = q
        return s

def main():
    b = [200, 2, 30, 20, 5]
    s = matrix_chain_mul(b, 1, 4)
    print(s)

if __name__ == "__main__":
    main()

