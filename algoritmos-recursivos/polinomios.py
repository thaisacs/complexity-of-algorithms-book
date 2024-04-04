
def calc_polinomios(a, x):
    print(a)
    if(len(a) == 1):
        y_linha = a[0]
    else:
        a_linha = a[1:len(a)]
        y = calc_polinomios(a_linha, x)
        y_linha = y*x + a[0]
    return y_linha


def main():
    a = [6, 5, 4, 3]
    x = 3
    y = calc_polinomios(a, x)
    print(y)

if __name__ == "__main__":
    main()

