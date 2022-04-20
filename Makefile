COMPILER=g++
NAME=main

main:$(NAME).cpp
	$(COMPILER) -Wall -g -o $(NAME) $(NAME).cpp
