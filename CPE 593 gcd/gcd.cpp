/*
 HW 1b - gcd
 Author: Matthew Jaworski
 CWID: 10436988
 I pledge my honor that I have abided by the Stevens Honor System.
 CITE: Class notes for the algorithm.
 */

#include <iostream>
#include <stdlib.h>

using namespace std;


int gcd(uint64_t a,uint64_t b){

    if(b == 0){
        return a;
    }

    else{

        return gcd(b, a%b);
    }
}


int main(){

    uint64_t input_a;
    uint64_t input_b;

    cout << "Please type a number and press ENTER." << endl;
    cin >> input_a;
    cout << "Please type another number and press ENTER." << endl;
    cin >> input_b;

    uint64_t output = gcd(input_a,input_b);

    cout << output << endl;

    return 0;
}