CC = gcc

LIB = libmalloc.o

FLAGS = -Wall -Wextra -Werror -Qunused-arguments

SRCS =  $(shell find ./srcs -type f -name '*.c')

INCLUDES = ./includes

OBJS = $(SRCS:.c=.o)

PWD = $(shell pwd)

.c.o:
	$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) -fPIC -shared -o $(LIB) $(OBJS)

docker:
	@docker build -t ft_malloc_image .
	@docker run  --name ft_ls_container -it --rm -v $(PWD):/ft_malloc ft_malloc_image /bin/bash

clean:
	rm -rf $(OBJS)
	rm -rf $(LIB)
	
fclean:	clean
	-docker image rm ft_malloc_image

re: fclean all