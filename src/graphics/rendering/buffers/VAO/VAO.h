#ifndef VAO_CLASS_H
#define VAO_CLASS_H
#include<glad/glad.h>


//Vertex Array Object ===============================


#include "VBO/VBO.h"


class VAO
{
public:
	GLuint ID{};

	VAO();
	void init();

	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, const void* offset);
	void Bind() const;
	void Unbind() const;
	void Delete() const;
};

#endif