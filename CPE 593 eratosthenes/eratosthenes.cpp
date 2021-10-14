/*
 HW 1a - Eratosthenes
 Author: Matthew Jaworski
 CWID: 10436988
 I pledge my honor that I have abided by the Stevens Honor System.
 CITE: Class notes for the algorithm.
 */

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

//using improved eratosthenes
int eratosthenes(uint64_t a){

    uint64_t array_length = a + 1;
    vector<bool> primes(array_length);


    for(uint64_t l = 0; l <= a; l++){
        primes[l] = l;
    }
    
    primes[1] = false;

    for(uint64_t i = 4; i <= a; i += 2){
        primes[i] = false;
    }


    for(uint64_t j = 3; j <= a; j += 2){
        if(primes[j]){
            for(uint64_t k = j*j; k <= a; k += 2*j){
                primes[k] = false;
            }
        }
    }

    uint64_t counter = 0;

    for(uint64_t m = 0; m <= a; m++){
        if(primes[m] == true){
            counter++;
        }
    }

    return counter;

}


int main(){

    uint64_t n;

    cout << "Please type a number and press ENTER." << endl;
    cin >> n;

    uint64_t output = eratosthenes(n);

    cout << output << endl;

    return 0;
}