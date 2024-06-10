#include <stdio.h>
#include <stdlib.h>

#include "addit.h"

void printMass(int * Gm, int * Vm, number * Cm, int count);
double calcDis(number * pivet, number * Cm, int number);
double eps();
double passReal(number * Cm, number * pivet, int i);
double passUnReal(number * Cm, number * pivet, int i);

int main(int argc, char * argv[])
{
  //enter sizes
  printf("Write number n and m\n");
  int n, m;
  scanf("%d %d\n", &n, &m);
  number * arr = (number *)malloc(sizeof(number));
  //count no zero elem
  int count = 0;
  //malloc 3 vectors
  int * Gm = (int *)malloc((count + 1) * sizeof(int));
  int * Vm = (int *)malloc((count + 1) * sizeof(int));
  number * Cm = (number *)malloc((count + 1) * sizeof(number));
  //insert 2D array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%lf/%lf", &arr->realV, &arr->unrealV);
      if (arr->realV != 0 || arr->unrealV != 0) {
        if (count > 0) {
          Gm = realloc(Gm, (count + 1) * sizeof(int));
          Vm = realloc(Vm, (count + 1) * sizeof(int));
          Cm = realloc(Cm, (count + 1) * sizeof(number));
        }
        Gm[count] = i + 1;
        Vm[count] = j + 1;
        Cm[count].realV = arr->realV;
        Cm[count].unrealV = arr->unrealV;
        count++;
      }
    }
  }
  if (count == 0) {
    printf("all 0/0\n");
    return 1;
  }
  //print //butt for what???
  printMass(Gm, Vm, Cm, count);
  //task to find closest emenemt to needed and dfarc i and j on it
  //if many, do all of them
  number * pivet = (number *)malloc(sizeof(number));
  number * povet = (number *)malloc(sizeof(number));
  double * distance = (double *)malloc(sizeof(double));
  //get index same distance
  int * dnum = (int *)malloc(sizeof(int));
  //index array
  int * iarr = (int *)malloc(sizeof(int));
  int * jarr = (int *)malloc(sizeof(int));
  //enter pivet
  printf("enter real povet and unreal povet\n");
  scanf("%lf/%lf", &povet->realV, &povet->unrealV);
  //get distance and first index'es
  if (count != 0) {
    distance[0] = calcDis(povet, Cm, 0);
    pivet->realV = Cm[0].realV;
    pivet->unrealV = Cm[0].unrealV;
    iarr[0] = Gm[0];
    jarr[0] = Vm[0];
    dnum[0] = 1;
  }
  for (int i = 1; i < count; i++) {
    //need to update distance and clear array of index'es
    if (calcDis(povet, Cm, i) < distance[0]) {
      dnum[0] = 1;
      iarr = realloc(iarr, dnum[0] * sizeof(int));
      jarr = realloc(jarr, dnum[0] * sizeof(int));
      pivet->realV = Cm[i].realV;
      pivet->unrealV = Cm[i].unrealV;
      iarr[0] = Gm[i];
      jarr[0] = Vm[i];
      distance[0] = calcDis(povet, Cm, i);
    //need to realloc new parametr to array of index'es
    } else if (fabs(calcDis(povet, Cm, i) - distance[0]) < eps()) {
      dnum[0] += 1;
      iarr = realloc(iarr, dnum[0] * sizeof(int));
      jarr = realloc(jarr, dnum[0] * sizeof(int));
      iarr[dnum[0] - 1] = Gm[i];
      jarr[dnum[0] - 1] = Vm[i];
    }
  }

  double p1;
  double p2;

  //delta finally
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < dnum[0]; j++) {
      if (Gm[i] == iarr[j] || Vm[i] == jarr[j]) {
        //printf("%lf, %lf\n", Cm[i].realV, Cm[i].unrealV);
        
        p1 = passReal(Cm, pivet, i);
        p2 = passUnReal(Cm, pivet, i);

        Cm[i].realV = p1;
        Cm[i].unrealV = p2;
        break;
      }
    }
  }
  //print //butt for what???
  printMass(Gm, Vm, Cm, count);
  //free pivet
  free(pivet);
  free(povet);
  //free distance
  free(distance);
  //free dnum
  free(dnum);
  //free iarr and jarr
  free(iarr);
  free(jarr);
  //free all else
  free(Gm);
  free(Vm);
  free(Cm);
  //free 2D array
  free(arr);
	return 0;
}
