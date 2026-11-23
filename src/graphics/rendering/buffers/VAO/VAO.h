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

	void attachVertexBuffer(GLuint slot, const VBO& vbo, GLsizei stride) const;
	void addAttrib(GLuint location, GLuint slot, GLint count, GLenum type, GLuint offset) const;
	void Bind() const;
	void Unbind() const;
	void Delete() const;
};

#endif