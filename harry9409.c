#include <stdio.h>
#include <string.h>
char dic[26000][20];// 단어 저장(전역변수)
int trans(int a, int b)
{
   int eod;
   int i;
   int count=0;
   eod=strlen(dic[a]);
   for(i=0;i<eod;i++)
   {
     if(dic[a][i]!=dic[b][i]) {
     count++;}
    } 
     return count;
 
}  
void main()
{
  int i,j; //반복문용
  int num=0; //문자갯수
  int ct;
  int x,y;
  int len;
  int max=0;
  FILE*fp=fopen("./input.txt", "r");
  for(i=1;;i++)
  {
        fscanf(fp," %s ",dic[i]);
        num=i;    
        if(feof(fp))
         { 
            break;
         }   
  }
 fclose(fp);
for(i=1;i<num;i++)
 {
    x=i;
    y=i+1;
    len=0;
    while(y<=num)///////////////////////////////////이새키에서 존나 에러가 나온다. 존나 답없어 답없어 답없어 답없어 답업서 답업
    {
       ct=trans(x,y);
      
       if(ct==1)
       {
          x=y;
          y=y+1;
          len++;
       }
       else if(ct>1)
       {
         y=y+1;
       }
  
     }
    
     if(max<=len)
     {
        max=len;
     }
}
printf("%d",max);
 
}
