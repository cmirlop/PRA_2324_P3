bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableentry.cpp TableEntry.h
bin/testHashTable: TableEntry.h testHashTable.cpp HashTable.h Dict.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp HashTable.h Dict.h 
	./bin/testHashTable

bin/testBStree: BSNode.h BSTree.h testBStree.cpp
	mkdir -p bin
	g++ -o bin/testBStree testBStree.cpp BSNode.h BSTree.h
	./bin/testBStree 


clean:
	rm -rf *.o *.gch bin
