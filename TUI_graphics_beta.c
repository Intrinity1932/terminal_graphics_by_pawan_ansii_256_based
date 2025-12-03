//pawan.c maded by pawan kumar
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// dpu = dynamic printing ultra wheredpu(array name or type sentence under "",colours are same as apf,speed of words per second) // def = dafault means white colour
// erase for directly clear screen
//timer = a virtual timer the format is (the counter in second);
//dl = {dot loading} a dot animation playing dl(times animation gonna played, how many dots gonna be in animation, speed)
//rl = {rotating loader} a animation that is impressive and existing in most of tui's rl(repeatation, speed)
//be = {blinking eyes} a blinking eyes abimation like (O_O >_<) bi(repeating time)
//be2 = {blinking eyes 2nd} a blinking eyes abimation like (O_O -_-) be2(repeating time)
//bos = {bracket o string} everything will be start under [] from 1 to end. bos("string",speed {25 is perfect})
//pb = {progress bar} used for [#] effect pb(count of # or length, speed 1 = 1 second[speed is equivelant to the digit 2 means 1/2 second etc])
//bb = {bouncy ball} used for bouncy ball animation of single character bb(count of times ball gonna bounce)
//de {dynamic eraser} erase the preveous characters in dynamic style in animation ->--- de(characters before function,speed)
//head {used for put text under a box} head("sentence",size of inner gap,gap from starting wall)
//heable- used for make head and table of one one raw heable(gap before sentence, "sentence for table", "sentence for table")
//apf means advance printf, apf("sentemce","colour"), coloours are - red green blue yellow grey orange pink cyan  //def means deafult
//blank box {used for make a blank box of desired size with gap included} blank_box(lenght,width,gap)
//part blank box is used to make blank boxes acording to needs part_blank_box(width,partitions)
//pos - use for edit the position of cursor.
//lcf - leak colour for foreground, lct("colour");
//sl - stop leaking, sl();
//lcb - leaking colour for background, lcb("colour");
//pxl - pixel with colour, pxl("colour");, covers 1*1 raw and pixel respectively.
//rpxl - resizable pixel, you can resize. rpxl("colour", length, width); but only usable when you start from first column in line
//arpxl - advance resizable pixel, arpxl("colour", length, width, row, column);
//repos - reposition, repos();
//apxl - advance pixel with coordinates, apxl("colour", row, column);
//rp - rainbow printing, syntax - rp(string or "message", speed);

void dpu(char[],char[],int);
void erase();
void timer(int);
void dl(int,int,int);
void rl(int,int);
void be(int);
void bos(char[],int);
void be2(int);
void pb(int,int);
void bb(int);
void de(int,int);
void heable(int,char[],char[]);
void apf(char[], char[]);
void blank_box(int,int,int);
void part_blank_box(int,int);
void head(char[],int,int);
void pos(int,int);
void lcf(char[]);
void sl();
void lcb(char[]);
void pxl(char[]);
void rpxl(char[], int, int);
void arpxl(char[],int ,int ,int ,int);
void repos();
void apxl(char[] ,int a ,int b);
void rp(char[], int);






void rp(char str[], int s)
{
    int i,k=1;
    s=1000000/s;
    for(i=0;str[i]!='\0';i++)
    {
        printf("\033[38;5;%dm%c",k++,str[i]);
        fflush(stdout);
        usleep(s);
        if(k>255)k=1;
    }
}

void apxl(char str[], int a, int b)
{
    printf("\033[%d;%dH",a,b);
    if(strcmp(str,"red")==0){printf("\033[48;5;196m ");printf("\033[0m");}
    else if(strcmp(str,"green")==0){printf("\033[48;5;46m ");printf("\033[0m");}
    else if(strcmp(str,"blue")==0){printf("\033[48;5;21m ");printf("\033[0m");}
    else if(strcmp(str,"yellow")==0){printf("\033[48;5;220m ");printf("\033[0m");}
    else if(strcmp(str,"grey")==0){printf("\033[48;5;236m ");printf("\033[0m");}
    else if(strcmp(str,"orange")==0){printf("\033[48;5;208m ");printf("\033[0m");}
    else if(strcmp(str,"pink")==0){printf("\033[48;5;207m ");printf("\033[0m");}
    else if(strcmp(str,"cyan")==0){printf("\033[48;5;87m ");printf("\033[0m");}
    else if(strcmp(str,"white")==0){printf("\033[47m ");printf("\033[0m");}
    else if(strcmp(str,"black")==0){printf("\033[40m ");printf("\033[0m");}
    else if(strcmp(str,"nc")==0){printf(" ");}
    else{printf("?");}
}

