### Complexity of Algorithms Book

```
function gcd(a, b) \\ to be, or not to be?
    while b ≠ 0
        t := b
        b := a mod b
        a := t
    return a
```
