## Iterações do algoritmo Selection Sort
O que o computador faz em cada iteração.

- Para o vector `3, 5, 2, 0, -1`:

---

#### 1º Loop externo (i = 0)
1.1
```cpp
i = 0 //3  
j = 1 //5  
menor = 0 //3  
```
1.2
```cpp
i = 0 //3  
j = 2 //2  
menor = 2 //2  
```
1.3
```cpp
i = 0 //3  
j = 3 //0  
menor = 3 //0  
```
1.4
```cpp
i = 0 //3  
j = 4 //-1  
menor = 4 //-1  
```

**Final do 1º loop externo:** `-1, 5, 2, 0, 3`

---

#### 2º Loop externo (i = 1)
2.1
```cpp
i = 1 //5  
j = 2 //2  
menor = 2 //2  
```
2.2
```cpp
i = 1 //5  
j = 3 //0  
menor = 3 //0  
```
2.3
```cpp
i = 1 //5  
j = 4 //3  
menor = 3 //0  
```

**Final do 2º loop externo:** `-1, 0, 2, 5, 3`

---

#### 3º Loop externo (i = 2)
3.1
```cpp
i = 2 //2  
j = 3 //5  
menor = 2 //2  
```
3.2
```cpp
i = 2 //2  
j = 4 //3  
menor = 2 //2  
```
**Final do 3º loop externo:** `-1, 0, 2, 5, 3`

---

#### 4º Loop externo (i = 3)
4.1
```cpp
i = 3 //5  
j = 4 //3  
menor = 4 //3  
```

**Final do 4º loop externo:** `-1, 0, 2, 3, 5`

---

### Resultado final:
`-1, 0, 2, 3, 5`
