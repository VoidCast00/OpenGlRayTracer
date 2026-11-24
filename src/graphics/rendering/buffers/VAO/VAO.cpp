#include "VAO/VAO.h"

//Vertex Array Object ===============================

VAO::VAO()=default;

void VAO::init(){
	 glCreateVertexArrays(1, &ID);
}

void VAO::attachVertexBuffer(GLuint slot, const VBO& vbo, GLsizei stride) const {
	glVertexArrayVertexBuffer(ID, slot, vbo.getID(), 0, stride);
}

void VAO::attachElementBuffer(const EBO& ebo) const {
	glVertexArrayElementBuffer(ID, ebo.getID());
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

GLuint VAO::getID() const {
	return ID;
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &ID);
}
