#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include <sched.h>


void *tour1(void *ptr);
void *tour2(void *ptr);

void *fraiseuse1(void *ptr);
void *fraiseuse2(void *ptr);
void *moteur1(void *ptr);
void *moteur2(void *ptr);
void *perceuse(void *ptr);



void *process();
void *process2();
void *process6();
void *process7();
void *process8();
void *process9();
void *process10();



struct W1 {
    int id;
    char data[32];
    struct W1 *next;
};

struct W1 *AddW1(int id, char *data){
    struct W1 *w;
    w = (struct W1 *)malloc(sizeof(struct W1));
    w->id = id;             /*set id*/
    strcpy(w->data, data);  /*set data*/
    w->next = NULL;         /*set next, point to NULL*/
    return w;
}
struct W2 {
    int id;
    char data[32];
    struct W2 *next;
};

struct W2 *AddW2(int id, char *data){
    struct W2 *w;
    w = (struct W2 *)malloc(sizeof(struct W2));
    w->id = id;             /*set id*/
    strcpy(w->data, data);  /*set data*/
    w->next = NULL;         /*set next, point to NULL*/
    return w;
}

struct W6 {
    int id;
    char data[32];
    struct W6 *next;
};

struct W6 *AddW6(int id, char *data){
    struct W6 *w;
    w = (struct W6 *)malloc(sizeof(struct W6));
    w->id = id;             /*set id*/
    strcpy(w->data, data);  /*set data*/
    w->next = NULL;         /*set next, point to NULL*/
    return w;
}
struct W7 {
    int id;
    char data[32];
    struct W7 *next;
};

struct W7 *AddW7(int id, char *data){
    struct W7 *w;
    w = (struct W7 *)malloc(sizeof(struct W7));
    w->id = id;             /*set id*/
    strcpy(w->data, data);  /*set data*/
    w->next = NULL;         /*set next, point to NULL*/
    return w;
}
struct W8 {
    int id;
    char data[32];
    struct W8 *next;
};

struct W8 *AddW8(int id, char *data){
    struct W8 *w;
    w = (struct W8 *)malloc(sizeof(struct W8));
    w->id = id;             /*set id*/
    strcpy(w->data, data);  /*set data*/
    w->next = NULL;         /*set next, point to NULL*/
    return w;
}
struct W9 {
    int id;
    char data[32];
    struct W9 *next;
};

struct W9 *AddW9(int id, char *data){
    struct W9 *w;
    w = (struct W9 *)malloc(sizeof(struct W9));
    w->id = id;             /*set id*/
    strcpy(w->data, data);  /*set data*/
    w->next = NULL;         /*set next, point to NULL*/
    return w;
}
struct W10 {
    int id;
    char data[32];
    struct W10 *next;
};

struct W10 *AddW10(int id, char *data){
    struct W10 *w;
    w = (struct W10 *)malloc(sizeof(struct W10));
    w->id = id;             /*set id*/
    strcpy(w->data, data);  /*set data*/
    w->next = NULL;         /*set next, point to NULL*/
    return w;
}


sem_t mutex;
struct W1 *alpha, *node;
struct W2 *alpha2, *node2;
struct W6 *alpha6, *node6;
struct W7 *alpha7, *node7;
struct W8 *alpha8, *node8;
struct W9 *alpha9, *node9;
struct W10 *alpha10, *node10;


int main()
{
pthread_t thread1,thread2,thread6,thread7,thread8,thread9,thread10;



char *msg1="machine1";
char *msg2="machine2";
char *msg6="machine6";
char *msg7="machine7";
char *msg8="machine8";
char *msg9="machine9";
char *msg10="machine10";



sem_init(&mutex,0,1);

printf("Ordonancement au niveau du hall technologique ");
printf("\n \n");


  pthread_attr_t attr;
    struct sched_param param;

    pthread_attr_init(&attr);
    param.sched_priority = 12;
    pthread_setschedparam(pthread_self(), SCHED_FIFO, &param); 
                                                               
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    
    param.sched_priority = 2;
    pthread_attr_setschedparam(&attr, &param);
    int ret1=pthread_create(&thread1,&attr,tour1,(void *) msg1);

    param.sched_priority = 7;
    pthread_attr_setschedparam(&attr, &param);
    int ret2=pthread_create(&thread2,&attr,tour2,(void *) msg2);




   
    param.sched_priority = 6;
    pthread_attr_setschedparam(&attr, &param);
    int ret6=pthread_create(&thread6,&attr,fraiseuse1,(void *) msg6);

    param.sched_priority = 4;
    pthread_attr_setschedparam(&attr, &param);
    int ret7=pthread_create(&thread7,&attr,fraiseuse2,(void *) msg7);


    param.sched_priority = 1;
    pthread_attr_setschedparam(&attr, &param);
    int ret8=pthread_create(&thread8,&attr,moteur1,(void *) msg8);

    param.sched_priority = 3;
    pthread_attr_setschedparam(&attr, &param);
    int ret9=pthread_create(&thread9,&attr,moteur1,(void *) msg9);

    param.sched_priority = 5;
    pthread_attr_setschedparam(&attr, &param);
   

    int ret10=pthread_create(&thread10,&attr,perceuse,(void *) msg10);







pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

pthread_join(thread6,NULL);
pthread_join(thread7,NULL);
pthread_join(thread8,NULL);
pthread_join(thread9,NULL);
pthread_join(thread10,NULL);


 pthread_attr_destroy(&attr);

sem_destroy(&mutex);


return 0;
}


