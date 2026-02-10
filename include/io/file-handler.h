#ifndef FILE_IO_H
#define FILE_IO_H
#include <fstream>
#include <iostream>
#include <stdexcept>

void error(const char* message);
class Writer {
    private:
        std::ofstream& output_file;
        uint8_t buffer;
        int buffer_index;
    public:
        Writer(std::ofstream& output_file);
        ~Writer();
        void writeBit();
        void writeByte();
        void writeInt();
        void writeChar();
        void flush();
        bool goodFile();
};

class Reader {
    private:
        std::ofstream& input_file;
        uint64_t buffer;
        int buffer_index;
    public:
        Reader(std::ofstream& input_file);
        ~Reader();
        void readBit();
        void readByte();
        void readInt();
        void readChar();
        bool goodFile();
        std::vector<int> readHeader(std::ofstream& input_file);
};

#endif