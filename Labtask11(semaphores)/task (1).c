#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
// Using semaphore as a Binary lock for IPC/Syncronization
sem_t sem ; 
int water = 10;
void *f1 ( void *arg ){ 
    sem_wait(&sem);
    
    water = water - 5;
    sleep(1);
    water = water + 10;
    
    sem_post(&sem);
    printf("water:%ld liter \n" , water);
    pthread_exit (NULL) ;
}

int main(){
    pthread_t tid1 , tid2 , tid3 , tid4 , tid5 ; 
    sem_init(&sem , 0 , 1 );
    printf("Statring threads...\n");
    pthread_create(&tid1 ,NULL, f1 ,NULL);
    pthread_create(&tid2 ,NULL, f1 ,NULL);
    pthread_create(&tid3 ,NULL, f1 ,NULL);
    pthread_create(&tid4 ,NULL, f1 ,NULL);
    pthread_create(&tid5 ,NULL, f1 ,NULL);
    pthread_exit (NULL);
}