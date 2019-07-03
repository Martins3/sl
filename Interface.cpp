#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <User.hpp>
#include <Interface.hpp>
#include <Loader.hpp>
#include <Printer.hpp>
#include <Util.hpp>
#include <api/Strategy.hpp>

using namespace std;

void Interface::parse_word_id() {
  if (User::show_word_id) {
    word_id = strtol(optarg, NULL, 10);
    if (word_id == errno) {
      std::cerr << "word id should be a integer" << std::endl;
      exit(1);
    }
  } else {
    word = optarg;
  }
}

int Interface::parse_options(int argc, const char *argv[]) {
  int opt;

  while ((opt = getopt(argc, (char **)argv, "r:f:c:d:w:hs:x:it:")) != EOF) {
    switch (opt) {
    case 'i':
      interactive = true;
      break;
    case 'r':
      parse_word_id();
      forget = false;
      review = false;
      break;
    case 'f':
      parse_word_id();
      forget = true;
      review = false;
      break;
    case 'c':
      path_to_config = optarg;
      cout << "Path to configuration is : " << path_to_config << endl;
      break;
    case 'd':
      path_to_new_words = optarg;
      break;
    case 'x':
      parse_word_id();
      remove = true;
      break;
    case 'l':
      learn();
      break;
    case 's':
      parse_word_id();
      shutdown = true;
      break;
    case 'w':
      add = true;
      word = optarg;
      cout << "Added words is : " << word << endl;
      break;
    case 't':
      show_record = optarg;
      break;
    case 'h':
      fprintf(stderr, "\
usuage is:\n\
  -h show this help information\n\
  -r remember\n\
  -l learn\n\
  -f forget\n\
  -c load new configuration file\n\
  -d add a file of words\n\
  -x remove one word from database permanentely\n\
  -s forbid this word to appear recently\n\
  -a set specific bit of the word's flag\n\
  -b clear specific bit of the word's flag\n\
  -t show user learn process\n\
  -w add one word\n");
      exit(0);
    default:
      cout << endl;
      abort();
    }
  }
  return 0;
}

void Interface::handle() {
  Loader &L = Loader::getInstance();
  bool id = User::show_word_id;
  vector<Word> &words = L.getWords();

  if (show_record.size()) {
    long long int limit = 0;

    if (show_record == "day") {
      limit = 24 * 60 * 60;
    }

    if (show_record == "week") {
      limit = 7 * 24 * 60 * 60;
    }

    if (show_record == "month") {
      limit = 30 * 7 * 24 * 60 * 60;
    }

    if (show_record == "year") {
      limit = (long long int)365 * 30 * 7 * 24 * 60 * 60;
    }

    if (limit == 0) {
      cerr << "Time range are:\n\
        Day\n\
        Week\n\
        Month\n\
        Year\n ";
      return;
    }
    vector<string> table_name = {"REVIEW",
                                 "INTERACTIVE",
                                 "ADD",
                                 "REM",
                                 "FORGET",
                                 "SHUTDOWN",
                                 "REMOVE"};
    L.load_record();
    vector<int> record_nums(7, 0);
    vector<OP_Record *> &records = L.getRecords();
    time_t now = time(nullptr);
    for (auto r : records) {
      if(now - r->time_point < limit){
        record_nums[r->type] ++;
      }
    }

    Printer::histogram(table_name, record_nums);
    return;
  }

  if (interactive) {
    L.add_record(INTERACTIVE);
    Strategy::interactive(words);
    return;
  }

  if (path_to_config.size()) {
    // TODO there is no need to doing things so complex
    return;
  }

  if (path_to_new_words.size()) {
    L.add_file(path_to_new_words);
    return;
  }

  if (shutdown) {
    L.add_record(SHUTDOWN);
    if (User::show_word_id) {
      L.check_word(word_id, SHUTDOWN);
    } else {
      L.check_word(word, SHUTDOWN);
    }
    return;
  }

  if (remove) {
    L.add_record(REMOVE);
    if (User::show_word_id) {
      L.check_word(word_id, REMOVE);
    } else {
      L.check_word(word, REMOVE);
    }
    return;
  }

  // add a word
  if (add) {
    L.add_one_word(word);
    return;
  }

  if (review) {
    // just show words
    L.add_record(REVIEW);
    int count = User::show_limitation;
    Strategy::sort(words, count);

    Printer::header(id);
    for (int i = 0; i < count; i++) {
      // words[i].add_index(-1);
      Printer::word_info(words[i], id);
    }

    // show random
    int len = words.size();
    int r_limit = User::random_show_limitation;

    if (r_limit > 0) {
      // TODO
    }

    srand(time(NULL));
    for (int i = 0; i < r_limit; i++) {
      int inx = rand() % len;
      Printer::word_info(words[inx], id);
    }

    return;
  }

  // show words
  if (forget) {
    L.add_record(FORGET);
    if (User::show_word_id) {
      L.check_word(word_id, FORGET);
    } else {
      L.check_word(word, FORGET);
    }
  } else {
    L.add_record(REM);
    if (User::show_word_id) {
      L.check_word(word_id, REM);
    } else {
      L.check_word(word, REM);
    }
  }
}
