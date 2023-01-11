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
    while (1)
    {

    int msqid;
    key_t key;
    message_buf rbuf;
    key = 1234;
    msqid = msgget(key, 0666);
    char message[128];
     
    msgrcv(msqid, &rbuf, MSGSZ, 1, 0);
    printf("Sender says: %s\n", rbuf.mtext);

    int msgflg = IPC_CREAT | 0666;
    message_buf sbuf;
    size_t buf_length;
    msqid = msgget(key, msgflg );
    sbuf.mtype = 1;
    
    scanf("%[^\n]%*c", message);
    strcpy(sbuf.mtext, message);
    buf_length = strlen(sbuf.mtext) + 1 ;
    msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT);

    }
    return 0;
}