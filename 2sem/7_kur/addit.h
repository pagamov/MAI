#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double realV;
  double unrealV;
} number;

double eps()
{
  double eps = 1;
  while (1 + eps != 1) {
    eps /= 2;
  }
  return eps;
}

void printMass(int * Gm, int * Vm, number * Cm, int count)
{

  for (int i = 0; i < count; i++) {
    printf("%d\t%d\t%lf, %lf\n", Gm[i], Vm[i], Cm[i].realV, Cm[i].unrealV);
  }
  printf("\n");
}

double calcDis(number * pivet, number * Cm, int number)
{
  return sqrt(pow(fabs(pivet->realV - Cm[number].realV), 2) + pow(fabs(pivet->unrealV - Cm[number].unrealV), 2));
}

double passReal(number * Cm, number * pivet, int i)
{
  return (Cm[i].realV * pivet->realV + Cm[i].unrealV * pivet->unrealV) / (pow(pivet->realV, 2) + pow(pivet->unrealV, 2));
}

double passUnReal(number * Cm, number * pivet, int i)
{
  return (pivet->realV * Cm[i].unrealV - Cm[i].realV * pivet->unrealV) / (pow(pivet->realV, 2) + pow(pivet->unrealV, 2));
}