void *tour1(void *ptr){
sem_wait(&mutex);
printf("DEBUT TRANSMISSION  %ld ", clock()/60);
 printf("\n \n");

alpha = AddW1(1, "A");
alpha->next = AddW1(1, "B");
alpha->next->next = AddW1(1, "C");
node = alpha; 
process();
sem_post(&mutex);
pthread_exit(0);
}

void *tour2(void *ptr){

sem_wait(&mutex);
printf("DEBUT TRANSMISSION  %ld ", clock()/60);
 printf("\n \n");
alpha2 = AddW2(2, "G");
alpha2->next = AddW2(2, "H");
alpha2->next->next = AddW2(2, "I"); 
node2 = alpha2; 
process2();
sem_post(&mutex);

pthread_exit(0);

}


void *fraiseuse1(void *ptr){

sem_wait(&mutex);
printf("DEBUT TRANSMISSION  %ld ", clock()/60);
 printf("\n \n");
alpha6 = AddW6(6, "P");
alpha6->next = AddW6(6, "Q");
alpha6->next->next = AddW6(6, "R"); 
node6 = alpha6; 
process6();
sem_post(&mutex);

pthread_exit(0);

}
void *fraiseuse2(void *ptr){

sem_wait(&mutex);
printf("DEBUT TRANSMISSION  %ld ", clock()/60);
 printf("\n \n");
alpha7 = AddW7(7, "S");
alpha7->next = AddW7(7, "T");
alpha7->next->next = AddW7(7, "U"); 
node7 = alpha7; 
process7();
sem_post(&mutex);

pthread_exit(0);

}
void *moteur1(void *ptr){

sem_wait(&mutex);
printf("DEBUT TRANSMISSION  %ld ", clock()/60);
 printf("\n \n");
alpha8 = AddW8(8, "V");
alpha8->next = AddW8(8, "W");
alpha8->next->next = AddW8(8, "X"); 
node8 = alpha8; 
process8();
sem_post(&mutex);

pthread_exit(0);

}
void *moteur2(void *ptr){

sem_wait(&mutex);
printf("DEBUT TRANSMISSION  %ld ", clock()/60);
 printf("\n \n");
alpha9 = AddW9(9, "Y");
alpha9->next = AddW9(9, "Z");
alpha9->next->next = AddW9(9, "ZZ"); 
node9 = alpha9; 
process9();
sem_post(&mutex);

pthread_exit(0);

}
void *perceuse(void *ptr){
sem_wait(&mutex);
printf("DEBUT TRANSMISSION   %ld ", clock()/60);
 printf("\n \n");
alpha10 = AddW10(10, "AA");
alpha10->next = AddW10(10, "BB");
alpha10->next->next = AddW10(10, "CC"); 
node10 = alpha10; 
process10();
sem_post(&mutex);

pthread_exit(0);

}


void *process(){
int i=0;

 printf("tour1 Machine id = %d   ", node->id);
while(node != NULL){/*process SCHEDUALING*/
        printf("data %d= %s   ",i, node->data);

        node = node->next;
i++;

  }

  printf("\n \n");



}
void *process2(){
int i=0;

 printf("tour2 Machine id = %d   ", node2->id);
while(node2 != NULL){/*process SCHEDUALING*/
        printf("data %d= %s   ",i, node2->data);

        node2 = node2->next;
i++;

  }

  printf("\n \n");



}
void *process6(){
int i=0;

 printf("Fraiseuse1 Machine id = %d   ", node6->id);
while(node6!= NULL){/*process SCHEDUALING*/
        printf("data %d= %s   ",i, node6->data);

        node6 = node6->next;
i++;

  }

  printf("\n \n");



}
void *process7(){
int i=0;

 printf("Fraiseuse2 Machine id = %d   ", node7->id);
while(node7 != NULL){/*process SCHEDUALING*/
        printf("data %d= %s   ",i, node7->data);

        node7 = node7->next;
i++;

  }

  printf("\n \n");



}
void *process8(){
int i=0;

 printf("Moteur1 Machine id = %d   ", node8->id);
while(node8 != NULL){/*process SCHEDUALING*/
        printf("data %d= %s   ",i, node8->data);

        node8 = node8->next;
i++;

  }

  printf("\n \n");

}
void *process9(){
int i=0;

 printf("Moteur2 Machine id = %d   ", node9->id);
while(node9 != NULL){/*process SCHEDUALING*/
        printf("data %d= %s   ",i, node9->data);

        node9 = node9->next;
i++;

  }

  printf("\n \n");



}
void *process10(){
int i=0;

 printf("Perceuse Machine id = %d   ", node10->id);
while(node10 != NULL){/*process SCHEDUALING*/
        printf("data %d= %s   ",i, node10->data);

        node10 = node10->next;
i++;

  }

  printf("\n \n");

}  
