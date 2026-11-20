#ifndef OPENGLRAYTRACER_RBO_H
#define OPENGLRAYTRACER_RBO_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>


class RBO
{
public:
    unsigned int ID{};
    RBO();
    void init();

    void Delete() const;
    void Bind() const;
    void Unbind() const;
};



#endif //OPENGLRAYTRACER_RBO_H
