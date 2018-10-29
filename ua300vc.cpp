// ua300vc.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "windows.h"
#include "stdafx.h"
#include "ua326d.h"

HANDLE h326a;
HANDLE h326b;

int main(int argc, char* argv[])
{
//short int	shortdat1, shortdat2, shortdat3, shortdat4;
short int fch,chn,ch,gain;
short int i,j;
short int addat[51200];

printf("Hello World!\n");

if(OpenUA326_a(0,h326a)!=0)  // ���豸,�õ����
{
	printf("device open error!!\n");
}
                  
if(OpenUA326_b(0,h326b)!=0)  // ���豸,�õ����
{
	printf("device open error!!\n");
}

printf("\ntest 1 \n");	


// ��ʾ0����ͨ�����ݣ���

fch=0;chn=8;gain=1;
for(i=0;i<8;i++){
	ss326(h326a,addat,fch,chn,gain);
	for(ch=0;ch<8;ch++){
		printf("%2.4f  ",addat[ch]*.00030518/gain);
	}
   printf("\n");
}

//Sleep(50);
printf("\ntest 2 \n");

fch=0; chn=6;gain=1;
mm326(h326a, addat,fch,chn,1000,512,gain);           // ���ɼ�, 1000 Hz, 512�� 

//  ��ʾ����

for(i=0;i<8;i++){
   for(ch=0;ch<chn;ch++){
      printf("%6d ",addat[i*chn+ch]);

   }
printf("%4d \n",i);
}


printf("\ntest 3 \n");

fch=0; chn=8;gain=1;

start326(h326a,fch,chn,1000,1);                      // ���ɼ���ʼ��,0-7ͨ��, 1KHz,����1

read326(h326a, addat,256);           // ���ɼ�, 256�� 

j=0;
for(i=0;i<2;i++){
   for(ch=0;ch<8;ch++){
      printf("%6d  ",addat[j++]);

   }
printf("\n");
}

read326(h326a, addat,256);           // ���ɼ�, 256�� 

j=0;
for(i=0;i<2;i++){
   for(ch=0;ch<8;ch++){
      printf("%6d  ",addat[j++]);

   }
printf("\n");
}

read326(h326a, addat,256);           // ���ɼ�, 256�� 

j=0;
for(i=0;i<2;i++){
   for(ch=0;ch<8;ch++){
      printf("%6d  ",addat[j++]);

   }
printf("\n");
}

stop326(h326a);


printf("\ntest DI \n");

printf(" %2x ",din(h326b));
//printf(" %2x \n",vin(h326));

printf("\ntest DA-out \n");

daout(h326b,0,0);        // DA1 0V 

daout(h326b,1,2048+1023);   // DA2 5V 
daout4(h326b, 1, 3, 5, 7);

CloseUA326_a(h326a);              //
CloseUA326_b(h326b);              //

return 0;

}





