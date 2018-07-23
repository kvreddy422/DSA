# include<stdio.h>

int Permutation(int n,int k){
	int a=n-k;
	if(n-k<1)
		a=1;
	if(k<1)
		k=1;
	if(n==1)
		return 1;
	else 
		return n*Permutation(n-1,k)/a;
}


int main(){
	int n=10,k=2;
	printf("Value of P(%d , %d) is %d",n,k,Permutation(n,k));
	return 0;
}
