/*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: PrimeNumbersIdentifier
@version: I
Creation: 25/08/2022
Last modification: 31/08/2022
------------------------------------------------------------------------------*/
// Imports
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <sstream>

// Parameters to follow
// --- Variables ---
int boundary;
int threads;
int primesSum;
// --- Threads info ---
struct info
{
    int id;
    int min; // *inferior limit
    int max; // *superior limit
};

// Function to determine if a number is prime
bool isPrime(int number) 
{
  if (number == 0 || number == 1 || number == 4) return false;
  for (int n = 2; n < number / 2; n++) 
  {
    if (number % n == 0) return false;
  }
  return true;
}

// Summatory of all the prime numbers found on range

