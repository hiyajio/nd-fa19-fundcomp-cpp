
CMP = g++
EXT = -std=c++17
CLASS = rational
MAIN = rationalmain
EXEC = runrational

$(EXEC): $(CLASS).o $(MAIN).o
	$(CMP) $(CLASS).o $(MAIN).o -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(EXT) $(CLASS).cpp -o $(CLASS).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c $(EXT) $(MAIN).cpp -o $(MAIN).o

clean:
	rm *.o
	rm $(EXEC)

