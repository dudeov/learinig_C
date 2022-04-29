# Grpaphs

 ```
        A
        |\
        B-C
        | |\
        D-E-J
        |/
        F
```
in Python:
```
graph = {"A":["B","C"], "B":["C", "A", "D"], "C":["B", "E", "J"], "D":["E", "F"], "E":["D", "C","J"], "J":["E", "C"], "F":["D", "E"],}
```
