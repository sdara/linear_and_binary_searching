/*
Programmer	: sdara
Program No.	: 3
Date Written	: 09/29/04
Date Revised	: 09/29/04
Program	Title	: Linear And Binary Searching
Description	:

  This program will ask the user for an account number (of 7 digits), preform a linear or binary
  search, and return the number of iterations for each.
  
  Input Validation: Do not allow numbers less than 1000000 or greater than 9999999.

*/

//Include header files for the entire program to use
#include <iostream.h>
#include <iomanip.h>

//Global Variables
const int GlobalArrayCount = 18;

//Function Prototypes
void GetSearchKey(void);
void SortArray(long AccountArray[]);
void SearchForAccountNumber_Linear(long AccountArray[],long SearchKey);
void SearchForAccountNumber_Binary(long AccountArray[],long SearchKey);


/*
This is the main program, which allows the user to preform multiple searches without
having to restart the program
*/
void main(void){
int ContinueNumber=0;

//a loop to allow the users to search more than once per run of the program
do{
GetSearchKey();
cout<<"If you would like to preform another search, type 1 and press enter.\n";
cin>>ContinueNumber;
cout<<endl;
}while(ContinueNumber==1);
cout<<"Thank you for using the software!\n\n";
}

/*
This is the GetSearchKey function, which initializes the account number array,
and allows users to enter a 7 digit account number, with input validation.
*/
void GetSearchKey(void){

//initialize account array. Because this function is called within a loop (from
//the main program),the AccountNumbers array is re-initialized to its
//original values each time, so doing a linear search after a binary search will yield expected
//iterations.
long AccountNumbers[GlobalArrayCount] = {
5658845,4520125,7895122,8777541,8451277,1302850,
8080152,4562555,5552012,5050552,7825877,1250255,
1005231,6545231,3852085,7576651,7881200,4581002
};
long key;
int SearchType;
do{
cout<<"Please enter a 7 digit account number between 1000000 and 9999999.\n";
cin>>key;
if(((key<1000000)||(key>9999999))){
cout<<"\n\t*** The number you enter is not 7 digits long. ***\n\n";
}
}while (((key<1000000)||(key>9999999)));

//if they got here, they have entered a valid 7 digit number
//now they can select which type of search to preform.
do{
cout<<"\nWhat type of search would you like to preform?\n============\n";
cout<<" 1: Linear Search\n 2: Binary Search\n==========\n";
cin>>SearchType;
if(SearchType!=1 && SearchType!=2)
cout<<"\n\t*** Please enter a 1 or 2 for search type! ***\n";
}while(SearchType!=1 && SearchType!=2);
if(SearchType==1){

//if they choose 1, preform a linear search on the current array
SearchForAccountNumber_Linear(AccountNumbers,key);
}else{

//if they choose 2, sort the array first, then preform a binary search
//on the sorted array.
SortArray(AccountNumbers);
SearchForAccountNumber_Binary(AccountNumbers,key);
}
}
/*
This is the linear search function, which searched through AccountArray (18 values) for
SearchKey. This function also outputs the results of the search as the number of itereations
it took to complete (or fail) the search.
*/
void SearchForAccountNumber_Linear(long AccountArray[],long SearchKey){
int x=0,counter=0;
bool found=false;
for(x=0;x<=GlobalArrayCount-1;x++){
if(SearchKey==AccountArray[x]){
counter++;
found=true;
break;
}
counter++;
}
if(found==true){
cout<<"\nThe account number " << SearchKey << " was found in the account array after " <<counter<< " iterations.\n\n";
}else{
cout<<"\nThe account number " << SearchKey << " was not found in the account after " <<counter<< " iterations.\n\n";
}
}
/*
This is the binary search function, which searched through AccountArray (18 values) for
SearchKey. This function also outputs the results of the search as the number of itereations
it took to complete (or fail) the search. This function is called AFTER the SortArray
function is called - otherwise, the binary search may not work at all.
*/
void SearchForAccountNumber_Binary(long AccountArray[],long SearchKey){
int first=0,last=GlobalArrayCount-1,middle,position=-1,counter1=0;
bool found=false;
while(!found && first <= last){
counter1++;
middle=(first+last)/2;
if(AccountArray[middle]==SearchKey)
{
found=true;
position=middle;
break;
}
else if(AccountArray[middle]>SearchKey){
last=middle-1;
}
else{
first=middle+1;
}
}
if(position!=-1)
cout<<"\nThe account number " << SearchKey << " was found in the account array after " <<counter1<< " iterations\n\n";
else{
cout<<"\nThe account number " << SearchKey << " was not found in the account array after "<<counter1<<" iterations.\n\n";
}
}

/*
This is the SortArray function. The sort being used here is a bubble sort, which goes through
each value in the arrray, and swaps it with the value in the cell previous to it only if that cell
has a higher value (or something to that effect).
*/
void SortArray(long AccountArray[]){
int y=0,swap;
long tempNumber;
do{
swap=0;
for(int y=0;y<GlobalArrayCount-1;y++){
if(AccountArray[y]>AccountArray[y+1])
{
tempNumber=AccountArray[y];
AccountArray[y]=AccountArray[y+1];
AccountArray[y+1]=tempNumber;
swap=1;
}
}
}while(swap!=0);
}