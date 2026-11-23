#ifndef VBO_CLASS_H
#define VBO_CLASS_H
#include <span>
#include <cstddef>
#include<glad/glad.h>

#include "vertex.h"

//VERTEX BUFFER OBJECT ========================================
class VBO
{	
public:
	GLuint ID{}; // 0
	VBO();

	void init();
	void setBufferData(std::span<const std::byte> data) const;

	void Delete() const;
};

#endif