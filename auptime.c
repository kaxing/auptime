#define _POSIX_C_SOURCE 200809L
#include <inttypes.h>
#include <stdio.h>
#include <time.h>

#ifndef __linux__
#error "auptime requires Linux CLOCK_MONOTONIC semantics"
#endif

static void format_uptime(char *out, size_t size, uintmax_t seconds)
{
    snprintf(out, size, "up %jud %02ju:%02ju:%02ju",
             seconds / 86400, seconds / 3600 % 24,
             seconds / 60 % 60, seconds % 60);
}

int main(int argc, char **argv)
{
    char out[80];
    if (argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    struct timespec now;
    if (clock_gettime(CLOCK_MONOTONIC, &now) == -1) {
        perror("clock_gettime");
        return 1;
    }
    format_uptime(out, sizeof(out), (uintmax_t)now.tv_sec);
    return puts(out) == EOF;
}
