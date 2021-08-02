#ifndef FILE_READER_H
#define FILE_READER_H
#include <fstream>
#include <vector>
#include <string>

class FileReader {
  public:
    FileReader(const std::string);
    ~FileReader();
    std::vector<std::string> getLines();
  private:
    std::fstream _file;
};

class FileReaderException : public std::exception {
  public:
    FileReaderException(const std::string& s) : _msg(s) {};
    ~FileReaderException() {};
   virtual const char* what() const noexcept override { return _msg.c_str(); }; 
  private:
    std::string _msg;
};
#endif
