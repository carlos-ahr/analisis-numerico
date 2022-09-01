# Método de Bisección

## Algoritmo

1. Datos
    - $f(x)$.
    - $[x_i,x_f]$.
    - $n$.
    - $E_r$i.
2. Evaluar
    - Si $f(x_i)f(x_f)<0\to$ La raiz esta en el intervalo.
    - Si $f(x_i)f(x_f)>0\to$ La raiz no esta en el intervalo.
3. Calcular
    - $x_m=\frac{x_i+x_f}{2}$.
4. Evaluar
    - Si $f(x_i)f(x_m)=0\to x_m$ es la raiz.
    - Si $f(x_i)f(x_m)<0\to [x_i,x_m]$.
    - Si $f(x_i)f(x_m)>0\to [x_m,x_f]$.
5. Evaluar
    - $|\frac{X_i-x_m}{x_m}|\cdot 100 < E_r\to x_m$ es la raiz.
6. Iterar de [3] a [5] n veces.

> Nota: Si f(x) es una funcion trigonometrica utilizar radianes.
