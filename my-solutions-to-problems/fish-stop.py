#!/usr/bin/python3

def fish_stops(F, m, t):
    solution = [0]
    last = F[0]
    for i in range(1, len(F) - 1):
        if(F[i] - last <= m and F[i+1] - last > m):
            solution.append(F[i])
            last = F[i]
    solution.append(t)
    return solution

def main():
    F = [0, 4, 6, 10, 12]
    F = [0, 3, 4, 6, 10, 12]
    s = fish_stops(F, 4, 12)
    print(s)

if __name__ == "__main__":
    main()

