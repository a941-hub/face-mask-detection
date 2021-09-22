#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n,r;
struct frame
{
    char ack; // yes or noem
    int data;
}frm[10];
int sender(void);
void recvack(void); // receive acnlowgement
void resend_sr(void);
void resend_gb(void);
void goback(void);
void selective(void);
int main()
{
    int c;
    do
    {
       printf("\n\n1.Selective repeat AQR \n2.Goback N\n3.exit");
       printf("\n Enter your choice");
       scanf("%d",&c);
       switch(c)
       {
           case 1: selective();
           break;
           case 2: goback();
           break;
           case 3: exit(0);
           break;
       }
    }while(c>=4);
}
void goback()
{
    sender();
    recvack();
    resend_gb();
    printf("\n all frames sent successfully");
    
}
void selective()
{
    sender();
    recvack();
    resend_sr();
    printf("\n all frames sent successfully");
}
int sender()
{
    int i;
    printf("\n Enter the no of frames to be sent:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\n Enter data for frame[%d]",i);
        scanf("%d",&frm[i].data); // data stored from user 
        frm[i].ack='y';// let all the frames are ack
    }
return 0;
}
void recvack()
{
    int i;
    rand(); //generate one random function which should be droped , generate one number which is clode 
    r = rand()%n; // genrate any one value with respective of total number of frames 
    
    frm[r].ack='n';// one random value achnolgemen is no
    for(i=1;i<=n;i++)
    {
        if(frm[i].ack=='n')
        {
            printf("\nthe frame number %d is not received ",r);
        }
    }
    
}
void resend_sr() // resend only one packet which is not receiced 
{
    printf("\n resending frame %d",r);
    frm[r].ack='y';
    printf("\n the receiver frame is %d",frm[r].data);
    
    
}
void resend_gb()// resend all the frames from ehich one frame is not receiced ackhnol
{
    int i;
    printf("\n resending from frames %d",r);
    for(i=r;i<=n;i++){
        frm[i].ack='y';
        printf("\n received data of frames %d is %d",i,frm[i].data);
    }
}