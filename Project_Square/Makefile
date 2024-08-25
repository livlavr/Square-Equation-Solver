CXX = gcc-14
OBJECTS = color_print.o double_compare.o quadratic_equation.o solve_equation.o unit_test.o user_communication.o
SRC = *cpp
TARGET = project_square

$(TARGET) : $(OBJECTS)
	@$(CXX) $^ -o $(TARGET)
	@printf "\033[1;32m$(TARGET) COMPILED\033[0m\n"

$(OBJECTS) : %.o : %.cpp
	$(CXX) -c $^ -o $@

ded : $(SRC)
	$(CXX) $^ -o $(TARGET) -D _DEBUG -ggdb2 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla

clean :
	rm -f $(TARGET) *.o
	@printf "\033[1;33m$(TARGET) CLEANED\033[0m\n"
