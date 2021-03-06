##
## Makefile for Makefile in /home/Epitech
##
## Made by moriss_h
## Login   <moriss_h@epitech.net>
##
## Started on  Sun Jun  9 03:35:24 2013 Hugues
## Last update Fri Mar 14 00:11:31 2014 Hugues
##

SRC			=	file.c \
				dereference.c \
				section64.c \
				section32.c \
				section_spec64.c \
				section_spec32.c \
				section_search.c \
				symbol64.c \
				symbol32.c \
				symbol_type64.c \
				symbol_type32.c \
				elf.c

SRCNM		=	nm/main.c \
			nm/display_info.c \
			nm/sort_sym.c

SRCOBJDUMP	=	objdump/main.c \
			objdump/dump.c \
			objdump/display_info.c \

SRCNM		+=	$(SRC)
SRCOBJDUMP	+=	$(SRC)

CC		=	gcc

RM		=	rm -f

NM		=	my_nm
OBJDUMP		=	my_objdump
NAME			=	NM/OBJDUMP

OBJDIR		=	obj/
SRCDIR		=	src/
INCDIR		=	inc/

CFLAGS		+=	-I$(INCDIR) -g
CFLAGS		+=	-Wall -Wextra -Winit-self
CFLAGS		+=	-Wunused-function -pipe -Winit-self

LDFLAGS		+=	-Wl,-O1

OBJNM		=	$(patsubst %.c,${OBJDIR}%.o, $(SRCNM))
OBJOBJDUMP	=	$(patsubst %.c,${OBJDIR}%.o, $(SRCOBJDUMP))

dummy		:=	$(shell test -d $(OBJDIR) || mkdir -p $(OBJDIR))
dummy		:=	$(shell test -d $(SRCDIR) || mkdir -p $(SRCDIR))
dummy		:=	$(shell test -d $(INCDIR) || mkdir -p $(INCDIR))

.PHONY:	all clean fclean re help $(NAME) nm objdump

$(NAME):	$(OBJDUMP) $(NM)

all:	$(NAME)

$(OBJDIR)%.o:		$(patsubst %.c,${SRCDIR}%.c, %.c)
			@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
			@echo -e "Compiling $< { $(CFLAGS) }" | sed 's/^-e //' \
			| sed 's/[-a-zA-Z]\+/\x1B[31m&\x1B[0m/g' \
			| sed 's/[A-Z]\+/\x1B[32m&\x1B[0m/g' \
			| sed 's/[{}]/\x1B[34m&\x1B[0m/g' \
			| sed 's/[─┬─├─└│]/\x1B[35m&\x1B[0m/g'
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDUMP):	$(OBJOBJDUMP)
	@echo -e "Linking $@ { $(LDFLAGS) }" | sed 's/^-e //' \
	| sed 's/[-a-zA-Z]\+/\x1B[34m&\x1B[0m/g'
	@$(CC) $(LDFLAGS) -o $(OBJDUMP) $(OBJOBJDUMP)

$(NM):	$(OBJNM)
	@echo -e "Linking $@ { $(LDFLAGS) }" | sed 's/^-e //' \
	| sed 's/[-a-zA-Z]\+/\x1B[34m&\x1B[0m/g'
	@$(CC) $(LDFLAGS) -o $(NM) $(OBJNM)

nm:	$(NM)

objdump:	$(OBJDUMP)

clean:
	@echo -e "Removing object !" | sed 's/^-e //' \
	| sed 's/[-a-zA-Z]\+/\x1B[35m&\x1B[0m/g'
	@$(RM) $(OBJOBJDUMP) $(OBJNM)

fclean:	clean
	@echo -e "Removing ${NM} ${OBJDUMP} !" | sed 's/^-e //' \
	| sed 's/[-a-zA-Z]\+/\x1B[36m&\x1B[0m/g'
	@$(RM) $(OBJDUMP) $(NM)

re:	fclean all

help:
	@echo -e "\033[37mTarget available: all, clean, fclean\033[00m" \
	| sed 's/^-e //'