void repos()
{
    printf("\033[1;1H");
}

void arpxl(char str[] ,int a, int b, int x, int y)
{
    int i,j;
    printf("\033[%d;%dH",x,y);
    for(i=0;i<=b;i++)
    {
        for(j=0;j<a;j++)
        {
            if(strcmp(str,"red")==0){printf("\033[48;5;196m ");printf("\033[0m");}
    else if(strcmp(str,"green")==0){printf("\033[48;5;46m ");printf("\033[0m");}
    else if(strcmp(str,"blue")==0){printf("\033[48;5;21m ");printf("\033[0m");}
    else if(strcmp(str,"yellow")==0){printf("\033[48;5;220m ");printf("\033[0m");}
    else if(strcmp(str,"grey")==0){printf("\033[48;5;236m ");printf("\033[0m");}
    else if(strcmp(str,"orange")==0){printf("\033[48;5;208m ");printf("\033[0m");}
    else if(strcmp(str,"pink")==0){printf("\033[48;5;207m ");printf("\033[0m");}
    else if(strcmp(str,"cyan")==0){printf("\033[48;5;87m ");printf("\033[0m");}
    else if(strcmp(str,"white")==0){printf("\033[47m ");printf("\033[0m");}
    else if(strcmp(str,"black")==0){printf("\033[40m ");printf("\033[0m");}
    else if(strcmp(str,"nc")==0){printf(" ");}
    else{printf("?");}
        }
        printf("\033[%d;%dH",x++,y);
    }
}

void rpxl(char str[] ,int a, int b)
{
    int i,j;
    for(i=0;i<b;i++)
    {
        for(j=0;j<a;j++)
        {
            if(strcmp(str,"red")==0){printf("\033[48;5;196m ");printf("\033[0m");}
    else if(strcmp(str,"green")==0){printf("\033[48;5;46m ");printf("\033[0m");}
    else if(strcmp(str,"blue")==0){printf("\033[48;5;21m ");printf("\033[0m");}
    else if(strcmp(str,"yellow")==0){printf("\033[48;5;220m ");printf("\033[0m");}
    else if(strcmp(str,"grey")==0){printf("\033[48;5;236m ");printf("\033[0m");}
    else if(strcmp(str,"orange")==0){printf("\033[48;5;208m ");printf("\033[0m");}
    else if(strcmp(str,"pink")==0){printf("\033[48;5;207m ");printf("\033[0m");}
    else if(strcmp(str,"cyan")==0){printf("\033[48;5;87m ");printf("\033[0m");}
    else if(strcmp(str,"white")==0){printf("\033[47m ");printf("\033[0m");}
    else if(strcmp(str,"black")==0){printf("\033[40m ");printf("\033[0m");}
    else if(strcmp(str,"nc")==0){printf(" ");}
    else{printf("?");}
        }
        printf("\n");
    }
}

void pxl(char str[])
{
    if(strcmp(str,"red")==0){printf("\033[48;5;196m ");printf("\033[0m");}
    else if(strcmp(str,"green")==0){printf("\033[48;5;46m ");printf("\033[0m");}
    else if(strcmp(str,"blue")==0){printf("\033[48;5;21m ");printf("\033[0m");}
    else if(strcmp(str,"yellow")==0){printf("\033[48;5;220m ");printf("\033[0m");}
    else if(strcmp(str,"grey")==0){printf("\033[48;5;236m ");printf("\033[0m");}
    else if(strcmp(str,"orange")==0){printf("\033[48;5;208m ");printf("\033[0m");}
    else if(strcmp(str,"pink")==0){printf("\033[48;5;207m ");printf("\033[0m");}
    else if(strcmp(str,"cyan")==0){printf("\033[48;5;87m ");printf("\033[0m");}
    else if(strcmp(str,"white")==0){printf("\033[47m ");printf("\033[0m");}
    else if(strcmp(str,"black")==0){printf("\033[40m ");printf("\033[0m");}
    else if(strcmp(str,"nc")==0){printf(" ");}
    else{printf("?");}
}

