#pragma once

#include "ifile.hpp"
#include <cstdio>
#include <iostream>

class BaseFile : public IFile {

private:
  FILE *m_file;
  const char *m_mode;

public:
  BaseFile() { // куонструктор по умолчанию

    std::cout << "Конструктор по умолчанию класса: BaseFile\n";
    m_file = nullptr;
    m_mode = nullptr;
  }

  BaseFile(const char *path,
           const char *mode) { // конструтор, принимающий путь к файлу и
                               // параметры для открытия

    std::cout << "Конструктор c параметрами класса: BaseFile\n";
    m_file = fopen(path, mode);
    m_mode = mode;
  }

  BaseFile(FILE *file) { // конструтор принимает готовый указатель

    std::cout << "Конструктор c параметром класса: BaseFile\n";
    m_file = file;
    m_mode = nullptr;
  }

  virtual ~BaseFile() {

    std::cout << "Деструтор класса: BaseFile\n";
    if (m_file != nullptr) {
      fclose(m_file);
    }
  }

  bool operator==(const BaseFile& other) const{
    return (m_file == other.m_file && m_mode == other.m_mode);
  }

  BaseFile(const BaseFile&) = delete;
  BaseFile& operator=(const BaseFile&) = delete;

  BaseFile& operator=(BaseFile&& other) noexcept{
    if (this == &other){
      return *this;
    }
    m_mode = other.m_mode;
    if (m_file != nullptr) {
      fclose(m_file);
    }
    m_file = other.m_file;
    other.m_mode = nullptr;
    other.m_file = nullptr;
    return *this;
  }

  BaseFile(BaseFile&& other) noexcept {
      m_file = other.m_file;
      m_mode = other.m_mode;

      other.m_file = nullptr;
      other.m_mode = nullptr;
  }

  bool is_open() const;
  bool can_read() const;
  bool can_write() const;
  size_t write_raw(const void *buf, size_t n_bytes);
  size_t read_raw(void *buf, size_t max_bytes);
  long tell() const;
  bool seek(long offset);
  virtual size_t write(const void *buf, size_t n_bytes);
  virtual size_t read(void *buf, size_t max_bytes);
};

void write_int(IFile &file, int n);

