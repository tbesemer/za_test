.PHONY: all
all: bit_count_test linked_list_test

.PHONY: linked_list_test
linked_list_test: linked_list_test.c
	cc -Wall -o linked_list_test linked_list_test.c

.PHONY: bit_count_test
bit_count_test:	bit_count_test.c
	cc -Wall -o bit_count_test bit_count_test.c

.PHONY:
clean:
	rm -f linked_list_test bit_count_test
