#include "RGBColor.h"

RGBColor::RGBColor() :red(0), blue(0), green(0), last_red(-1), last_blue(-1), last_green(-1) {
}
RGBColor::RGBColor(int r, int g, int b) : red(r), green(g), blue(b), last_red(-1), last_blue(-1), last_green(-1) {
    checkCrossing(&red);
    checkCrossing(&blue);
    checkCrossing(&green);
}
void RGBColor::setRed(int red) {
    this->red = red;
    checkCrossing(&red);
};
void RGBColor::setBlue(int blue) {
    this->blue = blue;
    checkCrossing(&blue);
};


void RGBColor::setGreen(int green) {
    this->green = green;
    checkCrossing(&green);
}
void RGBColor::increaseColorValue(int* color_address, int* last_color_address, int value) {
    *last_color_address = *color_address;
    *color_address += value;
    checkCrossing(color_address);
}

void RGBColor::decreaseColorValue(int* color_address, int* last_color_address, int value) {
    *last_color_address = *color_address;
    *color_address -= value;
    checkCrossing(color_address);
}


void RGBColor::changeGreen(int value) {
    bool increase = checkIncreasement(&(this->green), value);
    if (increase) increaseColorValue(&(this->green), &(this->last_green), value);
    else if (!increase) decreaseColorValue(&(this->green), &(this->last_green), value);
}

void RGBColor::changeRed(int value) {
    bool increase = checkIncreasement(&(this->red), value);
    if (increase) increaseColorValue(&(this->red), &(this->last_red), value);
    else if (!increase) decreaseColorValue(&(this->red), &(this->last_red), value);
}

void RGBColor::changeBlue(int value) {
    bool increase = checkIncreasement(&(this->blue), value);
    if (increase) increaseColorValue(&(this->blue), &(this->last_blue), value);
    else if (!increase) decreaseColorValue(&(this->blue), &(this->last_blue), value);
}

int* RGBColor::getLastColorAddress(int* color_address) {
    if (color_address == &(this->red)) return &(this->last_red);
    else if (color_address == &(this->blue)) return &(this->last_blue);
    else if (color_address == &(this->green)) return &(this->last_green);

}

void RGBColor::checkCrossing(int* color_address) {
    int* last_color_address = getLastColorAddress(color_address);
    if (*color_address < 0) {
        *color_address = 0;
        *last_color_address = -1;
    }
    else if (*color_address > 255) {
        *color_address = 255;
        *last_color_address = 256;
    }
}

/*return True if next change is increase*/
bool RGBColor::checkIncreasement(int* color_address, int value) {
    int* last_color_address = getLastColorAddress(color_address);
    if (*color_address > *last_color_address) return true;
    else if (*color_address < *last_color_address) return false;
}