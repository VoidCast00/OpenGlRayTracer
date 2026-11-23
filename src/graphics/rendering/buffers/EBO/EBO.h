#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <cstddef>
#include <span>
#include<glad/glad.h>

//Element Buffer Objects=====================

class EBO
{
public:
	GLuint ID{}; // automatically initialized to zero

	EBO();
	void setBufferData(std::span<const std::byte> data) const;
	void init();
	void Delete() const;
};

#endif