#include "setLL.h"
#include "MSetLL.h"
#include "mapLL.h"
#include "mmapLL.h"
#include "MapArr.cpp"
#include "mapHM.cpp"
#include "MMapArr.cpp"
#include "mmapHM.cpp"
#include "MSetArr.cpp"
#include "msetHM.cpp"
#include "setHM.cpp"
#include "SetArr.cpp"
#include <ctime>

using namespace std;
//Dynamic array is the fastest for all data structures
int main() {
    //g++ main.cpp setLL.cpp setLL.h node.cpp node.h MSetLL.h MSetLL.cpp mapLL.cpp mapLL.h mmapLL.cpp mmapLL.h -std=c++11
    
    clock_t tStart = clock();
    
    cout << "List 1" << endl;
    setLL list1;
    list1.insert("L1 A");
    list1.insert("L1 B");
    list1.insert("L1 C");
    list1.toString();
    list1.rmove("L1 B");
    cout << "Is L1 B in List 1 " << list1.is_in("L1 B") << endl;
    cout << "Is List 1 empty " << list1.is_empty() << endl;
    
    cout<<endl  << "List 5" << endl;
    setLL list5;
    list5.insert("L1 A");
    list5.insert("L5 B");
    list5.insert("L5 C");
    list5.toString();
    setLL list6 = list1.unin(list5);
    cout<<endl << "List 6" << endl;
    list6.toString();
    cout << "Is L5 A in list 6 " << list6.is_in("L5 A 3") << endl;
    cout << endl << "List 7" << endl;
    setLL list7 = list1.intersection(list5);
    list7.toString();
    
    printf("Time taken for setll: %.10fs\n", (float)(clock() - tStart)/CLOCKS_PER_SEC);
     
    cout << endl << endl;


clock_t tStart2 = clock();

    cout<<endl  << "List 2" << endl;
    MSetLL list2;
    list2.insert("a1");
    list2.insert("b1");
    list2.insert("c1");
    list2.insert("d1");
    list2.insert("e1");
    list2.insert("f1");
    list2.insert("g1");
    list2.insert("g1");
    list2.insert("g1");
    list2.insert("h1");
    list2.insert("i1");
    list2.insert("j1");
    list2.toString();
    cout << "Count of g1: " << list2.count("g1") << endl;
    list2.rmoveAll("g1");
    cout << "Is g1 in List 2 " << list2.is_in("g1") << endl;
    list2.toString();
    cout << "Your random key is: " << list2.draw_random() << endl;
    
    
    printf("Time taken for msetll: %.10fs\n", (float)(clock() - tStart2)/CLOCKS_PER_SEC);
    
    cout << endl << endl;
    
    
    clock_t tStart3 = clock();
    cout << endl << "List 3" << endl;
    mapLL list3;
    list3.set("abc",1);
    list3.set("def",2);
    list3.set("ghi",4159);
    list3.set("jkl",1);
    list3.toString();
    cout << "Value of ghi using get: " << list3.get("ghi") << endl;
    cout << "Value of ghi using []: " << list3["ghi"] << endl;
    list3.rmove("jkl");
    list3.toString();
    
     printf("Time taken for map linked list: %.10fs\n", (float)(clock() - tStart3)/CLOCKS_PER_SEC);
     
     cout << endl << endl;
     
     clock_t tStart4 = clock();
    
    cout << endl << "List 4" << endl;
    mmapLL list4;
    list4.set("abc",123);
    list4.set("kmno", 456);
    list4.set("abc", 789);
    list4.set("def", 12);
    list4.toString();
    cout << "Count for abc is " << list4.count("abc") << " and the values are: " << endl;
    int *l5int = list4.getAll("abc");
    for(int i = 0; i < list4.count("abc"); i++){
        cout << *(l5int + i) << " ";
    }
    cout << endl;
    list4.rmoveAll("abc");
    list4.toString();
    cout << endl << endl;
    
     printf("Time taken for mmapLL: %.10fs\n", (float)(clock() - tStart4)/CLOCKS_PER_SEC);
     
     cout << endl << endl;
     
    //Map implemented with a dynamic array
    
     clock_t tStart5 = clock();
    MapArr maria;
    maria.set("ah", 1);
    maria.set("aa", 2);
    maria.set("cl", 2);
    maria.set("dl", 2);
    maria.set("el", 2);
    maria.set("fl", 2);
    maria.set("gl", 2);
    maria.set("hl", 2);
    maria.set("il", 2);
    cout << "is ah in maria? " << maria.is_in("ah") << endl;
    cout << "removing ah" << endl;
    maria.rmove("ah");
    cout << "is ah in maria? " << maria.is_in("ah") << endl;
    cout << "Get aa using [] " << maria["aa"] << endl;
    cout << "Get il " << maria.get("il") << endl;
    cout << endl;
    
     printf("Time taken for map array: %.10fs\n", (float)(clock() - tStart5)/CLOCKS_PER_SEC);
     
     cout << endl << endl;
    
    //Map implemented with a hashmap
    
    clock_t tStart6 = clock();
    mapHM andy;
    andy.set("ah", 1);
    andy.set("aa", 2);
    andy.set("cl", 2);
    andy.set("dl", 2);
    andy.set("el", 2);
    andy.set("hl", 2);
    andy.set("il", 2);
    maria.set("as", 2);
    cout << "Removing aa " << endl;
    maria.rmove("aa");
    cout << "Is aa in andy? " << andy.is_in("aa") << endl;
    cout << "Get value for cl " << andy.get("cl") << endl;
    cout << "Get value for cl with [] " << andy.get("cl") << endl;
    
     printf("Time taken for map hashmap: %.10fs\n", (float)(clock() - tStart6)/CLOCKS_PER_SEC);
     
     cout << endl << endl;
    
    
    //Multiset implemented with a dynamic array
     
     clock_t tStart7 = clock();
     MSetArr wtf;
     wtf.insert("ab");
     wtf.insert("cd");
     wtf.insert("dd");
     wtf.insert("ee");
     wtf.insert("zz");
     wtf.insert("y");
     wtf.insert("y");
     wtf.insert("y");
     cout << "How many y in wtf? " << wtf.count("y") << endl;
     cout << "Remove one y " << endl;
     wtf.rmoveOne("y");
     cout << "How many y in wtf? " << wtf.count("y") << endl;
     cout << "Is ab in wtf? " << wtf.is_in("ab") << endl;
     cout << "Remove all y " << endl;
     wtf.rmoveAll("y");
     cout << "How many y in wtf? " << wtf.count("y") << endl;
     cout << wtf.is_empty() << endl;
     
      printf("Time taken for multiset array: %.10fs\n", (float)(clock() - tStart7)/CLOCKS_PER_SEC);
     
     cout << endl << endl;
    //Multiset implemented with a hashmap
    
    clock_t tStart8 = clock();
    msetHM b;
    b.insert("ah");
    b.insert("ah");
    b.insert("ac");
    b.insert("ad");
    cout << "Is ah in b? " << b.is_in("ah") << endl;
    cout << "Is zz in b? " << b.is_in("zz") << endl;
    cout << "Draw a random from b " << b.draw_random() << endl;
    cout << "Is b empty? " << b.is_empty() << endl;
    cout << "How many times is ah in b? " << b.count("ah") << endl;
    cout << "Remove all ah " << endl;
    b.rmoveAll("ah");
    cout << "How many times is ah in b now? " << b.count("ah") << endl;
    cout << "Remove ac " << endl;
    b.rmoveOne("ac");
    cout << "Is ac in b still? " << b.is_in("ac") << endl;
    
      printf("Time taken for msetHM: %.10fs\n", (float)(clock() - tStart8)/CLOCKS_PER_SEC);
      
      cout << endl << endl;
    
    
    //Set implemented with a dynamic array
     clock_t tStart9 = clock();
     SetArr novocin;
     cout<<"Is novocin empty? "<< novocin.is_empty()<<endl;
     novocin.insert("ah");
     novocin.insert("ha");
     novocin.insert("la");
     cout << "Is ab in novocin? "<< novocin.is_in("ab") << endl;
     cout << "Is ha in novocin? "<< novocin.is_in("ha") << endl;
    novocin.rmove("ah");
    cout << "Is ha in novocin? "<< novocin.is_in("ha") << endl;
     
     printf("Time taken for SetArr: %.10fs\n", (float)(clock() - tStart9)/CLOCKS_PER_SEC);
     
     cout << endl << endl;
     //Set dynamic array is the fastest so far
     
     clock_t tStart10 = clock();
     MMapArr x;
     x.set("hey", 6);
     x.set("hey", 7);
     x.set("hey", 8);
     x.set("hi", 9);
     cout << "Count for hey " << x.count("hey") << endl;
    cout << "Get all for hey " << x.getAll("hey") << endl;
    cout << "Removing all hey " << endl;
    x.rmoveall("hey");
    cout << "Count for hey " << x.count("hey") << endl;
      printf("Time taken for multimap array: %.10fs\n", (float)(clock() - tStart10)/CLOCKS_PER_SEC);
      
      cout << endl << endl;
     
     
     //Multimap implemented with a hashmap
     
      clock_t tStart11 = clock();
     cout << endl << endl;
    mmapHM u;
    u.set("ah", 1);
    u.set("ah", 3);
    u.set("ah", 4);
    u.set("ah", 5);
    u.set("ah", 5);
    u.set("ah", 6);
    u.set("ah", 7);
    u.set("ah", 1);
    u.set("ah", 3);
    u.set("ah", 6);
    u.set("ah", 7);
    u.set("yay", 12);
    cout << "count all the ah " << u.count("ah") << endl;
    cout << "Get all ah's " << u.getAll("ah") << endl;
    cout << "Remove one ah, 3 " << endl;
    u.removeOnePair("ah", 3); 
    cout << "count all the ah " << u.count("ah") << endl;
    cout << "Remove all ah's " << endl;
    u.rmoveAll("cl");
    cout << "count all the ah " << u.count("ah") << endl;
    
      printf("Time taken for mmapHM: %.10fs\n", (float)(clock() - tStart11)/CLOCKS_PER_SEC);
      
      cout << endl << endl;
    
    //Set implemented with a hashmap
    
     clock_t tStart12 = clock();
    setHM r;
    r.insert("a");
    r.insert("b");
    r.insert("y");
    setHM y;
    y.insert("z");
    y.insert("y");
    y.insert("x");
    cout << "Is aqa in r? " << r.is_in("aqa") << endl;
    cout << "Is a in r? " << r.is_in("a") << endl;
    r.rmove("a");
    cout << "Is a in r after we removed it? " << r.is_in("a") << endl;
    setHM jk = r.unin(y);
    cout << "jk is the union of r and y" << endl;
    cout << "Is a in jk? " << jk.is_in("a") << endl;
    cout << "Is b in jk? " << jk.is_in("b") << endl;
    cout << "Is y in jk? " << jk.is_in("y") << endl;
    cout << "Is z in jk? " << jk.is_in("z") << endl;
    cout << "Is y in jk? " << jk.is_in("y") << endl;
    cout << "Is x in jk? " << jk.is_in("x") << endl;
    cout << "Is jk empty? " << jk.is_empty() << endl;
    
    setHM kj = r.intersection(y);
    cout << "Is a in kj? " << kj.is_in("a") << endl;
    cout << "Is y in kj? " << kj.is_in("y") << endl;
    cout << "Is z in kj? " << kj.is_in("z") << endl;
    cout << "Is kj empty? " << kj.is_empty() << endl;
    
       printf("Time taken for setHM: %.10fs\n", (float)(clock() - tStart12)/CLOCKS_PER_SEC);
    
    return 0;
}