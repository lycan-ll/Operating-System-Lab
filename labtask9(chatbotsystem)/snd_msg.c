#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#define MSGSZ 128
typedef struct msgbuf {
    long mtype;
    char mtext[MSGSZ];
} message_buf;
int main()
{
    while (1){
    int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    message_buf sbuf;
    size_t buf_length;
    key = 1234;
    msqid = msgget(key, msgflg );
    sbuf.mtype = 1;
    char message[128];
    
    scanf("%[^\n]%*c", message);
    strcpy(sbuf.mtext, message);
    buf_length = strlen(sbuf.mtext) + 1 ;
    msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT);

    message_buf rbuf;
    msqid = msgget(key, 0666);
    
    msgrcv(msqid, &rbuf, MSGSZ, 1, 0);
    printf("Reciver says: %s\n", rbuf.mtext);
    
    }
    return 0;
    
}