SRC_NAME = Boucledebut.cpp \
						Bouclefin.cpp \
						Decroct.cpp \
						Decrptr.cpp \
						Incroct.cpp \
						Incrptr.cpp \
						Inoct.cpp \
						Outoct.cpp \
						main.cpp \


INC_PATH = ./
OBJ_PATH = ./obj/

NAME = some_functions

CC = clang++

CFLAGS = -Wall -Werror -Wextra

SRC_PATH = ./

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
