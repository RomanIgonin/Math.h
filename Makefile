NAME = s21_math.a

LIST = s21_math.c

UNIT = s21_unit

OBJECT = $(patsubst %.c,%.o, $(LIST))

FLAGS = -std=c11 -Wall -Wextra -Werror
G_FLAGS = -std=c11 --coverage

all : $(NAME)

$(NAME) : $(OBJECT)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

clean : 
	@rm -f $(OBJECT) $(UNIT)
	@rm -rf ./*.o ./*.gcno ./*.gcda ./*.html *.css ./s21_unit *.dSYM ./*.out

test : $(NAME)
	@gcc $(FLAGS) $(G_FLAGS) $(UNIT).c -L. s21_math.a -lcheck -o $(UNIT)
	./$(UNIT)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

gcov_report : test
	gcovr -dr . --html-details -o gcov_report.html
	open gcov_report.html
