NAME = libasm.a
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
NASM = nasm
NASMFLAGS = -f elf64
OBJS = $(SRCS:.s=.o)

all : $(NAME)
	rm -rf $(OBJS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	rm -rf $(OBJS)

.PHONY: re fclean clean all
