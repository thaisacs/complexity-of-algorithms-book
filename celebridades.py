
S = [0, 1, 2, 3]
M = [[0, 0, 0, 0],
     [1, 0, 0, 0],
     [1, 0, 0, 1],
     [1, 0, 0, 1]]

def celebridades(S, M):
    if(len(S) == 1):
        return S[0]
    else:
        i = S[0]
        j = S[1]
        s = i
        if(M[i][j] == 0):
            s = j
        if(s == j):
            S[1] = S[0]
        S_l = S[1:]
        k = celebridades(S_l, M)
        if(k != None and (M[k][s] == 1 or M[s][k] == 0)):
            return None
    return k

def main():
    k = celebridades(S, M)
    print(k)

if __name__ == "__main__":
    main()

