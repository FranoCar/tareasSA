# Tarea 1: Heurísticas Greedy para FFMSP
## Heurística Greedy:

Para compilar, utilizar la siguiente sintaxis:

```console
admin@admin:~$ ./greedy.out -i XXX-YYY-ZZZ.txt -th 0.75
```

Donde:
**-i XXX-YYY-ZZZ.txt**: Hace un llamado a la instancia del problema XXX-YYY-ZZZ.txt (ej: 100-300-001.txt)

**-th 0.75**: Indica por consola cuál es el threshold para dicha ejecución del problema (en el ejemplo, threshold = 0.75)

## Heurísitca Greedy Aleatorizado:

Para compilar, utilizar la siguiente sintaxis:

```console
admin@admin:~$ ./gr_aleatorio.out -i XXX-YYY-ZZZ.txt -th 0.75 -e 0.7
```

Donde:
**-i XXX-YYY-ZZZ.txt**: Hace un llamado a la instancia del problema XXX-YYY-ZZZ.txt (ej: 100-300-001.txt)

**-th 0.75**: Indica por consola cuál es el threshold para dicha ejecución del problema (en el ejemplo, threshold = 0.75)

**-e 0.7**: Indica el valor de epsilon que se escogerá para la aleatoreidad del problema. Si no se indica este parámetro, por defecto tiene un valor de 0.1