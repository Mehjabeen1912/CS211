/********************************************************************
This program reads from a file and make a linked list with all the words present in that file. The function buildLL builds the linked list. The bad.txt file contains some bad words which are also included in the essay.txt file. the removeBadWords function takes away the bad words from the linked list. Then the function outputtofile outputs all the words from the essay.txt file in a new directory according to their starting letter.This program uses some of the functions of LL.h

Name: Mehjabeen Tasnim Khan
Programmer Number: 61
**************************************************************************/
#include<string>
#include<iostream>
#include<fstream>
#include<ostream>
#include"LL.h"
#include "utility.h"

using namespace std;

//all the function prototyoes
void buildLL ( LL<string>& l);
void removeBadWords(LL<string>& l);
void outputToFile(LL<string>& l );

int main()
{
  LL<string> list;//creating a string linked list
  buildLL (list);//passing with the buildLL function
  removeBadWords(list);//removing the bad words using the removeBadWords function
  outputToFile(list);//outputting all the words in a different txt file
  return 0;
}//end of main

/****************************************************************************
This function takes the linked list as its parameter. It reads from the file and then build a linked list with all the words in the file. Before making the linked list, this function makes sure that there are no duplicate words in the linked list and all of the words are in small letters.
****************************************************************************/
void buildLL ( LL<string>& l)
{
  ifstream fin ("essay.txt");//opening the file
  if(!fin)//checking if the file is opening, if not then exit
    {
      exit(1);
    }
  string s;//making a string variable to store the words
  fin>>s;//reading from the file
  while (fin)//while the file is open
    { 
      if ( l.search(stripStr(s))== false)//if there are not any duplicates
	{
	  l.addInOrderAscend(stripStr ( s ));//adding the word in ascending order in the linked list
     
	}//end of if
      fin>>s;
    }//end of while
  fin.close();//closing the file
}//end of the buildLL function

/****************************************************************************
This function takes the linked list as its parameter. It read from a file bad.txt and search for the bad words in the linked list. If this function finds any bad word in the linked list, it deletes the node that is holding the word and thus makes the linked list bad words free.
*************************************************************************/
void removeBadWords(LL<string>& l)
{
  ifstream fin ("badWords.txt");//opening the file
  if (!fin)//if the file does not open exit the program
    {
      exit(1);
    }//end of if
  string s;//making a string variable to store the  word from the linked list
  fin>>s;
  while(fin)//while the file is open
    {
      if (l.search(s)== true)//if the word is found in the linked list
	{
	  l.deleteNode(s);//then delete the node
	}//endof if
      fin>>s;
    }//end of while
  fin.close();//closing the file
}//end of remove bad words

/*****************************************************************************************************************
This function reads every word from the linked list and list them according to their first alphabet and output them in different files. This function makes different files for different words starting with different letters in the linked list.
*************************************************************************************************/
void outputToFile(LL<string>& l )
{ string s;//declaring a string variable
  if (!l.isEmpty())//while the linked list is not empty
    {
      s= l.deleteFront();//delete the front node and return it
    }

  do//this while loop goes till the end of the linked list
    { 
      string fileName = "./dictionary/#.txt";//naming the file
      fileName[13]=toMyUpper(s[0]);//taking the first letter to rename the file
      ofstream fout;
     
      fout.open(fileName.c_str());//opening the output file
      // this do while loop keeps going until the loop is empty and until there are same first letter in words
      do
	{
	  fout<<s;//output the word
	  fout<<endl;
	  if(!l.isEmpty())//check again if the linked list is empty or not
	    {
	      s=l.deleteFront();//if not empty take another word
	    }
	}while(!l.isEmpty() && toMyUpper(s[0])== fileName[13]);//check if the second word start with the previous letter. If yes , stay in the same file. If no them close the file and then make a new file for the new letter
      fout.close();//closing the file
    }while (!l.isEmpty());//end of while
}//end of output to file 
