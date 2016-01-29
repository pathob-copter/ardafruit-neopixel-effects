#ifndef ADAFRUITNEOPIXELEFFECTS_SERIAL_H
#define ADAFRUITNEOPIXELEFFECTS_SERIAL_H

#include <iostream>

namespace AdafruitNeopixelEffects
{

    class _Serial
    {
        public:

            void print(std::string data) {
                std::cout << data;
            }

            void println(std::string data) {
                std::cout << data << std::endl;
            }
                
            void print(int data) {
                std::cout << data;
            }

            void println(int data) {
                std::cout << data << std::endl;
            }

    };
}

#endif
