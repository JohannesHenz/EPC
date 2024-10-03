# Variablen
CXX = clang++              # Der C++-Compiler (Clang++)
CXXFLAGS = -Wall -Wextra -std=c++17  # Compiler-Optionen für Warnungen und C++17
TARGET = main              # Name der Ausgabedatei (Executable)
SRCS = main.cpp newString.cpp  # Quellcodedateien
OBJS = $(SRCS:.cpp=.o)    # Objektdateien (ersetze .cpp durch .o)

# Regel zum Erstellen der Ausgabedatei
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regel zum Erstellen der Objektdateien
%.o: %.cpp newString.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regel für 'make clean', um temporäre Dateien zu löschen
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean  # Markiert 'clean' als Phony-Target
