#pragma once
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Vector2.h"
#include "vector3.h"
#include "Vector4.h"

namespace engine {
class Shader
{
public:
    Shader() : ID{ 0 } { }
    void Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr);

    unsigned int getID() const;
private:
    void checkCompileErrors(unsigned int object, std::string type);
    unsigned int ID;
};

}