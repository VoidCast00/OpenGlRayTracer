#include "Renderer.h"
#include <cstddef>


Renderer::Renderer() = default;

Renderer::~Renderer()
{
    vbo.Delete();
    ebo.Delete();
    vao.Delete();
    fbo.Delete();

    vertices.clear();
    indices.clear();
}


void Renderer::init()
{
    //generate all of the buffers
    //===========================//
    screenVAO.init();
    screenVBO.init();
    vbo.init();
    vao.init();
    ebo.init();
    fbo.init();



    vertices = {
        // positions                          // colors           // texture coords
        {0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f}, // top right
        {0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f}, // bottom right
        {-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f}, // bottom left
        {-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f}  // top left
   };
    indices = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };


    allocateMem(100,200);


    screenVBO.setBufferData(std::as_bytes(std::span(screenVertices)));
    screenVAO.attachVertexBuffer(0, screenVBO, sizeof(ScreenVertex));
    screenVAO.addAttrib(0, 0, 2, GL_FLOAT, offsetof(ScreenVertex, x));
    screenVAO.addAttrib(1, 0, 2, GL_FLOAT, offsetof(ScreenVertex, u));



    vbo.setBufferData(std::as_bytes(std::span(vertices)));
    ebo.setBufferData(std::as_bytes(std::span(indices)));


    vao.addAttrib(0, 0, 3, GL_FLOAT, offsetof(Vertex, x));
    vao.addAttrib(1,0,3, GL_FLOAT, offsetof(Vertex, r));
    vao.addAttrib(2,0,2, GL_FLOAT, offsetof(Vertex, u));


    fbo.Bind();
    fbo.generateTexture(800,600);
}

void Renderer::allocateMem( size_t sizeV, size_t sizeI)
{
    vertices.reserve(sizeV + indices.size());
    indices.reserve(sizeI + indices.size());
}

void Renderer::DrawElements() const
{
    vao.Bind();
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, nullptr);
}



