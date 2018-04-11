#ifndef LOGO_H
#define LOGO_H
#include <iostream>
#include <fstream>
#include <string>

void DrawImage(std::string img_name)
{
    std::fstream image;
    image.open(img_name);
    std::string line;

    do
    {
        std::getline(image, line);
        std::cout << line << "\n";
    } while (line !="");

    image.close();
}
#endif
