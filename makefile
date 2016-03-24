
COMP= g++
CFLAGS= -W -Wall -ansi -pedantic -lboost_regex -lboost_unit_test_framework -std=c++11
LINK= g++
LDFLAGS= -lboost_regex -lboost_unit_test_framework
INCLUDES= -I /usr/include/boost
LIBS= -L /usr/lib

SRCDIR= ./
BUILDDIR= ./
BINDIR = ./
EXE= lut

SOURCES= $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJECTS= $(patsubst $(SRCDIR)%,$(BUILDDIR)%, $(SOURCES:.cpp=.o))
TARGET = $(addprefix $(BINDIR), $(EXE))

CLEAN= clean
ECHO= @echo
RM= @rm
RMFLAGS= -rf

.PHONY: $(CLEAN)

$(TARGET): $(OBJECTS)
	$(ECHO) "Edition des liens de <$(EXE)>"
	@mkdir -p $(BINDIR)
	$(LINK) $(INCLUDES) $(LIBS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)
	$(ECHO)

$(BUILDDIR)%.o: $(SRCDIR)*%.cpp
	$(ECHO) "Compilation de <$<>"
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(dir $@)
	$(COMP) $(INCLUDES) -o $@ -c $< $(CFLAGS)
	$(ECHO)

$(CLEAN):
	$(RM) $(RMFLAGS) $(OBJECTS) core
