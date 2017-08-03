#include<stdio.h>
void main()
{
int p,q,r;
r=getpid();
printf("\nparent process id:%d",r);
p=fork();
if(p>0)
{
printf("\nparent process");
}
else if(p==0)
{
printf("\nchild process");
q=getpid();
printf("\nchild process id: %d",q);
}
else if(p==-1)
{
printf("\nerror");
}
}
