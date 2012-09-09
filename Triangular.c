#include<stdio.h>
    int main ()
   {
      float i,step,f=2,dur=1,fs=44100,amp=5,s[100000]={0};
      int c=0, x=1;
      unsigned short int r[100000]={0};
      FILE *filePtr;
      filePtr = fopen("floatArray.txt","w");
      step=(amp*(65535/5))*(f/fs);
      printf("%f\t",step);
      while(c<(f*dur))
      {
         s[x-1]=0;
         r[x-1]=s[x-1];
         printf("%u\t",r[x-1]);
         fprintf(filePtr, "%u\n", r[x-1]);
         for (i=0;i<((1/(2*f))-(1/fs));i=i+(1/fs))
         {
            s[x]=s[x-1]+step;
            r[x]=s[x];
            printf("%u\t",r[x]);
            fprintf(filePtr, "%u\n", r[x]);
            x++;
         }
         for (i=0;i<((1/(2*f))-(1/fs));i=i+(1/fs))
         {
            s[x]=s[x-1]-step;
            r[x]=s[x];
            printf("%u\t",r[x]);
            fprintf(filePtr, "%u\n", r[x]);
            x++;
         }
      
         c++;
      }
   }