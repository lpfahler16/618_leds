#include <functional>

class Lamp
{
private:
    int active;

public:
    Lamp(void (**modes)(), int size)
    {
        if (size > 9)
        {
            throw std::invalid_argument("Number of modes may not be larger than 9");
        }
    }
    void wait(unsigned long time)
    {
        unsigned long start = millis();
        unsigned long now = millis();
        while (now - start < time && active)
        {
            now = millis();
        }
    }
};