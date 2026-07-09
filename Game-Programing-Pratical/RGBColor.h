#pragma once
class RGBColor
{
    private:
        int red;
        int green;
        int blue;
        int last_red;
        int last_blue;
        int last_green;

    public:
        RGBColor();
        RGBColor(int r, int g, int b);

        int getRedValue() const {return this->red;}

        int getBlueValue() const {return this->blue;}

        int getGreenValue() const {return this->green;}

        void setRed(int red);

        void setBlue(int blue);

        void setGreen(int green);
        void increaseColorValue(int* color_address, int* last_color_address, int value);

        void decreaseColorValue(int* color_address, int* last_color_address, int value);


        void changeGreen(int value);

        void changeRed(int value);

        void changeBlue(int value);

        int* getLastColorAddress(int* color_address);

        void checkCrossing(int* color_address);

        /*
        return True if next change is increase
        *
        */
        bool checkIncreasement(int* color_address, int value);






};
