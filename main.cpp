#include <Interface.hpp>
#include <Loader.hpp>
#include <Test.hpp>
#include <Word.hpp>

// Test files
#include <iostream>
#include <stdio.h>
#include <thread>

using namespace std;

int main(int argc, const char *argv[]) {
  // add one line for test stash
  // test_load();
  // add_word_using_file();

  // histogram();

  test_main(argc, argv);

  // clear_user_data();
  // export_words_data();

  return 0;
}
