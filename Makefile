CFLAGS ?= -O2 -std=c11 -Wall -Wextra -Wpedantic

auptime: auptime.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)

.PHONY: clean
clean:
	rm -f auptime
