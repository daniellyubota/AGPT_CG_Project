#include "SpriteRenderer.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

namespace engine {

SpriteRenderer::SpriteRenderer()
{
    this->initRenderData();
}

SpriteRenderer::~SpriteRenderer()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}

void SpriteRenderer::DrawSprite(const Sprite& sprite)
{
    auto& shader = sprite.shader();
    auto texture = sprite.texture();
    auto position = glm::vec2(sprite.position().x(), sprite.position().y());
    auto size = glm::vec2(sprite.size().x(), sprite.size().y());
    float rotate = sprite.rotation();
    auto color = glm::vec3(1.0f);
    glUseProgram(shader.getID());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    model = glm::scale(model, glm::vec3(size, 1.0f));

    glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "model"), 1, false, glm::value_ptr(model));
    glUniform3f(glGetUniformLocation(shader.getID(), "spriteColor"), color.x, color.y, color.z);

    glActiveTexture(GL_TEXTURE0);
    texture.texture().Bind();

    glBindVertexArray(texture.vao());
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::initRenderData()
{
    unsigned int VBO;
    float vertices[] = {
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

}