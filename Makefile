# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fly <fly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 14:18:33 by fly               #+#    #+#              #
#    Updated: 2018/03/09 16:42:06 by fly              ###   ########.fr        #
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
CFLAGS		= $(INC_FLAGS) -W -Wall -Wextra -pedantic -std=c++11 -m64

RM		= rm -f
MKDIR	= mkdir -p

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

debug:
	$(CC) $(CFLAGS) -g -o $(TARGET).debug $(SRCS)

clean:
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(TARGET)

re: fclean all