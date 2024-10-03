# Variablen
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17  # Compiler-Flags
OBJS = main.o String.o               # Objektdateien
TARGET = main                        # Name der ausführbaren Datei

# Regel zum Erstellen der ausführbaren Datei
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Regel zum Erstellen der Objektdateien
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regel zum Bereinigen von Objektdateien und der ausführbaren Datei
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean  # Mach 'all' und 'clean' zu phony targets