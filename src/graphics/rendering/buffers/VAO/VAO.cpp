#include "VAO/VAO.h"

//Vertex Array Object ===============================

VAO::VAO()=default;

void VAO::init(){
	glGenVertexArrays(1, &ID);}

void VAO::attachVertexBuffer(GLuint slot, const VBO& vbo, GLsizei stride) const {
	glVertexArrayVertexBuffer(ID, slot, vbo.ID, 0, stride);
}


void VAO::addAttrib(GLuint location, GLuint slot, GLint count, GLenum type, GLuint offset) const {
	glEnableVertexArrayAttrib(ID, location);
	glVertexArrayAttribFormat(ID, location, count, type, GL_FALSE, offset);
	glVertexArrayAttribBinding(ID, location, slot);
}
void VAO::Bind() const
{
	glBindVertexArray(ID);
}

void VAO::Unbind() const
{
	glBindVertexArray(0);
}

void VAO::Delete() const
{
	glDeleteVertexArrays(1, &ID);
}
