#include <iostream>
#include <ctime>
#include <omp.h>
#include <vector>
#include "Ran2.h"
#include "Ran2ST.h"

int main(int argc, char *argv[]) {

  int num_iterations = std::stoi(argv[1]);

  /* Programa Secuencial: no me gustaría que estuviera aquí la función pero es bueno para enseñar la diferencias*/
  double t_seq_init = omp_get_wtime();
  long inp = -1;
  /*Calculate pi*/
  long eb = 0;
  long te = num_iterations;
  for (int i = 0; i < te; ++i) {
    float x = ran2(&inp);
    float y = ran2(&inp);
    if((x*x+y*y) <= 1.0)
      eb++;
  }
  double t_seq_fin = omp_get_wtime();

  /*
   *                          Programa paralelo
   * ----------------------------Inicia aquí----------------------------
   * */

  /*
   * Lamentablemente ran2 es un pseudogenerador de número aleatorios desde 0.0 a 1.0 que para el mismo número negativo
   * que se use para inicialización generará la misma secuencia lo que haría usar paralelismo con el mismo número
   * una tarea innecesaria. Por lo tanto debemos asegurar que cada hilo usará un número negativo distinto para inicializar
   * */

  /*Crear vector de clase Ran2 e inicializar*/
  double t_seq_par_init = omp_get_wtime();
  auto *rans = new std::vector<Ran2>();
  int num_threads = omp_get_max_threads();
  for (int i = 0; i < num_threads; ++i) {
    rans->emplace_back(Ran2(-((int) i+1), i));
  }

  /*Imprimir tamaño de vector*/
//  std::cout << "tamaño de vector después de inicialización: " << rans->size() << std::endl;

  /*Calculo de pi*/

  int ebT=0;

  #pragma omp parallel for default(none) shared(rans, num_iterations) reduction(+:ebT)
  for (int i = 0; i < num_iterations; ++i) {
    /*Debug printing*/
//    printf("indice: %d\t", i);
//    printf("thread: %d, ran2=%f\n",thread_num, rans->at(thread_num).ran2T());

    int thread_num = omp_get_thread_num();
    float x = rans->at(thread_num).ran2T();
    float y = rans->at(thread_num).ran2T();
    if((x*x+y*y) <= 1.0)
      ebT++;
  }

//  std::cout << "pi secuencial es: " << (float) eb/ (float) te*4 << ", tiempo secuencial es: " << t_seq_fin - t_seq_init << "s, " << "pi paralelo es: " << (float) ebT/ (float) num_iterations*4;

  double t_seq_par_fin = omp_get_wtime();
//  std::cout << ", tiempo paralelo es: " << t_seq_par_fin - t_seq_par_init << "s" << std::endl;
  /*formato de resultados: piseq, pipar, seqtime, partime*/
//  printf("%.5g %.5g %.5g %.5g\n", (float) eb/ (float) te*4, (float) ebT/ (float) num_iterations*4, t_seq_fin - t_seq_init, t_seq_par_fin - t_seq_par_init);
  /*formato de resultados: f*/
  double TaTm = (t_seq_fin - t_seq_init)/(t_seq_par_fin - t_seq_par_init);
  printf("%.5g\n", TaTm);
  /*
   *                          Programa paralelo
   * ---------------------------Termina aquí----------------------------
   * */

  return 0;
}