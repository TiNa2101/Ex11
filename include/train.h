// Copyright 2021 Ex11 TiNa
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_
#include <string>
#include <iostream>
#include <random>

class Cage {
  bool light;
 public:
  Cage* next;
  Cage* prev;
  Cage() : light(std::rand() % 2), next(nullptr), prev(nullptr) {}
  void on();
  void off();
  bool get() const;
};

class Train {
 private:
  Cage* first;
  Cage* last;
  int length;

 public:
  Train() : first(nullptr), last(nullptr) {}
  void addCage(Cage* cagein);
  void print(int num);
  void print();
  void createCages(int len);
  int getLength();
  int findLength();
};

#endif  // INCLUDE_TRAIN_H_
