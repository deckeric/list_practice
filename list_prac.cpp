//Author: Eric Deck
//Exercises taken from Chapter 3 of Data Structures and Algorithm Analysis in C++ by Mark Allen Weiss

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

//Using list Ps numbers as the indexes to print out for list L.
void printLots(const list<int> &L, const list<int> &P){
    int lPosition = 0;
    list<int>::const_iterator l_num;
    list<int>::const_iterator p_num = P.begin();
    for(l_num = L.begin(); l_num != L.end(); l_num++){
        if(lPosition == *p_num){
            cout << *l_num << endl;
            p_num++;
        }
        lPosition++;
    }
}

//Finding the intersection of two lists.
void intersection(const list<int> &listOne, const list<int> &listTwo, list<int> &output){
    list<int>::const_iterator L1 = listOne.begin();
    list<int>::const_iterator L2;
    list<int>::iterator outputIt = output.begin();
    for(L1; L1 != listOne.end(); L1++){
       for(L2 = listTwo.begin(); L2 != listTwo.end(); L2++){
           if(*L1 == *L2){
               output.insert(outputIt, *L2);
           }
       }
    }
}

//Find the union of two lists.
void unionList(const list<int> &listOne, const list<int> &listTwo, list<int> &output){
    list<int>::const_iterator L1 = listOne.begin();
    list<int>::const_iterator L2;
    list<int>::iterator outputIt = output.begin();
    for(L1; L1 != listOne.end(); L1++){
        output.insert(outputIt, *L1);  
    }
    for(L2 = listTwo.begin(); L2 != listTwo.end(); L2++){
        outputIt = output.begin();
        for(outputIt; outputIt != output.end(); outputIt++){
            if(*L2 == *outputIt){
                break;
            }
            else if(*L2 < *outputIt){
                output.insert(outputIt, *L2);
                break;
            }
        }
        if(outputIt == output.end()){
            output.insert(outputIt, *L2);
        }
    }
}



int main(){
    list<int> L1 = {1, 2, 4, 6, 8, 10, 11, 12, 27};
    list<int> P = {2, 3, 4, 6, 12, 15, 18};
    list<int> output;
    //intersection(L1, P, output);
    
    //unionList(L1, P, output);
    //for(auto v:output)
    //    cout << v << endl;
    
    //printLots(L1, P);
}
