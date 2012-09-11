#include<stdio.h>
#include<stdlib.h>
    int main()
   {
      float amp=5,dur=1;
      int x=0,size;
      float i,f=4,fs=44100;      
      float limit=1.0/(2*f);
      unsigned short int *r;  
      r = (unsigned short int *)malloc(size*sizeof(unsigned short int ));
      FILE *filePtr;
      filePtr = fopen("floatArray.txt","w");
      size = fs*dur;
      while(x<(fs*dur))
      {
         for(i=0;i<limit;i=i+(1/fs))
         {
            r[x]=amp*(65535/5);
            printf("%d\t",r[x]);
            fprintf(filePtr, "%u\n", r[x]);
            x++;
         }
         for(i=0;i<limit;i=i+(1/fs))
         {
            r[x]=0;
            printf("%d\t",r[x]);
            fprintf(filePtr, "%u\n", r[x]);
            x++;
         }
      }
      FILE *pipe = popen("gnuplot -persist","w");
      fprintf(pipe, "set data style lines \n");
      fprintf(pipe, "plot 'floatArray.txt'\n");
   }