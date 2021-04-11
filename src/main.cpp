// Copyright 2021 Ex11 TiNa
#include <string>
#include <iostream>
#include "train.h"

int main() {
  Train ntrain;
  ntrain.createCages(15);
  ntrain.print();
  std::cout << std::endl;
  int len = ntrain.findLength();
  ntrain.print(len);
  return 0;
}
