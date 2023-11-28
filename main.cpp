#include <iostream>
#include <string>
#include <fstream>
#include "Transpose.h"
#include "Count.h"
#include "MoveToFront.h"
using namespace std;

int main() {

    cout << "Programming Assignment 4 - Samuel Tran" << endl;
  

	Count<char> list;
   
    list.add('A');
    list.add('B');
    list.add('C');
    list.add('D');
    list.add('E');
    list.add('F');
    list.add('G');
    list.add('H');
    cout << "Starting list for Count: Size of list: " << list.size() << endl;
    list.printlist();
    cout << endl << endl;
 
    list.find('F');
    list.find('D');
    list.find('F');
    list.find('G');
    list.find('E');
    list.find('G');
    list.find('F');
    list.find('A');
    list.find('D');
    list.find('F');
    list.find('G');
    list.find('E');
    list.find('H');
    list.find('I');
    cout << "Count Heuristic: Size of list: "<< list.size() << endl;
    cout << "Number of compares: " << list.getCompares() << endl;
    list.printlist();
    cout << endl;
    cout << endl;
    cout << endl;
    MoveToFront<char> Mlist;
    

    Mlist.add('A');
    Mlist.add('B');
    Mlist.add('C');
    Mlist.add('D');
    Mlist.add('E');
    Mlist.add('F');
    Mlist.add('G');
    Mlist.add('H');
    cout << "Starting list for Move-to-Front: Size of list: " << Mlist.size() << endl;
    Mlist.printlist();
    cout << endl << endl;

    Mlist.find('F');
    Mlist.find('D');
    Mlist.find('F');
    Mlist.find('G');
    Mlist.find('E');
    Mlist.find('G');
    Mlist.find('F');
    Mlist.find('A');
    Mlist.find('D');
    Mlist.find('F');
    Mlist.find('G');
    Mlist.find('E');
    Mlist.find('H');
    Mlist.find('I');
    cout << "Move-to-Front Heuristic: Size of list: " << Mlist.size() << endl;
    cout << "Number of compares: " << Mlist.getCompares() << endl;
    Mlist.printlist();
    cout << endl;
    cout << endl;
    cout << endl;

    transpose<char>TList;
    TList.add('A');
    TList.add('B');
    TList.add('C');
    TList.add('D');
    TList.add('E');
    TList.add('F');
    TList.add('G');
    TList.add('H');
    cout << "Starting list for Transpose: Size of list: " << TList.size() << endl;
    TList.printlist();
    cout << endl << endl;
    TList.find('F');
    TList.find('D');
    TList.find('F');
    TList.find('G');
    TList.find('E');
    TList.find('G');
    TList.find('F');
    TList.find('A');
    TList.find('D');
    TList.find('F');
    TList.find('G');
    TList.find('E');
    TList.find('H');
    TList.find('I');
    cout << "Transpose Heuristic: Size of list: " << TList.size() << endl;
    cout << "Number of compares: " << TList.getCompares() << endl;
    TList.printlist();
    cout << endl;

    string word,filename;
    fstream fin;
    filename = "test.txt";
    fin.open(filename);
    Count<string> CStringList;
    MoveToFront<string> MStringList;
    transpose<string> TStringList;
    while (fin >> word)
    {

        CStringList.find(word);
        MStringList.find(word);
        TStringList.find(word);
    }
    cout << endl << endl;
    cout << "Count Heuristic: Size of list: " << CStringList.size() << endl;
    cout << "Number of compares: " << CStringList.getCompares() << endl;
    CStringList.printlist(10);
    cout << endl << endl;
    cout << "Move-to-Front Heuristic: Size of list: " << MStringList.size() << endl;
    cout << "Number of compares: " << MStringList.getCompares() << endl;
    MStringList.printlist(10);
    cout << endl << endl;
    cout << "Transpose Heuristic: Size of list: " << TStringList.size() << endl;
    cout << "Number of compares: " << TStringList.getCompares() << endl;
    TStringList.printlist(10);
    cout << endl << endl; 
    cout << endl << endl;


	return 0;
}