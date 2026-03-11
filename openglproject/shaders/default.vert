#version 330 core
layout (location = 0) in vec3 apos;
layout (location = 1) in vec3 acolor;
layout (location = 2) in vec2 aTex;

out vec3 color;
out vec2 texCoord;

uniform float scale;

uniform mat4 camMatrix;


void main()
{
    gl_Position =camMatrix * vec4(apos,1.0);

	color = acolor;

	texCoord=aTex;
}
