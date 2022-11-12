# Tarea 5: AG para FFMSP


Para compilar, usar el compilador de c++:

```console
admin@admin:~/tareasSA/Tarea5$ g++ src/*.cpp src/FFMS_Generator/*.cpp -o AG
```

Para ejecutar, utilizar la siguiente sintaxis:

```console
admin@admin:~/tareasSA/Tarea5$ ./AG -i XXX-YYY-ZZZ -t 20 -th 0.75 -mr 0.1 -cr 0.2 -e 0.1 -na 100
```

Donde:

**-i XXX-YYY-ZZZ**: Se refiere a la instancia del problema XXX-YYY-ZZZ.txt en la carpeta `dataset` (en el ejemplo,`instancia = 100-300-001.txt`)

**-t 20**: Indica el tiempo de ejecución del problema (en el ejemplo, `tiempo = 20 segundos`)

**-th 0.75**: Indica cuál es el threshold para dicha ejecución del problema (en el ejemplo, `threshold = 0.75`), th tiene que ser un valor entre 0 y 1, si no se indica este parámetro por defecto tiene un valor de 0.8.

**-mr 0.1**: Indica el mutation rate, es decir qué tan seguido sucede una mutación(en el ejemplo, `mutation rate = 0.1`), tiene que ser un valor entre 0 y 1, tiene un valor por defecto de 0.1.

**-cr**: Indica el crossover rate, es decir qué porcentaje de la población genera hijos por cada generación (en el ejemplo `crossover rate = 0.2`), tiene que ser un valor entre 0 y 1 y tiene un valor por defecto de 0.1.

**-e**: Indica el valor epsilon para controlar el nivel de aleatoriedad de la población generada en el algoritmo genético (en el ejemplo `epsilon = 0.1`), tiene que ser un valor entre 0 y 1 y por defecto tiene un valor de 0.1.

**-na**: Indica la cantidad de agentes de cada generación (en el ejemplo `número de agentes = 100`), tiene que ser un valor entero positivo y por defecto tiene un valor de 100.

## Archivos incluidos:
- `funciones.cpp`: Funciones generales de entrada y salida.
- `main.cpp`: Código fuente principal de ejecución y manejo de entrada
- `FFMS_Generator/FFMS_Generator.hpp`: Clase para manejo de variables del problema.
- `FFMS_Generator/algoritmo_genetico.cpp`: Implementación de algoritmo genético.
- `FFMS_Generator/generacion_poblacion.cpp`: Código para generación de población inicial.
- `FFMS_Generator/mutacion.cpp`: Código para mutacion de soluciones.
- `FFMS_Generator/seleccion.cpp`: Implementación de selección por torneo.
- `FFMS_Generator/reemplazo.cpp`: Implementación de reemplazo steady-state.
- `FFMS_Generator/crossover.cpp`: Implementación de 2-point crossover
- `FFMS_Generator/greedy_aleatorio.cpp`: Algoritmo greedy para la generación de población.