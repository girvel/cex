run:
    cmake . && make && ./cex

test:
    cd framework/tests; cmake . && make && ./cex_tests
