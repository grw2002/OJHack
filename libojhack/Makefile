CXX = c++
CXXFLAGS = -fPIC -O2 -Wall -Wextra
LDFLAGS = $(CXXFLAGS) -shared
TARGET = libojhack.so
SRCS = ojhack.cpp
# build directory for objects and final library
BUILD_DIR = build
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

install: $(TARGET)
	cp $(TARGET) /usr/local/lib/
	ldconfig

.PHONY: install

uninstall:
	rm -f /usr/local/lib/$(TARGET)
	ldconfig

.PHONY: uninstall
