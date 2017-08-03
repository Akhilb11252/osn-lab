#include<stdio.h>
main()
{
int a,b,p1[2],p2[2],pid,n,i;
char buff[100];
pipe (p1);
pipe (p2);
pid=fork();
if(pid>0){
printf("\nparent process\n");
close(p1[0]);
close(p2[1]);
printf("enter the number  ");
scanf("%d",&a);
write(p1[1],&a,sizeof(a));
sleep(1);
read(p2[0],&b,sizeof(b));
if(b==0)
{
printf("number is pallindrom\n");
}
else
{
printf("number is not pallindrom\n");
}
//puts(buff);
}
else
{
read(p1[0],&b,sizeof(b));
i=b;
n=0;
while(b>0)
{
n=n*10+b%10;
b=b/10;
}
if(i==n)
{
b=0;
}
else
{
b=1;
}

write(p2[1],&b,sizeof(b));
}}



