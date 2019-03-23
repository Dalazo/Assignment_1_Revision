// Assignment1.cpp : Defines the entry point for the console application.


//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

struct PERSON {

	char name[20];
	float balance;

};

using namespace std;

PERSON * readData(int & N);

void printmenu();
void Display (PERSON arr[], int & N);
void FindRichest (PERSON arr[], int & N);
void Deposit (PERSON arr[], int N, string custName, float amount);
void Newcopy (string filename,PERSON arr[], int &N);
int main()
{


	fstream myfile;
	int counter = 0;
	string line;
	

	myfile.open("data.txt");

	if (!myfile.is_open()) {

		cout << "File not found" << endl;

	}


	while (getline(myfile, line))
	{
		counter++;
	}
	cout << "File has this many lines: " << counter << endl;
	myfile.close();

	 
	PERSON *ptr = nullptr; 
	 
	 
	ptr = readData(counter);


    int choice;
    string custName;
	float depositAmount;
    do
    {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                Display(ptr,counter);
                break;

            case 2:
                {
				
				 cout << "What customer are you looking for?: ";
				 cin.ignore();
				 getline(cin,custName);
				 cout << "How much would you like to deposit: ";
				 cin >> depositAmount;
				 
				 Deposit(ptr,counter,custName, depositAmount);
				
				
                break;
				}
            case 3:
                FindRichest(ptr, counter);
                break;

            case 4:
                Newcopy("data.txt",ptr, counter);

                break;

            case 5:
                    cout << "Deleting memory..." ;

					delete [] ptr;
						 
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
	 cout << endl;
	    
	}  while(choice != 5);
          return 0;
}



PERSON * readData(int & n)
{
    PERSON *arr = new PERSON[n];

    fstream myfile;
	
	myfile.open("data.txt");

    int counter = 0;
	while (!myfile.eof())
	{
		
		string name;
		string lastname;
        string combined;
	    string space = " ";
		myfile >> name;
		myfile >> lastname;
		
        combined = name + space + lastname;
		

		strcpy(arr[counter].name,combined.c_str());
        myfile >> arr[counter].balance;
		
        
		
        counter++;
	}
    
	 return arr;
}




void Display (PERSON arr[], int & N)
{
cout << "        Name          Balance     " << endl;
cout << "__________________________________" << endl;

for (unsigned int i = 0; i < N; i++)
{

cout << arr[i].name << "  " << arr[i].balance << endl;

}
}


void FindRichest (PERSON arr[], int & N)
{

float checker = 0;
char name[20];

for (unsigned int i = 0; i < N-1; i++)
{

if (checker < arr[i].balance)
{
      
checker = arr[i].balance;
strcpy(name,arr[i].name);

}

}
 cout << "The richest person is: " << name << " with " << checker << endl;
 

}




void Deposit (PERSON arr[], int N, string custName, float amount)
{

char name[20];


strcpy(name,custName.c_str());

bool result;


for (int i = 0; i < N; i++)
{

if (strcmp(name,arr[i].name) == 0)
{

arr[i].balance = arr[i].balance + amount;
cout << "Your new balance is " << arr[i].balance << endl;
result = true;

}

else (result == false);

}

if (result == false)
{
cout << "Name not found :( " << endl;

}

}

void Newcopy (string filename, PERSON arr[], int &N)
{
fstream myfile;

myfile.open("data.txt");
for (int i = 0; i < N; i++){


myfile <<  arr[i].name ;
myfile << " ";
myfile << arr[i].balance << endl;



}
myfile.close();

}


void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}







