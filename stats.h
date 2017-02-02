#ifndef STATS_H
#define	STATS_H
#include <vector>

using namespace std;
class stats{
private:
    double total;
    double mean;
    double median;
    double standard_deviation;
public:
    stats();
    void get_mean(vector<double> & number_list);
    void get_median(vector<double> & number_list);
    void get_standard_deviation(vector<double> & number_list);
    void print_values(int choice);
};


#endif	/* STATS_H */
