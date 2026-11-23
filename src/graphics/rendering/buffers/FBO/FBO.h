#ifndef OPENGLRAYTRACER_FBO_H
#define OPENGLRAYTRACER_FBO_H
#include<glad/glad.h>

//@todo update to Direct State Access

//Frame Buffer Object =============================


class FBO
{
public:
    GLuint ID{};
    unsigned int textureColorBufferID{};
    FBO();
    void init();
    void generateTexture(int width, int height) ;
    void Delete() const;
    void Bind() const;
    void Unbind() const;
};


#endif //OPENGLRAYTRACER_FBO_H
