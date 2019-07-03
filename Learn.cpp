#include <vector>
#include <string>
#include <fstream>
#include <string>

#include <Util.hpp>
#include <Loader.hpp>
#include <User.hpp>

using namespace std;

/**
 * leading space : decrease
 * remove : data base
 * otherwise: increase
 */
void learn(){
  auto buffer_path = Loader::config_dir + "buffer.txt";
  std::ofstream outfile(buffer_path,
                        std::ios_base::app | std::ios_base::trunc);
  outfile << "leading space : decrease\nremove : data base\notherwise: increase"
          << endl;
  Loader & L = Loader::getInstance();
  vector<Word> & words =  L.getWords();
  random_shuffle(words.begin(), words.end());

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
  while (std::getline(infile, line)) {
    result.push_back(line);
#ifdef DEBUG
    printf("[%s]\n", line.c_str());
#endif
  }
  infile.close();
}
