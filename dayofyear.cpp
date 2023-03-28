#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "dayofyear.h"
using namespace std;



namespace doys{

DayOfYearSET::DayOfYearSET(list<DayOfYear>& list) {
    this->size = list.size();
    sets = new DayOfYear[size];

    auto i = list.begin();

    for (int j = 0; j < size; j++)
    {
        auto ni = std::next(i, j);
        sets[j].set((*ni).getmonth(), (*ni).getday());
        
    }

}
DayOfYearSET::DayOfYearSET() {

    this->size = 0;
    

}
ostream& operator<<(ostream& os, const DayOfYearSET& obj) {
	string month_name="A";

  
   
    os << obj.GetName() << " set is:{";
    for (int i = 0; i < obj.Size(); i++) {
    switch (obj.sets[i].getmonth()){
    case 1:
        month_name="January";
        break;
    case 2:
        month_name="February";
        break;
    case 3:
         month_name="march";
         break;
    case 4:
         month_name="april";
         break;
    case 5:
         month_name="may";
         break;
    case 6:
         month_name="june";
         break;
    case 7:
         month_name="july";
         break;
    case 8:
         month_name="august";
         break;
    case 9:
         month_name="september";
         break;
    case 10:
         month_name="october";
         break;
    case 11:
         month_name="november";
         break;
    case 12:
        month_name="december";
        break;
    }
    	
    	
        os << "{"<<obj.sets[i].getday() << "." << month_name << "},";
    }
    os << "}\n";
    return os;

}


DayOfYearSET::DayOfYear::DayOfYear() {
    day = 1;
    month = 1;
}

DayOfYearSET::DayOfYear::DayOfYear(const int& num) {
    month = num;
    day = 1;

}
DayOfYearSET::DayOfYear::DayOfYear(const int& _month, const int& _day) {
    month = _month;
    day = _day;
}
int DayOfYearSET::Size()const {
    return size;
}


bool DayOfYearSET::DayOfYear::checkvalid()const {
    if (month < 0 && month>12) {
        return false;
    }
    if (day < 0 && day>31) {
        return false;
    }
    if (month == 2 && day > 28) {
        return false;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day > 31) {
            return false;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11 || month == 10 || month == 12) {
        if (day > 30) {
            return false;
        }
    }


    return true;
}
void DayOfYearSET::DayOfYear::set(const int& _month, const int& _day) {
    month = _month;
    day = _day;

}

int DayOfYearSET::DayOfYear::getmonth()const {
    return month;
}

int DayOfYearSET::DayOfYear::getday()const {
    return day;
}

void DayOfYearSET::SetName(const string& _name) {
    name=_name;

}

string DayOfYearSET::GetName()const{
    return name;
}

DayOfYearSET& DayOfYearSET::operator+(const DayOfYear& d3){
    size++;
    DayOfYear* temp = new DayOfYear[size];
    for (int i = 0; i < size; i++) {
        temp[i].set(sets[i].getmonth(), sets[i].getday());
    }
    temp[size-1].set(d3.getmonth(), d3.getday());
    delete sets;
    sets = new DayOfYear[size];
    for (int i = 0; i < size; i++) {
        sets[i].set(temp[i].getmonth(), temp[i].getday());
    }

    
    return *this;
}
DayOfYearSET& DayOfYearSET::operator-(const int& index) {
    if (index > size) {
        cout << "incorrect size." << endl;

    }
    else if (index < 1) {
        cout << "incorrect size. \n" << endl;
       
    }
    else {
        
        DayOfYear* temp = new DayOfYear[size];
        for (int i = 0; i < size; i++) {
            if (i >= index - 1) {
                temp[i].set(sets[i + 1].getmonth(), sets[i + 1].getday());
            }
            else {
                temp[i].set(sets[i].getmonth(), sets[i].getday());
            }
       }
        delete sets;
        size--;
        sets = new DayOfYear[size];
        for (int i = 0; i < size; i++) {
            sets[i].set(temp[i].getmonth(), temp[i].getday());
        }
    }
    return *this;
}
bool  DayOfYearSET::operator==(const DayOfYearSET& other){
    int count = 0;
    
    if (this->Size() == other.Size()) {
        for (int i = 0; i < this->Size(); i++) {
            
            for ( int j = 0; j < this->Size(); j++) {
                if (sets[i].getday() == other.sets[j].getday() && sets[i].getmonth() == other.sets[j].getmonth()) {
                    count++;
                    break;
                }
            }
        }
        }
    if (count == this->Size()) {
        return true;
    }
    return false;




    }

bool  DayOfYearSET::operator!=(const DayOfYearSET& other) {
    int count = 0;

    if (this->Size() == other.Size()) {
        for (int i = 0; i < this->Size(); i++) {

            for (int j = 0; j < this->Size(); j++) {
                if (sets[i].getday() == other.sets[j].getday() && sets[i].getmonth() == other.sets[j].getmonth()) {
                    count++;
                    break;
                }
            }
        }
    }
    if (count == this->Size()) {
        return false;
    }
    return true;




}

DayOfYearSET DayOfYearSET::operator+(const DayOfYearSET& other) {
    DayOfYearSET unionset;
   
    vector<DayOfYear>vect;
    int cout=0;
    for (auto i = 0; i < this->size; i++) {
        vect.push_back(sets[i]);
    }
   
    for (auto i = 0; i < other.Size(); i++) {
        cout = 0;
        for (auto j = 0; j < vect.size(); j++) {
            if (vect[j].getday() != other.sets[i].getday() || vect[j].getmonth() != other.sets[i].getmonth()) {
                cout++;
            }


        }
        if (cout == vect.size()) {
            vect.push_back(other.sets[i]);
        }
    }
    auto i= vect.size();
    unionset.sets = new DayOfYear[i];
    unionset.size = i;
    for(auto k=0;k<i;k++){
        unionset.sets[k].set(vect[k].getmonth(), vect[k].getday());
    }
    return unionset;

}

DayOfYearSET DayOfYearSET::operator^(const DayOfYearSET& other) {
    DayOfYearSET unionset;
    vector<DayOfYear>vect;

    for (int i = 0; i < this->Size(); i++) {
        for (int j = 0; j < other.Size(); j++) {
            if (sets[i].getday() == other.sets[j].getday() && sets[i].getmonth() == other.sets[j].getmonth()) {
                vect.push_back(other.sets[j]);
            }
        }
   }
    auto i = vect.size();
    unionset.sets = new DayOfYear[i];
    unionset.size = i;
    for (auto k = 0; k < i; k++) {
        unionset.sets[k].set(vect[k].getmonth(), vect[k].getday());
    }
    return unionset;
}

DayOfYearSET DayOfYearSET::operator-(const DayOfYearSET& other) {
    DayOfYearSET unionset;
    vector<DayOfYear>vect;
    auto cout = 0;

    for (int i = 0; i < this->Size(); i++) {
        cout = 0;
        for (int j = 0; j < other.Size(); j++) {
            if (sets[i].getday() != other.sets[j].getday() || sets[i].getmonth() != other.sets[j].getmonth()) {
                cout++;
            }
            if (cout == other.Size()) {
                vect.push_back(sets[i]);
            }
        }
    }
    auto i = vect.size();
    unionset.sets = new DayOfYear[i];
    unionset.size = i;
    for (auto k = 0; k < i; k++) {
        unionset.sets[k].set(vect[k].getmonth(), vect[k].getday());
    }
    return unionset;

}
DayOfYearSET::DayOfYear DayOfYearSET::operator[](const int& index) {
    
    if (index > size) {
        cout << "incorrect size " << endl;
        exit(0);
    }
    else if (index < 1) {
        cout << "incorrect size\n." << endl;
        exit(0);
    }
    else {

        DayOfYear temp(sets[index-1].getmonth(), sets[index-1].getday());
        return temp;
      
    }
   
}


DayOfYearSET DayOfYearSET::operator!() {
    vector<DayOfYearSET::DayOfYear>vect;
    int count = 0;
    int a = 0;
    for (auto i = 1; i <= 12; i++) {
        
        for (auto j = 1; j <= getname(months(i)); j++) {
            count = 0;
            for (auto k = 0; k < this-> Size(); k++) {
                if (sets[k].getmonth() != i && sets[k].getday() != j) {
                    count++;
                  
                }
            }
            if (count == this->Size()){
                DayOfYear temp(i, j);
                    vect.push_back(temp);
                    a++;
            }
        }
    }

    DayOfYearSET C;
    C.SetName("C");
    C.size = a;
    cout << vect.size();
    this->size = a;

    C.sets = new DayOfYear[a];
    for (auto i = 0; i < a; i++) {
        sets[i] = vect[i];
    }
    return C;

}
int DayOfYearSET::getname(const months& m){
    switch (m) {
    case months::january:
        return 31;
    case months::february:
        return 28;
    case months::march:
        return 31;
    case months::april:
        return 30;
    case months::may:
        return 31;
    case months::june:
        return 30;
    case months::july:
        return 31;
    case months::august:
        return 31;
    case months::september:
        return 30;
    case months::october:
        return 31;
    case months::november:
        return 30;
    case months::december:
        return 31;
    }

	return 1;

}
const string DayOfYearSET::DayOfYear::getString(int m)const{
    switch (m) {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
         return "march";
    case 4:
         return "april";
    case 5:
         return "may";
    case 6:
         return "june";
    case 7:
         return "july";
    case 8:
         return "august";
    case 9:
         return "september";
    case 10:
         return "october";
    case 11:
         return "november";
    case 12:
        return "december";
    }

	return "january";

}
}
