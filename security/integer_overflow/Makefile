build:
# use 32 bit to reduce memory usage (char * 4 byte instead of 8)
	clang -fsanitize=fuzzer,address -g -m32 test.c -o build

test: build
	ASAN_OPTIONS="allocator_may_return_null=1" ./build

test-dict: build
	ASAN_OPTIONS="allocator_may_return_null=1" ./build -dict=test.dict

test-data: build
	ASAN_OPTIONS="allocator_may_return_null=1" ./build test.data

clean:
	rm -f build crash-* oom-*
