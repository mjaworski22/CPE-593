//Author: Matthew Jaworski

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;



class HashMap
{
    int bin;
    vector <string> *hashmap;

public:
    HashMap(int i);


    void insertWord(string word, int key);


    int hashFunction(int x) {
    	int func = pow(x,2) + 100;
        return (func % bin);
    }

    void displayHash();

    //void spellCheck();
};

HashMap::HashMap(int b)
{
    this->bin = b;
    hashmap = new vector <string>[bin];
}

//spellchecking a txt document:
//I kept getting errors

/*void Hash::spellCheck(){

	fstream newfile;

	newfile.open("C:/Users/Matthew Jaworski/Documents/CPE-593/CPE 593 Dictionary/src/modestproposal.txt",ios::out); //open a file to perform read operation using file object

	vector <string> incorrect;

				if (newfile.is_open()) {
					cout << "newfile is open AGAIN" << "\n";
					string word;

					while(newfile >> word){


						int ascii_sum = 0;
							for (int i = 0; i < word.length(); i++)
							{
								char x = word.at(i);
								int ascii_current = int(x);

								ascii_sum = ascii_sum + ascii_current;
							}
						int index = hashFunction(ascii_sum);
						string actual_check = hashmap[index].c_str();

						if(!actual_check){
							incorrect.push_back(word);
						}

					}


					newfile.close();

				}

				cout << "Misspelled Words: " <<endl;

				for(int i=0; i < incorrect.size(); i++){
					cout << incorrect.at(i) << ' ';
				}

}*/


void HashMap::insertWord(string word, int key)
{
	//key is the place that gets passed in (given in the loop)
	//word is the string that gets placed in

    int index = hashFunction(key);
    hashmap[index].push_back(word);
}



void HashMap::displayHash() {

	int bin_0 = 0;
	int bin_1 = 0;
	int bin_2 = 0;
	int bin_3 = 0;
	int bin_4 = 0;
	int bin_5 = 0;
	int bin_6 = 0;
	int bin_7 = 0;
	int bin_8 = 0;
	int bin_9 = 0;

	//fstream MyFile;
	//MyFile.open("C:/Users/Matthew Jaworski/Documents/CPE-593/CPE 593 Dictionary/src/simp.txt",ios::out);

	//file output was for me to visually test which bins the words fell into

  for (int i = 0; i < bin; i++) {
    //MyFile << i;
    int bin_sum = 0;
    for (auto x : hashmap[i]){
    	//increase branch count here and prepare to add to array
    	//array[correct bin number] = array[correct bin number] + 1;
      //MyFile << " , " << x;
      bin_sum++;

    }

    if(bin_sum == 0){bin_0++;}
    if(bin_sum == 1){bin_1++;}
    if(bin_sum == 2){bin_2++;}
    if(bin_sum == 3){bin_3++;}
    if(bin_sum == 4){bin_4++;}
    if(bin_sum == 5){bin_5++;}
    if(bin_sum == 6){bin_6++;}
    if(bin_sum == 7){bin_7++;}
    if(bin_sum == 8){bin_8++;}
    if(bin_sum >= 9){bin_9++;}

    //MyFile << endl;
  }


  //MyFile.close();

  cout << "Number of bins with 0 words: " << bin_0 << endl;
  cout << "Number of bins with 1 words: " << bin_1 << endl;
  cout << "Number of bins with 2 words: " << bin_2 << endl;
  cout << "Number of bins with 3 words: " << bin_3 << endl;
  cout << "Number of bins with 4 words: " << bin_4 << endl;
  cout << "Number of bins with 5 words: " << bin_5 << endl;
  cout << "Number of bins with 6 words: " << bin_6 << endl;
  cout << "Number of bins with 7 words: " << bin_7 << endl;
  cout << "Number of bins with 8 words: " << bin_8 << endl;
  cout << "Number of bins with 9 or more words: " << bin_9 << endl;
}






