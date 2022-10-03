# Tarea 2: GRASP para el FFMSP


Para compilar, usar el compilador de c++:

```console
admin@admin:~$ g++ src/*.cpp -o GRASP
```

Para ejecutar, utilizar la siguiente sintaxis:

```console
admin@admin:~$ ./GRASP -i XXX-YYY-ZZZ -t 10 -th 0.75 -e 0.2
```

Donde:

**-i XXX-YYY-ZZZ**: Se refiere a la instancia del problema XXX-YYY-ZZZ.txt en la carpeta `dataset` (en el ejemplo,`instancia = 100-300-001.txt`)

**-t 10**: Indica el tiempo de ejecución del problema (en el ejemplo, `tiempo = 10 segundos`)

**-th 0.75**: Indica cuál es el threshold para dicha ejecución del problema (en el ejemplo, `threshold = 0.75`). 
th tiene que ser un valor entre 0 y 1, si no se indica este parámetro por defecto tiene un valor de 0.8.

**-e 0.2**: Indica el valor epsilon que se escogerá para la aleatoreidad del problema (en el ejemplo, `epsilon = 0.2`). 
e tiene que ser un valor entre 0 y 1, si no se indica este parámetro por defecto tiene un valor de 0.1.

## Archivos incluidos:
- `funciones.cpp`: funciones generales para el funcionamiento del programa.
- `busqueda_local.cpp`: código fuente de la búsqueda local
- `greedy_aleatorio.cpp`: código fuente de algoritmo greedy aleatorizado
- `GRASP.cpp`: código fuente de algoritmo GRASP
- `main.cpp`: código fuente principal de ejecución y manejo de entrada