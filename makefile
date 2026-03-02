CC = g++
CFLAGS = -Wall -O2
LDFLAGS = -lm

OUTPUTS = spiro1.pdf spiro2.pdf spiro3.pdf spiro4.pdf spiro5.pdf

all: $(OUTPUTS)

spiro: spiro.cpp
	$(CC) $(CFLAGS) -o spiro spiro.cpp $(LDFLAGS)

spiro1.pdf: spiro inputs/input1.txt
	./spiro 96 10.0 < inputs/input1.txt | jgraph -P | ps2pdf - spiro1.pdf

spiro2.pdf: spiro inputs/input2.txt
	./spiro 96 10.0 < inputs/input2.txt | jgraph -P | ps2pdf - spiro2.pdf

spiro3.pdf: spiro inputs/input3.txt
	./spiro 105 10.0 < inputs/input3.txt | jgraph -P | ps2pdf - spiro3.pdf

spiro4.pdf: spiro inputs/input4.txt
	./spiro 96 10.0 < inputs/input4.txt | jgraph -P | ps2pdf - spiro4.pdf

spiro5.pdf: spiro inputs/input5.txt
	./spiro 96 10.0 < inputs/input5.txt | jgraph -P | ps2pdf - spiro5.pdf

clean:
	rm -f spiro *.pdf *.jgr

.PHONY: all clean
	MAKEEOF
