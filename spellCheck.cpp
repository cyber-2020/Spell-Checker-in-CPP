#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<cstring>
#include<cctype>            //Needed for the toupper function
//#include "CharBinaryTree.h" if using a BinaryTree to spellcheck
using namespace std;

int main(int argc, char *argv[])
{
	//Here is how to get the input
    if(argc==2)
    { /*used to get the warning off the screen*/   }	
	string arg_2 = argv[1];
	int firstequal=arg_2.find("=");
	int semicolon=arg_2.find(";");
	string file_1=arg_2.substr(firstequal+1,semicolon-(firstequal+1));
	
    int secondequal=arg_2.find("=",semicolon);
	int secondcolon=arg_2.find(";",secondequal);
    string file_2=arg_2.substr(secondequal+1,secondcolon-(secondequal+1));
    
    int thirdequal=arg_2.find("=",secondcolon);
	int thirdcolon=arg_2.find(";",thirdequal);
    string file_3=arg_2.substr(thirdequal+1,thirdcolon-(thirdequal+1));
    
    int fourthequal=arg_2.find("=",thirdcolon);
	string file_4=arg_2.substr(fourthequal+1,2);
   
    //create the output file
	ifstream inFile, inFile2;
    ofstream outFile;
	outFile.open("spellCheck.txt");
	
	//Declare necessary variables and arrays
	const int LENGTH = 256;
	char input[LENGTH];
	const int MAXD=3000;
    string myarray[MAXD];   
    char *pch;
        
//Differing scenarios
	if(secondcolon==-1)            //C A S E    1
	{    //structure=array  //sort=no  
         inFile.open(file_2.data());
         if(inFile.fail())
         {   
             cout << "Error opening dictionary file!" << endl;
             exit(1);
         } 
         else
         {
             int i=-1;
             inFile.getline(input,LENGTH);
             while(!inFile.fail())
             {
                 i++;
                 myarray[i] = input; 
                 inFile.getline(input,LENGTH);
             }   
             
             
             inFile2.open(file_1.data());
             if(inFile2.fail())
             {   
                 cout << "Error opening input file!" << endl;
                 exit(1);
             } 
             else
             {
                 char a[10],b[10]; 
                 int j,k,found,line=0; 
                 inFile2.getline(input,LENGTH);   
                 while(!inFile2.fail())
                 {  
                    line++;
                    pch = strtok(input," !@#$%^&*()_+=-`~[]\|}{;':,./?><");
                    while(pch!=NULL)
                    {   
                        found = 0;
                        for(k=0;k<=i;k++)
                        {        
                                 for(j=0;j<10;j++)  //if uppercase-> lowercase
                                 {   a[j]=tolower(pch[j]);   }
                         
                                 for(j=0;j<10;j++)   //turn string into char type
                                 {   b[j]=myarray[k][j];   }
                         
                                 if((strcmp(a,b)==0))   //Any match -> found=1  
                                 {   found = 1;  }
                         }   
                         
                         if(found == 0)  // No match -> print in outputFile      
                         {   
                             outFile << left << setw(12) << pch << left << setw(6)
                             << "line " << line << endl;
                         }                   
                         pch = strtok(NULL," !@#$%^&*()_+=-`~[]\|}{;':,./?><");
                    } //inner while closed
                  inFile2.getline(input,LENGTH);
                 }//outer while closed            
             } // inner else 
         }//outer else
    }
	else if(thirdcolon==-1)             //C A S E   2
	{    //structure=bintree   ->     sort = no
	     inFile.open(file_2.data());
         if(inFile.fail())
         {   
             cout << "Error opening dictionary file!" << endl;
             exit(1);
         } 
         else
         {
             //CharBinaryTree tree;
             inFile.getline(input,LENGTH);
             while(!inFile.fail())
             {
                 //tree.insert(input);
                 inFile.getline(input,LENGTH);
             }
                                                   
                   
         }
	}
	else                      //C A S E    3
	{   string k="no";
	    if(k>file_4)
	    {   cout << "do merge" << endl;   }
        else if(k<file_4)
        {   cout << "do quick" << endl;   }
        else
        {   cout << "do no" << endl;   }
        
        //else if(file_4=no)
        //else if(file_4=merge)
        //else if(file_4=quick)
        //if((strcmp(file_3,"bintree")==0)
        //outFile << file_3 << endl;
    }
    outFile.close();
    inFile.close();
    inFile2.close();
	return 0;
}
