#!/usr/bin/python3

def pascals(n):
    triangle = [[1], [1, 1]]
    if(n == 1):
        return [triangle[0]]
    if(n == 2):
        return [triangle[1]]
    for i in range(3, n+1):
        line = [1]
        for j in range(2, i):
            line.append(triangle[i-2][j-2] + triangle[i-2][j-1])
        line.append(1)
        triangle.append(line)
    return triangle


def main():
    x = pascals(5)
    print(x)

if __name__ == "__main__":
    main()

