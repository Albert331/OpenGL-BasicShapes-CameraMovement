#include "../HeaderFiles/TextureClass.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum pixeltype) {

    type = texType;
    stbi_set_flip_vertically_on_load(true);
    int widthImg, heightImg, numColCh;
    unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

  

    GLenum format;
    if (numColCh == 4)
        format = GL_RGBA;
    else if (numColCh == 3)
        format = GL_RGB;
    else
    {
        std::cout << "Unsupported format\n";
        return;
    }


    
    glGenTextures(1, &ID);
    glActiveTexture(slot);
    glBindTexture(texType,ID);

    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(texType, 0, format, widthImg, heightImg, 0, format, pixeltype, bytes);
    glGenerateMipmap(texType);

    stbi_image_free(bytes);
    glBindTexture(texType, 0);

    
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit) {
    GLuint tex0Uni = glGetUniformLocation(shader.ID, uniform);
    shader.Activate();
    glUniform1i(tex0Uni, unit);
}

void Texture::Bind() {
    glBindTexture(type, ID);
}

void Texture::UnBind() {
    glBindTexture(type, 0);
}

void Texture::Delete() {
    glDeleteTextures(1, &ID);
}