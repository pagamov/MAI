#include <stdio.h>
#include <math.h>

double eps(void)
{
	double eps = 1;
	double a = pow(10, 11);
	while ((a + eps / 2) > a) {
		eps /= 2;
	}
	return eps;
}

double valueFunc1(double x)
{
	// double i = 1 - pow(x, 3) * 0.3;
	// return acos(x) - sqrt(i);

	return 3 * x - 4 * log(x) - 5;
}

double valueFunc2(double x)
{
	return 3 * x - 4 * log(x) - 5 + x;
}

double stdiffFunc2(double x, double eps)
{
	return (valueFunc2(x + eps) - valueFunc2(x)) / (eps);
}

double stdiffFunc3(double x, double eps)
{
	return (valueFunc1(x + eps) - valueFunc1(x)) / eps;
}

double nddiffFunc3(double x, double eps)
{
	double a = stdiffFunc3(x + eps, eps) - stdiffFunc3(x, eps);
	double b = eps;
	return a / b;
}
	
int main(void)
{
	double e = eps();
	double ast = 2; //0 //2
	double bst = 4;	//1 //4
	int iteration = 0;
	double a = ast;
	double b = bst;
	//printf("%e, %e, %e\n", stdiffFunc2(a, e), stdiffFunc3(a, e), nddiffFunc3(a, e));
	printf("Epsilon = %e \nreal = 0,5629\n", e); //3.23
	//Половинное деление
	while(fabs(a - b) >= e) {
		if (valueFunc1(a) * valueFunc1((a+b)/2) > 0)
			a = (a + b) / 2;
		else if (valueFunc1(b) * valueFunc1((a+b)/2) > 0)
			b = (a + b) / 2;
		iteration++;
	}
	printf("iteration = %d, %.4f\n", iteration, (a + b) / 2);
	//Итерации
	a = ast; //0
	b = bst; //1
	iteration = 0;
	int pass = 1;
	double xn = a;
	while(xn < b) {
		break;
		if (fabs(stdiffFunc2(xn, e)) >= 1) {
			a += e;
			b -= e;
		}
		xn += e;
	}
	printf("%.16f, %.16f\n", a ,b);
	double x = (a + b) / 2;
	while(pass) {
		break;
		xn = valueFunc2(x);
		if (fabs(xn - x) < e) {
			printf("iteration = %d, %.4f\n", iteration, xn);
			break;
		}
		x = xn;
		iteration++;
	}
	//Ньютон
	a = ast;
	b = bst;
	iteration = 0;
	pass = 1;
	xn = a;
	while(xn < b) {
		if (fabs(valueFunc1(x) * nddiffFunc3(x, e)) > 0 && stdiffFunc3(x, e) != 0) {
			printf("iteration = 0, err\n");
			break;
		}
		xn += e;
	}
	x = (a + b) / 2;
	printf("Вроде все ок\n");
	while(pass) {
		xn = x - (valueFunc1(x) / stdiffFunc3(x, e));
		if (fabs(xn - x) < e) {
			printf("iteration = %d, %.4f\n", iteration, xn);
			break;
		}
		x = xn;
		iteration++;
	}
	return 0;
}
