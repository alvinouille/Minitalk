
NAMES	= server
NAMEC	= client

SRCS	=	server.c \
			utils.c

SRCC	=	client.c \
			utils.c

OBJS    = ${SRCS:.c=.o}
OBJC    = ${SRCC:.c=.o}

OPTION = -I ./

CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} -c ${CFLAGS} ${OPTION} $< -o ${<:.c=.o}

all:		${NAMES} ${NAMEC}

${NAMES}:	${OBJS} Makefile
			${CC} -o ${NAMES} ${OBJS}

${NAMEC}:	${OBJC} Makefile
			${CC} -o ${NAMEC} ${OBJC}

clean:
			${RM} ${OBJS} ${OBJC}

fclean:		clean
			${RM} ${NAMES} ${NAMEC}

re:			fclean all

.PHONY: all clean fclean re
