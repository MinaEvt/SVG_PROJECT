//
// Created by Mina on 8.8.2024 г..
//

#ifndef SVG_SHAPEFILE_H
#define SVG_SHAPEFILE_H

#include "File.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Line.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Polygon.h"


class ShapeFile : public File {
public:
    ShapeFile() : File() {};

    explicit ShapeFile(const char *filename) : File(filename) {};

    bool isCorrectFormat() override;

    bool hasCorrectExtension() override;

    bool correctMarkupTag(String &tag) const;

    bool correctSVGMarkupTag(String &tag) const;
};


#endif //SVG_SHAPEFILE_H
