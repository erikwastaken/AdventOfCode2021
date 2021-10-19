#ifndef FILE_READER_HPP
#define FILE_READER_HPP
#include <fstream>
#include <vector>
#include <string>
#include "exceptions.hpp"

namespace aoc21 {

  class FileReader {
    public:
      FileReader(const std::string&);
      ~FileReader();
      std::vector<std::string> getLines();
    private:
      std::fstream _file;
  };

};

#endif