void lcb(char str[])
{
    if(strcmp(str,"red")==0)printf("\033[41m");
    else if(strcmp(str,"green")==0)printf("\033[42m");
    else if(strcmp(str,"blue")==0)printf("\033[44m");
    else if(strcmp(str,"yellow")==0)printf("\033[43m");
    else if(strcmp(str,"grey")==0)printf("\033[48;5;245m");
    else if(strcmp(str,"orange")==0)printf("\033[48;5;208m");
    else if(strcmp(str,"pink")==0)printf("\033[45m");
    else if(strcmp(str,"cyan")==0)printf("\033[46m");
    else if(strcmp(str,"white")==0)printf("\033[47m");
    else if(strcmp(str,"black")==0)printf("\033[40m");
    else{printf("?");}
}


void lcf(char str[])
{
    if(strcmp(str,"red")==0)printf("\033[38;5;196m");
    else if(strcmp(str,"green")==0)printf("\033[32m");
    else if(strcmp(str,"blue")==0)printf("\033[34m");
    else if(strcmp(str,"yellow")==0)printf("\033[33m");
    else if(strcmp(str,"grey")==0)printf("\033[30m");
    else if(strcmp(str,"orange")==0)printf("\033[38;5;208m");
    else if(strcmp(str,"pink")==0)printf("\033[35m");
    else if(strcmp(str,"cyan")==0)printf("\033[36m");
    else if(strcmp(str,"black")==0)printf("\033[30m");
    else if(strcmp(str,"white")==0)printf("\033[37m");
    else{printf("?");}
}

void sl()
{
    printf("\033[0m");
}


void pos(int a,int b)
{
    printf("\033[%d;%dH",a,b);
}

void head(char str[], int n, int m)
{
    int i,j,k;
    k=strlen(str);
    if(k<=n){
    for(j=0;j<m;j++)printf(" ");printf("┌");for(i=0;i<n;i++)printf("─");printf("┐");printf("\n");
    for(j=0;j<m;j++)printf(" ");printf("│");printf("%s",str);for(i=0;i<n-k;i++)printf(" ");printf("│");printf("\n");
    for(j=0;j<m;j++)printf(" ");printf("└");for(i=0;i<n;i++)printf("─");printf("┘");printf("\n");
    }else{printf("stringe should be under size!");}
}

void part_blank_box(int w, int n)
{
    int i,j,k,x,m,l,g=2;                    //x = box count
    if(n<1||w<2){printf("n shoud not be less than 1 amd w should not be less than 2");}
    else
    {
                ++n;
                m=194-(2*n);
                m=(m/n);
                for(i=0;i<n;i++)
                {
                    if(i>0)for(k=0;k<g;k++)printf(" ");
                    printf("┌");for(j=0;j<m-2;j++)printf("─");printf("┐");
                }
                printf("\n");
                if(w==2)
                    for(i=0;i<n;i++)
                    {
                        if(i>0)for(k=0;k<g;k++)printf(" ");
                        printf("└");for(j=0;j<m-2;j++)printf("─");printf("┘");
                    }
                if(w>2)
                {
                    for(i=0;i<w-2;i++)
                    {
                        for(k=0;k<n;k++)
                        {
                            if(k>0)for(l=0;l<g;l++)printf(" ");
                            printf("│");for(j=0;j<m-2;j++)printf(" ");printf("│");
                        }
                        printf("\n");
                    }
                    for(i=0;i<n;i++)
                    {
                        if(i>0)for(k=0;k<g;k++)printf(" ");
                        printf("└");for(j=0;j<m-2;j++)printf("─");printf("┘");
                    }
                }
    }
    printf("\n");
}


void apf(char str1[], char str2[])
{
    if(strcmp(str2,"red")==0)printf("\033[38;5;196m%s\033[0m",str1);
    if(strcmp(str2,"green")==0)printf("\033[32m%s\033[0m",str1);
    if(strcmp(str2,"blue")==0)printf("\033[34m%s\033[0m",str1);
    if(strcmp(str2,"yellow")==0)printf("\033[33m%s\033[0m",str1);
    if(strcmp(str2,"grey")==0)printf("\033[30m%s\033[0m",str1);
    if(strcmp(str2,"orange")==0)printf("\033[38;5;208m%s\033[0m",str1);
    if(strcmp(str2,"pink")==0)printf("\033[35m%s\033[0m",str1);
    if(strcmp(str2,"cyan")==0)printf("\033[36m%s\033[0m",str1);
    if(strcmp(str2,"def")==0)printf("%s",str1);
}



