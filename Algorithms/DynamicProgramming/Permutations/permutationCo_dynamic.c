//P(n, k) = P(n-1, k) + k* P(n-1, k-1) 

# include<stdio.h>

long Permutation(int n,int k){
	long array[n+1][k+1];
	array[1][0]=1;
	array[0][1]=1;
	array[0][0]=0;
	
	//printf("the value is %d",array[0][0]);
	for(int i=1;i<=n;i++){
		for (int j=0;j<=k;j++){
			if(j==0)
				array[i][j]=1;
			else
				array[i][j]=array[i-1][j]+array[i-1][j-1];
		if(j>i)
			array[i][j]=0;		
		}	
	}
	return array[n][k];	
}


int main(){	
	int i=100;
	int j=50;
	
			printf("Value of P(%d , %d) is %lu\n",i,j,Permutation(i,j));
	return 0;
}
