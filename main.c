#include<stdint.h>
#include<stdlib.h>
#include<stdio.h> //cstdio in cpp
#include <netinet/in.h>
#include<stddef.h>
#include<string.h>

uint32_t getNboNum(char fileName[]){
	void *buff=malloc(sizeof(uint32_t));
	uint32_t *res = (uint32_t*)buff,n;
	
	FILE *fp=fopen(fileName,"rb");
	if (fp==NULL){fputs("fopen err\n",stderr); exit(1);}
	fread(buff,1,sizeof(uint32_t),fp);
	//printf("%x",n);
	n = ntohl(*res);
	//printf("%d\n",(int)n);
	//printf("%x\n",n);
	return n;
}

int main(){
	
	uint32_t thousand, five_hundred,sum;
	thousand = getNboNum("thousand.bin");
	five_hundred = getNboNum("five-hundred.bin");
	sum = thousand+five_hundred;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",(int)thousand,thousand,(int)five_hundred,five_hundred,(int)sum,sum);


	return 0;
}