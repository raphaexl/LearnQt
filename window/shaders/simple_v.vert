
#version 330 core

layout (location = 0) in vec3 position;
layout(location = 1) in vec3 color;

out vec4    v_color;

void main(void)
{
    gl_Position = vec4(position, 1.0);
    v_color     = vec4(color, 1.0);
}
