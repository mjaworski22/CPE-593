/*
 HW 3c - Growth Array
 Author: Matthew Jaworski
 CWID: 10436988
 I pledge my honor that I have abided by the Stevens Honor System.
 CITE: Class notes for the algorithm.
 */

//I implemented the growth array w

#include <iostream>
#include <stdlib.h>

using namespace std;

//using improved eratosthenes
string read_numbers(){

    string input_string;

    cout << "\nPlease type the integers with a space in between each integer." << endl;

    cin >> input_string;

    return input_string;
}



int *double_size(int *dynamic_array){
    //returns the pointer to the doubled size array
    int array_length = sizeof(dynamic_array)/sizeof(dynamic_array[0]);
    int new_size = array_length*3;
    int *doubled_array = (int *) realloc(dynamic_array, new_size *(int)sizeof(int));

    return doubled_array;
}



int *array_builder(string &string_input){
    //create a dynamic array of 1 element
    
    int size = 1;
    int counter = 1;
    int *dynamic_array = new int[size];


    //start reading in the values
        //if counter (start counter at 1) == array size
            //double the size of the array

    for(int i = 0; i < string_input.length(); i++){
        //add the ith item to the array
        //if counter == array size
            //run double_size
        int array_length = sizeof(dynamic_array)/sizeof(dynamic_array[0]);

        int int_char = string_input.at(i) - '0';

        cout << "int_char: " << int_char << endl;

        if((dynamic_array[counter + 1] != 0) && (int_char != ' ')){ //if(!pointer)

            if((array_length == counter)){
            
            cout << "Made it A" << endl;

            dynamic_array = double_size(dynamic_array);

            dynamic_array[counter + 1] = int_char;
            }

            else{
            
            cout << "Made it B" << endl;

            dynamic_array[counter + 1] = int_char;
        
            }
        }

        counter++;
        
        }

        return dynamic_array;
    //========================================================
    }







int main(){

    //cout << "Please enter your first 3 numbers." << endl;
    //string user_input1 = read_numbers();

    cout << "Please enter your array." << endl;
    string user_input2 = read_numbers();

    //perform dynamic array on the string inputs
    cout << array_builder(user_input2) << endl;

    return 0;
}