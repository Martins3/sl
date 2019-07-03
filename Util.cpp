#include<Util.hpp>
#include<iostream>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <assert.h>
#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <cstring>

std::string Util::exec(const std::string cmd){
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}

void Util::edit_file(const char *file) {
  char path[200];
  strcpy(path, file);
  char program[] = "nvim";
  char *args[] = {program, path, NULL};
  int status;
  if (!fork()) {
    execvp("nvim", args);
  }
  wait(&status);
}
