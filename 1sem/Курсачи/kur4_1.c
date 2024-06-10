#include <stdio.h>
#include <math.h>

double e(void)
{
	double ep = 1;
	while ((1 + ep / 2) > 1) {
		ep /= 2;
	}
	return ep;
}

double valueFunc(double x)
{
	return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}

double derivative(double (*f)(double), double x0, int order)
{
    const double delta = pow(10, -10);
    if (order == 1) {
        double x1 = x0 - delta;
        double x2 = x0 + delta;
        double y1 = f(x1);
        double y2 = f(x2);

        return (y2 - y1) / (x2 - x1);
    } else if(order == 2) {
        double x1 = x0 - delta;
        double x2 = x0 + delta;
        double y1 = derivative(f, x1, 1);
        double y2 = derivative(f, x2, 1);

        return (y2 - y1) / (x2 - x1);
    }
    return 0;
}

double lymbda(double x, double e)
{
	double l = 1;
	if (derivative(valueFunc, x, 1) < 0) {
		l = -1;
	}
	while (1 - l * derivative(valueFunc, x, 1) >= 1) {
		l /= 2;
		if (fabs(l) < e) {
			return 0;
		}
	}
	return l;
}

double iteration(double x, double eps)
{
	return x - lymbda(x, eps) * valueFunc(x);
}
	
int main(void)
{
	double eps = pow(10, -15);
	double aa = 0;
	double bb = 1;
	double a = aa;
	double b = bb;
	int i = 0;
	printf("Epsilon = %.e\n", eps);

	// Половинное деление
	do {
		if (valueFunc(a) * valueFunc(b) > 0) {
			printf("Fail\n");
			break;
		}
		if (valueFunc(a) * valueFunc((a + b) / 2) > 0) {
			a = (a + b) / 2;
		} else if (valueFunc(b) * valueFunc((a + b) / 2) > 0) {
			b = (a + b) / 2;
		}
		i++;
	} while (fabs(a - b) >= eps);
	printf("n : %d root : %.16f\n", i, (a + b) / 2);
	printf("value : %.16f\n\n", valueFunc((a + b) / 2));

	// Итерации
	i = 0;
	a = aa;
	b = bb;
	double x = (a + b) / 2;
	double x1;
	while(1) {
		x1 = iteration(x, eps);
		if (fabs(x1 - x) < eps) {
			printf("n : %d root : %.16f\n", i, x1);
			printf("value : %.16f\n\n", valueFunc(x1));
			break;
		}
		x = x1;
		i++;
	}

	// Ньютон
	a = aa;
	b = bb;
	double diff2;
	x = (a + b) / 2;
	while(1) {
		diff2 = derivative(valueFunc, x, 2);
		printf("%.16f, %.16f, %.16f\n", diff2, valueFunc(x), pow(derivative(valueFunc, x, 1), 2));
		if (fabs(valueFunc(x) * diff2) >= pow(derivative(valueFunc, x, 1), 2)) {
			printf("Fail\n");
			break;
		}
		x1 = x - valueFunc(x) / derivative(valueFunc, x, 1);
		if (fabs(x1 - x) < eps) {
			printf("n : %d root : %.16f\n", i, x1);
			printf("value : %.16f\n\n", valueFunc(x1));
			break;
		}
		x = x1;
	}
	return 0;
}
