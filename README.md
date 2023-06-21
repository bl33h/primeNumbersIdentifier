# primeNumbersIdentifier
A multi-threaded program that identifies prime numbers within a given range and calculates their summation. It prompts the user to input the superior limit and the number of threads to be used. The program divides the range evenly among the threads and assigns them specific limits to check for prime numbers. Each thread determines if a number within its range is prime and adds it to the summation. The program prints the prime numbers found by each thread, their respective limits, and the summation of prime numbers across all threads.

<p align="center">
  <br>
  <img src="https://4.bp.blogspot.com/-GXf7kRb2kg4/UaNig1qAybI/AAAAAAAAA_4/BNOa5CLBkBA/s1600/check_prime.gif" alt="pic" width="500">
  <br>
</p>
<p align="center" >
  <a href="#Files">Files</a> •
  <a href="#Features">Features</a> •
  <a href="#how-to-use">How To Use</a> 
</p>

## Files

- src: the file that implements de solution.
- flowchart: flowchart: the model construction.

## Features
The main features of the application include:
- Multi-threading: The program utilizes multiple threads to concurrently identify prime numbers within the given range and calculate their summation. Each thread operates independently on a specific portion of the range.
- Thread Synchronization: To ensure correct and synchronized output, the code uses a mutex lock (pthread_mutex_t) to control access to shared resources, such as the summation variable. This prevents race conditions and ensures that each thread updates the shared data appropriately.
- Input Handling: The program prompts the user to enter the superior limit and the number of threads to be used. It takes these inputs and divides the range among the threads, allocating specific limits to each thread for prime number identification.
- Prime Number Identification: The code includes a function isPrime that determines whether a given number is prime. It iterates from 2 to the square root of the number to check for divisibility. If a number is found to be prime, it is added to the summation for the respective thread.
- Thread Data Management: The program uses a struct info to store information about each thread, including its ID, minimum and maximum limits for prime number checking. This struct is passed as an argument to the thread function.
- Output Display: The code provides informative output, printing the thread ID, limits, the prime numbers found within each thread's range, and the summation of prime numbers for each thread. It also displays the total summation of all prime numbers across all threads.
- Reusability: The code is designed to be reusable, allowing the user to modify the number of threads and the range to find prime numbers in different scenarios.


## How To Use
To clone and run this application, you'll need [Git](https://git-scm.com) and a [C++ compiler](https://www.fdi.ucm.es/profesor/luis/fp/devtools/mingw.html) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/bl33h/primeNumbersIdentifier

# Open the folder
$ cd src

# Run the app
$ g++ primeNumbersIdentifier.cpp -o primeNumbersIdentifier
$ ./primeNumbersIdentifier
```

Alternatively, you can run the code using Google Colab:
1. [Open Google Colab](https://colab.research.google.com) in your web browser.
2. Click on "File" in the top menu, then select "Open notebook".
3. In the "GitHub" tab, enter the repository URL: https://github.com/bl33h/primeNumbersIdentifier
4. Choose the desired notebook file and click "Open".
5. Follow the instructions within the Colab notebook to execute the code.

Note: Running the code in Google Colab requires an internet connection and a Google account. It provides a convenient online environment for executing code without the need for local setup or dependencies.
