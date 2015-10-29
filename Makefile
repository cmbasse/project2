output: main.o SetArr.o MSetArr.o MapArr.o MMapArr.o node.o setLL.o MSetLL.o mapLL.o mmapLL.o setHM.o msetHM.o mapHM.o mmapHM.o
	g++ main.o SetArr.o MSetArr.o MapArr.o MMapArr.o node.o setLL.o MSetLL.o mapLL.o mmapLL.o setHM.o msetHM.o mapHM.o mmapHM.o -o output -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

#Dynamic Array Files
SetArr.o: SetArr.cpp
	g++ -c SetArr.cpp
	
MSetArr.o: MSetArr.cpp
	g++ -c MSetArr.cpp
	
MapArr.o: MapArr.cpp
	g++ -c MapArr.cpp
	
MMapArr.o: MMapArr.cpp
	g++ -c MMapArr.cpp
	
#Linked List Files
node.o: node.cpp node.h
	g++ -c node.cpp -std=c++11

setLL.o: setLL.cpp setLL.h
	g++ -c setLL.cpp -std=c++11
	
MSetLL.o: MSetLL.cpp MSetLL.h
	g++ -c MSetLL.cpp -std=c++11
	
mapLL.o: mapLL.cpp mapLL.h
	g++ -c mapLL.cpp -std=c++11
	
mmapLL.o: mmapLL.cpp mmapLL.h
	g++ -c mmapLL.cpp -std=c++11

#Hash Files

setHM.o: setHM.cpp
	g++ -c setHM.cpp
	
msetHM.o: msetHM.cpp
	g++ -c msetHM.cpp
	
mapHM.o: mapHM.cpp
	g++ -c mapHM.cpp
	
mmapHM.o: mmapHM.cpp
	g++ -c mmapHM.cpp
	
clean:
	rm *.o output