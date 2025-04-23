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
  
  long double cargaElementarExperimental = 1.8*10E-19;
  long double mediaDiferencasParaInteiros = 10000; //Valor grande aleatorio, apenas para entrar no while
  float precisaoMedia = 0.0001; //Escolhe precisao da media
  const int numeroDeMedidas = 34;

  while (mediaDiferencasParaInteiros > precisaoMedia) { //Tenta encontrar um valor de media que possua a precisao setada
    mediaDiferencasParaInteiros = 0.0;
    cargaElementarExperimental -= 0.001*10E-19; //Descrecimo com passo curto

    for (int i = 0; i < numeroDeMedidas; i++) {
      long double numeroDeCargasPorBolha = cargasDasBolhas[i]/cargaElementarExperimental;
      mediaDiferencasParaInteiros += fabsl(roundl(numeroDeCargasPorBolha) - numeroDeCargasPorBolha); //Calcula a diferenca entre o numero calculado e o inteiro mais proximo
    }

    mediaDiferencasParaInteiros = mediaDiferencasParaInteiros/numeroDeMedidas; //Calcula a media das diferencas com inteiros
  }

  printf("valorQExperimental: %.30Lf c/ media dos desvios: %.25Lf", cargaElementarExperimental, mediaDiferencasParaInteiros);

  return 0;
}