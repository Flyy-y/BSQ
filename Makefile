# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fly <fly@flyy.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 14:18:33 by fly               #+#    #+#              #
#    Updated: 2018/03/08 03:23:55 by fly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET	= bsq

SRC_DIRS	= ./src
INC_DIRS	= ./includes

BUILD_DIR	= ./build

SRCS	= $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c)
OBJS	= $(SRCS:%=$(BUILD_DIR)/%.o)

CC			= g++
INC_FLAGS	= $(addprefix -I,$(INC_DIRS))
CCFLAGS	= $(INC_FLAGS) -W -Wall -Wextra -pedantic -std=c++11

RM		= rm -f
MKDIR	= mkdir -p

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR) $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) $(CCFLAGS) -o $(TARGET) $(OBJS)

debug:
		$(CC) $(CFLAGS) -g -o $(NAME).debug $(SRCS)

clean:
	$(RM) -r $(BUILD_DIR)

fclean:	clean
	$(RM) $(TARGET)

re:	fclean all