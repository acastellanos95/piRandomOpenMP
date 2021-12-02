//
// Created by andre on 11/30/21.
//

#ifndef PIRANDOM__RAN2_H_
#define PIRANDOM__RAN2_H_

typedef struct{
  long idum;
  long idum2;
  long iy;
  long iv[32];
} ran2NR;

class Ran2 {
  ran2NR _r;
  unsigned int _id;
 public:
  Ran2() = default;
  explicit Ran2(int inum_init, unsigned int id);
  float ran2T();
};

#endif //PIRANDOM__RAN2_H_
