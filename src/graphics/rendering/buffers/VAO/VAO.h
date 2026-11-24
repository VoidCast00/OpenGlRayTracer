#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include "non_copyable.h"


//Vertex Array Object ===============================


#include "VBO/VBO.h"
#include "EBO/EBO.h"

class VAO:non_copyable
{
private:
	GLuint ID{};
public:
	VAO();
	~VAO();
	void init();
	[[nodiscard]] GLuint getID() const;
	void attachVertexBuffer(GLuint slot, const VBO& vbo, GLsizei stride) const;
	void attachElementBuffer(const EBO& ebo) const;
	void addAttrib(GLuint location, GLuint slot, GLint count, GLenum type, GLuint offset) const;
	void Bind() const;
	void Unbind() const;
};

#endif