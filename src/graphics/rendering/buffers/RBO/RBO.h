#ifndef OPENGLRAYTRACER_RBO_H
#define OPENGLRAYTRACER_RBO_H
#include<glad/glad.h>
//@todo update to Direct State Access
//Render Buffer Object ======================



class RBO
{
public:
    GLuint ID{};
    RBO();
    void init();

    void Delete() const;
    void Bind() const;
    void Unbind() const;
};



#endif //OPENGLRAYTRACER_RBO_H
