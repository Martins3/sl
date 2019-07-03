#include <Loader.hpp>
#include <Statistic.hpp>
#include <User.hpp>
#include <Word.hpp> // 用于提供friend 信息
#include <api/Strategy.hpp>

#include <fstream>
#include <iomanip>
#include <set>
#include <string>

using json = nlohmann::json;
using namespace std;

// 注意：这里的~不可以使用
const std::string Loader::config_dir = "/home/shen/Core/sl/src/";

void to_json(json &j, const OP_Record &p) {
  j = json{
      {"time", p.time_point},
      {"type", p.type},
  };
}

void from_json(const json &j, OP_Record &p) {
  j.at("time").get_to(p.time_point);
  j.at("type").get_to(p.type);
}

void to_json(json &j, const Word &p) {
  j = json{
      {"word", p.word},
      {"index", p.index},
      {"id", p.id},
      {"flag", p.flag},
      {"query_time_point", p.query_time_point},
  };
}

void from_json(const json &j, Word &p) {
  j.at("word").get_to(p.word);
  j.at("index").get_to(p.index);
  j.at("id").get_to(p.id);
  j.at("flag").get_to(p.flag);
  j.at("query_time_point").get_to(p.query_time_point);
}

void Loader::store() {
  std::ofstream outfile(config_dir + "words.txt");
  for (Word &w : words) {
    json j = w;
    outfile << j.dump() << endl;
  }
  outfile.close();
}

void Loader::load_record() {
  std::ifstream infile(config_dir + "record.txt");
  string line;
  while (std::getline(infile, line)) {
    json j = json::parse(line);
    OP_Record r = j;
    OP_Record *w = new OP_Record(r);
    records.push_back(w);
  }
  infile.close();
}

void Loader::load_words() {
  std::ifstream infile(config_dir + "words.txt");
  string line;
  // TODO: should not restricted to a line
  while (std::getline(infile, line)) {
    json j = json::parse(line);
    Word w = j;
    words.push_back(w);
  }
  infile.close();
}

void Loader::add_one_word(const std::string &w) {
  // get unused id
  int word_num = words.size();
  vector<bool> id(word_num, false);
  for (int i = 0; i < word_num; i++) {
    id[words[i].get_id()] = true;
    // check if alread exits
    if (w == words[i].get_word()) {
      cerr << "This word has already been in the database" << endl;
      words[i].check(true);
      return;
    }
  }

  int i;
  for (i = 0; i < word_num; i++) {
    if (!id[i]) {
      break;
    }
  }

  // add word
  Loader::getInstance().add_record(ADD);
  words.emplace_back(w, i);
}

/**
 * @path the file path
 * add words in a patch
 */
void Loader::add_file(const std::string &path) {
  ifstream f(path);
  if (!f.good()) {
    fprintf(stderr, "%s can't be opened !\n", path.c_str());
    exit(0);
  }
  fprintf(stderr, "Open %s\n", path.c_str());

  // get a bunch of id just by appending
  int max_id = 0;
  for (auto &w : words) {
    if (max_id < w.get_id()) {
      max_id = w.get_id();
    }
  }

  // word and location
  map<string, int> sorted_words;
  int loc = 0;
  for (auto w : words) {
    sorted_words.insert(make_pair(w.get_word(), loc));
    loc++;
  }

  std::ifstream infile(path);
  string line;
  while (std::getline(infile, line)) {
    auto f = sorted_words.find(line);
    if (f == sorted_words.end()) {
      max_id++;
      words.emplace_back(line, max_id);
      sorted_words.insert(make_pair(line, loc));
      loc++;
    } else {
      words[f->second].check(true);
    }
  }
}

void Loader::check_word(int id, check_t type) {
  // find the word
  int word_num = words.size();
  int i;
  for (i = 0; i < word_num; i++) {
    if (words[i].get_id() == id) {
      cout << "id check : " << words[i].get_word() << endl;
      break;
    }
  }

  if (i == word_num) {
    fprintf(stderr, "Error: can not find word with id");
    exit(0);
  }
  handle_word(words[i], type);
}

void Loader::check_word(std::string &word, check_t type) {
  int word_num = words.size();
  int i;
  for (i = 0; i < word_num; i++) {
    if (words[i].get_word() == word) {
      cout << "word check : " << word << endl;
      break;
    }
  }

  if (i == word_num) {
    fprintf(stderr, "Check you spell");
    exit(0);
  }
  handle_word(words[i], type);
}

void Loader::handle_word(Word &word, check_t type) {
  switch (type) {
  case REM:
    word.check(false);
    break;
  case FORGET:
    word.check(true);
    break;
  case SHUTDOWN:
    // TODO : use change mode instead of reading the line.
    break;
  case REMOVE:
    int i;
    for (i = 0; i < words.size(); i++) {
      if (words[i].get_id() == word.get_id())
        break;
    }
    words.erase(words.begin() + i, words.begin() + i + 1);
    break;
  default:
    cerr << "This action not belonging to word's action" << endl;
    return;
  }
}

void Loader::add_record(check_t t) {
  OP_Record record(t);
  std::ofstream outfile(config_dir + "record.txt",
                        std::ios_base::app | std::ios_base::out);
  json j = record;
  outfile << j.dump() << endl;
  outfile.close();
}

