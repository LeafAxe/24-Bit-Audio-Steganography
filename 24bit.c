#include <stdio.h>
#include <stdlib.h>

void encode();
void decode();


int main(){
	char choice;
	printf("(E/D)\n");
	scanf(" %c",&choice);
	if (choice=='E'){
		encode();
	}else if (choice=='D'){
		decode();
	}
	
	return 0;
}

void encode(){
	int check;
	int filesize[48];
	
	//24bit read
	
	FILE *point;
	int i=0;
	char filename[60];
	
	do{
	printf("Put in 24 bit filename\n");
	scanf("%s",&filename);
	point=fopen(filename,"rb");
	}while(point==NULL);
	
	fread(filesize,0x30,1,point);
	fclose(point);
	
	int x=filesize[1];
	
	unsigned char *horse=malloc(x);
	unsigned char *trojan=malloc(x);
	
	FILE *point4;
	point4=fopen(filename,"rb");
	
	
	fread(horse,x,1,point4);
	
	fclose(point4);
	
	for(i=0x0;i<0x60;i++){
		printf("%X",horse[i]);
	}
	printf("\n\n\n");
	//hidden file read
	
	FILE *point2;
	
	do{
	printf("Put in hidden file filename\n");
	scanf("%s",&filename);
	point2=fopen(filename,"rb");
	}while(point2==NULL);
	
	fread(trojan,filesize[10],1,point2);
	
	fclose(point2);
	
	//operations with horse and trojan
	int k=0;
	
	for (int j=0x2C;j<=(filesize[10]);j=j+3){
		horse[j]=trojan[k];
		k++;
	}
	for (i=0x0;i<=0x100;i=i+8){
		printf("%X\t%X\t%X\t%X\t%X\t%X\t%X\t%X\t\t%C%C%C%C%C%C%C%C\n",horse[i],horse[i+1],horse[i+2],horse[i+3],horse[i+4],horse[i+5],horse[i+6],horse[i+7],horse[i],horse[i+1],horse[i+2],horse[i+3],horse[i+4],horse[i+5],horse[i+6],horse[i+7]);
	}
	
	FILE *point3;
	point3=fopen("hiden.wav","wb");
	
	fwrite(horse,1,x,point3);
	
	fclose(point3);
	
	free(horse);
	free(trojan);
	
}

void decode(){
	
	int filesize[48];

	FILE *point;
	char filename[60];
	
	do{
		printf("Input encoded file\n");
		scanf("%s",&filename);
		point=fopen(filename,"rb");
	}while(point==NULL);
	
	fread(filesize,0x30,1,point);
	fclose(point);
	int x=filesize[10];
	
	unsigned char *horse=malloc(x);
	unsigned char *trojan=malloc(x);
	
	FILE *point4;
	point4=fopen(filename,"rb");
	fread(horse,filesize[1]+9,1,point4);
	
	int j=0x0;
	for(int i=0x2C;i<=filesize[1]+9;i=i+3){
		trojan[j]=horse[i];
		j++;
	}
	
	fclose(point4);
	char newfilename[60];
	
	FILE *point2;
	printf("Name of output?\n");
	scanf("%s",&newfilename);
	point2=fopen(newfilename,"wb");
	fwrite(trojan,1,(x/3),point2);
	
	fclose(point2);
	
	free(horse);
	free(trojan);

	
}

