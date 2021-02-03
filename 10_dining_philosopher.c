#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 10

sem_t chopstick[N];

void *philospher(void *num){
        int i = *(int *) num;
        while(1){
                printf("%d th philospher is hungry.\n",i);
                sem_wait(&chopstick[i]);
                sem_wait(&chopstick[(i+1)%N]);
                printf("%d th philospher is eating.\n",i);
                sleep(10);
                printf("%d th philospher stopped eating.\n",i);
                sem_post(&chopstick[i]);
                sem_post(&chopstick[(i+1)%N]);
                printf("%d th philospher is thinking.\n",i);
        }
}
int main(){
    int i,n;
    pthread_t thread_id[N];
    for(i=0;i<N;i++)
            sem_init(&chopstick[i],1,1);
    for(i=0;i<N;i++){
            pthread_create(&thread_id[i],NULL,philospher,&i);
    }
    for(i=0;i<N;i++)
            pthread_join(thread_id[i],NULL);
}