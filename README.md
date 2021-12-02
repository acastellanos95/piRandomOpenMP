# piRandomOpenMP

project for HPCI

## `sizes.txt`

Este archivo contiene el número de puntos a generar y lo hilos asociados a ellos. Puede modificarlos acorde al formato sin borrar la cabecera

## Formato de salida

En el archivo `main.cpp` tenemos múltiples salidas para poder llenar los archivos de datos que guardan los resultados: `resultadosseq.data`, `resultadospar.data`, `pi.data` y `aceleracion.data`.

## Resultados

1. `resultadosseq.data` contiene el número de puntos generados y el tiempo que le tomó de manera secuencial calcular $\pi$.

2. `resultadospar.data` contiene para un número de puntos generados, el número de hilos y su tiempo de ejecución.

3. `pi.data` los valores de pi calculados para un número de puntos generados con su número de hilos.

4. `aceleracion.data` tiene para el número de puntos generados y el número de hilos se asocia el tiempo de ejecución en secuencial entre el tiempo de ejecución paralelo.

## Ejecución

Correr el script `runWithSizes.sh` para generar resultados usando sizes.txt.
