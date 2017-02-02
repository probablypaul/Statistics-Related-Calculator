#include <iostream>
#include <sstream>
#include <vector>
#include "stats.h"

using namespace std;

vector<double> get_list();

int main(){
    
    vector<double> number_list; //Vector that stores a list of numbers
    while(number_list.empty()){ //Call get_list until there is a list of valid input
        number_list = get_list();
    }
    cout << endl;
    string user_choice = "";
    while (user_choice != "5"){ //Loop until the user chooses to quit the program
        //Show the user the available choices
        cout << "Please select one of the following options:" << endl;
        cout << "   1. Enter a newlist of numbers" << endl;
        cout << "   2. Print mean" << endl;
        cout << "   3. Print median" << endl;
        cout << "   4. Print standard deviation" << endl;
        cout << "   5. End program" << endl;
        cout << " >> ";
        getline(cin, user_choice); //Get the users choice
        stats statistics; //Create an stats object
        //Choice 1 allows the user to enter a new list of numbers
        if (user_choice == "1"){
            //Empty the old list
            while (!number_list.empty()){
                number_list.pop_back();
            }
            while(number_list.empty()){ //Call get_list until there is a list of valid input
                number_list = get_list();
            }
        }
        //Choice 2 computes the mean of the given list and prints it
        else if (user_choice == "2"){
            statistics.get_mean(number_list);
            statistics.print_values(1);
        }
        //Choice 3 computes the median of the given list and prints it
        else if (user_choice == "3"){
            statistics.get_median(number_list);
            statistics.print_values(2);
        }
        //Choice 4 computes the standard deviation of the given list and prints it
        else if (user_choice == "4"){
            statistics.get_standard_deviation(number_list);
            statistics.print_values(3);
        }
        //Report an error if the user enters an invalid choice
        else if (user_choice != "5"){
            cout << "Error: Invalid choice!" << endl;
        }
        cout << endl;
    }
    return 0;
}

vector<double> get_list(){
    vector<double> number_list; //Vector that will be returned to main
    string new_list_string = "";
    string element = "";
    //Prompt the user for their list
    cout << "Enter your list, separated by spaces: " << endl;
    cout << " >> ";
    //Get the user input, add each element to the list as a double
    getline(cin, new_list_string);
    istringstream stream(new_list_string);
    while(stream >> element){
        try{
            number_list.push_back(stod(element));
        }
        //Empty the list and report an error if the user enters an invalid character or number
        catch(invalid_argument&){
            cout << "Error: not a number!" << endl;
            while(!number_list.empty()){
                number_list.pop_back();
            }
            cout << endl;
            return number_list;
        }
        catch(out_of_range&){
            cout << "Error: number out of range!" << endl;
            while(!number_list.empty()){
                number_list.pop_back();            
            }
            cout << endl;
            return number_list;
        }
    }
    cout << endl;
    return number_list; //Return the list to main
}
