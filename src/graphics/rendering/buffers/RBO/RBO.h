#ifndef OPENGLRAYTRACER_RBO_H
#define OPENGLRAYTRACER_RBO_H

#include<glad/glad.h>
#include "non_copyable.h"

//@todo update to Direct State Access
//Render Buffer Object ======================



class RBO:non_copyable
{
public:
    GLuint ID{};
    RBO();
    ~RBO();
    void init();

    void Bind() const;
    void Unbind() const;
};



#endif //OPENGLRAYTRACER_RBO_H
