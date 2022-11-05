# Tarea 5: AG para FFMSP


Para compilar, usar el compilador de c++:

```console
admin@admin:~/tareasSA/Tarea2$ g++ src/*.cpp -o AG
```

Para ejecutar, utilizar la siguiente sintaxis:

```console
admin@admin:~/tareasSA/Tarea2$ ./AG -i XXX-YYY-ZZZ -t 10 -th 0.75 -e 0.2
```

Donde:

**-i XXX-YYY-ZZZ**: Se refiere a la instancia del problema XXX-YYY-ZZZ.txt en la carpeta `dataset` (en el ejemplo,`instancia = 100-300-001.txt`)

**-t 10**: Indica el tiempo de ejecución del problema (en el ejemplo, `tiempo = 10 segundos`)

**-th 0.75**: Indica cuál es el threshold para dicha ejecución del problema (en el ejemplo, `threshold = 0.75`), th tiene que ser un valor entre 0 y 1, si no se indica este parámetro por defecto tiene un valor de 0.8.

## Archivos incluidos:
- `funciones.cpp`: funciones generales compartido por varios algoritmos.
- `genetico.cpp`: 
- `main.cpp`: código fuente principal de ejecución y manejo de entrada