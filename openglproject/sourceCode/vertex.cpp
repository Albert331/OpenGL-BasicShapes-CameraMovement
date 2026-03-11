#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION

#include "../HeaderFiles/TextureClass.h"
#include "../HeaderFiles/shaderCLass.h"
#include "../HeaderFiles/VAO.h"
#include "../HeaderFiles/VBO.h"
#include "../HeaderFiles/EBO.h"
#include "../HeaderFiles/camera.h"

const unsigned int width = 800;
const unsigned int height = 800;


GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
    -0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
    -0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
     0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
     0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
     0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
};

// Indices for vertices order
GLuint indices[] =
{
    0, 1, 2,
    0, 2, 3,
    0, 1, 4,
    1, 2, 4,
    2, 3, 4,
    3, 0, 4
};



int main()
{
    //initialize glfw
    glfwInit();

    //make a window object
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "chal", NULL, NULL);



    if (window == NULL) {
        std::cout << "not done!!";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, width, height);

    

    
    //initialize the shaders
    Shader shaderProgram =Shader("shaders/default.vert","shaders/default.frag");
    
 
   
    //create the vao,vbo and ebo objects and bind them 
    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float),(void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3*sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));


    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();



    //texture

    

    Texture popCat("pop_catt.png", GL_TEXTURE_2D, 0, GL_UNSIGNED_BYTE);
    popCat.texUnit(shaderProgram,"tex0",0);
    popCat.Bind();




    glEnable(GL_DEPTH_TEST);

    camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        //used to clear the screen every frame
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        int count = 0;

        //tells GPU how to render
        shaderProgram.Activate();

        //camera
        camera.Inputs(window); 
        camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");
       
      
        
        popCat.Bind();

        VAO1.Bind();

        //draws the actual shape parameters:(render_type,starting_value_index,stride)
        glDrawElements(GL_TRIANGLES,sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    popCat.Delete();
    

    shaderProgram.Delete();



    
    //faaah
    glfwTerminate();
    return 0;
}