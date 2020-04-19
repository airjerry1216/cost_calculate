#include<iostream>
#include<fstream>
#include<sstream>
#include "item.h"
using namespace std;

int main()
{
    /*double fixed=102;
    double insurance=0;
    double variable=0;
    double age=55;
    double inflat_rate=1.025;
    double annuity=360;
    double total=0;
    double year;*/

    string name;
    double cost;
    double inflat_rate;
    int from;
    int to;
    Item *item[20];
    for(int i=0;i<=19;++i)
         item[i]=new Item("",0,1,0,0);
    int cnt=0;
    double total=0;
    char line[200];

    cout<<"  項目\t"<<"支出(萬)\t"<<"通膨\t"<<"from(年)\t"<<"to(年)"<<endl;
    /*while(cin>>name&&name!="0"){
        cin>>cost>>inflat_rate>>from>>to;
        item[cnt]=new Item(name,cost,inflat_rate,from,to);
        
        cout<<"此項目花費:"<<item[cnt]->calculate()<<"萬"<<endl;
        total=total+item[cnt]->calculate();
        cnt++;
    }
    cout<<"總花費:"<<total<<"萬"<<endl;*/

    fstream fin;
    fin.open("file.txt",ios::in);
    while(fin.getline(line,sizeof(line),'\n'))
    {
        if(cnt!=0)
        {
            istringstream is(line);
            string str;
            int i=0;
            cout<<cnt<<".";
            while(is>>str)  
            {
                if(i==0)
                    item[cnt]->name=str;
                else if(i==1)
                    item[cnt]->cost=stod(str);
                else if(i==2)
                    item[cnt]->inflat_rate=stod(str);
                else if(i==3)
                    item[cnt]->from=stod(str);
                else if(i==4)
                    item[cnt]->to=stod(str);
                cout<<str<<"\t";
                i++;
            }
            cout<<endl;
            cout<<"------------------------------------此項目花費:"<<item[cnt]->calculate()<<"萬"<<endl;
            total=total+item[cnt]->calculate();
        }
        cnt++;  
    }
    cout<<endl<<"------------------------------------總花費:"<<total<<"萬"<<endl;

/*
    year=fixed+insurance+variable;
    for(int i=55;i<=95;i++)
    {   
        //if(i==57)
          //  fixed-=300;
        //if(i==65)
          //  variable=100;
        //if(i==60)
          //  insurance=50;
        //if(i<=65)
          //  total+=fixed+insurance+variable;
        //else
        //{
            total+=fixed;
        //}
        fixed*=inflat_rate;
    }
    //total-=annuity*40;
    cout<<102*40<<endl;
    cout<<fixed<<endl;
    cout<<total<<endl;
*/
    return 0;
}