void blank_box(int l,int w,int g)        //g = gap
{
    int i,j;
    if(g<0)g/=-1;
    if(l<0)l/=-1;
    if(w<0)w/=-1;

    if((l==1&&w==1)||(l>1&&w==1))                                //l = w = 1
    {
        for(i=0;i<g;i++)printf(" ");
        for(i=0;i<l;i++)printf("─");
    }
    else if(l==1&&w>1)
    {
        
        for(i=0;i<w;i++)
        {
            for(j=0;j<g;j++)printf(" ");
            printf("│\n");
        }
    }
    else if(l!=1&&w==2)                     // l > 1      w = 2
    {
        if(l!=1&&w==1){
            for(i=0;i<g;i++)printf(" ");
            for(i=0;i<l;i++)printf("─");
        }
        if(l>1&&w>1)
        {
            for(i=0;i<g;i++)printf(" ");
            printf("┌");for(i=0;i<l-2;i++)printf("─");printf("┐");printf("\n");

            for(i=0;i<g;i++)printf(" ");
            printf("└");for(i=0;i<l-2;i++)printf("─");printf("┘");
        }
    }
    else if(l>2&&w>2)                       //l > 2        w > 2
    {
        for(i=0;i<g;i++)printf(" ");
        printf("┌");for(i=0;i<l-2;i++)printf("─");printf("┐");printf("\n");
        for(j=0;j<w-2;j++){
            for(i=0;i<g;i++)printf(" ");
        printf("│");for(i=0;i<l-2;i++){printf(" ");}printf("│\n");
        }
        for(i=0;i<g;i++)printf(" ");
        printf("└");for(i=0;i<l-2;i++)printf("─");printf("┘");
    }

    else if(l==2&&w>l)                                // l = 2       w > l
    {
        for(i=0;i<g;i++)printf(" ");
        printf("┌");printf("┐\n");
        for(j=0;j<w-2;j++)
        {
            for(i=0;i<g;i++)printf(" ");
        printf("│");printf("│\n");
        }
        for(i=0;i<g;i++)printf(" ");
        printf("└");printf("┘");

    }
    printf("\n");
}


void heable(int a,char str1[],char str2[])
{
    int len1,len2,len3,i;
    len1=strlen(str1);
    len2=strlen(str2);

    if(len1>len2)
    {
        len3=len1-len2;     //difference betwen character of two arrays
        for(i=0;i<a;i++){printf(" ");}printf("┌");
        for(i=0;i<len1;i++){printf("─");}
        printf("┐\n");
        for(i=0;i<a;i++){printf(" ");}printf("│");
        printf("%s",str1);
        printf("│\n");
        for(i=0;i<a;i++){printf(" ");}printf("├");
        for(i=0;i<len1;i++){printf("─");}
        printf("┤\n");
        for(i=0;i<a;i++){printf(" ");}printf("│");
        printf("%s",str2);
        for(i=0;i<len3;i++){printf(" ");}
        printf("│\n");
        for(i=0;i<a;i++){printf(" ");}printf("└");
        for(i=0;i<len1;i++){printf("─");}
        printf("┘");

    }

    else if(len2>len1)
    {
        len3=len2-len1;    //difference betwen character of two arrays
        for(i=0;i<a;i++){printf(" ");}printf("┌");
        for(i=0;i<len2;i++){printf("─");}
        printf("┐\n");
        for(i=0;i<a;i++){printf(" ");}printf("│");
        printf("%s",str1);
        for(i=0;i<len3;i++){printf(" ");}
        printf("│\n");
        for(i=0;i<a;i++){printf(" ");}printf("├");
        for(i=0;i<len2;i++){printf("─");}
        printf("┤\n");
        for(i=0;i<a;i++){printf(" ");}printf("│");
        printf("%s",str2);
        printf("│\n");
        for(i=0;i<a;i++){printf(" ");}printf("└");
        for(i=0;i<len2;i++){printf("─");}
        printf("┘");
    }

    else if(len1==len2)
    {
        len3=len2-len1;    //difference betwen character of two arrays
        for(i=0;i<a;i++){printf(" ");}printf("┌");
        for(i=0;i<len2;i++){printf("─");}
        printf("┐\n");
        for(i=0;i<a;i++){printf(" ");}printf("│");
        printf("%s",str1);
        for(i=0;i<len3;i++){printf(" ");}
        printf("│\n");
        for(i=0;i<a;i++){printf(" ");}printf("├");
        for(i=0;i<len2;i++){printf("─");}
        printf("┤\n");
        for(i=0;i<a;i++){printf(" ");}printf("│");
        printf("%s",str2);
        printf("│\n");
        for(i=0;i<a;i++){printf(" ");}printf("└");
        for(i=0;i<len2;i++){printf("─");}
        printf("┘");
    }
    printf("\n");
}



