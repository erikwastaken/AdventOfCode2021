#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

namespace aoc21 {

  class AoCException : public std::exception {
    public:
      AoCException(std::string s) : _msg(s) {};
      ~AoCException() {};
      virtual const char* what() const noexcept override { return _msg.c_str(); };
    protected:
      std::string _msg;
  };

  class FactoryException : public AoCException {
    public:
      FactoryException(std::string s) : AoCException(s) {};
  };

  class FileReaderException : public AoCException {
    public:
      FileReaderException(std::string s) : AoCException(s) {};
  };

};
#endif
