#!/bin/bash
STUDENT_NAME="./ai"
BUFF_NAME="./VREP/n4s_buffer"
N4S_NAME="./VREP/n4s"

FIFONAME=".fifo_n4s"
trap "rm -f $FIFONAME" EXIT

if [ ! -p $FIFONAME ]; then
  mkfifo $FIFONAME
fi

"./$STUDENT_NAME" < $FIFONAME |  "./$BUFF_NAME" | "./$N4S_NAME" $@ 2> /dev/null |  "./$BUFF_NAME" > $FIFONAME
