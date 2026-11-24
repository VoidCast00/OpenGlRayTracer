#ifndef OPENGLRAYTRACER_RENDERER_H
#define OPENGLRAYTRACER_RENDERER_H

#include "graphics/objects/vertexArray/VAO.h"
#include "graphics/objects/buffer/VBO.h"
#include "graphics/objects/buffer/EBO.h"
#include <vector>
#include <GLFW/glfw3.h>
#include "util/vertex.h"
#include "graphics/objects/framebuffer/FBO.h"
#include "stb_image.h"
#include "util/non_copyable.h"
class Renderer : non_copyable
{

public:
    Renderer();
    ~Renderer();
    void init();
    void allocateMem(size_t sizeV, size_t sizeI);


    void DrawElements() const;
    std::vector<Vertex> vertices{};
    std::vector<GLuint> indices{};
    ScreenVertex screenVertices[6] = {
    {-1.0f,  1.0f,  0.0f, 1.0f},
    {-1.0f, -1.0f,  0.0f, 0.0f},
    {1.0f, -1.0f,  1.0f, 0.0f},

    {-1.0f,  1.0f,  0.0f, 1.0f},
    {1.0f, -1.0f,  1.0f, 0.0f},
    {1.0f,  1.0f,  1.0f, 1.0f}
    };



 //@todo temp
    VAO screenVAO;
    VBO screenVBO;
    FBO fbo;

private:

    VAO vao;
    VBO vbo;
    EBO ebo;


    //EBO screenEBO;

};


#endif //OPENGLRAYTRACER_RENDERER_H
