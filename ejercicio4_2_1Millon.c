#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

// Variables globales para almacenar el tiempo de inicio, fin y el acumulado
struct timeval tinicio, tfin;
double total = 0.0;

// Se declara la función que ejecutará cada hilo
void* hilo(void* arg) {
    gettimeofday(&tfin, NULL); // Captura el tiempo justo cuando el hilo comienza su ejecución

    // Calcula el tiempo transcurrido en microsegundos
    double tiempo = (tfin.tv_sec - tinicio.tv_sec) * 1000000.0 + (tfin.tv_usec - tinicio.tv_usec);
    total += tiempo; // Acumula el tiempo en la variable global

    return NULL;
}

int main() {
    int i;
    pthread_t h;
    // Bucle para crear 1 millón de hilos
    for (i = 0; i < 1000000; i++) {
        gettimeofday(&tinicio, NULL); // Se guarda el tiempo justo antes de crear el hilo

        pthread_create(&h, NULL, hilo, NULL); // Se crea un hilo que ejecuta la función "hilo"
        pthread_join(h, NULL); // Espera a que el hilo termine antes de continuar
    }

    // Imprime el resultado final acumulado
    printf("Tiempo total: %f microsegundos\n", total);

    return 0;
}
