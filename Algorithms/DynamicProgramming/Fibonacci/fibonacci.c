# include<stdio.h>
int fibo(int n){
	if (n<=1)
		return n;
	return fibo(n-1)+fibo(n-2);
}

void main(){
	printf("%d ",fibo(6));
}
