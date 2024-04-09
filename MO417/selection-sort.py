#!/usr/bin/python3

def selection_sort(x):
    for i in range(0, len(x)-1):
        index_min = i
        for j in range(i+1, len(x)):
            if(x[index_min] > x[j]):
                index_min = j
        z = x[i]
        x[i] = x[index_min]
        x[index_min] = z
    return x


def main():
    x = [6, 5, 4, 3]
    y = selection_sort(x)
    print(y)

if __name__ == "__main__":
    main()

