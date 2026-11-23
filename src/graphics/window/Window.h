#ifndef OPENGLRAYTRACER_WINDOW_H
#define OPENGLRAYTRACER_WINDOW_H

#include  "shader.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include <stdexcept>
#include <iostream>



class Window
{
public:
     const unsigned int HEIGHT;
     const unsigned int WIDTH;
     double cameraPosX = 0;
     double cameraPosY = 0;
     GLFWwindow* window{};
     Window(int h, int w);
     ~Window();
     void init();
     void processInput(const Shader* shader);

     
private:
     void static framebuffer_size_callback (GLFWwindow* window,  int width,  int height);
     void static glfwErrorCallback(int error, const char* description);

};





#endif