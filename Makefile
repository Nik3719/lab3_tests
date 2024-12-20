# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS := -std=c++17 -Wall -Wextra -g --coverage

# Библиотеки и флаги линковки
LFLAGS = -lgtest -lgtest_main -lpthread --coverage

# Директории проекта
OUTPUT := output
SRC := src
INCLUDE := include
LIB := lib
BUILD_DIR := build
COVERAGE_DIR := coverage_report

ifeq ($(OS),Windows_NT)
MAIN := main.exe
SOURCEDIRS := $(SRC)
INCLUDEDIRS := $(INCLUDE)
LIBDIRS := $(LIB)
FIXPATH = $(subst /,\,$1)
RM := del /q /f
MD := mkdir
else
MAIN := main
SOURCEDIRS := $(shell find $(SRC) -type d)
INCLUDEDIRS := $(shell find $(INCLUDE) -type d)
LIBDIRS := $(shell find $(LIB) -type d)
FIXPATH = $1
RM = rm -f
MD := mkdir -p
endif

# Пути к заголовочным файлам и библиотекам
INCLUDES := $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
LIBS := $(patsubst %,-L%, $(LIBDIRS:%/=%))

# Список исходных файлов и объектных файлов
SOURCES := $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))
OBJECTS := $(patsubst $(SRC)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
DEPS := $(OBJECTS:.o=.d)

# Главный бинарник
OUTPUTMAIN := $(call FIXPATH,$(OUTPUT)/$(MAIN))

ARGS :=

# Основные цели сборки
all: $(OUTPUT) $(BUILD_DIR) $(MAIN)
	@echo Executing 'all' complete!

$(OUTPUT) $(BUILD_DIR):
	$(MD) $@

$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

# Включение зависимостей
-include $(DEPS)

# Компиляция объектных файлов
$(BUILD_DIR)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -MMD $< -o $@

# Очистка проекта
.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	$(RM) $(call FIXPATH,$(DEPS))
	$(RM) -r $(COVERAGE_DIR)
	# $(RM) $(wildcard *.gcda *.gcno *.gcov)
	$(RM) $(BUILD_DIR)/*.gcda
	$(RM) $(BUILD_DIR)/*.gcov
	$(RM) $(BUILD_DIR)/*.gcno
	@echo Cleanup complete!

# Запуск тестов
run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete

# Генерация покрытия кода
# Генерация покрытия кода
coverage: run
	@echo "Capturing coverage data..."
	lcov --capture --directory $(BUILD_DIR) --output-file coverage.info --ignore-errors inconsistent || exit 1
	
	@echo "Filtering relevant files for coverage..."
	lcov --extract coverage.info '*/src/*' --output-file coverage_filtered.info || exit 1
	
	@echo "Demangling symbols..."
	cat coverage_filtered.info | c++filt > coverage_demangled.info || exit 1
	
	@echo "Generating HTML coverage report..."
	genhtml coverage_filtered.info --output-directory $(COVERAGE_DIR) || exit 1
	
	@echo "Coverage report generated at $(COVERAGE_DIR)/index.html"


