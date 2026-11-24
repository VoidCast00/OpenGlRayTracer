#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <cstddef>
#include <span>
#include<glad/glad.h>
#include "non_copyable.h"

//Element Buffer Objects=====================

class EBO : non_copyable
{
private:
	GLuint ID{}; // automatically initialized to zero
public:

	EBO();
	~EBO();
	[[nodiscard]] GLuint getID()const; // warn the user when the output is not used
	void setBufferData(std::span<const std::byte> data) const;
	void init();
};

#endif