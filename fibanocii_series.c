#include<stdio.h>
#include<string.h>
main()
{
int p[2],pid,a,b,c,n;
if(pipe(p)==-1)
{
printf("error in pipe connection");
exit(0);
}
pid=fork();
if(pid>0)
{
printf("\nparent process");
printf("\n fibanocii series");
printf("\n enter the limit");
scanf("%d",&n);
close(p[0]);
write(p[1],&n,sizeof(n));
close(p[1]);
exit(0);
}
else
{
close(p[1]);
read(p[0],&n,sizeof(n));
printf("\nchild process");
a=0;b=1;
close(p[0]);
printf("\n fibinocii series is");
printf("\n%d\n%d\n",a,b);
while(n>2)
{
c=a+b;
printf("%d\n",c);
a=b;b=c;
n--;
}}}
