#include<stdio.h>
#include<stdarg.h>

void myprint(char *fmt, ...)
{
    va_list ap;
    int i;
    double d;
    char *p, *s;
    
    va_start(ap,fmt);
    
    for(p=fmt;*p;p++)
    {
        if (*p != '%')
        {
            printf("%c",*p);
            continue;
        }
        
        switch(*++p)
        {
            case 'd':   i = va_arg(ap,int);
                        printf("%d",i);
                        break;
            case 'f':   d = va_arg(ap,double);
                        printf("%f",d);
                        break;
            case 's':   for(s = va_arg(ap,char *);*s;s++)
                            printf("%c",*s);
                        break;
            default:    putchar(*p);
                        break;
        }
    }
    va_end(ap);
}

int main()
{
    int a = 1;
    double b = 2.5;
    char c[] = "Test My String";
    myprint("This works yaar %d %f %s",a,b,c);
}
