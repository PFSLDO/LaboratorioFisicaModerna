#include "stdio.h"
#include "stdlib.h"
#include "math.h"

//------------------------------------------------------------------------------------------------------------------------------

int main() {
  const long double cargasDasBolhas[] = {3.14E-18,
                                         4.49E-18,
                                         1.66E-17,
                                         9.93E-18,
                                         1.47E-17,
                                         4.23E-18,
                                         7.51E-18,
                                         4.74E-18,
                                         2.59E-18,
                                         1.86E-18,
                                         2.00E-18,
                                         8.01E-18,
                                         1.98E-18,
                                         5.09E-18,
                                         5.75E-18,
                                         8.41E-18,
                                         1.36E-17,
                                         5.24E-18,
                                         1.46E-17,
                                         1.76E-17,
                                         1.74E-17,
                                         2.37E-17,
                                         1.86E-17,
                                         3.50E-18,
                                         8.58E-18,
                                         1.83E-17,
                                         1.08E-17,
                                         7.36E-18,
                                         1.04E-17,
                                         2.33E-17,
                                         7.95E-18,
                                         4.23E-17,
                                         5.08E-18,
                                         3.95E-18
                                        };

  long double cargaElementarExperimental = 1.9E-19;
  long double melhorMediaInteiros = 0.0;
  const int numeroDeMedidas = sizeof(cargasDasBolhas) / sizeof(cargasDasBolhas[0]);

  for (long double c = 1.9E-19; c > 1.4E-19; c -= 0.00001E-19) {
    long double mediaDiferencasParaInteiros = 0.0;

    for (int i = 0; i < numeroDeMedidas; i++) {
      long double numeroDeCargasPorBolha = cargasDasBolhas[i]/c;
      mediaDiferencasParaInteiros += fabsl(roundl(numeroDeCargasPorBolha) - numeroDeCargasPorBolha); //Calcula a diferenca entre o numero calculado e o inteiro mais proximo
    }

    mediaDiferencasParaInteiros /= numeroDeMedidas; //Calcula a media das diferencas com inteiros

    if (melhorMediaInteiros == 0 || mediaDiferencasParaInteiros < melhorMediaInteiros) {
      melhorMediaInteiros = mediaDiferencasParaInteiros;
      cargaElementarExperimental = c;
    }
  }

  printf("valorQExperimental: %.30Lf c/ media dos desvios: %.25Lf", cargaElementarExperimental, melhorMediaInteiros);

  return 0;
}