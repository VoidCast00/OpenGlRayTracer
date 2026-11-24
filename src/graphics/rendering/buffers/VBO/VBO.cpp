#include "VBO.h"

VBO::VBO() = default;

void VBO::setBufferData(std::span<const std::byte> data) const {
	glNamedBufferData(ID, data.size_bytes(), data.data(), GL_STATIC_DRAW);
}


void VBO::init(){
	glCreateBuffers(1, &ID);

}

GLuint VBO::getID() const {
	return ID;
}

VBO::~VBO()
{
	glDeleteBuffers(1, &ID);
}