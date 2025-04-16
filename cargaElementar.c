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
                                         5.09E-18
                                        };
    
  double cargaElementarExperimental = 1.8*10E-19;
  float mediaValoresArredondados = 10000;

  while (mediaValoresArredondados > 0.00001) {
    cargaElementarExperimental -= 0.0000001*10E-19;

    for (int i = 0; i < 14; i++) {
      mediaValoresArredondados += abs(round(cargasDasBolhas[i]/cargaElementarExperimental) - cargasDasBolhas[i]/cargaElementarExperimental);
    }

    mediaValoresArredondados = mediaValoresArredondados/14;
  }

  printf("valorQExperimental: %.25lf c/ media dos desvios: %.25lf", cargaElementarExperimental, mediaValoresArredondados);

  return 0;
}