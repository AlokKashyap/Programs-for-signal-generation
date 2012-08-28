#include<stdio.h>
    int main()
   {
      float amp=5,dur=1;
      int x=0;
      float i,f=4,fs=44100;
      unsigned short int r[100000]={0};      
      float limit=1.0/(2*f);
      FILE *filePtr;
      filePtr = fopen("floatArray.txt","w");
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
   }