.PHONY: build
build:
	clang -Weverything -fsanitize=undefined -fno-sanitize-recover=undefined test.c -o test_c
	rustc test.rs -o test_rs

.PHONY: test
test: build
	-./test_c 4
	-./test_rs 4

.PHONY: clean
clean:
	rm -f test_rs test_c
