#include "basefile.hpp"

bool BaseFile::is_open() const { return m_file != nullptr; }

bool BaseFile::can_read() const {
  if (!is_open() || m_mode == nullptr) {
    return false;
  }

  for (int i = 0; m_mode[i] != '\0'; i++) {
    if (m_mode[i] == 'r' || m_mode[i] == '+') {
      return true;
    }
  }

  return false;
}

bool BaseFile::can_write() const {
  if (!is_open() || m_mode == nullptr) {
    return false;
  }

  for (int i = 0; m_mode[i] != '\0'; i++) {
    if (m_mode[i] == 'w' || m_mode[i] == '+' || m_mode[i] == 'a') {
      return true;
    }
  }

  return false;
}

size_t BaseFile::write_raw(const void *buf, size_t n_bytes) {

  if (!can_write()) {
    return 0;
  }

  return fwrite(buf, 1, n_bytes, m_file);
}

size_t BaseFile::read_raw(void *buf, size_t max_bytes) {

  if (!can_read()) {
    return 0;
  }

  return fread(buf, 1, max_bytes, m_file);
}

long BaseFile::tell() const {

  if (!is_open()) {
    return -1;
  }
  return ftell(m_file);
}

bool BaseFile::seek(long offset) {
  if (!is_open()) {
    return false;
  }

  return fseek(m_file, offset, SEEK_SET) == 0;
}

size_t BaseFile::write(const void *buf, size_t n_bytes) {
  return write_raw(buf, n_bytes);
}

size_t BaseFile::read(void *buf, size_t max_bytes) {
  return read_raw(buf, max_bytes);
}

void write_int(IFile &file, int n) {
  {
    file.write("START\n", 6);
    if (n < 0) {
      file.write("-", 1);
      n = -n;
    }
    char buf[20];
    int i = 0;

    if (n == 0) {
      buf[i++] = '0';
    }

    while (n > 0) {
      char a = '0' + (n % 10);
      n = n / 10;
      buf[i++] = a;
    }

    for (int j = i - 1; j >= 0; j--) {
      file.write(&buf[j], 1);
    }
    file.write("\nEND", 4);
  }
}