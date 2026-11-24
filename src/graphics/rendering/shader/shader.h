#ifndef OPENGLRAYTRACER_SHADER_H
#define OPENGLRAYTRACER_SHADER_H

#include <string>
#include <glad/glad.h>
#include "non_copyable.h"


class Shader : non_copyable{
public:
    GLuint ID{};
    Shader(const char* vertexSource, const char* fragmentSource);
    ~Shader();

    void init();
    void use() const;

    void setData(const std::string &varName, bool data) const;
    void setData(const std::string &varName, float data) const ;
    void setData(const std::string &varName, int data) const ;
    void setData(const std::string &varName, double data)const;

private:

    const char* m_vertexSource;
    const char* m_fragmentSource;
    
    static unsigned int CompileShader(unsigned int type, const char* source);
    static unsigned int CreateProgram(const char* vertexSource, const char* fragmentSource);
    static void CheckCompileErrors(unsigned int shader, const std::string& type);
};




#endif //OPENGLRAYTRACER_SHADER_H
