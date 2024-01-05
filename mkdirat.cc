#include <cstdlib>
#include <cstring>
#include <fcntl.h> /* Definition of AT_* constants */
#include <sys/stat.h>

// int mkdirat(int dirfd, const char *pathname, mode_t mode);

int main(int argc, char** argv) {
    char* name = argv[1];

    int ret = mkdirat(AT_FDCWD, name, S_IRWXU | S_IRWXG | S_IRWXO);

    return ret;
}