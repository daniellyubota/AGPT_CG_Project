#include "TextureFragment.h"
#include <GL/glew.h>
#include <iostream>
#include "Vector2.h"

namespace engine {


SpriteTexture::SpriteTexture(Texture2D& texture, int columns, int rows) : _texture{ texture }
{
    VAOs.resize(rows * columns);
    Vector2<float> tsize = { float(texture.Width), float(texture.Height) };
    tsize = tsize.normalize();
    Vector2<float> delta = {
        tsize.x() / float(columns),
        tsize.y() / float(rows)
    };
    Vector2<float> currentPoint = {
        0.0f, 0.0f
    };

    for (int x = 0; x < columns; ++x) {
        for (int y = 0; y < rows; ++y) {
            unsigned int* VAO = &VAOs[y * columns + x];
            unsigned int VBO;
            float vertices[] = {
                0.0f, 1.0f, currentPoint.x(), currentPoint.y() + delta.y(),
                1.0f, 0.0f, currentPoint.x() + delta.x(), currentPoint.y(),
                0.0f, 0.0f, currentPoint.x(), currentPoint.y(),

                0.0f, 1.0f, currentPoint.x(), currentPoint.y() + delta.y(),
                1.0f, 1.0f, currentPoint.x() + delta.x(), currentPoint.y() + delta.y(),
                1.0f, 0.0f, currentPoint.x() + delta.x(), currentPoint.y()
            };

            glGenVertexArrays(1, VAO);
            glGenBuffers(1, &VBO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glBindVertexArray(*VAO);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);

            currentPoint.y() += delta.y();
        }
        currentPoint.x() += delta.x();
    }

}

unsigned int SpriteTexture::vao() const
{
    return VAOs[index];
}

void SpriteTexture::setActiveFrame(int index)
{
    this->index = std::min(index, int(VAOs.size()) - 1);
}

const Texture2D& SpriteTexture::texture() const
{
    return _texture;
}

const std::vector<unsigned int>& SpriteTexture::getVaos() const
{
    return VAOs;
}

}