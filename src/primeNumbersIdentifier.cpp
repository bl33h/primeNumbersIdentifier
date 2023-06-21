/*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: primeNumbersIdentifier
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

// Namespace
using namespace std;

// Mutex lock
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Parameters to follow
// --- Variables ---
int boundary;
int threadss;
int primesSum;
// --- Threads info ---
struct info
{
    int id;
    int min; // *inferior limit
    int max; // *superior limit
};

// Function to determine if a number is prime
// --- Function taken from StackOverflow ---
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
// --- Function taken from StackOverflow ---
void* primeSum(void* arg)
{
    info *temp;
    temp = (info*)arg;
    int summatory = 0;
    string primeNumb = "- The prime numbers found on range are: ";
    int i = (temp ->min);
    while ( i <= (temp ->max))
    {
        if(isPrime(i))
        {
            summatory += i;
            stringstream temp;
            temp<<i;
            string temp2;
            temp>>temp2;
            temp2 += " ";
            primeNumb += temp2; 
        }
        i++; // Counter addition
    }

 // Data print with mutex implemented (threads)
    pthread_mutex_lock(&lock);
    primesSum += summatory;
    // --- Variables printing ---
    cout << "-------------------------------------------------\n";
    cout << "- Thread id: " << (temp -> id) << "\n";
    cout << "- Inferior limit: " << (temp -> min) << "\n";
    cout << "- Superior limit: " << (temp -> max) << "\n";
    cout << primeNumb << "\n";
    cout << "- Summatory of all the prime numbers found on range: " << summatory <<"\n";
    cout << "-------------------------------------------------\n";
    pthread_mutex_unlock(&lock); // *Lock to avoid threads taking other data
    return 0;
    pthread_exit(NULL); // *Thread's exit
}

// Main method
int main()
{
    cout << "- Type the superior limit (int) = " << endl;
    cin >> boundary;
    cout << "- Type the number of threads you would like to use (int) = " << endl;
    cin >> threadss;
    int threadData = boundary / threadss;
    info threads1[threadss];
    pthread_t threads[threadss];
    int succesor = 1; 
    for(int i = 0; i < threadss;i++)
    {
        threads1[i].id = i;
        threads1[i].min = succesor;
        succesor += threadData - 1;
        if(i == (threadss - 1) && succesor < boundary){
             threads1[i].max = boundary; 
        } else{
            if (succesor > boundary){
                threads1[i].max = boundary; 
            } else{
            threads1[i].max = succesor;
            }
        }
        succesor++;
        pthread_create(&threads[i], NULL,primeSum,(void *)&threads1[i]);
    }
     for(int i = 0; i < threadss;i++)
     {
        pthread_join(threads[i], NULL);
     }
     cout << "- Total summatory of all the prime numbers found on range: " << primesSum << endl;
    return 0; 
}
