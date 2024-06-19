# 定义编译器
CXX = g++

# 定义编译选项
CXXFLAGS = -Wall -std=c++11

# 目标文件
TARGET = main

# 对象文件
OBJS = main.o Management.o Person.o Book.o

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# 编译规则
main.o: main.cpp Management.h Person.h Book.h LibraryItem.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Management.o: Management.cpp Management.h LibraryItem.h
	$(CXX) $(CXXFLAGS) -c Management.cpp

Person.o: Person.cpp Person.h LibraryItem.h
	$(CXX) $(CXXFLAGS) -c Person.cpp

Book.o: Book.cpp Book.h LibraryItem.h
	$(CXX) $(CXXFLAGS) -c Book.cpp

# 清理规则
.PHONY: clean
clean:
	del /Q main.o Management.o Person.o Book.o main.exe