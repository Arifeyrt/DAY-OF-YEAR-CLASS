#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <ostream>
#include <string>
using namespace std;


enum class months {
    january = 1, february = 2, march = 3, april = 4, may = 5, june = 6, july = 7, august = 8, september = 9, october = 10, november = 11, december = 12
};
namespace doys{

class DayOfYearSET {
public:

    class DayOfYear {


    public:
        DayOfYear();
        DayOfYear(const int&);
        DayOfYear(const int&, const int&);
        int getmonth()const;
        int getday()const;
        void set(const int&, const int&);
        bool checkvalid()const;
       const string getString(int)const;
    private:
        int month;
        decltype(month) day;

    };


    DayOfYearSET();
    DayOfYearSET(list<DayOfYear>&);
    int Size()const;
    void SetName(const string&);
    string GetName()const;
    friend ostream& operator<< (ostream& os, const DayOfYearSET&);//
    DayOfYearSET& operator+(const DayOfYear&);//adding elements to set.
    DayOfYearSET& operator-(const int&);//removing elements from the set.
    DayOfYear operator[](const int&);//getting the element in the index
    bool operator==(const DayOfYearSET&);//checking if two sets are equal
    bool operator!=(const DayOfYearSET&);//checking if two sets are not equal
    DayOfYearSET operator+(const DayOfYearSET&);// the sum of two sets
    DayOfYearSET operator^(const DayOfYearSET&);//intersection of two sets
    DayOfYearSET operator-(const DayOfYearSET&);//the difference of the two sets
    DayOfYearSET operator!();//elements that are not in the set
    int  getname(const months&);
    
    



private:
    DayOfYear* sets;
    int size;
    string name;



};
}
#endif
