#include<unistd.h>
int main(int argc, char *v[]){
char arr[][7]={{"000000\n"},
				{"000000\n"},
				{"000000\n"},
				{"000000\n"},
				{"000000\n"},
				{"000000\n"},
				};
int i,j,k,set=0;
for(i=0;i<6;i++){
for(j=0;j<6;j++){
	if(k<4){
		if(set==0){set=1;j=1;}
		arr[i][j]=v[k];
		}
	else if(k>3&&k<8){
		if(set==1){i=5;set=0;j=1;}
		arr[i][j]=v[k];	
		}
		else if(k>7&&k<12){
			if(set==0){i=0;set=1;}
			if(j>0)break;
			arr[i][j]=v[k];
			}
		else if(k>11&&k<16){
			if(set==1){i=1;set=0;}
			j=5;
			arr[i][j]=v[k];
		}k++;
}}
write(1,arr,42);	
return 0;
}