void hashDriver(){


		fstream newfile;
		newfile.open("dict.txt",ios::in);

		//I couldn't get the above to read the file correctly on my machine so I used the direct path below:
		//newfile.open("C:/Users/Matthew Jaworski/Documents/CPE-593/CPE 593 Dictionary/src/dict.txt",ios::in);
		/* Below is the output when I used the direct file path. My hash function produced this histogram. My function spaced the filled
		 * bins out and it falls well below the suggested 25%-30% bin empty space from class
Word count:
213557
Number of bins with 0 words: 211593
Number of bins with 1 words: 145
Number of bins with 2 words: 109
Number of bins with 3 words: 66
Number of bins with 4 words: 63
Number of bins with 5 words: 35
Number of bins with 6 words: 27
Number of bins with 7 words: 27
Number of bins with 8 words: 29
Number of bins with 9 or more words: 1463
		 * */

		int count = 0;


		if (newfile.is_open()) {
			//cout << "newfile is open" << "\n";
			string line_word;

		    while (getline(newfile, line_word)) {
		    count++;

		    }
		    newfile.close();
		}

		   cout << "Word count:\n" << count << "\n";



		  HashMap new_hashmap(count);



		  newfile.open("dict.txt",ios::in);

		  		//I couldn't get the above to read the file correctly on my machine so I used the direct path below:
		  		//newfile.open("C:/Users/Matthew Jaworski/Documents/CPE-593/CPE 593 Dictionary/src/dict.txt",ios::in);
		  		/* Below is the output when I used the direct file path. My hash function produced this histogram. My function spaced the filled
		  		 * bins out and it falls well below the suggested 25%-30% bin empty space from class
		  Word count:
		  213557
		  Number of bins with 0 words: 211593
		  Number of bins with 1 words: 145
		  Number of bins with 2 words: 109
		  Number of bins with 3 words: 66
		  Number of bins with 4 words: 63
		  Number of bins with 5 words: 35
		  Number of bins with 6 words: 27
		  Number of bins with 7 words: 27
		  Number of bins with 8 words: 29
		  Number of bins with 9 or more words: 1463
		  		 * */

		if (newfile.is_open()) {
			//cout << "newfile is open AGAIN" << "\n";
			string word;

			//loop to add to the hash table
			while (getline(newfile, word)) {

				//convert to ascii chars every time I need to locate
				int ascii_sum = 0;
				for (int i = 0; i < word.length(); i++)
				{
					char x = word.at(i);
					int ascii_current = int(x);

					ascii_sum = ascii_sum + ascii_current;
				}


				//cout << "Converted ASCII value of current word: " << ascii_sum <<"\n";
				new_hashmap.insertWord(word, ascii_sum);

			}
			newfile.close();

		}


		new_hashmap.displayHash();


}






//TRIE CODE
//won't compile but my hashmap compiles and runs


/*

 class Trie
{


public:

struct Node
{
    struct Node *alphabet[26];
    bool word_found;
};

    void insertWord(string word, int key);

    void displayHash();

};



Trie::struct Node *get()
{
    struct Node *Node =  new Node;

    Node->word_found = false;

    for (int i = 0; i < 26; i++)
        Node->alphabet[i] = NULL;

    return Node;
}



Trie::void search(struct Node *root, string key)
{
    struct Node *searchNode = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i];

        if (!searchNode->alphabet[index]){
            return false;
        }

        searchNode = searchNode->alphabet[index];
    }

}


Trie::void insert(struct Node *root, string key)
{
    struct Node *searchNode = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i];
        if (!searchNode->alphabet[index]){
        	searchNode->alphabet[index] = get();
        }

        searchNode = searchNode->alphabet[index];
    }

    searchNode->word_found = true;
}



void trieDriver(){

	vector <string> keys;


	fstream triefile;

			//open file
			//triefile.open("dict.txt",ios::in); //open a file to perform read operation using file object

			//use the commented file opening below if the non-path reference doesn't work
			triefile.open("C:/Users/Matthew Jaworski/Documents/CPE-593/CPE 593 Dictionary/src/dict.txt",ios::in); //open a file to perform read operation using file object


			int count = 0;


			if (triefile.is_open()) {
				cout << "triefile is open" << "\n";
				string word;

				int index = 0;

			    while (getline(triefile, word)) {

			    	for (int i = 0; i < word.length(); i++)
			    					{
			    			char x = word.at(i);
			    			keys[index].push_back(x);

			    	}


			    }
			    triefile.close();
			}

			   cout << "count:\n" << count << "\n";




	    struct TrieNode *root = get();


	    for (int i = 0; i < keys.size(); i++){
	        insert(root, keys[i]); //error with this line
	    }


}*/


int main()
{

	hashDriver();
	//trieDriver();
	return 0;
}
