#include <stdio.h>
#include <pthread.h>



void* mensaje (void* arg){
        char* msg;
        msg = (char*) arg;
        printf ("%s\n", msg);
        return NULL;
}

int main() {

        pthread_t hilo1, hilo2, hilo3, hilo4;

        char* msgHilo1 = "Soy el Hilo 1";
        char* msgHilo2 = "Soy el Hilo 2";
        char* msgHilo3 = "Soy el Hilo 3";
        char* msgHilo4 = "Soy el Hilo 4";

        pthread_create (&hilo1,NULL,mensaje, (void*)msgHilo1);
        pthread_create (&hilo2, NULL, mensaje, (void*)msgHilo2);
        pthread_create (&hilo3, NULL, mensaje, (void*)msgHilo3);
        pthread_create(&hilo4, NULL, mensaje, (void*)msgHilo4);


        pthread_join(hilo1,NULL);
        pthread_join(hilo2,NULL);
        pthread_join(hilo3,NULL);
        pthread_join(hilo4,NULL);

        return 0;

}#include <stdio.h>
#include <pthread.h>



void* mensaje (void* arg){
        char* msg;
        msg = (char*) arg;
        printf ("%s\n", msg);
        return NULL;
}

int main() {

        pthread_t hilo1, hilo2, hilo3, hilo4;

        char* msgHilo1 = "Soy el Hilo 1";
        char* msgHilo2 = "Soy el Hilo 2";
        char* msgHilo3 = "Soy el Hilo 3";
        char* msgHilo4 = "Soy el Hilo 4";

        pthread_create (&hilo1,NULL,mensaje, (void*)msgHilo1);
        pthread_create (&hilo2, NULL, mensaje, (void*)msgHilo2);
        pthread_create (&hilo3, NULL, mensaje, (void*)msgHilo3);
        pthread_create(&hilo4, NULL, mensaje, (void*)msgHilo4);


        pthread_join(hilo1,NULL);
        pthread_join(hilo2,NULL);
        pthread_join(hilo3,NULL);
        pthread_join(hilo4,NULL);

        return 0;

}
