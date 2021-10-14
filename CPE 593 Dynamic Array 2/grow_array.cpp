/*
 HW 3c - Growth Array
 Author: Matthew Jaworski
 CWID: 10436988
 I pledge my honor that I have abided by the Stevens Honor System.
 CITE: Class notes for the algorithm.
 */

#include <iostream>
#include <chrono>

using namespace std;


class GrowArray{

    private:
        int *memory;
        int size;

    public:
        GrowArray(){
            memory = nullptr;
            size = 1;
        }

        void append_array(int index){
            const int* memory_copy = memory;

            if(memory[index] == memory[size]){
                memory = new int[size*2];
            }

            for(int i = 0; i < size; i++){
                memory[i] = memory_copy[i];
                delete [] memory_copy;
                memory[size] = index; //placing the v value at the end
            }
        }
        

        void deleteIndex(int index){
            //locate index
            //delete
            //compact the dynamic array
            int previous = memory[index - 1];

            for(int j = index - 2; j >= 0 && memory[j] != memory[index]; j--){
                int position = memory[j];
                memory[j] = previous;
                previous = position;
            }

        }

        int lookUpIndex(int index){
            return memory[index];
        }
};




int main(){
    
    uint64_t lower = 0;
    cout << "Please enter your first number (lower bound)." << endl;
    cin >> lower;


    uint64_t upper = 0;
    cout << "Please enter your second number (upper bound)." << endl;
    cin >> upper;


    uint64_t third = 0;
    cout << "Please enter your third number." << endl;
    cin >> third;
    
    //we  will print the dynamic array using the printer function
    //start timer
    auto start = chrono::steady_clock::now();
    uint64_t final_size = 0;
    uint64_t final_sum = 0;
    uint64_t time = 0;

    auto stop = chrono::steady_clock::now();


    cout << "The amount of elements in the final array is: " << final_size <<endl;
    cout << "The sum of the elements in the final array is: " << final_sum << endl;
    cout << "The elapsed time for this program was: " << chrono::duration_cast<chrono::seconds>(stop - start).count()<< " sec";


    GrowArray b;

    cout << "Made it past the object instantiation" << endl;

    for(int i = lower; i < upper; i++){
        cout << "Made it into the for loop." << endl;
        b.append_array(i);
    }
    
    for(int j = lower; j < upper; j++){
        for(int k = 2; k < third; k++){
            if(b.lookUpIndex(j) % k){
                b.deleteIndex(j);
            }
        }
    }

    cout << "Made it past the deletion for loop." << endl;
 

    cout << "Made it past final output instantiation." << endl;


    return 0;
}