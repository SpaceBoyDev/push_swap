#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM 10000  // Rango máximo para los números aleatorios

// Función para verificar si un número ya existe en el array
bool existe(int array[], int tamaño, int num) {
    for (int i = 0; i < tamaño; i++) {
        if (array[i] == num)
            return true;
    }
    return false;
}

int main() {
    int cantidad;

    printf("¿Cuántos números aleatorios únicos deseas generar? ");
    scanf("%d", &cantidad);

    if (cantidad > MAX_NUM) {
        printf("Error: No se pueden generar más de %d números únicos dentro del rango.\n", MAX_NUM);
        return 1;
    }

    int *numeros = malloc(cantidad * sizeof(int));
    if (numeros == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    srand(time(NULL)); // Semilla basada en el tiempo

    int generados = 0;
    while (generados < cantidad) {
        int num = rand() % MAX_NUM;
        if (!existe(numeros, generados, num)) {
            numeros[generados] = num;
            generados++;
        }
    }

    char *resultado = malloc(cantidad * 6);
    if (resultado == NULL) {
        printf("Error al asignar memoria para la cadena.\n");
        free(numeros);
        return 1;
    }

    resultado[0] = '\0'; // Inicializar cadena vacía

    for (int i = 0; i < cantidad; i++) {
        char buffer[16];
        snprintf(buffer, sizeof(buffer), "%d ", numeros[i]);
        strcat(resultado, buffer);
    }

    printf("Cadena de números generada");

	char comando[100000]; // Asegúrate de que tenga suficiente espacio
	snprintf(comando, sizeof(comando), ".././push_swap \"%s\" | wc -l", resultado);
	system(comando);
	snprintf(comando, sizeof(comando), ".././push_swap \"%s\" | .././checker_linux \"%s\"", resultado, resultado);
	system(comando);

    free(numeros);
    return 0;
}
