#include <stdio.h>
long recursion(long base, long power);
int main() 
{
	long base,power,result;

	printf("Input the base value:\n");
	scanf("%ld", &base);
	printf("Input the value of power:\n");
	scanf("%ld", &power);
	result = recursion(base,power);

	printf("The value of %ld to the power of %ld is: %ld", base,power,result);


	return 0;
}

long recursion(long base, long power)
{

	if(power == 0)
		return 1;	
	else 
		return (base * recursion(base, power - 1));

}