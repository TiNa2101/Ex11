// Copyright 2021 Ex11 TiNa
#include <gtest/gtest.h>
#include <string>
#include "train.h"

TEST(TrainTest, test1) {
  Train train1;
  train1->createCages(20);
  EXPECT_EQ(20, train1.findLength());
}

TEST(TrainTest, test2) {
  Train train2;
  train2->createCages(15);
  EXPECT_EQ(15, train2.findLength());
}

TEST(TrainTest, test3) {
  Train train3;
  train3->createCages(33);
  EXPECT_EQ(33, train3.findLength());
}
