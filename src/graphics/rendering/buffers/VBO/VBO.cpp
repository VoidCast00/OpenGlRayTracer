#include "VBO.h"

VBO::VBO() = default;

void VBO::setBufferData(std::span<const std::byte> data) const {
	glNamedBufferData(ID, data.size_bytes(), data.data(), GL_STATIC_DRAW);
}


void VBO::init(){
	glCreateBuffers(1, &ID);

}



void VBO::Delete() const
{
	glDeleteBuffers(1, &ID);
}