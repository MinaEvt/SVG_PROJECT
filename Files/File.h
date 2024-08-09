//
// Created by Mina on 8.8.2024 г..
//

#ifndef SVG_FILE_H
#define SVG_FILE_H

#include "../Helpers/String.h"
#include <fstream>

class File {
public:
    File() {
        this->filename = "<filename>";
    }

    explicit File(const char *fileName);

    static bool exists(const char *fileName);

    String getFileName();

    virtual bool isCorrectFormat() {
        return true;
    }

    void setFileName(const char *fileName);

    virtual bool hasCorrectExtension() {
        return true;
    }

protected:
    String filename;
};


#endif //SVG_FILE_H
