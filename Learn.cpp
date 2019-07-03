#include <fstream>
#include <string>
#include <vector>

#include <Loader.hpp>
#include <User.hpp>
#include <Util.hpp>

using namespace std;

/**
 * leading space : decrease
 * remove : data base
 * otherwise: increase
 */
void learn() {
  auto buffer_path = Loader::config_dir + "buffer.txt";
  std::ofstream outfile(buffer_path, std::ios_base::out | std::ios_base::trunc);
  outfile << "#space : decrease\n#* : data base\n# otherwise: "
             "increase"
          << endl;
  Loader &L = Loader::getInstance();
  vector<Word> &words = L.getWords();
  random_shuffle(words.begin(), words.end());

  // FIXME why we can not merge these two line.
  auto num = User::learn_num;
  num = min(num, (int)words.size());

  for (int i = 0; i < num; ++i) {
    outfile << words[i].get_word() << endl;
  }
  outfile.close();

  Util::edit_file(buffer_path.c_str());

  vector<string> result;
  std::ifstream infile(buffer_path);
  string line;

  int i = 0;
  while (std::getline(infile, line)) {
    if (line[0] != '#') {
      if(line[0] == ' '){
        words[i].check(false);
      }else if(line[0] == '*'){
        words.erase(i + words.begin());
      }else{
        words[i].check(true);
      }
      i ++;
    }
  }
  infile.close();
}
