
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_dir(const char *path) {
    DIR *dir;
    struct dirent *ent;
    char full_path[PATH_MAX];

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            // skip . and ..
            continue;
        }

        sprintf(full_path, "%s/%s", path, ent->d_name);

        if (ent->d_type == DT_DIR) {
            // subdirectory, recurse
            print_dir(full_path);
        } else {
            // file, print name
            printf("%s\n", full_path);
        }
    }

    closedir(dir);
}

int main() {
    print_dir("/mnt/d/Console Games/RomFS/Splatoon 3 9.1.0 RomFS");
    return 0;
}