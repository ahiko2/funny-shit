#include<stdio.h>
int main(int argc, char*argv[])
{
   FILE *fp;
   unsigned char buf[16];
   unsigned long addr =0;
   int readnum, i;
 
   if(argc<=1){
       printf("usage:dump filename\n");
       return 1;
   }
   if(!(fp=fopen(argv[1],"rb"))){
       printf("file open error.\n");
       return 1;
   }
   while(1) {
       printf("%08x ",addr);
       readnum = fread(buf, 1, 16, fp);
       for(i=0;i<readnum;i++){
           if(i==8)
               printf(" ");
           printf("%02x ",buf[i]);
       }
       for(i=readnum;i<=16;i++){
           if(i==8)
               printf(" ");
           printf("   ");
       }
       printf("  ");
       for(i=0;i<readnum;i++)
           printf("%c ", (32<=buf[i]&&buf[i]<=126)?buf[i]:'.');
       printf("\n");
       addr +=16;
       if(feof(fp))
           break;
   }
   fclose(fp);
   return 0;
}
