//
// Created by Mina on 8.8.2024 г..
//

#include "ShapeFile.h"

bool ShapeFile::hasCorrectExtension() {
    if (!filename.contains((String) ".svg")) {
//        throw std::invalid_argument("Unsupported file format!");
        std::cerr << "unsupported file format!" << std::endl;
        return false;
    }
    return true;
}

bool ShapeFile::isCorrectFormat() {
    if (!this->hasCorrectExtension())
        return false;

    std::ifstream fileStream(this->filename.getText());

    if (fileStream) {
        String line;
        while (!line.contains((String) "<svg") && !fileStream.eof()) {
            fileStream >> line;
            if (!line.contains((String) "xmlns=\"http://www.w3.org/2000/svg\">") || !this->correctMarkupTag(line)) {
                std::cerr << "Incorrect file format!" << std::endl;
                fileStream.close();
                return false;
            }
            fileStream >> line;
            while (line.contains((String) "</svg>") && !fileStream.eof()) {
                if (!this->correctSVGMarkupTag(line)) {
                    fileStream.close();
                    return false;
                }
                fileStream >> line;
            }
            fileStream.close();
            return true;
        }
        return false;
    }
}

bool ShapeFile::correctMarkupTag(String &tag) const {
    if (tag.contains((String) "<!--") && tag.contains((String) "-->"))
        return true;
    char *lineToCheck = new char[tag.getSize() + 1];
    std::strcpy(lineToCheck, tag.getText());
    int currChar = 0;
    while (lineToCheck[currChar] == ' ')
        currChar++;
    bool openingTag = lineToCheck[currChar] == '<';
    while (lineToCheck[currChar] != '>')
        currChar++;
    bool closingTag = lineToCheck[currChar] == '>';
    bool emptyAfterClosingTag = true;
    while (emptyAfterClosingTag && currChar < tag.getSize() - 1) {
        currChar++;
        if (lineToCheck[currChar] != ' ' && lineToCheck[currChar] != '\n' && lineToCheck[currChar] != '\r') {
            emptyAfterClosingTag = false;
        }
    }
    if (!(closingTag && openingTag && emptyAfterClosingTag)) {
        std::cerr << "Error in file: " << this->filename << " At line: " << lineToCheck << std::endl;
        throw std::invalid_argument("Error in file!");
    }
    delete[] lineToCheck;
    return (closingTag && openingTag && emptyAfterClosingTag);


}

bool ShapeFile::correctSVGMarkupTag(String &tag) const {
    if (this->correctMarkupTag(tag)) {
        if (tag.contains((String) "line")) {
            if (!tag.contains((String) "x1") &&
                !tag.contains((String) "y1") &&
                !tag.contains((String) "x2") &&
                !tag.contains((String) "y2") &&
                !tag.contains((String) "stroke")) {
                std::cerr << "Unsupported shape." << std::endl;
                return false;
            }
            return true;
        }
        if (tag.contains((String) "rect")) {
            if (!tag.contains((String) "x") &&
                !tag.contains((String) "y") &&
                !tag.contains((String) "width") &&
                !tag.contains((String) "height") &&
                !tag.contains((String) "stroke") &&
                !tag.contains((String) "fill")) {
                std::cerr << "Unsupported shape." << std::endl;
                return false;
            }
        }
        if (tag.contains((String) "circle")) {
            if (!tag.contains((String) "cx") &&
                !tag.contains((String) "cy") &&
                !tag.contains((String) "r") &&
                !tag.contains((String) "stroke") &&
                !tag.contains((String) "fill")) {
                std::cerr << "Unsupported shape." << std::endl;
                return false;
            }
        }
        if (tag.contains((String) "polygon")) {
            if (!tag.contains((String) "points") &&
                !tag.contains((String) "stroke") &&
                !tag.contains((String) "fill")) {
                std::cerr << "Unsupported shape." << std::endl;
                return false;
            }
        }
    } else {
        std::cerr << "Unsupported shape." << std::endl;
        return false;
    }
}