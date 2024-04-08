#!/usr/bin/python3

def intercala(x, p, m, q):
    a = []
    for i in range(p, m+1):
        a.append(x[i])
    b = []
    for i in range(m+1, q+1):
        b.append(x[i])
    c = []
    max_len = len(a)
    if(len(c) > max_len):
        max_len = len(c)
    a_index = 0
    b_index = 0
    while(a_index < len(a) and b_index < len(b)):
        if(a[a_index] < b[b_index]):
            c.append(a[a_index])
            a_index = a_index + 1
        else:
            c.append(b[b_index])
            b_index = b_index + 1
    while(a_index < len(a)):
        c.append(a[a_index])
        a_index = a_index + 1
    while(b_index < len(b)):
        c.append(b[b_index])
        b_index = b_index + 1
    j = p
    for i in range(len(c)):
        x[j] = c[i]
        j = j + 1

def merge_sort(x, p, q):
    if(p != q):
        m = int((p+q)/2)
        merge_sort(x, p, m)
        merge_sort(x, m+1, q)
        x = intercala(x, p, m, q)
    return x

def main():
    x = [6, 5, 4, 3, 11, 34, 32, 9, 10]
    merge_sort(x, 0, 8)
    print(x)

if __name__ == "__main__":
    main()

