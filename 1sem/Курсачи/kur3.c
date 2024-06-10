#include <stdio.h>
#include <math.h>

double eps(void)
{
	double eps = 1;
	while ((1 + eps / 2) > 1) {
		eps /= 2;
	}
	return eps;
}

double proiz(double x, int i)
{
	return -(pow(2, i) * pow(x, i)) / (pow(5, i + 1));
}

int main(void)
{
	double e = eps();
	double firstArg = 0;
	double lastArg = 2 + 0.01;
	double value = firstArg, valueNext;
	double step = 0.1;
	double valueReal;
	double delta;
	int i = 0;
	double valueFunc = 0;
	printf("Epsilon = %.e\n", e);
	printf("n      value   tailor                real\n");
	while (value <= lastArg) {
		i = 0;
		valueFunc = proiz(value, i);
		valueNext = proiz(value, i + 1);
		delta = valueNext / valueFunc;
		while (1) {
			if (fabs(valueNext) < e) {
				break;
			}
			valueFunc += valueNext;
			valueNext = valueNext * delta;
			i++;
		}
		valueReal = (1 / (2 * value - 5));
		printf("n : %d, %.2f, %.16f, %.16f\n", i, value, valueFunc, valueReal);
		value += step;
	}
	return 0;
}
