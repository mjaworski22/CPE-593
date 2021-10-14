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
#include <string>

using namespace std;

//using improved eratosthenes
string read_numbers(){

    string input_string;

    cout << "\nPlease type the integers with a space in between each integer." << endl;

    getline(cin, input_string);


    return input_string;
}


int string_counter(string &string_input){
    //create a dynamic array of 1 element
    int counter = 0;

    //string parser
    for(int i = 0; i < string_input.length(); i++){
        //int int_char = string_input.at(i) - '0';

        if(!isspace(string_input.at(i))){
            //add int_char to counter index of the dynamic array
            //dynamic_array[counter] = int_char;
            //include this later^
            counter++;
        }

    }
    
    return counter;
}


int *array_builder(int size, string &string_input){ //returns the memory address of the first element in the array

    int integer_count = 0;

    for(int i = 0; i < size*2 - 1; i++){


        if(!isspace(string_input.at(i))){
            integer_count++;
        }

    }



    int *dynamic_array = new int[integer_count];

    int counter_ints = 0;
    for(int j = 0; j < size*2 - 1; j++){
        if(!isspace(string_input.at(j))){
            char string_char = string_input.at(j);
            int string_int = string_char - 48;
            string_char >> string_int;
            dynamic_array[counter_ints] = string_int;
            cout << dynamic_array[counter_ints] << "\n";
            counter_ints++;
        }

        else if(isspace(string_input.at(j))){

        }
    }


//printer function -----------------
    for(int k = 0; k < counter_ints; k++){
        
        if(k == counter_ints - 1){
            cout << dynamic_array[k];
        }

        else{
        cout << dynamic_array[k] << " ";
        }
    }
//printer function -----------------
    //loop through array and get rid of values

    cout << "\nArray size: " << integer_count << endl;



}






int main(){

    //cout << "Please enter your first 3 numbers." << endl;
    //string user_input1 = read_numbers();

    cout << "Please enter your array." << endl;

    string user_input2 = read_numbers();
    int size = string_counter(user_input2);

    int *dynamic_array = array_builder(size, user_input2);

    cout << "\n" << " Dynamic Array First Element: " << dynamic_array[0] << endl;
    //we  will print the dynamic array using the printer function

    //replace the 'deleted' values with 2147483647 (the last possible number) and then count how many non those values there are and use that size for the new array

    return 0;
}