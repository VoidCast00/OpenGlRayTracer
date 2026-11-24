
#include "EBO.h"

//Element Buffer Objects ===================================

EBO::EBO()= default;

void EBO::setBufferData(std::span<const std::byte> data) const
{
	glNamedBufferData(ID, data.size_bytes(), data.data(), GL_STATIC_DRAW);
}
void EBO::init(){
	glCreateBuffers(1, &ID);
}

GLuint EBO::getID() const {
	return ID;
}


EBO::~EBO()
{
	glDeleteBuffers(1, &ID);
}
