#include "setLL.h"
#include "MSetLL.h"
#include "mapLL.h"
#include "mmapLL.h"
using namespace std;

int main() {
    cout << "List 1" << endl;
    setLL list1;
    list1.insert("L1 A");
    list1.insert("L1 B");
    list1.insert("L1 C");
    list1.toString();
    
    cout<<endl  << "List 5" << endl;
    setLL list5;
    list5.insert("L1 A");
    list5.insert("L5 B");
    list5.insert("L5 C");
    list5.toString();
    setLL list6 = list1.unin(list5);
    cout<<endl << "List 6" << endl;
    list6.toString();
    cout << "Is L5 A in list 7 " << list6.is_in("L5 A 3") << endl;
    cout << endl << "List 8" << endl;
    setLL list8 = list1.intersection(list5);
    list8.toString();

    // MSetLL list2;
    // list2.insert("a1");
    // list2.insert("b1");
    // list2.insert("c1");
    // list2.insert("d1");
    // list2.insert("e1");
    // list2.insert("f1");
    // list2.insert("g1");
    // list2.insert("g1");
    // list2.insert("g1");
    // list2.insert("h1");
    // list2.insert("i1");
    // list2.insert("j1");
    // list2.toString();
    // cout << list2.count("g1") << endl;
    // list2.rmoveAll("g1");
    // list2.toString();
    // cout << "Your random key is: " << list2.draw_random() << endl;
    
    // mapLL list3;
    // list3.set("abc",1);
    // list3.set("def",2);
    // list3.set("ghi",3);
    // list3.set("jkl",1);
    // list3.toString();
    // cout << list3.get("ghi") << endl;
    // cout << list3["ghi"] << endl;
    // list3.rmove("jkl");
    // list3.toString();
    
    // mmapLL list4;
    // list4.set("abc",1234567890);
    // list4.set("def", 456);
    // list4.set("abc", 21234);
    // list4.set("def", 120);
    // list4.set("abc", 34326);
    // list4.toString();
    // int *l5int = list4.getAll("abc");
    // int getAllArray[] = {*(l5int)};
    // for(int i = 0; i < list4.count("abc"); i++){
    //     cout << *(l5int + i) << " ";
    // }
    // cout << endl;
    
    return 0;
}