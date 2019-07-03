#ifndef TEST_LODER_HPP
#define TEST_LODER_HPP

#include <Loader.hpp>
#include <Printer.hpp>
#include <iomanip>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>

#include <Interface.hpp>
#include <string>

using namespace std;
using json = nlohmann::json;

void store_data();

int test_main(int argc, const char *argv[]) {
  Loader &L = Loader::getInstance();
  L.load_words();
  Interface &I = Interface::getInstance();
  if (I.parse_options(argc, argv) == 0) {
    // no every parameter should call handle
    I.handle();
  }
  
 L.store();
  return 0;
}

void clear_data() { Loader::getInstance().store(); }

void export_words_data() {
  auto &L = Loader::getInstance();
  L.load_words();
  for (auto &w : L.getWords()) {
    cout << w.get_word() << endl;
  }
}

void histogram() {
  // string str= "Added Words";
  // int left_indent = str.size();
  // int num = 202;
}

#endif
