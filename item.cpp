#include<iostream>
#include "item.h"
using namespace std;

//constructor
Item::Item(string Name,double Cost,double Inflat_Rate,int From,int To)
{
    this->name=Name;
    this->cost=Cost;
    this->inflat_rate=Inflat_Rate;
    this->from=From;
    this->to=To;
}

double Item::calculate(){
    double Cost=this->cost;
    double Total_Cost=0;
    for(int i=this->from;i<=this->to;++i){
        if(i>this->from)
            Cost=Cost*this->inflat_rate;
        Total_Cost+=Cost;
    }
    return Total_Cost;
}