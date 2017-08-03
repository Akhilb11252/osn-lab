#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
char buff[100];
int p1[2],p2[2],i;
pipe(p1);
pipe(p2);
if(fork()==0)
{
printf("\nopening child");
close(p1[0]);
close(p2[1]);
if(write(p1[1],"hello",7)<0)
printf("\nchild:write error");
if(read(p2[0],buff,sizeof(buff))<0)
printf("\nchild:read error");
else
{
printf("\nreceived msg from parent:paret says :%s\n",buff);
}
printf("\nclosing child\n");

}else
{
close(p1[1]);
close(p2[0]);
printf("\nopening parent");
if(read(p1[0],buff,sizeof(buff))<0)
printf("parent:read errror");
else
printf("\nreceived msg from child : child says %s",buff);
if(write(p2[1],"hai",4)<0)
{
printf("\nparent:write erroe");
}
wait(0);
printf("\nclosing parent");
} 
exit(0);
}
