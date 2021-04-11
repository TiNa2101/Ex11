// Copyright 2021 Ex11 TiNa
#include <string>
#include <iostream>
#include "train.h"

void Cage::on() { light = true; }

void Cage::off() { light = false; }

bool Cage::get() const { return light; }

void Train::addCage(Cage* cagein) {
  if (first == nullptr) {
    first = cagein;
    last = cagein;
  } else {
    last->prev = cagein;
    cagein->next = last;
    cagein->prev = first;
    first->next = cagein;
    last = cagein;
  }
}

//void Train::print() {
//  Cage* tmp = first;
//  int count = 1;
//  while (tmp != last) {
//    if (tmp->get()) {
//      std::cout << "Cage (" << count << ")  light (on)" << std::endl;
//    } else {
//      std::cout << "Cage (" << count << ")  light (off)" << std::endl;
//    }
//    count++;
//    tmp = tmp->next;
//  }
//  if (tmp->get()) {
//    std::cout << "Cage (" << count << ")  light (on)" << std::endl;
//  } else {
//    std::cout << "Cage (" << count << ")  light (off)" << std::endl;
//  }
//}
void Train::print(int num) {
  Cage* tmp = first;
  for (int i = 0; i < num; i++) {
    if (tmp->get()) {
      std::cout << "Cage (" << i+1 << ")  light (on)" << std::endl;
    } else {
      std::cout << "Cage (" << i+1 << ")  light (off)" << std::endl;
    }
    tmp = tmp->prev;
  }
}

void Train::print() {
  Cage* tmp = first;
  int count = 1;
  while (tmp != last) {
    if (tmp->get()) {
      std::cout << "Cage (" << count << ")  light (on)" << std::endl;
    } else {
      std::cout << "Cage (" << count << ")  light (off)" << std::endl;
    }
    count++;
    tmp = tmp->prev;
  }
}

void Train::createCages(int len) {
  for (int i = 0; i < len; i++) {
    addCage(new Cage());
  }
}

int Train::getLength() { return length; }

int Train::findLength() {
  Cage* tmp = first;
  tmp->on();
  int count = 1;
  while (true) {
    for (int i = 0; i < count; i++) {
      tmp = tmp->next;
      tmp->off();
    }
    for (int i = 0; i < count; i++) {
      tmp = tmp->prev;
    }
    if (tmp->get() == false) {
      break;
    }
    count++;
  }
  return count;
}
