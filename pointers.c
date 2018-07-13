main(){
	int a=10;
	int *b,**c,***d;
	b=&a;
	c=&b;
		
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%d\n",d);
	printf("%d\n",&a);
	printf("%d\n",&b);
	printf("%d\n",&c);
	printf("%d\n",&d);
}









/*
1186078508
1186078512
1186078768
1186078508
1186078512
1186078520
1186078528
*/
