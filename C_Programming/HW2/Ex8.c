// C Program to Make a Simple Calculator to Add, Subtract, Multiply or Divide Using switch...case

#include "stdio.h"

void main()
{
	char operator;
	float operand1, operand2;
	printf("Enter operator either + or - or * or divide : ");
	scanf("%c", &operator);

	printf("Enter two operands: ");
	scanf("%f\n%f", &operand1, &operand2);

	switch(operator)
	{
	case '+':
		printf("%0.1f %c %0.1f = %0.1f", operand1, operator, operand2, operand1 + operand2);
		break;
	case '-':
		printf("%0.1f %c %0.1f = %0.1f", operand1, operator, operand2, operand1 - operand2);
		break;
	case '*':
		printf("%0.1f %c %0.1f = %0.1f", operand1, operator, operand2, operand1 * operand2);
		break;
	case '/':
		printf("%0.1f %c %0.1f = %0.1f", operand1, operator, operand2, operand1 / operand2);
		break;
	default:
		printf("Please Enter A Valid Operator");
		break;
	}
}