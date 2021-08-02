#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
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
#endif
