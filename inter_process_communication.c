#include<stdio.h>
void main()
{
int p[2],pid,ppid,f;
char a[100];
pipe (p);
f=fork();
pid=getpid();
ppid=getppid();
if(f==0)
{
printf("\nchild process id   %d",pid);
printf("\nparent process id    %d",ppid);
printf("\nenter the child message    ");
fgets(a,sizeof (a),stdin);
write(p[1],a,sizeof (a));
sleep(1);
read(p[0],a,sizeof (a));
printf("\nchild reads & print parent message  ");
puts(a);
}
else
{
read(p[0],a,sizeof (a));
printf("\n parent reads & print child message    ");
puts(a);
printf("\nenter parent message     ");
fgets(a,sizeof (a),stdin);
write(p[1],a,sizeof(a));
}}
