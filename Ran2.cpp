//
// Created by andre on 11/30/21.
//

#include <iostream>
#include "Ran2.h"


#define IM1 2147483563
#define IM2 2147483393
#define AM (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014
#define IA2 40692
#define IQ1 53668
#define IQ2 52774
#define IR1 12211
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

float Ran2::ran2T() {
  int j;
  long k;
  float temp;

  if(this->_r.idum <= 0){
    if (-(this->_r.idum) < 1) this->_r.idum=1;
    else this->_r.idum = -(this->_r.idum);
    this->_r.idum2 = (this->_r.idum);
    for (j = NTAB+7; j >= 0; j--) {
      k = (this->_r.idum)/IQ1;
      this->_r.idum = IA1*(this->_r.idum-k*IQ1)-k*IR1;
      if (this->_r.idum < 0) this->_r.idum += IM1;
      if (j < NTAB) this->_r.iv[j] = this->_r.idum;
    }
    this->_r.iy = this->_r.iv[0];
  }

  k = (this->_r.idum)/IQ1;
  this->_r.idum = IA1*(this->_r.idum-k*IQ1)-k*IR1;
  if (this->_r.idum < 0) this->_r.idum += IM1;
  k = this->_r.idum2/IQ2;
  this->_r.idum2 = IA2*(this->_r.idum2-k*IQ2)-k*IR2;
  if (this->_r.idum2 < 0) this->_r.idum2 += IM2;
  j = this->_r.iy/NDIV;
  this->_r.iy = this->_r.iv[j]-this->_r.idum2;
  this->_r.iv[j] = this->_r.idum;
  if (this->_r.iy < 1) this->_r.iy += IMM1;

  if ((temp=AM*this->_r.iy) > RNMX) return RNMX;
  else return temp;
}

Ran2::Ran2(int idum_init, unsigned int id) {
  this->_r.idum = idum_init;
  this->_id = id;
}



#undef IM1
#undef IM2
#undef AM
#undef IMM1
#undef IA1
#undef IA2
#undef IQ1
#undef IQ2
#undef IR1
#undef IR2
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX