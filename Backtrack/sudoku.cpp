#include<stdio.h>
#include<cstring>
using namespace std;
int matrix[10][10]={-1};
bool find_empyt_space(int *empty_r,int *empty_c);
bool backtrack();


bool final_flag=false;


int main(){
		
		int test;
		scanf("%d",&test);
		while(test--){
		char str[90];
		int temp=9,i=1,k=0;
		scanf("%s",str);
		
		while(i<=temp){
			
			for(int j=1;j<=9;j++){ 

				if(str[k]=='.'){
					matrix[i][j]=-1;
					
				}
			else
				matrix[i][j]=str[k]-48;
			
			k++;
			}
			i++; 

		}
		if(backtrack())
		for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			printf("%d",matrix[i][j]);
		}
		

	}

	memset(matrix,0,sizeof(matrix));
	
	}
return 0;}



bool find_empyt_space(int *empty_r,int *empty_c){


	//find emptty space

	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(matrix[i][j]==-1){
				
				*empty_r=i;
				*empty_c=j;
				
				//	printf("I found aanempty sapce at %d %d\n",i,j);
					return true;
					
			}

		}
		
		}

return false;}
bool backtrack(){
	int empty_r=1,empty_c=1;

		if(!find_empyt_space(&empty_r,&empty_c)){
			
			return true;
		}
		
	for(int i=1;i<=9;i++){
	bool within_row,within_col,within_box=false;	
		for(int cc=1;cc<=9;cc++){
			if(matrix[empty_r][cc]==i){
				within_row=true;
				break;
			}

		}
		if(within_row){
			within_row=false;
			continue;
			
		}
		for(int rr=1;rr<=9;rr++){
			if(matrix[rr][empty_c]==i){
				within_col=true;
				break;
			}


		}
		if(within_col){
		
			within_col=false;
			continue;
			
		}	

		int sboxr=0;
		int sboxc=0;
		

		if(empty_r>=1 && empty_r<=3){
			sboxr=1;
		}
		else if(empty_r>=4 && empty_r<=6)
		{
			sboxr=4;
		}
		else if(empty_r>=7 && empty_r<=9){
			sboxr=7;
		}
		else{
			printf("empty_r is out of range\n");

		}


		if(empty_c>=1 && empty_c<=3){
			sboxc=1;
		}
		else if(empty_c>=4 && empty_c<=6){
			sboxc=4;
		}
		else if(empty_c>=7 && empty_c<=9){
			sboxc=7;
		}
		else{
			printf("empty_c outof range\n");
		}

		for(int box1=sboxr;box1<=sboxr+2;box1++){
			for(int box2=sboxc;box2<=sboxc+2;box2++){
				if(matrix[box1][box2]==i){
					within_box=true;
					break;
				}
			}
			if(within_box){
				break;
			}
		}
		if(within_box){
						within_box=false;
			continue;
		}
		
		matrix[empty_r][empty_c]=i;
		
		if(backtrack())
		return true;
		
			//printf("I am again going back after chagig empty_r %d empty_c %d\n",empty_r,empty_c);
		

		matrix[empty_r][empty_c]=-1;

	
	}		

		return false;

}




