#ifndef OPENGLRAYTRACER_FBO_H
#define OPENGLRAYTRACER_FBO_H

#include<glad/glad.h>
#include "util/non_copyable.h"

//@todo update to Direct State Access

//Frame Buffer Object =============================


class FBO : non_copyable
{
private:
    GLuint ID{};
    GLuint textureColorBufferID{};

public:
    FBO();
    ~FBO();

    [[nodiscard]] GLuint getID() const;
    [[nodiscard]] GLuint getTextureID() const;
    void init();
    void generateTexture(int width, int height) ;
    void Bind() const;
    void Unbind() const;
};


#endif //OPENGLRAYTRACER_FBO_H
