# Tarea 2: GRASP para el FFMSP


Para compilar, usar el compilador de c++:

```console
admin@admin:~$ g++ 
```

Para ejecutar, utilizar la siguiente sintaxis:

```console
admin@admin:~$ ./GRASP -i XXX-YYY-ZZZ -t 10 -th 0.75 -e 0.2
```

Donde:

**-i XXX-YYY-ZZZ.txt**: Se refiere a la instancia del problema XXX-YYY-ZZZ.txt en la carpeta `dataset` (ej: 100-300-001.txt)

**-t 10**: Indica el tiempo de ejecución del problema (en el ejemplo, `tiempo = 10 segundos`)

**-th 0.75**: Indica cuál es el threshold para dicha ejecución del problema (en el ejemplo, `threshold = 0.75`)

**-e 0.2**: Indica el valor epsilon que se escogerá para la aleatoreidad del problema. Si no se indica este parámetro, por defecto tiene un valor de 0.1

## Archivos incluidos:
- `funciones.cpp`: 
- `busqueda_local.cpp`: código fuente de la búsqueda local
- `greedy_aleatorio.cpp`: código fuente de algoritmo greedy aleatorizado
- `GRASP.cpp`: 
- `main.cpp`: