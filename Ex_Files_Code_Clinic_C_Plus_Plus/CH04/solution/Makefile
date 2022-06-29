# Instrument Makefile by Olivia Stone for Code Clinic: C++
CC		= g++
TARGET	= Instrument
SRC		= InstrumentWinMain.cpp Instrument.cpp
LDLIBS	= -lao

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(LDLIBS)

.PHONY: clean
clean:
	rm -f $(TARGET)