NAME		=	libftprintf.a

SRCS		=	ft_printf.c ft_info.c ft_info2.c ft_getlen.c\
				print_add.c print_char.c print_nbr.c print_nbr2.c print_hex.c\
				print_str.c print_unbr.c print_add2.c print_str2.c

LNAME		=	libft.a

LDIR		=	libft/

CC			=	gcc
RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -c
CFLAGS2		=	-lft -L$(NAME)

OBJS		=	$(SRCS:%.c=%.o)

all			:	$(LNAME) $(NAME)

$(NAME) 	:	$(OBJS) $(LNAME)
	cp $(LDIR)/$(LNAME) ./$(NAME)
	ar rsc $(NAME) $(OBJS)

$(LNAME)	:
	@make -C $(LDIR) all

$(OBJS) 	:
	$(CC) $(CFLAGS) $(SRCS)

clean		:
	$(RM) $(OBJS)
	@make -C $(LDIR) clean

fclean		:	clean
	$(RM) $(NAME)
	@make -C $(LDIR) fclean
	$(RM) $(TEST_FILE:.c=.out)

re			:	fclean all

TEST_FILE = test.c

debug_make	:	$(NAME)
	$(RM) $(TEST_FILE:.c=.out)
	$(CC) -g $(TEST_FILE) $(SRCS) $(LDIR)/*.c -o $(TEST_FILE:.c=.out) -L. -lftprintf

.PHONY		:	all clean fclean re libft libftprintf debug_make
