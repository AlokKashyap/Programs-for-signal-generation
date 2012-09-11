#include<stdio.h>
#include<stdlib.h>
    int main ()
   {
      float i,step,f=7,dur=1,fs=44100,amp=5,s[100000]={0};
      int c=0, x=1,size;
      unsigned short int *r;  
      r = (unsigned short int *)malloc(size*sizeof(unsigned short int ));
      size=fs*dur;
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
         for (i=0;i<((1/f)-(1/fs));i=i+(1/fs))
         {
            s[x]=s[x-1]+step;
            r[x]=s[x];
            printf("%u\t",r[x]);
            fprintf(filePtr, "%u\n", r[x]);
            x++;
         }
         c++;
      }
      s[x-1]=0;
      r[x-1]=s[x-1];
      printf("%u\t",r[x-1]);
      fprintf(filePtr, "%u\n", r[x-1]);
      FILE *pipe = popen("gnuplot -persist","w");
      fprintf(pipe, "set data style lines \n");
      fprintf(pipe, "plot 'floatArray.txt'\n");
   }