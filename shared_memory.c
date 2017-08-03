#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
main()
{
char *a;
key_t key=ftok("shm.c",'A');
int shmid=shmget(key,sizeof(char),IPC_CREAT|0666);
a=(char*)shmat(shmid,0,0);
if(shmid!=-1)
printf("shared memory created with id:%d\n",shmid);
else
printf("shared memory donot created");
}
