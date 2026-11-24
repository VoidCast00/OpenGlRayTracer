#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <span>
#include <cstddef>
#include<glad/glad.h>
#include "non_copyable.h"

#include "vertex.h"

class VBO:non_copyable
{
private:
	GLuint ID{}; // 0
public:
	VBO();
	~VBO();
	[[nodiscard]] GLuint getID() const;
	void init();
	void setBufferData(std::span<const std::byte> data) const;

};

//VERTEX BUFFER OBJECT ========================================

#endif
