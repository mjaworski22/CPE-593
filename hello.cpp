#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <ctime>

using namespace std;


class Rep_Exercise{
    private:
      string Name = "name";
      int Reps = 0;
      string Procedure = "procedure";
      //picture object

    public:
      Rep_Exercise(string name, int reps, string procedure){
        Name = name;
        Reps = reps;
        Procedure = procedure;
      }


      void print_info(){
        cout << "The name of this exercise is: " << Name << endl;
        cout << "The amount of reps of this exercise is: " << Reps << endl;
        cout << "The procedure of this exercise is: " << Procedure << endl;
      }
};


class Timed_Exercise{
    private:
      string Name = "name";
      int Time = 0; //time is in seconds
      string Procedure = "procedure";

    public:
      Timed_Exercise(string name, int time, string procedure){
        Name = name;
        Time = time;
        Procedure = procedure;
      }


      void print_info(){
        cout << "The name of this exercise is: " << Name << endl;
        cout << "The amount of reps of this exercise is: " << Time << endl;
        cout << "The procedure of this exercise is: " << Procedure << endl;
      }
};


class Push_Ups : public Rep_Exercise
{
    private:
      string Name = "name";
      int Reps = 0;
      string Procedure = "procedure";

    public:
      using Rep_Exercise::Rep_Exercise;

      void show_tutorial(){
        cout << "This is how you do push ups" << endl;
      }
      
};


class Pull_Ups : public Rep_Exercise
{
    private:
      string Name = "name";
      int Reps = 0;
      string Procedure = "procedure";

    public:
      using Rep_Exercise::Rep_Exercise;

      void show_tutorial(){
        cout << "This is how you do pull ups" << endl;
      }
      
};


class Sit_Ups : public Rep_Exercise
{
    public:
      int id_c;
};

class Burpees : public Rep_Exercise
{
    public:
      int id_c;
};

//create another base class: Timed_Exercise
//create factory class
//create push ups class
//create sit ups class
//create pull ups class
//create dips class
//basically factory pattern

//pick 5 exercises to do and randomize them into a queue structure
//pick 5 based on exercise type
//print output to a text file that is formatted nicely
//array for the types of exercises
//pick one at random and get its index

int exercises [20] = {};

//chooses 5 unique random integers
//this DOES NOT WORK
int * getRandom( ) {

  static int choices[5] = {};
  srand((unsigned)time(NULL));
   
  for (int i = 0; i < 5; i++) {

    int generated = 1 + rand() % 20;
    for (int j = 0; j < 5; j++){
      if(choices[j] == generated){
        i--;
      }
    }
    
    choices[i] = generated;
    cout << choices[i] << endl;
  }

  return choices;
}

//we have to create a dictionary of the exercise objects
//now we will pass the choices array into the workout builder to pick those corresponding numbers' exercises and put them into a workout array

int main(){


  /*std::cout<< "Have fun..."<< std::endl;
  Rep_Exercise exercise1 = Rep_Exercise("Push Ups", 20, "Get on all fours. Put hands slightly wider than shoulders. Drop yourself to the floor and push yourself back up. Do not let your knees touch the ground.");
  exercise1.print_info();
  std::cout<< " "<< std::endl;


  std::cout<< "Have fun..."<< std::endl;
  Push_Ups exercise2 = Push_Ups("Plank", 120, "Get on all fours. Put hands slightly wider than shoulders. Hold yourself on your forearms. Do not let your knees touch the ground.");
  exercise2.print_info();
  std::cout<< " "<< std::endl;*/

  /*Push_Ups exercise1 = Push_Ups("Push Ups", 20, "Get on all fours. Put hands slightly wider than shoulders. Drop yourself to the floor and push yourself back up. Do not let your knees touch the ground.");
  exercise1.show_tutorial();


  Pull_Ups exercise2 = Pull_Ups("Push Ups", 20, "Get on all fours. Put hands slightly wider than shoulders. Drop yourself to the floor and push yourself back up. Do not let your knees touch the ground.");
  exercise2.show_tutorial();*/

  getRandom();

  return 0;
}
