#include <stdio.h>
#include <pthread.h>

// Se declara la función que ejecutará el hilo para imprimir un mensaje
void* mensaje (void* arg){
        char* msg; // Se hace un casting de void* a char* para recuperar el texto enviado
        msg = (char*) arg;
        printf ("%s\n", msg);
        return NULL;
}

int main() {
        // Se declara 4 identificadores de hilos
        pthread_t hilo1, hilo2, hilo3, hilo4;

        // Se define las cadenas de texto que se pasarán a cada hilo
        char* msgHilo1 = "Soy el Hilo 1";
        char* msgHilo2 = "Soy el Hilo 2";
        char* msgHilo3 = "Soy el Hilo 3";
        char* msgHilo4 = "Soy el Hilo 4";

        // Creación de los hilos, se les pasa el puntero al mensaje como cuarto argumento
        pthread_create (&hilo1,NULL,mensaje, (void*)msgHilo1);
        pthread_create (&hilo2, NULL, mensaje, (void*)msgHilo2);
        pthread_create (&hilo3, NULL, mensaje, (void*)msgHilo3);
        pthread_create(&hilo4, NULL, mensaje, (void*)msgHilo4);

        // Se bloquea el hilo principal hasta que cada hilo específico termine, así nos aseguramos de que el programa no finalice antes de que los hilos impriman
        pthread_join(hilo1,NULL);
        pthread_join(hilo2,NULL);
        pthread_join(hilo3,NULL);
        pthread_join(hilo4,NULL);

        return 0;
