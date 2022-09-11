# Tarea 1: Heurísticas Greedy para FFMSP
## Heurística Greedy:

Para compilar, usar el compilador de c++:

```console
admin@admin:~$ g++ src/greedy.cpp -o greedy.out
```

Para ejecutar, utilizar la siguiente sintaxis:

```console
admin@admin:~$ ./greedy.out -i XXX-YYY-ZZZ -th 0.75
```

Donde:

**-i XXX-YYY-ZZZ**: Se refiere a la instancia del problema XXX-YYY-ZZZ.txt en la carpeta `dataset` (ej: 100-300-001)

**-th 0.75**: Indica cuál es el threshold para dicha ejecución del problema (en el ejemplo, `threshold = 0.75`)

## Heurísitca Greedy Aleatorizado:

Para compilar, usar el compilador de c++:

```console
admin@admin:~$ g++ src/greedy_aleatorio.cpp -o gr_aleatorio.out
```

Para ejecutar, utilizar la siguiente sintaxis:

```console
admin@admin:~$ ./gr_aleatorio.out -i XXX-YYY-ZZZ -th 0.75 -e 0.2
```

Donde:

**-i XXX-YYY-ZZZ.txt**: Se refiere a la instancia del problema XXX-YYY-ZZZ.txt en la carpeta `dataset` (ej: 100-300-001.txt)

**-th 0.75**: Indica cuál es el threshold para dicha ejecución del problema (en el ejemplo, `threshold = 0.75`)

**-e 0.2**: Indica el valor epsilon que se escogerá para la aleatoreidad del problema. Si no se indica este parámetro, por defecto tiene un valor de 0.1

## Archivos incluidos:
- `greedy.cpp`: código fuente de algoritmo greedy
- `greedy_aleatorio.cpp`: código fuente de algoritmo greedy aleatorizado
- `greedy.out`: programa compilado de algoritmo greedy para linux
- `gr_aleatorio.out`: programa compilado de algoritmo greedy aleatorizado para linux
- `test.py`: script de python para obtener media y desviación estandar, uso: `python test.py <programa>`