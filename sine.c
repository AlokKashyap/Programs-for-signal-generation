#include<stdio.h>
#include<math.h>
#include<stdlib.h>
    int main()
   {
      int freq,fs,amplitude,cycle,duration,x=0,cent,size;
      unsigned short int *r;  
      r = (unsigned short int *)malloc(size*sizeof(unsigned short int )); 
      double angle,increment,sample;
      int i;
      FILE *filePtr;
      filePtr = fopen("floatArray.txt","w");
      printf("enter the desired frequency of the signal:\n");
      scanf("%d",&freq);
      printf("enter the desired sampling frequency:\n");
      scanf("%d",&fs);
      printf("enter the amplitude of the signal:\n");
      scanf("%d",&amplitude);
      printf("enter the duration of the signal:\n");
      scanf("%d",&duration);
      angle=0;
      size = fs*duration;
      increment=((2*M_PI*freq)/fs);
      cent=(amplitude*65535/10);
      while (angle<=(2*M_PI*freq*duration))
      {
         r[x]=cent+((amplitude * sin(angle))*32768/5);
         fprintf(filePtr, "%u\n", r[x]);
         printf("%u\t",r[x]);
         angle=angle+increment;
         x++;
      }
      FILE *pipe = popen("gnuplot -persist","w");
      fprintf(pipe, "set data style lines \n");
      fprintf(pipe, "plot 'floatArray.txt'\n");
   }