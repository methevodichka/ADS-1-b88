// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (uint64_t i = 2; i <= sqrt(value); ++i) {
    if (!(value % i)) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0, i = 2;
  while (1) {
    if (checkPrime(i)) {
      count++;
      if (count == n) {
        break;
      }
    }
    i++;
  }
  return i;
}

uint64_t nextPrime(uint64_t value) {
  while (1) {
    value++;
    if (checkPrime(value)) {
      return value;
    }
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound; i++) {
    if (checkPrime(i) && checkPrime(i + 2) && (i + 2) < hbound) {
      count++;
    }
  }
  return count;
}
