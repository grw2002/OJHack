CXX = c++
TESTCXXFLAGS = -DOJHACK_DEBUG -fPIC -O2 -Wall -Wl,-rpath="./build" -Wextra
CXXFLAGS = -fPIC -O2 -Wall -Wextra
LDFLAGS = $(CXXFLAGS) -shared
TARGET = libojhack.so
SRCS = ojhack.cpp
TEST_SRCS = test/test_qsort.cpp
TEST_BIN = $(BUILD_DIR)/test-qsort
# build directory for objects and final library
BUILD_DIR = build
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET)

test: all $(TEST_BIN)
	@echo "Running test..."
	@$(TEST_BIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(LDFLAGS) -o $@ $^

$(TEST_BIN): $(BUILD_DIR) | $(BUILD_DIR)
	$(CXX) $(TEST_SRCS) -DOJHACK_DEBUG $(CXXFLAGS) -lojhack -L$(BUILD_DIR) -o $@

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean test
test: CXXFLAGS = $(TESTCXXFLAGS)

install: $(TARGET)
	cp $(TARGET) /usr/local/lib/
	ldconfig

.PHONY: install

uninstall:
	rm -f /usr/local/lib/$(TARGET)
	ldconfig

.PHONY: uninstall
