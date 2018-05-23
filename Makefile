# Compiler
CXX = g++

# flags regular
CXXFLAGSREG = --std=c++17 -Wall -Werror -pedantic -O3

#flags debug
CXXFLAGSDEB = --std=c++17 -Wall -Werror -pedantic -g3

test: *.cpp
	$(CXX) $(CXXFLAGSREG) $^ -o $@

debug: *.cpp
	$(CXX) $(CXXFLAGSDEB) $^ -o test_debug

test_debug: *.cpp
	$(CXX) $(CXXFLAGSDEB) $^ -o $@

.PHONY: clean
clean:
	-rm -f test test_debug
