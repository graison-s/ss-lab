#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define buffersize 5
pthread_mutex_t mutex;
pthread_t tidP[20],tidC[20];
sem_t full,empty;
int x;
int buffer[buffersize];
void initialize(){
        pthread_mutex_init(&mutex,NULL);
        sem_init(&full,1,0);
        sem_init(&empty,1,buffersize);
        x = -1;
}
void print_buffer(){
        printf("\nThe buffer is : [ ");
        for(int i=0; i<=x; i++)
                printf("%d ",buffer[i]);
        printf("]\n");
}
void write(int item){
        buffer[++x] = item;
}
int read(){
        return buffer[x--];
}
void * producer (void * param){
        int item,i;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        write(x+2);
        printf("\nProducer has produced item: %d\n",buffer[x]);
        print_buffer();
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
}
void *consumer (void * param){
        int item;
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item=read();
        printf("\nConsumer has consumed item: %d\n",item);
        print_buffer();
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
}
int main(){
        int n1,n2,i;
        initialize();
        printf("\nEnter the no of producers: ");
        scanf("%d",&n1);
        printf("\nEnter the no of consumers: ");
        scanf("%d",&n2);
        for(i=0;i<n1;i++)
                pthread_create(&tidP[i],NULL,producer,NULL);
        for(i=0;i<n2;i++)
                pthread_create(&tidC[i],NULL,consumer,NULL);
        for(i=0;i<n1;i++)
                pthread_join(tidP[i],NULL);
        for(i=0;i<n2;i++)
                pthread_join(tidC[i],NULL);
}