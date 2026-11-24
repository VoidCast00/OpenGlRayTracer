#ifndef OPENGLRAYTRACER_FBO_H
#define OPENGLRAYTRACER_FBO_H

#include<glad/glad.h>
#include "non_copyable.h"

//@todo update to Direct State Access

//Frame Buffer Object =============================


class FBO : non_copyable
{
private:
    GLuint ID{};
public:
    unsigned int textureColorBufferID{};
    FBO();
    ~FBO();

    [[nodiscard]] GLuint getID() const;
    void init();
    void generateTexture(int width, int height) ;
    void Bind() const;
    void Unbind() const;
};


#endif //OPENGLRAYTRACER_FBO_H
