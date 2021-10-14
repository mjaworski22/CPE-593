/*
 LinkedList Homework
 Author: Matthew Jaworski
 CWID: 10436988
 I pledge my honor that I have abided by the Stevens Honor System.
 CITE: 
        Class notes for the algorithm.
        https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm for pointer usage and syntax
 */


#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node * previous;
    Node * next;


  Node() {
    data = 0;
    next = NULL;
    previous = NULL;
  }

};

class DoubleLinkedList2 {

  public:
    Node * head;

  DoubleLinkedList2() {
    head = NULL;
  }
  DoubleLinkedList2(Node * node_object) {
    head = node_object;
  }

    //used to grab the last element
    Node * nodeEnd() {
        Node * temp = NULL;
        Node * ptr = head;


        while (ptr != NULL) {
        if (ptr -> next == NULL) {
            temp = ptr;
        }
        ptr = ptr -> next;
        }

    return temp;
}




void addStart(int value) {

    Node * node_object = new Node();
    node_object -> data = value;

      if (head == NULL) {
        head = node_object;
      } 
      
      else {
        head -> previous = node_object;
        node_object -> next = head;
        head = node_object;
      }
}




void addEnd(int value) { 

    Node * node_object = new Node();
    node_object -> data = value;

    Node * end_node = nodeEnd(); //pointer to end node

    if (end_node == NULL) { 
        addStart(value);
        
        return;
        }

    Node * nextNode = end_node -> next;

        if(nextNode == NULL) {
          end_node -> next = node_object;
          node_object -> previous = end_node;
          
          }

}



  
  void removeEnd() {
        Node * end_node = nodeEnd();
      
        Node * next_node = end_node -> next;
        Node * previous_node = end_node -> previous;
       
        if (next_node == NULL) {

          previous_node -> next = NULL;
          
        }
}




void printList() {
    if (head == NULL) {
    } 
    
    else {

      Node * temp = head;

    cout << "  " << endl;
      while (temp != NULL) {
        cout << temp -> data << "  ";
        temp = temp -> next;
      }
    }

}




int size() {
    if (head == NULL) {
    int zero_size = 0;
    return zero_size;
    } 
    else {

      Node * temp = head;

    int counter = 0;
      while (temp != NULL) {
        counter++;
        temp = temp -> next;
      }
      return counter;
    }

}


};






int main() {

    DoubleLinkedList2 mylist;


    for (int i = 0; i < 10; i++){
            mylist.addEnd(i);
          } // 0 1 2 3 4 5 6 7 8 9
        

    for (int i = 0; i < 10; i++){
            mylist.addStart(i);
        } //9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9


    for (int i = 0; i < 5; i++){
            mylist.removeEnd();
        }
    
    mylist.printList();

    int size = mylist.size();
    cout << "\nSize: " << size << endl;

  return 0;
}