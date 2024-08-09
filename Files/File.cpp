//
// Created by Mina on 8.8.2024 г..
//

#include "File.h"

bool File::exists(const char *fileName) {
    std::ifstream fileStream(fileName);
    return fileStream.good();
}

File::File(const char *fileName) {
    this->filename = fileName;
}

String File::getFileName() {
    return this->filename;
}

void File::setFileName(const char *fileName) {
    this->filename = fileName;
}