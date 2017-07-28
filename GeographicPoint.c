 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h>

#define filas 500
#define columnas 744

int indice(int i,int j);
void lectura(int *arch);
int radio(int i, int j, int *arch);
void printij(int i, int j, int rmax);

int main(void){
	
	srand48(1);
	srand(time(NULL));
	int t;
	int n=2000;
	int *coordenadas=malloc((filas*columnas)*sizeof(int));
	lectura(coordenadas);
	int i = rand()%(filas-1);
	int j= rand()%(columnas-1);
	int radio1=radio(i,j, coordenadas);
	//printf("hola1 %d \n", radio1);
	int i_prima;
	int j_prima;
	int radio_prima;

	for(t=1; t<n; t++){
		i_prima=(int) i+((1-2*drand48())*100);
		j_prima=(int) j+((1-2*drand48())*100);
		radio_prima=radio(i_prima,j_prima, coordenadas);
		//printf("hola2 %d \n", radio_prima);	
		float alfa=exp((radio_prima-radio1));
		//printf("hola3 %f \n", alfa);
		if(alfa>=1.0){
			i=i_prima;
			j=j_prima;
			radio1=radio_prima;
		}
    	else{
        	float beta= drand48();
        	if(alfa>=beta){
			i=i_prima;
			j=j_prima;
			radio1=radio_prima;

		}

	}
		
	}
	printij(i,j,radio1);
	printf("las coordenadas del punto mass alejado son: longitud %d,latitud %d\n", j, i);
return 0;
}
void lectura(int *arch){
	FILE*file;
	file=fopen("map_data.txt","r");
	int len=1500;
	char line_buffer[len];
	char *split_buffer;
	const char *delimiter;
	delimiter=" ";
	int i=0;
	int j=0;
	while(fgets(line_buffer,len,file)){
		j=0;
		split_buffer=strtok(line_buffer,delimiter);
		while(split_buffer != NULL){
			if (j != 0)		
			{ 
				arch[indice(i,j)]=atof(split_buffer);
				//printf("%f\n",arch[indice(i,j)]);
			}
			split_buffer=strtok(NULL,delimiter);
			
			j+=1;
		}
	i+=1;
	}
	fclose(file);
}


int indice(int i,int j){
	if(i>filas){
		i= i%filas;		
	}
	if(j>columnas){
		j= j%columnas;
	}
	if(i<0){i=filas+i;}
	if(j<0){j=columnas+j;}

	return ((columnas*i)+j);
}

int radio(int i, int j, int *arch){
	int r=0;
	int n;
	int h;
	int k;
	float temp;
	int num =arch[indice(i,j)];
	if(num!=1){
	 for (n=1; n<=filas/2;n++){
			r=n;
			//printf("hola1 \n");
			for(h=-r; h<=r;h++){
				//printf("hola2 \n");
				for(k=-r; k<=r;k++){
					//printf("hola3 \n");
					temp= pow(pow(h,2)+pow(k,2),0.5);
					if(arch[indice(i+h,j+k)]==1 && temp<=r){
						return temp;
					}

				}
			}
		
		}
	}
}


void printij(int i, int j, int rmax){
	FILE *out;
	out=fopen("temporal.txt","w");
	fprintf(out,"%d %d %d\n", i, j, rmax);  
	fclose(out);
}














		

