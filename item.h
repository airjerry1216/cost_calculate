#include<iostream>
using namespace std;

class Item{
public:
    
    string name;
    double cost;
    double inflat_rate;
    int from;
    int to;
    double total_cost;

    Item(string name,double cost,double inflat_rate,int from,int to);//constructor
    double calculate();
};