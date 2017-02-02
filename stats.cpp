#include "stats.h"
#include <iostream>
#include <vector>
#include <math.h>

//Default constructor: set all private variables to zero
stats::stats(){
    total = 0;
    mean = 0;
    median = 0;
    standard_deviation = 0;
}

//Gets the list's mean
void stats::get_mean(vector<double> & number_list){
    //Add up each element of the list and divide it by the total number of elements
    for (int i = 0; i < number_list.size(); i++){
        total += number_list[i];
    }
    mean = total/number_list.size();
}

//Gets the list's median
void stats::get_median(vector<double> & number_list){
    //If there is an even number of elements in the list
    if (number_list.size() % 2 == 0){
        //Divide the sum of the two middle numbers in the list
        median = (number_list[(number_list.size()-1)/2]+number_list[(number_list.size()+1)/2])/2;
    }
    //If there is an odd number of elements in the list
    else{
        //Just get the middle element
        median = number_list[number_list.size()/2];
    }
}

//Gets the list's standard deviation
void stats::get_standard_deviation(vector<double> & number_list){
    //Get the mean if it hasn't been computed already
    if (mean == 0){
        get_mean(number_list);
    }
    double total_squared_deviation = 0; //Total squared deviation = sum of (element - mean)^2
    for (int i = 0; i < number_list.size(); i++){
        total_squared_deviation += pow(number_list[i]-mean, 2);
    }
    //Standard deviation is equal to sqrt(total squared deviation / n - 1)
    standard_deviation = sqrt(total_squared_deviation/(number_list.size()-1));    
}

//Prints the value of the user's choice
void stats::print_values(int choice){
    if (choice == 1){
        cout << "Mean: " << mean << endl;
    }
    else if (choice == 2){
        cout << "Median: " << median << endl;
    }
    else{
        cout << "Standard Deviation: " << standard_deviation << endl;
    }
}
