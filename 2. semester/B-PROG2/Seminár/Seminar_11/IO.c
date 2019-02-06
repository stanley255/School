#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* txtToString(FILE *fin){
	char* ptr;
	int length;
	fseek(fin,0,SEEK_END);
	length = ftell(fin);
	rewind(fin);
	ptr = malloc(length);
	fread(ptr,1,length,fin);
	ptr[length]='\0';
	fclose(fin);
	return ptr;
}

void prekopirujSubor(){
	FILE *fin, *fout;
	char c;
	fin = fopen("input.txt","rt");
	fout = fopen("output.txt","wt");
	while ((c = fgetc(fin)) != EOF){
		fputc(c,fout);
	}	
	fclose(fin);
	fclose(fout);
}

void prekopirujSuborBinarne(){
	FILE *fin, *fout;
	int length;
	fin = fopen("input.txt","rb");
	fout = fopen("output.txt","wb");
	fseek(fin,0,SEEK_END);
	length = ftell(fin);
	rewind(fin);
	char *buffer = malloc(length);
	//fread ( void * ptr, size_t size, size_t count, FILE * stream );
	fread(buffer,1,length,fin);
	fwrite(buffer,1,length,fout);
	fclose(fin);
	fclose(fout);
}

void spocitajRiadky(FILE *fin){
	int c;
	int counter = 0;
	while ((c = fgetc(fin))!=EOF){
		if (c=='\n') counter++;
	}
	printf("Pocet riadkov: %i\n",++counter);
}

void spocitajRiadky2(){
	FILE *fin = fopen("input.txt","rt");
	spocitajRiadky(fin);
	rewind(fin);
	spocitajRiadky(fin);
	fclose(fin);
}

void spocitajCisla(){
	int a;
	int counter = 0;
	FILE *fin = fopen("input2.txt","rt");
	while (fscanf(fin,"%i",&a)>0)
		counter++;
	printf("%i",counter);
	fclose(fin);
}

void spojDvaDokumenty(FILE* f1, FILE* f2){
	// Inicializacia vystupneho subora
	FILE * f3 = fopen("spojene.txt","w");
	
	// Zistenie velkosti oboch suborov
	int length1, length2;
	fseek(f1,0,SEEK_END);
	fseek(f2,0,SEEK_END);
	length1 = ftell(f1);
	length2 = ftell(f2);	
	rewind(f1);
	rewind(f2);
	
	// Inicializovanie bufferov
	char* buff1 = malloc(length1);
	char* buff2 = malloc(length2);
	
	// Nacitanie udajov do bufferov
	fread(buff1,1,length1,f1);
	fread(buff2,1,length2,f2);
	
	// Spojenie do jedneho subora
	fwrite(buff1,1,length1,f3);
	fwrite(buff2,1,length2,f3);
	
	// Zatvorenie suborov
	fclose(f1);
	fclose(f2);
	fclose(f3);	
}

int main(){
	FILE * f1 = fopen("input2.txt","r");
	FILE * f2 = fopen("input.txt","r");
	spojDvaDokumenty(f1,f2);
	char c[10] = {'a','b'};
	printf("%c",*(c+1));
	
	return 0;
}
