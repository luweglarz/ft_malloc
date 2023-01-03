HOSTTYPE ?= $(shell uname -m)_$(shell uname -s)

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS =  $(shell find ./srcs -type f -name '*.c')

OBJS = $(SRCS:.c=.o)

INCLUDES = ./includes

LIB_NAME = libft_malloc.so

FULL_LIB_NAME := libft_malloc_$(HOSTTYPE).so

DOCKER_IMAGE = ft_malloc_image

PWD = $(shell pwd)

%.o : %.c
	$(CC) $(FLAGS) -fPIC -I$(INCLUDES) -c $< -o $@

all: $(FULL_LIB_NAME)

$(FULL_LIB_NAME): $(OBJS)
	make -C libft/ all
	$(CC) -shared -o $(FULL_LIB_NAME) libft/libft.a  $(OBJS)
	ln -s $(FULL_LIB_NAME) $(LIB_NAME)

docker:
	@docker build -t $(DOCKER_IMAGE) .
	@docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined --name ft_ls_container -it --rm -v $(PWD):/ft_malloc $(DOCKER_IMAGE) /bin/bash

clean:
	rm -rf $(OBJS)
	make -C libft/ fclean
	rm -rf $(LIB_NAME)
	rm -rf $(FULL_LIB_NAME)
	
fclean:	clean
	-docker image rm $(DOCKER_IMAGE)

re: fclean all