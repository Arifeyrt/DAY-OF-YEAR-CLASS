#include <iostream>
#include <list>
#include <vector>
#include "dayofyear.h"
using namespace std;
using namespace doys;


int main()
{
    list<DayOfYearSET::DayOfYear>list1;
    list<DayOfYearSET::DayOfYear>list2;
    DayOfYearSET::DayOfYear d1(12, 28);
    DayOfYearSET::DayOfYear d2(7, 14);
    DayOfYearSET::DayOfYear d3(4, 15);
    DayOfYearSET::DayOfYear d4(5, 19);
    DayOfYearSET::DayOfYear d5(9, 21); 
    DayOfYearSET::DayOfYear d6(3, 14);
    DayOfYearSET::DayOfYear d7(1, 25);
    DayOfYearSET::DayOfYear d8(7, 7);

    list1.push_back(d1);
    list1.push_back(d2);
    list1.push_back(d3);
    list2.push_back(d5);
    list2.push_back(d2);
    list2.push_back(d7);
    list2.push_back(d6);
    DayOfYearSET a(list1);
    a.SetName("A");
    cout << "Elements of the A set";
    cout << a;
    DayOfYearSET b(list2);
    b.SetName("B");
    cout << "Elements of the B set";
    cout << b;

    cout << "testing add (+operator) function" << endl;
    cout << "A+{14,March}" << endl;
    a = a + d6;
    cout << a << endl;
     

    cout << "testing remove (-operator) function" << endl;
    cout << "B-{14,March}" << endl;
    b= b - 4;
    cout << "B="<<b << endl;


    cout << "testing == operator and != operator" << endl;
    if (a == b) {
        cout << " A and B equal\n";
    }
    else {
        cout << "A and B not equal\n" << endl;
    }
    cout << "**************************************************" << endl;
    cout << a;
    cout << b << endl;
    DayOfYearSET c;
    cout<<"union(+operator) functions"<<endl;
    c = a + b;
    cout << "A+B=" << c;
    cout << "**************************************************" << endl;
    DayOfYearSET k;
    cout << "intersection(^ operator) functions" << endl;
    k = a ^ b;
    cout << "A ^ B" << k;
    cout << "****************************************************" << endl;
    DayOfYearSET f;
    cout << "difference(- operator) functions" << endl;
    f = a - b;
    cout <<"A-B" << f;
    cout << "**************************************************" << endl;
    DayOfYearSET::DayOfYear e = a[2];
    cout << "testing [] operator" << endl;
    cout << "A[2]="<<" {" << e.getday() << "," << e.getmonth() << "}" << endl;
    cout << "**************************************************" << endl;
    DayOfYearSET::DayOfYear e_ = b[3];
    cout << "testing [] operator" << endl;
    cout << "B[3]=" <<" {" << e_.getday() << "," << e_.getmonth() << "}" << endl;

    DayOfYearSET t;
    cout << "testing ! operator " << endl;
    t = !a;
    cout << "!A=" << t << endl;

}

