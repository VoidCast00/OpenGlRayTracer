#include "graphics/objects/framebuffer/FBO.h"

//Frame Buffer Object =============================

FBO::FBO()=default;

void FBO::init(){
    glCreateFramebuffers(1, &ID);
}

void FBO::generateTexture(int width, int height){
    Bind();
    glGenTextures(1, &textureColorBufferID);
    glBindTexture(GL_TEXTURE_2D, textureColorBufferID);
    //@todo figure out how to get the current size bc this texture is suposed to cover the whole screen
    glTexImage2D(GL_TEXTURE_2D, 0 , GL_RGB, width,height,0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glBindTexture(GL_TEXTURE_2D, 0);


    //@todo implement RBO for depth and stencil for 3D
    // remember those cant be sampled
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorBufferID, 0);
}

void FBO::Bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, ID);
}

void FBO::Unbind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}


GLuint FBO::getID() const {
    return ID;
}

GLuint FBO::getTextureID() const {
    return textureColorBufferID;
}

FBO::~FBO()
{
    glDeleteFramebuffers(1, &ID);
}
