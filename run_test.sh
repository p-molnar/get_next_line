#!/usr/bin/env bash

for ((i=0; i <= 200; i++))
do
	echo "gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$i *.c *.h && ./a.out"
	echo ""
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$i *.c *.h && ./a.out > text_buff_$i.txt
	diff text_buff_$i.txt test_files/laid.txt
	rm text_buff_$i.txt
done