void de(int r,int s)
{
    if(r<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    int i,j;
    s=1000000/s;
    char d[10][11]={">---------","->--------","-->-------","--->------","---->-----","----->----","------>---","------->--","-------->","--------->"};
    for(i=0;i<r;i++)
    {
        for(j=0;j<10;j++)
        {
        printf("%s",d[j]);
        fflush(stdout);
        usleep(s);
        printf("\033[10D\033[K");
        }
    }
}

void bb(int c)
{
    if(c<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    int i,j;
    char d[10]="000o__o0";
    for(i=0;i<c;i++)
    {
        for(j=0;j<8;j++)
        {
        printf("%c",d[j]);
        fflush(stdout);
        usleep(83333);
        printf("\033[1D\033[K");
        }
    }
}

void pb(int c, int s)
{
    if(s<=0||c<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    int i,j;
    s=1000000/s;
    for(i=0;i<c+1;i++)
    {
        printf("[");
        for(j=0;j<i;j++)
        {
            printf("#");
        }
        printf("]");
        fflush(stdout);
        usleep(s);
        printf("\033[%dD\033[K",i+2);
    }
}

void be2(int t)
{
    if(t<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    char s[5][4]={"O_O","O_O","-_-","O_O","O_O"};
    int i,j;
    for(i=0;i<t;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%s",s[j]);
            fflush(stdout);
            usleep(333333);
            printf("\033[3D\033[K");
        }
        usleep(555555);
    }
}

void bos(char sen[],int t)
{
    if(t<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    int i,j,s,l;
    l=strlen(sen);
    s=1000000/t;
    printf(" ");
    for(i=0;i<l+1;i++)
    {
        printf("\033[%dD\033[K",i+1);
        printf("[");
        for(j=0;j<i;j++)
        {
            printf("%c",sen[j]);
        }
        printf("]");
        fflush(stdout);
        usleep(s);
    }
    usleep(999999);
}

void be(int t)
{
    if(t<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    char s[5][4]={"O_O","O_O",">_<","O_O","O_O"};
    int i,j;
    for(i=0;i<t;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%s",s[j]);
            fflush(stdout);
            usleep(333333);
            printf("\033[3D\033[K");
        }
        usleep(555555);
    }
}

void rl(int r,int s)
{
    if(s<=0||r<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    int i,j;
    s=1000000/s;
    char d[5]="-\\|/";
    for(i=0;i<r;i++)
    {
        for(j=0;j<4;j++)
        {
        printf("%c",d[j]);
        fflush(stdout);
        usleep(s);
        printf("\033[1D\033[K");
        }
    }
}

void dpu(char a[],char str2[],int s)
{
    if(s<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    int i,count=0,speed=1000000/s;
    count=strlen(a);
    for(i=0;i<count;i++)
    {
        if(strcmp(str2,"red")==0)printf("\033[31m%c\033[0m",a[i]);
        if(strcmp(str2,"green")==0)printf("\033[32m%c\033[0m",a[i]);
        if(strcmp(str2,"blue")==0)printf("\033[34m%c\033[0m",a[i]);
        if(strcmp(str2,"yellow")==0)printf("\033[33m%c\033[0m",a[i]);
        if(strcmp(str2,"grey")==0)printf("\033[30m%c\033[0m",a[i]);
        if(strcmp(str2,"orange")==0)printf("\033[38;5;208m%c\033[0m",a[i]);
        if(strcmp(str2,"pink")==0)printf("\033[35m%c\033[0m",a[i]);
        if(strcmp(str2,"cyan")==0)printf("\033[36m%c\033[0m",a[i]);
        if(strcmp(str2,"def")==0)printf("%c",a[i]);
        fflush(stdout);
        usleep(speed);
    }
}

void erase()
{
    printf("\033[H\033[J");
}

void timer(int a)
{
    if(a<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    int i,t=1000000;
    for(i=1;i<=a;i++)
    {
        usleep(t);
    }
}

void dl(int t,int c,int s)
{
    if(c<=0||t<=0||s<=0){printf("\nsomething is wrong!"); printf("\nNo zeros allowed for any parameter!"); exit(1);}
    int i,j;                 //t = how many time dots gonna be print, p = needed position from where you want them to start again (collum's position), c = count of dots
    s=1000000/s;
    for(i=0;i<t;i++)
    {
        for(j=0;j<c;j++)
        {
            printf(".");
            fflush(stdout);
            usleep(s);
        }
        printf("\033[%dD\033[K",c);
        fflush(stdout);
    }
}

