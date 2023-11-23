bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableentry.cpp TableEntry.h

clean:
	rm -rf *.o *.gch bin
